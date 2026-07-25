#include "s21_string.h"

char *s21_strncat(char *dest, const char *src, s21_size_t n) {
    char *ptr1 = dest;

    while (*ptr1 != '\0') ptr1++;

    while (n--) {
        *ptr1++ = *src++;
    }
    *ptr1 = '\0';

    return dest;
}