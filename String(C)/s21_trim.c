#include "s21_string.h"

#define DEFAULT_TRIM_CHARS " \t\n\r\v\f"

void *s21_trim(const char *src, const char *trim_chars) {
    if (!src) return s21_NULL;

    const char *actual_trim_chars =
        trim_chars && *trim_chars ? trim_chars : DEFAULT_TRIM_CHARS;

    const char *start = src;
    const char *end = src + s21_strlen(src) - 1;

    while (*start && s21_is_trim_char(*start, actual_trim_chars)) start++;
    while (end >= start && s21_is_trim_char(*end, actual_trim_chars)) end--;

    s21_size_t new_len = end >= start ? (end - start + 1) : 0;

    char *result = (char *)malloc(new_len + 1);
    if (!result) return s21_NULL;

    for (s21_size_t i = 0; i < new_len; i++) {
        result[i] = start[i];
    }
    result[new_len] = '\0';

    return result;
}

int s21_is_trim_char(char ch, const char *trim_chars) {
    while (*trim_chars) {
        if (ch == *trim_chars) return 1;
        trim_chars++;
    }
    return 0;
}