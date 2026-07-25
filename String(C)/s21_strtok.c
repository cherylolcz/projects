#include "s21_string.h"

char *s21_strtok(char *str, const char *delim) {
    if (delim == s21_NULL) return s21_NULL;

    char *result = s21_NULL;
    static char *next = s21_NULL;

    if (str) next = str;

    if (next) {
        while (*next && !s21_strcspn(next, delim)) next++;

        if (*next != '\0') {
            result = next;

            while (*next && s21_strcspn(next, delim)) next++;

            if (*next) {
                *next++ = '\0';
            } else
                next = s21_NULL;
        }
    }

    return result;
}