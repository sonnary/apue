# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

/**
* date +%s
*/
int main() {
    puts("Begin!");
  execl("/bin/date", "date", "+%s", NULL); // 用date进程代替本进程, 若成功则不会返回, 失败才会返回
  perror("execl");
  exit(1);
  
  puts("End!");
  exit(0);
}
