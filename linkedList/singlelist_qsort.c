#include <stdio.h>
#include <assert.h>

#include "singlelist.h"

void sl_qsort (struct SLNode **list) {
  assert (list);

  if (!*list || !(*list)->next) {
    return;
  }

  int cmp = (*list)->data;
  struct SLNode *middle = (*list);

  struct SLNode *smaller_head = NULL;
  struct SLNode *smaller = NULL;

  struct SLNode *larger_head = NULL;
  struct SLNode *larger = NULL;

  struct SLNode *temp = (*list)->next;
  while (temp) {
    if (temp->data < cmp) {
      if (smaller) {
        smaller->next = temp;
        smaller = temp;
      } else {
        smaller_head = smaller = temp;
      }
    } else {
      if (larger) {
        larger->next = temp;
        larger = temp;
      } else {
        larger_head = larger = temp;
      }
    }
    temp = temp->next;
  }

  if (smaller) {
    smaller->next = NULL;
    sl_qsort (&smaller_head);
    while (smaller->next) {
      smaller = smaller->next;
    }
    smaller->next = middle;
    *list = smaller_head;
  }

  if (larger) {
    larger->next = NULL;
    sl_qsort (&larger_head);
  }
  middle->next = larger_head;

  return;
}
