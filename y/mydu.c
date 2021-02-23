# include <stdio.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <unistd.h>
# include <fcntl.h>
# include <glob.h>
# include <dirent.h>
# include <string.h>
# define PATHSIZE 1024

static int path_noloop(const char *path) {
    char *pos = strrchr(path, '/');
  if ( pos == NULL )
    exit(1);
  if ((strcmp(pos+1, ".") == 0) || (strcmp(pos+1, "..") == 0))
    return 0;
  return 1;
}

static int mydu(char *path) {
  struct stat statres;
  glob_t globres;
  char nextpath[PATHSIZE];
  int sum = 0;

  if (lstat(path, &statres) < 0) {
    perror("lstat");
    exit(1);
  }

  if (!S_ISDIR(statres.st_mode))
    return statres.st_blocks;

  strncpy(nextpath, path, PATHSIZE);
  strncat(nextpath, "/*", PATHSIZE);
  glob(nextpath, 0, NULL, &globres);

  strncpy(nextpath, path, PATHSIZE);
  strncat(nextpath, "/.*", PATHSIZE);
  glob(nextpath, GLOB_APPEND, NULL, &globres);

  int i = 0;
  for (i = 0; i < globres.gl_pathc; i++) {
    if (!path_noloop(globres.gl_pathv[i]))
      continue;
    sum += mydu(globres.gl_pathv[i]);
  }
  sum += statres.st_blocks;
  return sum;
}

int main(int argc, char **argv) {
  if (argc != 2) {
    fprintf(stderr, "Usage: 1 argv");
    exit(1);
  }

  printf("%d", mydu(argv[1]));

  exit(1);
}
