#include "s21_string.h"

void *s21_to_lower(const char *str) {
    if (str == s21_NULL) return s21_NULL;
    s21_size_t len = s21_strlen(str);

    char *result = (char *)malloc((len + 1));
    char *result_start = result;

    if (result == s21_NULL) return s21_NULL;

    while (len--) {
        if (*str >= 'A' && *str <= 'Z')
            *result = *str + 32;
        else
            *result = *str;
        result++;
        str++;
    }
    *result = '\0';

    return (void *)result_start;
}