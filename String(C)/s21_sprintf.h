#ifndef SPRINTF_H
#define SPRINTF_H

#include "s21_string.h"

typedef struct {
    char specifier_val, length_val, char_width_val;
    size_t accuracy_val;
    int width_val;
} value;

typedef struct {
    bool is_minus, is_plus, is_probel, is_accuracy, is_negative, is_width,
        is_nul, is_g, is_reshetka, is_notnormal, is_accuracy_now;
    value value;
} flags;

// ОСНОВНЫЕ ФУНКЦИИ

int s21_sprintf(char *str, const char *format, ...);
void s21_sprintf_process(char *str, const char *format, va_list args);
void s21_pars_print_flags(const char **format, flags *state, va_list args);
void s21_pars_print_spec(va_list args, char *str, char **ptr, flags *state);

void s21_oxud_process(long int value, char **ptr, flags *status);
void s21_float_process(long double value, char **ptr, flags *state, char *str);
void s21_e_process(int *exponenta, s21_size_t *len, char **ptr, flags *state);
void s21_g_process(long double value, s21_size_t *len, char **ptr, flags *state,
                   char *str);
void s21_char_process(char value, char **ptr, flags *state);
void s21_string_process(char *value, char **ptr, flags *state);
void s21_ptr_process(void *ptr_val, char **ptr, flags *state);

// ВСОПОМОГАТЕЛЬНЫЕ ФУНКЦИИ

void s21_change_pos(s21_size_t *len, int char_count, char **ptr, char ch,
                    flags *state);
void s21_reshetka_process(char **ptr, flags *state, s21_size_t *len);
s21_size_t s21_nums_into_str(unsigned long value, char **ptr, flags *state);
void s21_check_sign(long int *value, char **ptr, flags *state, s21_size_t *len);
int s21_check_param_num(const char **format);
s21_size_t s21_num_length(unsigned int value);
void s21_accuracy_process_INT(char **ptr, flags *state, size_t *len);
void s21_width_process(s21_size_t len, char **ptr, flags *state);
void s21_get_exp(long double *abs_value, int *exponenta);

#endif  //  SPRINTF_H