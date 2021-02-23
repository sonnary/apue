# include <stdio.h>
# include <stdlib.h>
# include <errno.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <fcntl.h>
# include <signal.h>

# define CPS 10
# define BUFSIZE CPS // 速度, 即缓冲区大小

static volatile int loop = 0;
static void alrm_handler (int s) {
  alarm(1);
  loop = 1;
}

int main(int argc, char **argv) {
  int sfd, dfd = 1; // dfd 为写向stdout

  if (argc < 2) {
    fprintf(stderr, "Usage: 2 args...");
    exit(1);
  }

  signal(SIGALRM, alrm_handler);
  alarm(1);
  
  do {
    sfd = open(argv[1], O_RDONLY);
    if (sfd < 0) {
      if (errno != EINTR) {
        perror("open");
        exit(1);
      }
    }
  } while(sfd < 0);

  char buf[BUFSIZE];
  int readed = 0, writted = 0;
  while(1) {
    while(!loop)
      pause();
    loop = 0;
    
    readed = read(sfd, buf, BUFSIZE);
    if (readed < 0) {
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
