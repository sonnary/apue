#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <syslog.h>
#define FNAME "/tmp/out"
static int daemonize() {
  pid_t pid = fork();
  if (pid < 0) {
    return -1;
  }
  if (pid > 0)  // parent
    exit(0);

  // ------以下为child------
  // 重定向stdin, stdout, stderr
  int fd = open("/dev/null", O_RDWR);
  if (fd < 0) {
    return -1;
  }
  dup2(fd, 0);
  dup2(fd, 1);
  dup2(fd, 2);
  if (fd > 2) 
    close(fd);

  setsid();

  chdir("/");
  umask(0);// 如果不产生文件的话, 可以关掉umask

  return 0;
}

int main() {
  openlog("mydaemon", LOG_PID, LOG_DAEMON);
  
  if (daemonize()) {
    syslog(LOG_ERR, "daemonize() failed!"); // 注意这里不要加\n, syslog自己控制格式
    exit(1);
  } 
  syslog(LOG_INFO, "daemonize() seccessed!");
  
  FILE *fp = fopen(FNAME, "w");
  if (fp == NULL) {
    syslog(LOG_ERR, "fopen:%s", strerror(errno));
    exit(1);
  }
  syslog(LOG_INFO, "%s was opened.", FNAME);
  
  int i = 0;
  for ( i = 0; ; i++) {
    fprintf(fp, "%d", i);
    fflush(fp);
    syslog(LOG_DEBUG, "%d is printed.", i);
    sleep(1);
  }
  
  fclose(fp);
  closelog();
  exit(0);
}
