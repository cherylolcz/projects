#include "s21_string.h"

char *s21_strchr(const char *str, int c) {
    if (str == s21_NULL) return s21_NULL;

    while (1) {
        if (*str == (unsigned char)c) {
            return (char *)str;
        }
        if (*str == '\0') break;
        str++;
    }

    return s21_NULL;
}