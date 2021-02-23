# include <stdio.h>
# include <stdlib.h>
# include <signal.h>
# include <unistd.h>

static void int_handler(int s) {
  write(1, "!", 1);
}

int main() {
  int i, j;
  signal(SIGINT, int_handler);
  for (j = 0; i < 1000; j++) {
    for (i = 0; i < 10; i++) {
      write(1, "*", 1);
      sleep(1);
    }
    write(1, "\n", 1);
  }
  exit(0);
}
