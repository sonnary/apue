# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <errno.h>
# include <signal.h>
# include <sys/time.h>
# include "mytbf.h"

// typedef void (*sighandler_t)(int);

static struct mytbf_st* job[MYTBF_MAX];
static int inited = 0;
// static sighandler_t alrm_handler_save;
static struct sigaction alrm_sa_save;

struct mytbf_st {
  int cps;
  int burst;
  int token;
  int pos;
};

static void alrm_action(int s, siginfo_t *infop, void *unuesd) {
  int i = 0;
  // alarm(1);
  if(infop->si_code != SI_KERNEL) {
    return;
  }
  
  for (i = 0; i< MYTBF_MAX; i++) {
    if (job[i] != NULL) {
      job[i]->token += job[i]->cps;
      if (job[i]->token > job[i]->burst)
        job[i]->token = job[i]->burst;
    }
  }
}

static void module_unload(void) {
//  signal(SIGALRM, alrm_handler_save);
//  alarm(0);
  
  sigaction(SIGALRM, &alrm_sa_save, NULL);
  
  struct itimerval itv;
  itv.it_interval.tv_sec = 0;
  itv.it_interval.tv_usec = 0;
  itv.it_value.tv_sec = 0;
  itv.it_value.tv_usec = 1;
  setitimer(ITIMER_REAL, &itv, NULL);
  
    int i = 0;
  for (i = 0; i < MYTBF_MAX; i++)
    free(job[i]);
}

static void module_load(void) {
//  alrm_handler_save = signal(SIGALRM, alrm_handler);
//  alarm(1);

  struct sigaction sa;
  sa.sa_sigaction = alrm_action;
  sigemptyset(&sa.sa_mask);
  sa.sa_flags = SA_SIGINFO;
  sigaction(SIGALRM, &sa, &alrm_sa_save);
  
  struct itimerval itv;
  itv.it_interval.tv_sec = 1;
  itv.it_interval.tv_usec = 0;
  itv.it_value.tv_sec = 1;
  itv.it_value.tv_usec = 1;
  setitimer(ITIMER_REAL, &itv, NULL);
  
  atexit(module_unload); // 卸载模块 只被调用一次
}

static int get_free_pos(void) {
  int i = 0;

  for ( i = 0; i < MYTBF_MAX; i++) {
    if (job[i] == NULL)
      return i;
  }
  return -1;
}

mytbf_t *mytbf_init(int cps, int burst) {
  struct mytbf_st *me;

  if (!inited) {
    module_load();
    inited = 1;
  }

  int pos = get_free_pos();
  if (pos < 0)
    return NULL;

  me = malloc(sizeof(*me));
  if (me == NULL) {
    return NULL;
  }
  me->token = 0;
  me->cps = cps;
  me->burst = burst;
  me->pos = pos;

  job[pos] = me;

  return me;
}

static int min(int a, int b) {
  if (a < b)
    return a;
  return b;
}

int mytbf_fetchtoken(mytbf_t *ptr , int size){
  struct mytbf_st *me = ptr; // 空指针强转: 相当于interface{}的reflect
  if (size <= 0)
    return -EINVAL;
  while(me->token <= 0) // 无token则阻塞, 当有token时会发signal, 则pause()的阻塞会被打破
    pause();
  int n = min(me->token, size);
  me->token -= n;
  return n;
}

int mytbf_returntoken(mytbf_t *ptr, int size) {
  struct mytbf_st *me = ptr;
  if (size <= 0)
    return -EINVAL;
  me->token += size;
  if (me->token > me->burst)
    me->token = me->burst;
  return size;
}

int mytbf_destroy(mytbf_t *ptr) {
  struct mytbf_st *me = ptr;
  job[me->pos] = NULL;
  free(ptr);
  return 0;
}
