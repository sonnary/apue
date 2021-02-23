# include <stdio.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <unistd.h>
# include <fcntl.h>
# include <glob.h>
# include <dirent.h>

# define PAT "/etc"

int main(int argc, char *argv[]) {
  DIR *dp;
  struct dirent *cur;
  
  dp = opendir(PAT);
  if (dp == NULL) {
    perror("opendir()");
    exit(1);
  }
  
  while((cur = readdir(dp)) != NULL)
    puts(cur->d_name);
  
  closedir(dp);
  
  exit(0);
}
