#include <stdio.h>

int main (int argc, char **argv) {
    int i;
    printf ("Number of parameters = %d\n", argc);

    for (i = 0; i < argc ; ++i) {
        printf ("Parameter %d = %s\n", i, argv[i]);
    }
    // return 0; // doesn't have to return anything?
}
