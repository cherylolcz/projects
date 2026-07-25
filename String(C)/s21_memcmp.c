#include "s21_string.h"

int s21_memcmp(const void *str1, const void *str2, s21_size_t n) {
    unsigned char *ptr1 = (unsigned char *)str1;
    unsigned char *ptr2 = (unsigned char *)str2;

    for (s21_size_t i = 0; i < n; i++) {
        if (ptr1[i] != ptr2[i]) return ptr1[i] - ptr2[i];
    }

    return 0;
}