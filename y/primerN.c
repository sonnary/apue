# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
# define LEFT 30000000
# define RIGHT 30000200
# define N 3
int main() {
	pid_t pid;
	int i, j, n, mark;

	for (n = 0; n < N; n++) {
		pid = fork();
		if (pid < 0) {
			perror("");
			exit(1);
		}

		if (pid == 0) {
			for (i = LEFT+n; i <= RIGHT; i+=N) {
				mark = 1;
				for (j = 2; j < i/2; j++) {
					if (i % j == 0) {
						mark = 0;
						break;
					}
				}
				if (mark) {
					printf("[第%d个进程] 数字%d is a primer\n", n, i);
				}   
			}
			exit(0); // 子进程的退出方法, 防止子进程再fork孙进程
		}
	}

	for (n = 0; n < N; n++) {
		wait(NULL); // 循环3次, 等3个子进程exit后, 收3个子进程的收尸
	}

	exit(0);
}
