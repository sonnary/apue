# include <stdio.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <unistd.h>
# include <fcntl.h>

off_t flen(char *filename) {
  struct stat data;
  
  if (stat(filename, &data) != 0) {
    return 0;
  }
  return data.st_size;
}

int main(int argc, char **argv) {
  if (argc < 2) {
    fprintf(stderr, "Usage...\n");
    exit(1);
  }
  
  printf("%lld\n", flen(argv[1]));
}
