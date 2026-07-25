#include "s21_sprintf.h"

#include "s21_string.h"

int s21_sprintf(char *str, const char *format, ...) {
    setlocale(LC_ALL, "C.UTF-8");

    va_list args;
    va_start(args, format);

    s21_sprintf_process(str, format, args);

    return s21_strlen(str);
}

void s21_sprintf_process(char *str, const char *format, va_list args) {
    flags state = {0};
    state.value.accuracy_val = 6;

    char *ptr = str;
    while (*format != '\0') {
        if (*format == '%') {
            s21_pars_print_flags(&format, &state, args);
            s21_pars_print_spec(args, str, &ptr, &state);
        } else {
            *ptr++ = *format;
        }
        format++;
    }

    *ptr = '\0';
    va_end(args);
}

void s21_pars_print_flags(const char **format, flags *state, va_list args) {
    state->is_minus = state->is_plus = state->is_probel = state->is_accuracy =
        state->is_negative = state->is_width = state->is_nul = state->is_g =
            state->is_reshetka = state->is_notnormal = state->is_accuracy_now =
                false;
    state->value.accuracy_val = 6;

    (*format)++;
    while (**format == '+' || **format == '-' || **format == ' ' ||
           **format == '0' || **format == '#') {
        switch (**format) {
            case '+':
                state->is_plus = true;
                break;
            case '-':
                state->is_minus = true;
                break;
            case ' ':
                state->is_probel = true;
                break;
            case '0':
                state->is_nul = true;
                break;
            case '#':
                state->is_reshetka = true;
                break;
        }
        (*format)++;
    }

    if (**format == '*') {
        state->is_width = true;
        state->value.width_val = va_arg(args, int);
        if (state->value.width_val < 0) {
            state->is_minus = true;
            state->value.width_val *= -1;
        }
        (*format)++;
    } else if (**format >= '0' && **format <= '9') {
        state->is_width = true;
        state->value.width_val = s21_check_param_num(format);
    }

    if (**format == '.') {
        state->is_accuracy = true;
        (*format)++;
        if (**format == '*') {
            state->value.accuracy_val = va_arg(args, int);
            (*format)++;
        } else {
            state->value.accuracy_val = s21_check_param_num(format);
        }
    }

    if (**format == 'h' || **format == 'l' || **format == 'L') {
        state->value.length_val = **format;
        (*format)++;
    }

    state->value.specifier_val = *(*format);

    if (state->value.specifier_val == 'o' ||
        state->value.specifier_val == 'x' || state->value.specifier_val == 'X')
        state->is_notnormal = true;
}

void s21_pars_print_spec(va_list args, char *str, char **ptr, flags *state) {
    switch (state->value.specifier_val) {
        case 'd':
            long long d = state->value.length_val == 'h'
                              ? (short)va_arg(args, int)
                          : state->value.length_val == 'l' ? va_arg(args, long)
                                                           : va_arg(args, int);
            s21_oxud_process(d, ptr, state);
            break;
        case 'u':
        case 'x':
        case 'X':
        case 'o':
            unsigned long long u =
                state->value.length_val == 'h'
                    ? (unsigned short)va_arg(args, unsigned int)
                : state->value.length_val == 'l' ? va_arg(args, unsigned long)
                                                 : va_arg(args, unsigned int);
            s21_oxud_process(u, ptr, state);
            break;
        case 'f':
        case 'e':
        case 'E':
        case 'g':
        case 'G':
            double f = state->value.length_val == 'L'
                           ? va_arg(args, long double)
                           : va_arg(args, double);
            s21_float_process(f, ptr, state, str);
            break;
        case 'p':
            void *p = va_arg(args, void *);
            s21_ptr_process(p, ptr, state);
            break;
        case 'c':
            char c = va_arg(args, int);
            s21_char_process(c, ptr, state);
            break;
        case 's':
            char *s = va_arg(args, char *);
            s21_string_process(s, ptr, state);
            break;
        default:
            *(*ptr)++ = '%';
    }
}

void s21_oxud_process(long int value, char **ptr, flags *state) {
    s21_size_t len = 0;
    if (state->value.specifier_val == 'd' || state->value.specifier_val == 'p')
        s21_check_sign(&value, ptr, state, &len);
    len += s21_nums_into_str(value, ptr, state);
    if (state->is_accuracy) s21_accuracy_process_INT(ptr, state, &len);
    if (state->is_reshetka) s21_reshetka_process(ptr, state, &len);
    if (state->is_width) s21_width_process(len, ptr, state);
}

void s21_float_process(long double value, char **ptr, flags *state, char *str) {
    s21_size_t len = 0;
    int exponenta = 0;
    long int left_part;
    long double abs_value = fabsl(value);
    char *spec = &state->value.specifier_val;

    if (*spec == 'g' || *spec == 'G') {
        state->is_g = true;
        if (abs_value >= 1e4 || (abs_value > 0 && abs_value < 1e-4))
            *spec = (*spec == 'g') ? 'e' : 'E';
        else
            *spec = 'f';
    }

    if (*spec == 'e' || *spec == 'E') s21_get_exp(&abs_value, &exponenta);

    value = (value >= 0) ? abs_value : -abs_value;

    s21_size_t mean_nums =
        (!state->is_g) ? state->value.accuracy_val
                       : state->value.accuracy_val - s21_num_length((int)value);

    long double round = 0.5 / pow(10, mean_nums);
    value += (value >= 0) ? round : -round;

    left_part = (int)value;
    s21_check_sign(&left_part, ptr, state, &len);
    len += s21_nums_into_str(left_part, ptr, state);

    if (state->value.accuracy_val > 0 || state->is_reshetka) {
        *(*ptr)++ = '.';
        len++;
    }

    if (state->value.accuracy_val > 0) {
        long double fraction = (fabsl(value) - left_part);
        for (s21_size_t i = 0; i < mean_nums; i++) {
            fraction *= 10;
            int digit = (int)fraction;
            *(*ptr)++ = digit + '0';
            len++;
            fraction -= digit;
        }
    }

    if (*spec == 'e' || *spec == 'E')
        s21_e_process(&exponenta, &len, ptr, state);
    if (state->is_g) s21_g_process(value, &len, ptr, state, str);
    if (state->is_width) s21_width_process(len, ptr, state);
}

void s21_e_process(int *exponenta, s21_size_t *len, char **ptr, flags *state) {
    char sign = *exponenta >= 0 ? '+' : '-';

    *(*ptr)++ = state->value.specifier_val;
    *(*ptr)++ = sign;

    if (s21_num_length(abs(*exponenta)) == 1) *(*ptr)++ = '0';

    (*len) += 3 + s21_nums_into_str(abs(*exponenta), ptr, state);
}

void s21_g_process(long double value, s21_size_t *len, char **ptr, flags *state,
                   char *str) {
    char *end = (state->value.specifier_val == 'f') ? *ptr - 1 : *ptr - 5;
    if (!state->is_reshetka) {
        while (*end == '0') {
            s21_memcpy(end, end + 1, sizeof(end));
            end--;
            (*len)--;
        }
        if (*end == '.') {
            s21_memcpy(end, end + 1, sizeof(end));
            (*len)--;
        }
    }
    *ptr = str + s21_strlen(str);
    if (state->value.specifier_val == 'f' && value < 1.0) {
        *(*ptr)++ = '0';
        (*len)++;
    }
}

void s21_char_process(char value, char **ptr, flags *state) {
    *(*ptr)++ = value;
    if (state->is_width) s21_width_process(1, ptr, state);
}

void s21_string_process(char *value, char **ptr, flags *state) {
    s21_size_t len =
        state->is_accuracy ? state->value.accuracy_val : s21_strlen(value);

    for (int i = len; i > 0; i--) {
        *(*ptr)++ = *value;
        value++;
    }

    if (state->is_width) s21_width_process(len, ptr, state);
}

void s21_ptr_process(void *ptr_val, char **ptr, flags *state) {
    uintptr_t subval = (uintptr_t)ptr_val;
    s21_oxud_process((uintptr_t)subval, ptr, state);
}