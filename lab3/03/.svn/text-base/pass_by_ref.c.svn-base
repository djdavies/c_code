#include <stdio.h>

/* A copy of the passed parameter is put into icopy
 * Anything done to icopy applies to this copy, not the parameter that was passed in
 */
void AlterCopy (int icopy) {
  icopy = 2;
  return;
}

/* A copy of the pointer is put into the parameter
 * Copies of pointers point to the same object as the original.
 */
void AlterValue (int *picopy) {
  *picopy = 3;
  return;
}

int main (int argc, char *argv[]) {
  int i = 1;
  printf ("Initial value of i is %d\n", i);
  AlterCopy (i);
  printf ("After AlterCopy, value of i is %d\n", i);
  AlterValue (&i);
  printf ("After AlterValue, value of i is %d\n", i);
  return 0;
}
