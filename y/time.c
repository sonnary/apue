# include <stdio.h>
# include <time.h>
# include <stdlib.h>
# define TIMESTRSIZE 1024

int main() {
  struct tm *tm;
  char timestr[TIMESTRSIZE];
  
     time_t stamp = time(NULL);
  tm = localtime(&stamp);
  strftime(timestr, TIMESTRSIZE, "Now:%Y-%m-%d", tm);
  puts(timestr);
  
  exit(0);
}
