#include <stdio.h>

int main (int argc, char *argv[]) {
  int intarray[5][6];
  int l, k;

  printf( "Addresses of array elements:\n" );
  for (l = 0 ;l < 5 ; ++l) {
    for (k = 0 ;k < 6 ; ++k) {
      printf( "Array element [%d][%d] is at address %p\n", l, k, &(intarray[l][k]) );
    }
  }

  return 0;
}
