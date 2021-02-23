# include <stdio.h>
# include <stdlib.h>
# define BUFSIZE 100

int main(int argc, char **argv) {
    FILE *fps = NULL;
    FILE *fpd = NULL;
    char buf[BUFSIZE];

    if (argc != 3) {
        fprintf(stderr, "Usage: %s <src_file_name>, <dst_file_name> need 2 arguments", argv[0]);
        exit(1);
    }

    fps = fopen(argv[1], "r");
    if (fps == NULL) {
        fclose(fps);
        perror("fopen");
        exit(1);
    }
    fpd = fopen(argv[2], "w");
    if (fpd == NULL) {
        perror("fopen");
        exit(1);
    }

    while ( fgets(buf, BUFSIZE, fps) != NULL ) {
        fputs(buf, fpd);
    }

    fclose(fps);
    fclose(fpd);

    exit(0);
}
