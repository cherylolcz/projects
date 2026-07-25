#include "s21_string.h"

void *s21_insert(const char *src, const char *str, s21_size_t start_index) {
    if (src == s21_NULL || str == s21_NULL) return s21_NULL;

    s21_size_t len_1 = s21_strlen(src);
    s21_size_t len_2 = s21_strlen(str);

    if (start_index > len_1) return s21_NULL;

    char *result = (char *)malloc(len_1 + len_2 + 1);

    s21_size_t i = 0;
    for (; i < start_index; i++) {
        result[i] = src[i];
    }

    for (s21_size_t j = 0; j < len_2; j++) {
        result[i++] = str[j];
    }

    for (s21_size_t k = start_index; k < len_1; k++) {
        result[i++] = src[k];
    }

    result[i] = '\0';
    return (void *)result;
}