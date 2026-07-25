#include "s21_sprintf.h"
#include "s21_string.h"

void s21_change_pos(s21_size_t *len, int char_count, char **ptr, char ch,
                    flags *state) {
    bool sign_for_d =
        state->value.specifier_val == 'd' && state->is_nul &&
        (state->is_negative || state->is_plus || state->is_probel);
    if (sign_for_d) (*len)--;
    if (state->value.specifier_val == 'p' && state->is_accuracy_now) {
        (*len) -= 2;
        char_count += 2;
    }

    char *start = *ptr - *len;
    char tmp[64];

    s21_memcpy(tmp, start, *len);

    for (int i = 0; i < char_count; i++) {
        *start++ = ch;
        (*len)++;
    }

    s21_memcpy(start, tmp, *len);
    *ptr += char_count;

    if (sign_for_d) (*len)++;
    if (state->value.specifier_val == 'p' && state->is_accuracy_now)
        (*len) += 2;
}

void s21_reshetka_process(char **ptr, flags *state, s21_size_t *len) {
    char *spec = &state->value.specifier_val;
    if (state->is_notnormal) {
        if (*spec != 'o') s21_change_pos(len, 1, ptr, *spec, state);
        s21_change_pos(len, 1, ptr, '0', state);
    }
}

s21_size_t s21_nums_into_str(unsigned long value, char **ptr, flags *state) {
    char *ptr_spec = &state->value.specifier_val;
    char tmp[64];
    int i, div;
    i = div = 0;

    switch (*ptr_spec) {
        case 'x':
        case 'X':
        case 'p':
            div = 16;
            break;
        case 'o':
            div = 8;
            break;
        default:
            div = 10;
    }

    if (value == 0) tmp[i++] = '0';

    while (value > 0) {
        char ch;
        int ostatok = value % div;
        if (ostatok < 10)
            ch = ostatok + '0';
        else {
            char letter;
            if (*ptr_spec > 96 && *ptr_spec < 122)
                letter = 'a';
            else
                letter = 'A';
            ch = ostatok + (letter - 10);
        }

        tmp[i++] = ch;
        value /= div;
    }

    s21_size_t len = i;

    if (state->value.specifier_val == 'p') {
        *(*ptr)++ = '0';
        *(*ptr)++ = 'x';
        len += 2;
    }

    while (i > 0) {
        *(*ptr)++ = tmp[--i];
    }

    return len;
}

void s21_check_sign(long int *value, char **ptr, flags *state,
                    s21_size_t *len) {
    char sign = '\0';

    if (*value < 0) {
        state->is_negative = true;
        *value *= -1;
        sign = '-';
    } else if (state->is_plus) {
        sign = '+';
    } else if (state->is_probel) {
        sign = ' ';
    }

    if (state->is_negative || state->is_plus || state->is_probel) {
        (*len)++;
        *(*ptr)++ = sign;
    }
}

int s21_check_param_num(const char **format) {
    int num = 0;
    while (**format >= '0' && **format <= '9') {
        num = (num * 10) + **format - '0';
        (*format)++;
    }

    return num;
}

s21_size_t s21_num_length(unsigned int value) {
    s21_size_t len = 0;

    do {
        value /= 10;
        len++;
    } while (value > 0);

    return len;
}

void s21_accuracy_process_INT(char **ptr, flags *state, s21_size_t *len) {
    state->is_accuracy_now = true;
    int accuracy_count = state->value.accuracy_val - *len;

    if (accuracy_count > 0)
        s21_change_pos(len, accuracy_count, ptr, '0', state);

    state->is_accuracy_now = false;
}

void s21_width_process(s21_size_t len, char **ptr, flags *state) {
    int char_count = state->value.width_val - len;
    if (char_count > 0) {
        if (state->is_minus) {
            for (int i = 0; i < char_count; i++) *(*ptr)++ = ' ';
        } else {
            s21_change_pos(&len, char_count, ptr, state->is_nul ? '0' : ' ',
                           state);
        }
    }
}

void s21_get_exp(long double *abs_value, int *exponenta) {
    while (*abs_value > 10.0) {
        *abs_value /= 10.0;
        (*exponenta)++;
    }

    while (*abs_value < 1.0) {
        *abs_value *= 10.0;
        (*exponenta)--;
    }
}