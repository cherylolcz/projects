#ifndef S21_SSCANF_H
#define S21_SSCANF_H

#include "s21_sprintf.h"
#include "s21_string.h"

typedef struct {
    char specifier_val, length_val;
    bool is_negative, is_width, is_skip;
    s21_size_t width_val, buf_len;
} spec;

int s21_sscanf(const char *str, const char *format, ...);
void s21_pars_scan_flags(const char **format, spec *val);
int s21_pars_scan_specs(const char **p_str, const char **str, va_list args,
                        spec *val);

int s21_d_process(const char **p_str, va_list args, spec *val, int *final_len);
int s21_f_process(const char **p_str, va_list args, spec *val, int *final_len);
int s21_u_process(const char **p_str, va_list args, spec *val, int *final_len);
void s21_c_process(const char **p_str, char *value);
void s21_wide_c_process(const char **p_str, wchar_t *value);
void s21_s_process(const char **p_str, char **value, spec *val);
void s21_wide_s_process(const char **p_str, wchar_t **value, spec *val);
void s21_p_process(const char **p_str, void **value, spec *val);

char *s21_get_form_in_buf(const char **p_str, spec *val);
long long s21_unsigned_converter(char **buffer, spec *val, int *count);
unsigned long s21_atoi(const char *str);
long double s21_atof(const char *str);
int s21_change_width_val(spec *val);

bool s21_is_valid_char(const char *ch, char *spec);
bool s21_is_valid_x_char(const char *ch, char *spec);
bool s21_is_valid_hex_char(const char ch, char *spec);
bool s21_is_valid_double_char(const char ch, char *spec);

#endif  //  S21_SSCANF_H