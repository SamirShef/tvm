#ifndef UTILS_LIST_H
#define UTILS_LIST_H

#define listGet(l, i, t) (t)__listGet(l, i)

typedef struct {
    void **data;
    int count;
    int cap;
} TList;

TList *
listNew(int count);

void
listAdd(TList *l, void *el);

void *
__listGet(TList *l, int index);

void
listRemove(TList *l, void *el);

void
listRemoveAt(TList *l, int index);

void
listDel(TList *l);

#endif
