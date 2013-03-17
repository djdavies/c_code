#include <stdio.h>

void f1 () {
  printf ("f1 (); ");
}

void f2 () {
  printf ("f2 (); ");
}

int f3() {
  printf ("f3 (); ");
  return 3;
}

int f4() {
  printf ("f4 (); ");
  return 4;
}

int f5 (int i) {
  printf ("f5 (%d); ", i);
  return i + 1;
}

int f6 (int i) {
  printf ("f6 (%d); ", i);
  return i - 2;
}

/* Execute a function 10 times */
int Do10 (int (*func)(int)) {
  int i = 0, j = 0;
  for (i = 0 ; i < 10 ; ++i) {
    j = func (j);
  }
  return j;
}

int main (int argc, char **argv) {
  void (*g1)() = NULL;
  void (*g2)() = NULL;
  int (*g3)() = NULL;
  int (*g4)() = NULL;
  int (*g5)( int ) = NULL;
  int (*g6)( int ) = NULL;

  printf ("Test 1: ");
  g1 = &f1;
  (*g1) ();
  g1 ();

  printf ("\nTest 2: ");
  g2 = &f2;
  (*g2) ();
  g2 ();

  // Assignment of function pointers
  printf ("\nTest 3: ");
  g2 = g1;
  (*g2) ();
  g2 ();

  printf ("\nTest 4: ");
  g3 = &f3;
  g4 = &f4;
  printf ("Result = %d", g3 ());
  printf ("Result = %d", g4 ());

  printf ("\nTest 5: ");
  g5 = &f5;
  g6 = &f6;
  g5 (1);
  g6 (2);
  printf ("\nTest 6: ");
  g5 (g3 ());
  printf ("\nTest 7: ");
  g6 (g4 ());
  printf ("\nTest 8: " );
  g6 (g5 (g3 ()));

  printf ("\nTest 9: ");
  Do10 (g5);
  printf ("\nTest 10: ");
  Do10 (g6);
  printf ("\n");

  return 0;
}
