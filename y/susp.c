# include <stdio.h>
# include <stdlib.h>
# include <signal.h>
# include <unistd.h>

static void int_handler(int s) {
  write(1, "!", 1);
}

int main() {
  int i, j;
  sigset_t set, saveset, oset;

  signal(SIGINT, int_handler);
  sigemptyset(&set);
  sigaddset(&set, SIGINT);
  sigprocmask(SIG_UNBLOCK, &set, &saveset); // 记录进此模块之前的saveset值以便后续恢复, 并按此模块业务逻辑初始化set为取消屏蔽信号
  sigprocmask(SIG_BLOCK, &set, &oset); // 屏蔽信号, 记录到oldset

  for (j = 0; i < 1000; j++) {
    for (i = 0; i < 5; i++) {
      write(1, "*", 1);
      sleep(1);
    }
    write(1, "\n", 1);

    sigsuspend(&oset); // 原子操作: 解除屏蔽信号 + 恢复至oldset信号, 开始响应信号
    /*
    sigset_t tmpset;
    sigprocmask(SIG_UNBLOCK, &oset, &tmpset); // 解除信号的屏蔽
        pause();
        sigprocmask(SIG_UNBLOCK, &tmpset, NULL); // 解除信号的屏蔽
        */
  }
  sigprocmask(SIG_SETMASK, &saveset, NULL); // 出模块后, 恢复为进此模块之前的saveset值

  exit(0);
}
