#include "s21_string.h"

char *s21_strstr(const char *haystack, const char *needle) {
    for (s21_size_t i = 0; haystack[i] != '\0'; i++) {
        s21_size_t j;
        for (j = 0; needle[j] != '\0'; j++) {
            if (haystack[i + j] == '\0' || haystack[i + j] != needle[j]) break;
        }

        if (needle[j] == '\0') return (char *)(haystack + i);
    }
    return s21_NULL;
}