#ifndef SINGLELIST_H
#define SINGLELIST_H 1

struct SLNode {
  struct SLNode *next;
  int data;
};

void sl_push_front (struct SLNode **list, int n);
int  sl_pop_front  (struct SLNode **list);
void sl_push_back  (struct SLNode **list, int n);
int  sl_pop_back   (struct SLNode **list);

int  sl_erase      (struct SLNode **list, int n);
void sl_clear      (struct SLNode **list);

int  sl_find       (struct SLNode *list, int n);

int  sl_empty      (struct SLNode *list);

int  sl_length     (struct SLNode *list);

void sl_display    (struct SLNode *list);

void sl_reverse    (struct SLNode **list);

void sl_qsort      (struct SLNode **list);

#endif /* SINGLEIST_H */