#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "singlelist.h"

void sl_push_front (struct SLNode **list, int n) {
  assert (list);
  struct SLNode *temp = (struct SLNode *)malloc (sizeof (struct SLNode));
  if (!temp) {
    fprintf (stderr, "Out of memory\n");
    exit (1);
  }
  temp->next = *list;
  temp->data = n;
  *list = temp;
  return;
}

int sl_pop_front (struct SLNode **list) {
  assert (list && *list);
  int ret = (*list)->data;
  struct SLNode *temp = *list;
  *list = (*list)->next;
  free (temp);
  return ret;
}

void sl_push_back (struct SLNode **list, int n) {
  assert (list);
  struct SLNode *temp = (struct SLNode *)malloc (sizeof (struct SLNode));
  if (!temp) {
    fprintf (stderr, "Out of memory\n");
    exit (1);
  }
  temp->data = n;
  temp->next = NULL;
  if (*list) {
    struct SLNode *last = *list;
    while (last->next != NULL) {
      last = last->next;
    }
    last->next = temp;
  } else {
    *list = temp;
  }
  return;
}

int sl_pop_back (struct SLNode **list) {
  assert (list && *list);
  struct SLNode *prev = NULL;
  struct SLNode *temp = *list;
  while (temp->next != NULL) {
    prev = temp;
    temp = temp->next;
  }
  int ret = temp->data;
  if (prev) {
    prev->next = NULL;
  } else {
    *list = NULL;
  }
  free (temp);
  return ret;
}

int sl_erase (struct SLNode **list, int n) {
  assert (list);
  struct SLNode *prev = NULL;
  struct SLNode *temp = *list;
  while (temp) {
    if (temp->data == n) {
      if (prev) {
        prev->next = temp->next;
      } else {
        *list = temp->next;
      }
      free (temp);
      return 1;
    }
    prev = temp;
    temp = temp->next;
  }
  return 0;
}

void sl_clear (struct SLNode **list) {
  assert (list);
  struct SLNode *temp = *list;
  while (temp) {
    struct SLNode *next = temp->next;
    free (temp);
    temp = next;
  }
  *list = NULL;
  return;
}

int sl_find (struct SLNode *list, int n) {
  assert (list);
  struct SLNode *temp = list;
  while (temp) {
    if (temp->data == n) {
      return 1;
    }
    temp = temp->next;
  }
  return 0;
}

int sl_empty (struct SLNode *list) {
  return list == NULL;
}

int  sl_length (struct SLNode *list) {
  unsigned long len = 0UL;
  while (list) {
    ++len;
    list = list->next;
  }
  return len;
}

void sl_display (struct SLNode *list) {
  unsigned long p = 0UL;
  while (list) {
    printf ("[%lu] = %d\n", p++, list->data);
    list = list->next;
  }
  return;
}

void sl_reverse (struct SLNode **list) {
  assert (list);
  struct SLNode *head = *list;
  struct SLNode *new_head = NULL;
  while (head) {
    struct SLNode *next = head->next;
    head->next = new_head;
    new_head = head;
    head = next;
  }
  *list = new_head;
  return;
}
