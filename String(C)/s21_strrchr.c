#include "s21_string.h"

char *s21_strrchr(const char *str, int c) {
    const char *p = s21_NULL;

    do {
        if (*str == (char)c) {
            p = str;
        }
    } while (*str++);

    return (char *)p;
}