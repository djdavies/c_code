#include <stdio.h>

int main (int argc, char **argv) {
    int l = 0;
    printf ("l=%d\n", l);

    {
        int l = 1;
        printf ("{ l=%d }\n", l);
    }

    printf ("l=%d\n", l);

    return 0;
}
