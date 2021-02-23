# include <stdio.h>
# include <stdlib.h>
# include <errno.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <fcntl.h>
# include <signal.h>
# include <sys/time.h>

# define CPS 10
# define BUFSIZE CPS // 速度, 即缓冲区大小

static volatile int loop = 0;
static void alrm_handler (int s) {
  loop = 1;
}

int main(int argc, char **argv) {

printf("000");
  int sfd, dfd = 1; // dfd 为写向stdout
  struct itimerval itv;
  
printf("aaa%d", sfd);
  if (argc < 2) {
    fprintf(stderr, "Usage: 2 args...");
    exit(1);
  }

printf("xxx%d", sfd);
  if (signal(SIGALRM, alrm_handler) == SIG_ERR) {
    perror("signal");
    exit(1);
  }

printf("yyy%d", sfd);
  itv.it_interval.tv_sec = 1;
  itv.it_interval.tv_usec = 0;
  itv.it_value.tv_sec = 1;
  itv.it_value.tv_usec = 0;
  if (setitimer(ITIMER_REAL, &itv, NULL) < 0) {
    perror("setitimer failed()");
    exit(1);
  }

printf("before sfd:%d", sfd);
  do {
    sfd = open(argv[1], O_RDONLY);
    if (sfd < 0) {
      if (errno != EINTR) {
        perror("open");
        exit(1);
      }
    }
  } while(sfd < 0);

printf("after sfd:%d", sfd);

  char buf[BUFSIZE];
  int readed = 0, writted = 0;
  while(1) {
	printf("before while");
    while(!loop)
      pause();
    loop = 0;
	printf("after while");

    while (readed = read(sfd, buf, BUFSIZE) < 0) {
      if (errno == EINTR)
        continue;
      perror("read fail");
      break;
    }
    if (readed == 0) {
      fprintf(stdout, "all readed done");
      break;
    }

    int pos = 0;
    int towrite = readed;
    while(towrite > 0) {
      writted = write(dfd, buf + pos, towrite);
      if (writted < 0) {
        if (errno == EINTR)
          continue;
        perror("write fail");
        exit(1);
      }

      towrite -= writted;
      pos += writted;
    }
    sleep(1);
  }

  close(sfd);
  close(dfd);

  exit(0);
}
