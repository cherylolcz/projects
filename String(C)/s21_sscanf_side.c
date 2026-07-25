#include "s21_sscanf.h"

char *s21_get_form_in_buf(const char **p_str, spec *val) {
    char *buffer = (char *)malloc(100 * sizeof(char));

    char *p_buffer = buffer;
    char *spec = &val->specifier_val;
    int count = 0;

    while (**p_str == ' ') (*p_str)++;
    while (s21_is_valid_char(*p_str, spec)) {
        if (s21_change_width_val(val)) break;
        *p_buffer++ = *(*p_str)++;
        count++;
    }
    *p_buffer = '\0';

    int o = 0, x = 1;
    if (*buffer == '-' || *buffer == '+') {
        val->is_negative = true;
        o++;
        x++;
        count--;
    }
    if (*(buffer + o) == '0' && *spec != 'p') {
        *spec = 'o';
        if (*(buffer + x) == 'x' || *(buffer + x) == 'X') *spec = *(buffer + x);
    }
    if (*spec == 'x' || *spec == 'X' || *spec == 'o') {
        long new_val = s21_unsigned_converter(&buffer, val, &count);
        s21_sprintf(buffer, "%u", new_val);
    }

    return buffer;
}

long long s21_unsigned_converter(char **buffer, spec *val, int *count) {
    char *p = *buffer;
    int num, div;
    long long res = 0;
    num = 0;

    if (*p == '-' || *p == '+') p++;

    switch (val->specifier_val) {
        case 'x':
        case 'X':
            div = 16;
            if (*count > 2 && p[0] == '0' && (p[1] == 'x' || p[1] == 'X')) {
                p += 2;
                *count -= 2;
            }
            break;
        case 'o':
            div = 8;
            if (*count > 1 && p[0] == '0') {
                p++;
                (*count)--;
            }
            break;
    }

    for (int i = 0; i < *count; i++) {
        if (*p >= 'A' && *p <= 'Z')
            num = (*p - 'A' + 10) * pow(div, *count - i - 1);
        else if (*p >= 'a' && *p <= 'z')
            num = (*p - 'a' + 10) * pow(div, *count - i - 1);
        else if (isdigit(*p))
            num = (*p - '0') * pow(div, *count - i - 1);
        res += num;
        p++;
    }

    if (val->is_negative) res *= -1;
    return res;
}

unsigned long s21_atoi(const char *str) {
    unsigned long res = 0;
    bool is_negative = false;

    while (*str == ' ') str++;

    if (*str == '-') {
        is_negative = true;
        str++;
    } else if (*str == '+')
        str++;

    while (*str != '\0' && isdigit(*str)) {
        res = (res * 10) + (*str - '0');
        str++;
    }
    if (is_negative) res *= -1;

    return res;
}

long double s21_atof(const char *str) {
    long double res, frac_div;
    res = 0.0;
    frac_div = 10.0;
    int exp_sign, exp_val;
    exp_sign = 1;
    exp_val = 0;

    bool is_negative = false;

    while (*str == ' ') str++;

    if (*str == '-') {
        is_negative = true;
        str++;
    } else if (*str == '+')
        str++;

    bool has_start = false;
    while (isdigit(*str)) {
        has_start = true;
        res = (res * 10) + (*str - '0');
        str++;
    }

    if (*str == '.' && has_start) {
        str++;
        while (*str != '\0' && isdigit(*str)) {
            res += (*str - '0') / frac_div;
            frac_div *= 10.0;
            str++;
        }
    }

    if (*str == 'e' || *str == 'E') {
        str++;
        if (*str == '-') {
            exp_sign *= -1;
            str++;
        } else if (*str == '+')
            str++;

        while (*str != '\0' && isdigit(*str)) {
            exp_val = (exp_val * 10) + (*str - '0');
            str++;
        }

        if (exp_sign == 1)
            while (exp_val--) res *= 10.0;
        else
            while (exp_val--) res /= 10.0;
    }

    if (is_negative) res *= -1;

    return res;
}

int s21_change_width_val(spec *val) {
    int flag = 0;
    if (val->is_width) {
        if (!val->width_val)
            flag++;
        else
            val->width_val--;
    }
    return flag;
}

bool s21_is_valid_char(const char *ch, char *spec) {
    return isdigit(*ch) || s21_is_valid_hex_char(*ch, spec) ||
           s21_is_valid_x_char(ch, spec) ||
           s21_is_valid_double_char(*ch, spec) || *ch == '-' || *ch == '+';
}

bool s21_is_valid_x_char(const char *ch, char *spec) {
    return (*ch == 'x' || *ch == 'X') && *(ch - 1) == '0' &&
           (*spec == 'x' || *spec == 'X' || *spec == 'i' || *spec == 'p');
}

bool s21_is_valid_double_char(const char ch, char *spec) {
    return (*spec == 'f' || *spec == 'e' || *spec == 'E' || *spec == 'g' ||
            *spec == 'G') &&
           (ch == 'e' || ch == 'E' || ch == '.');
}

bool s21_is_valid_hex_char(const char ch, char *spec) {
    return (*spec == 'x' || *spec == 'X' || *spec == 'i' || *spec == 'p') &&
           (isdigit(ch) || (ch >= 'a' && ch <= 'f') ||
            (ch >= 'A' && ch <= 'F'));
}