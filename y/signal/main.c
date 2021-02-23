# include <stdio.h>
# include <stdlib.h>
# include <errno.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <fcntl.h>
# include <signal.h>
# include <string.h>
# include "mytbf.h"

# define CPS 10 // 速度, 即缓冲区大小
# define BUFSIZE 1024
# define BURST 100

static volatile int token = 0;
static void alrm_handler (int s) {
  alarm(1);
  token++;
  if (token > BURST)
    token = BURST;
}

int main(int argc, char **argv) {
  int sfd, dfd = 1; // dfd 为写向stdout

	printf("before sfd:%d", sfd);
  if (argc < 2) {
    fprintf(stderr, "Usage: 2 args...");
    exit(1);
  }

  mytbf_t *tbf = mytbf_init(CPS, BURST);
  if (tbf == NULL) {
    fprintf(stderr, "mytbf_init failed");
    exit(1);
  }

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
    int got_token_size = mytbf_fetchtoken(tbf, BUFSIZE);
    if (got_token_size < 0) {
      fprintf(stderr, "mytbf_ftchtoken(): %s\n", strerror(-got_token_size));
      exit(1);
    }

    while ((readed = read(sfd, buf, got_token_size)) < 0) {
      if (errno == EINTR)
        continue;
      perror("read fail");
      break;
    }
    
    if (readed == 0) {
	printf("read 0");
      break;
    }
	printf("read some");

    // 归还用不完的token
    if (got_token_size - readed > 0) {
      mytbf_returntoken(tbf, got_token_size - readed);
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
  mytbf_destroy(tbf);

  exit(0);
}


