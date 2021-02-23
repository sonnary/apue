# include <stdio.h>
# include <stdlib.h>

int main(int argc, char **argv) {
    FILE *fps = NULL;
    FILE *fpd = NULL;
    int ch;
    int put_ret_code;

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

    while (1) {
        ch = fgetc(fps);
        if (ch == EOF) {
            break;
        }
        put_ret_code = fputc(ch, fpd);
        if (put_ret_code == EOF) {
            break;
        }
    }

    fclose(fps);
    fclose(fpd);
}
