#include "s21_string.h"

int s21_strncmp(const char *str1, const char *str2, s21_size_t n) {
    for (s21_size_t i = 0; i < n; i++) {
        unsigned char c1 = (unsigned char)str1[i];
        unsigned char c2 = (unsigned char)str2[i];

        if (c1 != c2) return c1 - c2;

        if (c1 == '\0') break;
    }

    return 0;
}