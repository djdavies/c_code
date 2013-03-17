#include <stdio.h>

void f1 () {
  printf ("  f1 ();\n");
}

int f2 (int a) {
  printf ("  f2 (%d);\n", a);
  return 2 * a;
}

int main (int argc, char **argv) {
  void (*g1) () = NULL;
  int (*g2) (int) = NULL;

  printf ("Test 1:\n");
  g1 = &f1;
  (*g1) ();
  g1 ();

  printf ("Test 2:\n");
  g2 = &f2;
  printf ("  Result: %d\n", (*g2) (1));
  printf ("  Result: %d\n", g2 (1));

  return 0;
}
