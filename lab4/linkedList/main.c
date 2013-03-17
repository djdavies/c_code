#include <stdio.h>

#include "singlelist.h"

int main (int argc, char *argv[]) {
  int l;
  int max_value = 10;

  struct SLNode *list = NULL;

  printf ("Push Front:\n");
  for (l = 0; l < max_value; ++l) {
    sl_push_front (&list, l);
  }
  sl_display (list);

  printf ("Pop Back:\n");
  for (l = 0; l < max_value / 2; ++l) {
    printf ("%d: %d\n", l, sl_pop_back (&list));
  }

  printf ("Pop Front:\n");
  while (!sl_empty (list)) {
    printf ("%d: %d\n", l, sl_pop_front (&list));
  }

  printf ("Push Back:\n");
  for (l = 0; l < max_value; ++l) {
    sl_push_back (&list, l);
  }
  sl_display (list);

  printf ("Reverse:\n");
  sl_reverse (&list);
  sl_display (list);

  printf ("Sort1:\n");
  sl_qsort (&list);
  sl_display (list);

  printf ("Sort2:\n");
  sl_qsort (&list);
  sl_display (list);

  printf ("Delete even:\n");
  for (l = 0; l < max_value; l += 2) {
    sl_erase (&list, l);
  }
  sl_display (list);

  printf ("Clear:\n");
  sl_clear (&list);

  sl_display (list);

  return 0;
}