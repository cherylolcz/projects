#include "s21_string.h"

s21_size_t s21_strcspn(const char *str1, const char *str2) {
    const char *ptr1 = str1;
    while (*ptr1) {
        const char *ptr2 = str2;
        while (*ptr2) {
            if (*ptr1 == *ptr2) {
                return ptr1 - str1;
            }
            ptr2++;
        }
        ptr1++;
    }
    return ptr1 - str1;
}