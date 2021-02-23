# include <stdio.h>
# include <stdlib.h>
# include <string.h>

int main(int argc, char **argv) {
  if (argc < 2) {
    fprintf(stderr, "Usage...\n");
    exit(1);
  }

  FILE *fp = fopen(argv[1], "r");
  if (fp == NULL) {
    perror("fopen");
    exit(1);
  }

  char *linebuf;
  size_t linesize;
  while(1) {
    if (getline(&linebuf, &linesize, fp) < 0 ) {
      break;
    }
    printf("%lu\n", strlen(linebuf));
  }

  fclose(fp);
  exit(0);
}
