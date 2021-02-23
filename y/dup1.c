# include <stdio.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <unistd.h>
# include <fcntl.h>
# define TMP_FILE "/tmp/out"
int main() {
  int fd = open(TMP_FILE, O_RDONLY|O_WRONLY|O_CREAT|O_TRUNC, 0600);
  if (fd < 0) {
    perror("open");
    exit(1);
  }
  
  close(1);
  dup(fd); 
  close(fd);
  
  puts("hello!");
  exit(0);
}
