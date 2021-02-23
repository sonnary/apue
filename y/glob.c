# include <stdio.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <unistd.h>
# include <fcntl.h>
# include <glob.h>

int main(int argc, char *argv[]) {
  if (argc != 2) {
    fprintf(stderr, "Usage: 1 argvs");
    exit(1);
  }
  
  glob_t globres;
  int i, err;
  
  err = glob(argv[1], 0, NULL, &globres);
  if (err) {
    printf("Error code = %d\n", err);
    exit(1);
  }
  
  for (i = 0; i < globres.gl_pathc; i++) {
    puts(globres.gl_pathv[i]);
  }
  
  exit(0);
}
