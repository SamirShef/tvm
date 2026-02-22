#ifndef UTILS_STRING_H
#define UTILS_STRING_H

typedef struct {
    char *data;
    int len;
    int cap;
} TString;

TString *
strNew(const char *s);

TString *
strCat(TString *s1, const char *s2);

TString *
strCat2(TString *s1, TString *s2);

int
strEq(TString *s1, const char *s2);

int
strEq2(TString *s1, TString *s2);

void
strDel(TString *s);

#endif
