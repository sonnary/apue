# include <stdio.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <fcntl.h>
# define BUFSIZE 1024

int main(int argc, char **argv) {
  int sfd, dfd;
  
  if (argc < 3) {
    fprintf(stderr, "Usage: 3 args...");
    exit(1);
  }
  
  sfd = open(argv[1], O_RDONLY);
  if (sfd < 0) {
    perror("open");
    exit(1);
  }
  
  dfd = open(argv[2], O_WRONLY|O_CREAT|O_TRUNC,0600);
  if (dfd < 0) {
    close(sfd);
    perror("open");
    exit(1);
  }
  
  char buf[BUFSIZE];
  int readed = 0, writted = 0;
  while(1) {
    readed = read(sfd, buf, BUFSIZE);
    if (readed < 0) {
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
        perror("write fail");
        exit(1);
      }
      
      towrite -= writted;
      pos += writted;
    }
  }
  
  close(sfd);
  close(dfd);
  
  exit(0);
}
