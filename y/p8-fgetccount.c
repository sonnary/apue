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

    long count = 0;
    while (fgetc(fp) != EOF) {
        count++;
    }

    fclose(fp);

    fprintf(stdout, "count: %ld\n", count);
    exit(0);
}
