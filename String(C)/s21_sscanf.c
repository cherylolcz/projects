#include "s21_sscanf.h"

int s21_sscanf(const char *str, const char *format, ...) {
    setlocale(LC_ALL, "C.UTF-8");

    va_list args;
    va_start(args, format);

    spec val = {'\0', '\0', false, false, false, 0, 0};
    const char *p_str = str;

    int res = 0;
    while (*format != '\0') {
        if (*format == '%') {
            s21_pars_scan_flags(&format, &val);
            if (val.is_skip) {
                if (isdigit(*p_str++) || val.specifier_val == 's')
                    while (*p_str != ' ') p_str++;
            } else
                res += s21_pars_scan_specs(&p_str, &str, args, &val);
        } else {
            if (*p_str == *format) p_str++;
            format++;
        }
    }

    va_end(args);

    return res;
}

void s21_pars_scan_flags(const char **format, spec *val) {
    (*format)++;

    val->is_negative = val->is_width = val->is_skip = false;
    val->length_val = '\0';

    if (**format == '*') {
        val->is_skip = true;
        (*format)++;
    }

    if (isdigit(**format)) {
        val->is_width = true;
        val->width_val = s21_check_param_num(format);
    }

    if (**format == 'l' || **format == 'h' || **format == 'L') {
        val->length_val = **format;
        (*format)++;
    }

    val->specifier_val = **format;
}

int s21_pars_scan_specs(const char **p_str, const char **str, va_list args,
                        spec *val) {
    int final_len = 0;
    switch (val->specifier_val) {
        case 'd':
        case 'i':
            s21_d_process(p_str, args, val, &final_len);
            break;
        case 'f':
        case 'g':
        case 'G':
        case 'e':
        case 'E':
            s21_f_process(p_str, args, val, &final_len);
            break;
        case 'x':
        case 'X':
        case 'o':
        case 'u':
            s21_u_process(p_str, args, val, &final_len);
            break;
        case 'c':
            if (val->length_val == 'l') {
                wchar_t *c = va_arg(args, wchar_t *);
                s21_wide_c_process(p_str, c);
            } else {
                char *c = va_arg(args, char *);
                s21_c_process(p_str, c);
            }
            final_len++;
            break;
        case 's':
            if (val->length_val == 'l') {
                wchar_t *s = va_arg(args, wchar_t *);
                s21_wide_s_process(p_str, &s, val);
                final_len++;
            } else {
                char *s = va_arg(args, char *);
                s21_s_process(p_str, &s, val);
                final_len++;
            }
            break;
        case 'n':
            int *n = va_arg(args, int *);
            *n = *p_str - *str;
            break;
        case 'p':
            void **p = va_arg(args, void **);
            s21_p_process(p_str, p, val);
            final_len++;
            break;
    }

    return final_len;
}

int s21_d_process(const char **p_str, va_list args, spec *val, int *final_len) {
    char *str = s21_get_form_in_buf(p_str, val);
    long int res = s21_atoi(str);

    if (res != 0) (*final_len)++;

    if (val->length_val == 'h')
        *(short *)va_arg(args, void *) = (short)res;
    else if (val->length_val == 'l')
        *(long *)va_arg(args, void *) = (long)res;
    else
        *(int *)va_arg(args, void *) = (int)res;

    free(str);

    return *final_len;
}

int s21_f_process(const char **p_str, va_list args, spec *val, int *final_len) {
    char *str = s21_get_form_in_buf(p_str, val);
    long double res = s21_atof(str);

    if (res != 0) (*final_len)++;

    if (val->length_val == 'L')
        *(long double *)va_arg(args, void *) = (long double)res;
    else if (val->length_val == 'l')
        *(double *)va_arg(args, void *) = (double)res;
    else
        *(float *)va_arg(args, void *) = (float)res;

    free(str);

    return *final_len;
}

int s21_u_process(const char **p_str, va_list args, spec *val, int *final_len) {
    char *str = s21_get_form_in_buf(p_str, val);
    unsigned long long res = s21_atoi(str);

    if (res != 0) (*final_len)++;

    if (val->length_val == 'l')
        *(unsigned long *)va_arg(args, void *) = (unsigned long)res;
    else if (val->length_val == 'h')
        *(unsigned short *)va_arg(args, void *) = (unsigned short)res;
    else
        *(unsigned int *)va_arg(args, void *) = (unsigned int)res;

    free(str);

    return *final_len;
}

void s21_c_process(const char **p_str, char *value) {
    while (**p_str == ' ') (*p_str)++;
    *value = **p_str;
    (*p_str)++;
}

void s21_wide_c_process(const char **p_str, wchar_t *value) {
    const char *pp_str = *p_str;
    mbstate_t state = {0};

    while (*pp_str == ' ') pp_str++;

    wchar_t wc;
    s21_size_t converter = mbrtowc(&wc, pp_str, MB_CUR_MAX, &state);

    if (converter == (s21_size_t)-1 || converter == (s21_size_t)-2 ||
        converter == 0)
        return;

    *value = wc;
    *p_str = pp_str;
}

void s21_s_process(const char **p_str, char **value, spec *val) {
    char *p_value = *value;

    while (**p_str == ' ') (*p_str)++;

    while (!isspace(**p_str) && **p_str != '\0') {
        if (s21_change_width_val(val)) break;
        *p_value++ = *(*p_str)++;
    }
    *p_value = '\0';
}

void s21_wide_s_process(const char **p_str, wchar_t **value, spec *val) {
    wchar_t *p_value = *value;
    const char *pp_str = *p_str;
    mbstate_t state = {0};

    while (*pp_str == ' ') pp_str++;

    while (!isspace(**p_str) && *pp_str != '\0') {
        if (s21_change_width_val(val)) break;

        wchar_t wc;
        s21_size_t converter = mbrtowc(&wc, pp_str, MB_CUR_MAX, &state);

        if (converter == (s21_size_t)-1 || converter == (s21_size_t)-2 ||
            converter == 0)
            break;

        *p_value++ = wc;
        pp_str += converter;
    }

    *p_value = L'\0';

    *p_str = pp_str;
}

void s21_p_process(const char **p_str, void **value, spec *val) {
    char *str = s21_get_form_in_buf(p_str, val);
    uintptr_t ptr_case = 0;
    if (str[0] == '0' && (str[1] == 'x' || str[1] == 'X')) str += 2;

    while (*str != '\0') {
        char c = *str;
        ptr_case *= 16;
        if (isdigit(c))
            ptr_case += c - '0';
        else if (c >= 'a' && c <= 'f')
            ptr_case += c - 'a' + 10;
        else if (c >= 'A' && c <= 'F')
            ptr_case += c - 'A' + 10;
        else
            break;

        str++;
    }

    *value = (void *)ptr_case;
}