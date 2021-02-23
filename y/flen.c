# include <stdio.h>
# include <stdlib.h>

int main(int argc, char **argv) {

    if (argc != 2) {
        fprintf(stderr, "Usage: need 1 arg\n");
        exit(1);
    }

    FILE *fp = fopen(argv[1], "r");
    if (fp == NULL) {
        perror("fopen");
        exit(1);
    }

    int seek_success = fseek(fp, 0, SEEK_END);
  	if (seek_success != 0) {
      perror("seek fail");
      exit(1);
    }
  
    printf("%ld\n", ftell(fp));

    fclose(fp);
    exit(0);
}
