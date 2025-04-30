#include "stdafx.h" // Если используете precompiled headers
#include "utils.h"

void string_copy(char* d, char* s) {
    while (*s) {
        *d++ = *s++;
    }
    *d = '\0';
}

int len(const char* s) {
    int length = 0;
    while (*s++) {
        length++;
    }
    return length;
}

int compare(const char* s, const char* t) {
    while (*s && *t && *s == *t) {
        s++;
        t++;
    }
    return *s - *t;
}