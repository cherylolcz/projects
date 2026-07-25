#include "s21_string.h"

s21_size_t s21_strlen(const char *str) {
    const char *p = str;
    s21_size_t i;

    for (i = 0; *p != '\0'; i++) {
        p++;
    }

    return i;
}