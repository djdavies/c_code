#include <stdio.h>

int main (int argc, char **argv) {
    int i;

    short s[] = { 4, 1, 6, 34, 2, 19, 253, 32767, 32768, 40000 };

    long l[] = { 100000, 5, 400000, 1234567890, 3456789012 };
    /* Note that 3456789012 is too big for a long, so will be an
     * unsigned long and converted to a long for the assignment.
     * You should get a warning from the compiler that the value
     * is too big for a signed long */

    char ac[] = { 'C', '-', 'S', 't', 'r', 'i', 'n', 'g', '\0' };


    printf( "Array of shorts: sizeof(short)=%ld\n", sizeof(short));
    for (i = 0; i < sizeof (s) / sizeof (short); ++i) {
        printf ("s[%d] has value %6d and address %p\n", i, s[i], &(s[i]));
    }
    printf ("Array of longs: sizeof(long)=%ld\n", sizeof(long));
    for (i = 0; i < sizeof (l) / sizeof (long); ++i) {
        printf ("l[%d] has value %12ld and address %p\n", i, l[i], &(l[i]));
    }
    printf( "Array of chars: sizeof(char)=%ld\n", sizeof(char));
    for (i = 0; i < sizeof(ac) / sizeof(char); ++i) {
        printf ("ac[%d] has value '%c' or %3d and address %p\n", i, ac[i], ac[i], &(ac[i]));
    }

    return 0;
}
