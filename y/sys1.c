# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/wait.h>

int main() {
  puts("BEGIN");
  
  fflush(NULL);
  pid_t pid = fork();
  if (pid < 0) {
    perror("fork()");
    exit(0);
  }
  
  if (pid == 0) {
    execl("/bin/sh", "sh", "-c", "date +%s", NULL);
    perror("execl()");
    exit(1);
  }
  
  wait(NULL);
  
  puts("END");
  
  exit(0);
}
