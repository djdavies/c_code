#include <stdio.h>

int main (int argc, char *argv[]) {
  int intarray[5][6][4];
  int l, k, j;

  printf ("Addresses of array elements:\n");
  for (l = 0 ;l < 5 ; ++l) {
    for (k = 0 ;k < 6 ; ++k) {
      for (j = 0 ;j < 4 ; ++j) {
        printf ("Array element [%d][%d][%d] is at address %p\n", l, k, j, &(intarray[l][k][j]));
      }
    }
  }

  return 0;
}
