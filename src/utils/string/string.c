#include <utils/string/string.h>
#include <stdlib.h>
#include <string.h>

TString *
strNew(const char *s) {
    int len = strlen(s);
    TString *ts = (TString *)malloc(sizeof(TString));
    ts->cap = len < 8 ? 8 : len * 2;
    ts->len = len;
    ts->data = (char *)malloc(ts->cap);
    for (int i = 0; i < len; ++i) {
        ts->data[i] = s[i];
    }
    return ts;
}

TString *
strCat(TString *s1, const char *s2) {
    int len2 = strlen(s2);
    s1->len += len2;
    if (s1->len > s1->cap) {
        s1->cap *= 2;
        s1->data = (char *)realloc(s1->data, s1->cap);
    }
    for (int i = 0; i < len2; ++i) {
        s1->data[s1->len - len2 + i] = s2[i];
    }
    return s1;
}

TString *
strCat2(TString *s1, TString *s2) {
    return strCat(s1, s2->data);
}

int
strEq(TString *s1, const char *s2) {
    int len2 = strlen(s2);
    if (s1->len != len2) {
        return 0;
    }
    for (int i = 0; i < s1->len; ++i) {
        if (s1->data[i] != s2[i]) {
            return 0;
        }
    }
    return 1;
}

int
strEq2(TString *s1, TString *s2) {
    return strEq(s1, s2->data);
}

void
strDel(TString *s) {
    free(s->data);
    free(s);
}
