#include <utils/list/list.h>
#include <stdlib.h>
#include <assert.h>

TList *
listNew(int count) {
    TList *l = (TList *)malloc(sizeof(TList));
    l->cap = count < 8 ? 8 : count * 2;
    l->count = count;
    l->data = (void **)malloc(sizeof(void *) * l->cap);
    return l;
}

void
listAdd(TList *l, void *el) {
    if (l->cap < l->count + 1) {
        l->cap *= 2;
        l->data = (void **)realloc(l->data, sizeof(void *) * l->cap);
    }
    l->data[l->count++] = el;
}

void *
__listGet(TList *l, int index) {
    assert(index >= 0 && index < l->count);
    return l->data[index];
}

void
listRemove(TList *l, void *el) {
    for (int i = 0; i < l->count; ++i) {
        if (__listGet(l, i) == el) {
            listRemoveAt(l, i);
            return;
        }
    }
}

void
listRemoveAt(TList *l, int index) {
    assert(index >= 0 && index < l->len);
    for (int i = index; i < l->count - 1; ++i) {
        l->data[i] = l->data[i + 1];
    }
    --l->count;
}

void
listDel(TList *l) {
    free(l->data);
    free(l);
}
