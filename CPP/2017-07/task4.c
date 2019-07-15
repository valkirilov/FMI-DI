#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

int main( int argc, char * argv[]) {
    int fdi,
        fdo,
        k,
        broi,
        i = 0,
        status;
    char buff[40], c;

    if ((fdi = open("file.txt", O_RDWR)) == -1) {
        printf("\n Cannot open 1 \n");
        exit(1);
    }

    if ((fdo = open(argv[1], O_CREAT | O_TRUNC | O_RDWR, 0666)) == -1) {
        printf("\n Cannot open 2 \n");
        exit (1);
    }

    if (fork() == 0) {
        k = dup(1);
        close(1);
        dup(fdi);

        broi = read(fdi, buff, 40); // 22 abcdef\n0123456789\nABCD
        c = buff[i++]; // b

        if (c <= '0' || c >= '9') {
            while (buff[i++] != '\n' && i < broi)
                write(1, "*", 1);
            write(1, "\n", 1);
            close(1);
            dup(k);
            write (1, buff, 3);
            write (fdo, buff, 10);
        }
        else {
            write(1, buff, broi); // abcdef\n0123456789\nABCD
            close(1);
            dup(k);
            write(1, "*\n", 2); // *\n
        }

        lseek(fdo, 0, 0);
        write(fdo, "*\n", 2); // *\n
        close(fdi);
        close(fdo);
    }
    else {
        printf("Parent %d", status);
        wait(&status);
        close(1);
        dup(fdi);
        execlp("grep", "grep", "c", argv[1], 0);
        execlp("wc", "wc", "-l", "ff" , 0);
    }
}
