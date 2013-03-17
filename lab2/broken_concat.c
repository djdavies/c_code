#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int length_of_concatenation (char **strs) {
    int length = 0;
    char **p = strs;
    while (p) {
        char *q = *p++;
        while (*q++);
        length += q - *p - 1;
    }
    return length;
}

void concatenate (char *dest, char **strs) {
    char *d = dest;
    char **p = strs;
    while (p) {
        char *q = *(++p);
        while (*d++ = *q++);
    }
    return;
}

int main (int argc, char **argv) {
    /* Create an array of strings, terminated by 0 */
    char *strs[] = { "C", "-Str", "ings", " ", "are", " ", "tricky", "", "!", 0 };

    /* Determine length of concatenated strings in strs and
       31     * allocate sufficient memory */
    char *res = malloc ((length_of_concatenation (strs)) * sizeof (char));
    if (!res) {
        fprintf (stderr, "Not enough memory!\n");
        exit (-1);
    }

    /* Concatenate strings */
    concatenate (res, strs);

    /* Print result */
    printf ("%s\n", res);

    /* Free memory */
    free (res);

    return 0;
}
