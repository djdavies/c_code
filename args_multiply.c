#include <stdio.h>

int main (int argc, char **argv){
    int num1, num2;

    if (argc < 3) {
        printf ("Usage: %s <val1> <val2>\n", argv[0]);
        return 1;
    }

    num1 = atoi (argv[1]); // atoi = char string to int
    num2 = atoi (argv[2]);

    printf("Num 1 = %d, num2 = %d\n", num1, num2);
    printf( "%d * %d = %d\n", num1, num2, num1 * num2 );

    return 0;
}
