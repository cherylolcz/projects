#include "s21_string.h"

void *s21_memcpy(void *dest, const void *src, s21_size_t n) {
    unsigned char *ptr1 = (unsigned char *)dest;
    const unsigned char *ptr2 = (const unsigned char *)src;

    while (n--) {
        *ptr1++ = *ptr2++;
    }

    return dest;
}