#ifndef TESTS_HUB_H
#define TESTS_HUB_H

#include <check.h>
#include <string.h>

#include "../s21_sprintf.h"
#include "../s21_sscanf.h"
#include "../s21_string.h"

#define BUFF_SIZE 2042

Suite *suite_string(void);
int sign_int(int x);

#endif  //  TESTS_HUB_H