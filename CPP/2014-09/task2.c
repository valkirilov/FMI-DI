#include <stdio.h>

int main (int argc, char** argv) {

    int a = 1000;

    if (fork()) {
        a /= 2;
        printf("\n1. Value of a = %d", a);
    }
    else {
        if (fork()) {
            a *= 2;
            printf("\n2. Value of a = %d", a);

            if (execl("ls", "ls", "-l", 0) == -1) {
                a = a + 2;
                printf("\n2.1. Value of a = %d", a);
            }
        }
        else {
            a +=2 ;
            printf("\n3.Value of a = %d", a);
        }
    }

    a++;
    printf("\nEnd: Value of a = %d", a);

}