#include "test_hub.h"

START_TEST(test_s21_sscanf_1) {  // s
    const char *str = "Hello,\tJohn\n";
    const char *pattern = "Hello,\t%s\n";

    char result[10] = {0};
    char expected[10] = {0};
    int result_len = 0;
    int expected_len = 0;

    result_len = s21_sscanf(str, pattern, result);
    expected_len = sscanf(str, pattern, expected);

    ck_assert_str_eq(result, expected);
    ck_assert_int_eq(result_len, expected_len);
}
END_TEST

START_TEST(test_s21_sscanf_2) {  // d
    const char *str = "Hello, John,\nmy age\t   is 25";
    const char *pattern = "Hello, John,\nmy age\t   is %d";

    int result;
    int expected;
    int result_len = 0;
    int expected_len = 0;

    result_len = s21_sscanf(str, pattern, &result);
    expected_len = sscanf(str, pattern, &expected);

    ck_assert_int_eq(result, expected);
    ck_assert_int_eq(result_len, expected_len);
}
END_TEST

START_TEST(test_s21_sscanf_3) {  // d
    const char *str = "Hello, John,\nmy age\t   is -25";
    const char *pattern = "Hello, John,\nmy age\t   is %d";

    int result;
    int expected;
    int result_len = 0;
    int expected_len = 0;

    result_len = s21_sscanf(str, pattern, &result);
    expected_len = sscanf(str, pattern, &expected);

    ck_assert_int_eq(result, expected);
    ck_assert_int_eq(result_len, expected_len);
}
END_TEST

START_TEST(test_s21_sscanf_4) {  // f
    const char *str = "Hello, John,\nmy weight\t   is 66.6";
    const char *pattern = "Hello, John,\nmy weight\t   is %d";

    float result;
    float expected;
    int result_len = 0;
    int expected_len = 0;

    result_len = s21_sscanf(str, pattern, &result);
    expected_len = sscanf(str, pattern, &expected);

    ck_assert_float_eq(result, expected);
    ck_assert_int_eq(result_len, expected_len);
}
END_TEST

START_TEST(test_s21_sscanf_5) {  // i
    const char *str = "Hello, John,\nmy age\t   is 0xF";
    const char *pattern = "Hello, John,\nmy age\t   is %i";

    int result;
    int expected;
    int result_len = 0;
    int expected_len = 0;

    result_len = s21_sscanf(str, pattern, &result);
    expected_len = sscanf(str, pattern, &expected);

    ck_assert_int_eq(result, expected);
    ck_assert_int_eq(result_len, expected_len);
}
END_TEST

START_TEST(test_s21_sscanf_6) {  // i
    const char *str = "Hello, John,\nmy age\t   is -0xFED";
    const char *pattern = "Hello, John,\nmy age\t   is %i";

    int result;
    int expected;
    int result_len = 0;
    int expected_len = 0;

    result_len = s21_sscanf(str, pattern, &result);
    expected_len = sscanf(str, pattern, &expected);

    ck_assert_int_eq(result, expected);
    ck_assert_int_eq(result_len, expected_len);
}
END_TEST

START_TEST(test_s21_sscanf_7) {  // i
    const char *str = "Hello, John,\nmy age\t   is +15";
    const char *pattern = "Hello, John,\nmy age\t   is %i";

    int result;
    int expected;
    int result_len = 0;
    int expected_len = 0;

    result_len = s21_sscanf(str, pattern, &result);
    expected_len = sscanf(str, pattern, &expected);

    ck_assert_int_eq(result, expected);
    ck_assert_int_eq(result_len, expected_len);
}
END_TEST

START_TEST(test_s21_sscanf_8) {  // e
    const char *str = "Hello, John,\nmy age\t   is 61.1e-5";
    const char *pattern = "Hello, John,\nmy age\t   is %e";

    float result;
    float expected;
    int result_len = 0;
    int expected_len = 0;

    result_len = s21_sscanf(str, pattern, &result);
    expected_len = sscanf(str, pattern, &expected);

    ck_assert_float_eq(result, expected);
    ck_assert_int_eq(result_len, expected_len);
}
END_TEST

START_TEST(test_s21_sscanf_9) {  // E
    const char *str = "Hello, John,\nmy age\t   is 61.1e+5";
    const char *pattern = "Hello, John,\nmy age\t   is %E";

    float result;
    float expected;
    int result_len = 0;
    int expected_len = 0;

    result_len = s21_sscanf(str, pattern, &result);
    expected_len = sscanf(str, pattern, &expected);

    ck_assert_float_eq(result, expected);
    ck_assert_int_eq(result_len, expected_len);
}
END_TEST

START_TEST(test_s21_sscanf_10) {  // f
    const char *str = "Hello, John,\nmy age\t   is 61.1e-5";
    const char *pattern = "Hello, John,\nmy age\t   is %f";

    float result;
    float expected;
    int result_len = 0;
    int expected_len = 0;

    result_len = s21_sscanf(str, pattern, &result);
    expected_len = sscanf(str, pattern, &expected);

    ck_assert_float_eq(result, expected);
    ck_assert_int_eq(result_len, expected_len);
}
END_TEST

START_TEST(test_s21_sscanf_11) {  // g
    const char *str = "Hello, John,\nmy age\t   is 61.1e-5";
    const char *pattern = "Hello, John,\nmy age\t   is %g";

    float result;
    float expected;
    int result_len = 0;
    int expected_len = 0;

    result_len = s21_sscanf(str, pattern, &result);
    expected_len = sscanf(str, pattern, &expected);

    ck_assert_float_eq(result, expected);
    ck_assert_int_eq(result_len, expected_len);
}
END_TEST

START_TEST(test_s21_sscanf_12) {  // o
    const char *str = "Hello, John,\nmy age\t   is 6";
    const char *pattern = "Hello, John,\nmy age\t   is %o";

    int result;
    int expected;
    int result_len = 0;
    int expected_len = 0;

    result_len = s21_sscanf(str, pattern, &result);
    expected_len = sscanf(str, pattern, &expected);
    ck_assert_int_eq(result, expected);
    ck_assert_int_eq(result_len, expected_len);
}
END_TEST

START_TEST(test_s21_sscanf_13) {  // o
    const char *str = "Hello, John,\nmy age\t   is -6";
    const char *pattern = "Hello, John,\nmy age\t   is %o";

    int result;
    int expected;
    int result_len = 0;
    int expected_len = 0;

    result_len = s21_sscanf(str, pattern, &result);
    expected_len = sscanf(str, pattern, &expected);

    ck_assert_int_eq(result, expected);
    ck_assert_int_eq(result_len, expected_len);
}
END_TEST

START_TEST(test_s21_sscanf_14) {  // u
    const char *str = "Hello, John,\nmy age\t   is -7";
    const char *pattern = "Hello, John,\nmy age\t   is %u";

    unsigned int result;
    unsigned int expected;
    int result_len = 0;
    int expected_len = 0;

    result_len = s21_sscanf(str, pattern, &result);
    expected_len = sscanf(str, pattern, &expected);

    ck_assert_uint_eq(result, expected);
    ck_assert_int_eq(result_len, expected_len);
}
END_TEST

START_TEST(test_s21_sscanf_15) {  // u
    const char *str = "Hello, John,\nmy age\t   is 77";
    const char *pattern = "Hello, John,\nmy age\t   is %u";

    unsigned int result;
    unsigned int expected;
    int result_len = 0;
    int expected_len = 0;

    result_len = s21_sscanf(str, pattern, &result);
    expected_len = sscanf(str, pattern, &expected);

    ck_assert_uint_eq(result, expected);
    ck_assert_int_eq(result_len, expected_len);
}
END_TEST

START_TEST(test_s21_sscanf_16) {  // x
    const char *str = "Hello, John,\nmy age\t   is 0xfbc";
    const char *pattern = "Hello, John,\nmy age\t   is %x";

    unsigned int result;
    unsigned int expected;
    int result_len = 0;
    int expected_len = 0;

    result_len = s21_sscanf(str, pattern, &result);
    expected_len = sscanf(str, pattern, &expected);

    ck_assert_uint_eq(result, expected);
    ck_assert_int_eq(result_len, expected_len);
}
END_TEST

START_TEST(test_s21_sscanf_17) {  // x
    const char *str = "Hello, John,\nmy age\t   is -0xFF";
    const char *pattern = "Hello, John,\nmy age\t   is %x";

    unsigned int result;
    unsigned int expected;
    int result_len = 0;
    int expected_len = 0;

    result_len = s21_sscanf(str, pattern, &result);
    expected_len = sscanf(str, pattern, &expected);

    ck_assert_uint_eq(result, expected);
    ck_assert_int_eq(result_len, expected_len);
}
END_TEST

START_TEST(test_s21_sscanf_18) {  // X
    const char *str = "Hello, John,\nmy age\t   is 0xAA";
    const char *pattern = "Hello, John,\nmy age\t   is %X";

    unsigned int result;
    unsigned int expected;
    int result_len = 0;
    int expected_len = 0;

    result_len = s21_sscanf(str, pattern, &result);
    expected_len = sscanf(str, pattern, &expected);

    ck_assert_uint_eq(result, expected);
    ck_assert_int_eq(result_len, expected_len);
}
END_TEST

START_TEST(test_s21_sscanf_19) {  // X
    const char *str = "Hello, John,\nmy age\t   is -0xAA";
    const char *pattern = "Hello, John,\nmy age\t   is %X";

    unsigned int result;
    unsigned int expected;
    int result_len = 0;
    int expected_len = 0;

    result_len = s21_sscanf(str, pattern, &result);
    expected_len = sscanf(str, pattern, &expected);

    ck_assert_uint_eq(result, expected);
    ck_assert_int_eq(result_len, expected_len);
}
END_TEST

START_TEST(test_s21_sscanf_20) {  // p
    const char *str = "Hello, John,\nmy age\t   is 25, my name   is Alex";
    const char *pattern = "Hello, John,\nmy age\t   is";

    void *result = s21_NULL;
    void *expected = s21_NULL;
    int result_len = 0;
    int expected_len = 0;

    result_len = s21_sscanf(str, pattern, result);
    expected_len = sscanf(str, pattern, expected);

    ck_assert_ptr_eq(result, expected);
    ck_assert_int_eq(result_len, expected_len);
}
END_TEST

START_TEST(test_s21_sscanf_21) {  // p
    const char *str = "Hello, John,\nmy age\t   is 25, my name   is Alex";
    const char *pattern = "Hello, John,\nmy age\t   is %p, my name   is Alex";

    void *result = s21_NULL;
    void *expected = s21_NULL;
    int result_len = 0;
    int expected_len = 0;

    result_len = s21_sscanf(str, pattern, &result);
    expected_len = sscanf(str, pattern, &expected);

    ck_assert_ptr_nonnull(result);
    ck_assert_ptr_nonnull(expected);
    ck_assert_ptr_eq(result, expected);
    ck_assert_int_eq(result_len, expected_len);
}
END_TEST

START_TEST(test_s21_sscanf_22) {  // p
    const char *str = "Hello, John,\nmy age\t   is 25, my name   is Alex";
    const char *pattern = "Hello, John,\nmy age\t   is %p, my name   is Alex";

    void *result = s21_NULL;
    void *expected = s21_NULL;
    int result_len = 0;
    int expected_len = 0;

    result_len = s21_sscanf(str, pattern, &result);
    expected_len = sscanf(str, pattern, &expected);

    ck_assert_ptr_eq(result, expected);
    ck_assert_int_eq(result_len, expected_len);
}
END_TEST

START_TEST(test_s21_sscanf_23) {  // n
    const char *str = "Hello, John,\nmy age\t   is 25, my name   is Alex";
    const char *pattern = "Hello, John,\nmy age\t   is %n, my name   is Alex";

    int result;
    int expected;
    int result_len = 0;
    int expected_len = 0;

    result_len = s21_sscanf(str, pattern, &result);
    expected_len = sscanf(str, pattern, &expected);

    ck_assert_int_eq(result, expected);
    ck_assert_int_eq(result_len, expected_len);
}
END_TEST

START_TEST(test_s21_sscanf_24) {  // n
    const char *str = "Hello, John,\nmy age\t   is 25, my name   is Alex";
    const char *pattern = "%n";

    int result;
    int expected;
    int result_len = 0;
    int expected_len = 0;

    result_len = s21_sscanf(str, pattern, &result);
    expected_len = sscanf(str, pattern, &expected);

    ck_assert_int_eq(result, expected);
    ck_assert_int_eq(result_len, expected_len);
}
END_TEST

START_TEST(test_s21_sscanf_25) {  // n
    const char *str = "Hello, John,\nmy age\t   is 25, my name   is Alex";
    const char *pattern = "asd%nasd";

    int result = 0;
    int expected = 0;
    int result_len = 0;
    int expected_len = 0;

    result_len = s21_sscanf(str, pattern, &result);
    expected_len = sscanf(str, pattern, &expected);

    ck_assert_int_eq(result, expected);
    ck_assert_int_eq(result_len, expected_len);
}
END_TEST

START_TEST(test_s21_sscanf_26) {  // %
    const char *str = "Hello, my\t dear\n friend, 100%, yes its true!!!";
    const char *pattern = "Hello, my\t dear\n friend, %d%%, yes its true!!!";
    int d_result = 0;
    int d_expected = 0;
    int result_len;
    int expected_len = 0;

    result_len = s21_sscanf(str, pattern, &d_result);
    expected_len = sscanf(str, pattern, &d_expected);

    ck_assert_int_eq(d_result, d_expected);
    ck_assert_int_eq(result_len, expected_len);
}
END_TEST

START_TEST(test_s21_sscanf_27) {  // (num)
    const char *str = "Hello, my\t dear\n friend, 100, yes its true!!!";
    const char *pattern = "Hello, my\t dear\n friend, %10d, yes its true!!!";

    int result;
    int expected;
    int result_len = 0;
    int expected_len = 0;

    result_len = s21_sscanf(str, pattern, &result);
    expected_len = sscanf(str, pattern, &expected);

    ck_assert_int_eq(result, expected);
    ck_assert_int_eq(result_len, expected_len);
}
END_TEST

START_TEST(test_s21_sscanf_28) {  // (num)
    const char *str = "Hello, my\t dear\n friend, 100, yes its true!!!";
    const char *pattern = "Hello, my\t dear\n friend, %2d, yes its true!!!";

    int result;
    int expected;
    int result_len = 0;
    int expected_len = 0;

    result_len = s21_sscanf(str, pattern, &result);
    expected_len = sscanf(str, pattern, &expected);

    ck_assert_int_eq(result, expected);
    ck_assert_int_eq(result_len, expected_len);
}
END_TEST

START_TEST(test_s21_sscanf_29) {  // (num)
    const char *str = "Hello, my\t dear\n friend, 100, yes its true!!!";
    const char *pattern = "Hello, my\t dear\n friend, %2d, yes its true!!!";

    int result;
    int expected;
    int result_len = 0;
    int expected_len = 0;

    result_len = s21_sscanf(str, pattern, &result);
    expected_len = sscanf(str, pattern, &expected);

    ck_assert_int_eq(result, expected);
    ck_assert_int_eq(result_len, expected_len);
}
END_TEST

START_TEST(test_s21_sscanf_30) {  // (num)
    const char *str = "Hello, my\t dear\n friends, 100, yes its true!!!";
    const char *pattern = "Hello, my\t dear\n %6s, 100, yes its true!!!";

    char result[10] = {0};
    char expected[10] = {0};
    int result_len = 0;
    int expected_len = 0;

    result_len = s21_sscanf(str, pattern, result);
    expected_len = sscanf(str, pattern, expected);

    ck_assert_str_eq(result, expected);
    ck_assert_int_eq(result_len, expected_len);
}
END_TEST

START_TEST(test_s21_sscanf_31) {  // (num)
    const char *str = "Hello, my\t dear\n friend, 100, yes its true!!!";
    const char *pattern = "Hello, my\t dear\n %6s, 100, yes its true!!!";

    char result[10] = {0};
    char expected[10] = {0};
    int result_len = 0;
    int expected_len = 0;

    result_len = s21_sscanf(str, pattern, result);
    expected_len = sscanf(str, pattern, expected);

    ck_assert_str_eq(result, expected);
    ck_assert_int_eq(result_len, expected_len);
}
END_TEST

START_TEST(test_s21_sscanf_32) {  // *
    const char *str = "Hello, my dear friend, 100, yes its true!!!";
    const char *pattern = "Hello, %*s dear friend, 100, yes %s true!!!";

    char result[10] = {0};
    char expected[10] = {0};
    int result_len = 0;
    int expected_len = 0;

    result_len = s21_sscanf(str, pattern, result);
    expected_len = sscanf(str, pattern, expected);

    ck_assert_str_eq(result, expected);
    ck_assert_int_eq(result_len, expected_len);
}
END_TEST

START_TEST(test_s21_sscanf_33) {  // hd
    const char *str = "Hello, my dear friend, 100, yes its true!!!";
    const char *pattern = "Hello, my dear friend, %hd, yes its true!!!";

    short int result;
    short int expected;
    int result_len = 0;
    int expected_len = 0;

    result_len = s21_sscanf(str, pattern, &result);
    expected_len = sscanf(str, pattern, &expected);

    ck_assert_uint_eq(result, expected);
    ck_assert_int_eq(result_len, expected_len);
}
END_TEST

START_TEST(test_s21_sscanf_34) {  // ld
    const char *str = "Hello, my dear friend, 100, yes its true!!!";
    const char *pattern = "Hello, my dear friend, %ld, yes its true!!!";

    long int result;
    long int expected;
    int result_len = 0;
    int expected_len = 0;

    result_len = s21_sscanf(str, pattern, &result);
    expected_len = sscanf(str, pattern, &expected);

    ck_assert_int_eq(result, expected);
    ck_assert_int_eq(result_len, expected_len);
}
END_TEST

START_TEST(test_s21_sscanf_35) {  // Lf
    const char *str = "Hello, my dear friend, 25.25, yes its true!!!";
    const char *pattern = "Hello, my dear friend, %Lf, yes its true!!!";

    long double result = 0;
    long double expected = 0;
    int result_len = 0;
    int expected_len = 0;

    result_len = s21_sscanf(str, pattern, &result);
    expected_len = sscanf(str, pattern, &expected);

    ck_assert_ldouble_eq(result, expected);
    ck_assert_int_eq(result_len, expected_len);
}
END_TEST

START_TEST(test_s21_sscanf_36) {  // octal
    const char *str = "Hello, my dear friend, 0761, yes its true!!!";
    const char *pattern = "Hello, my dear friend, %i, yes its true!!!";

    int result = 0;
    int expected = 0;
    int result_len = 0;
    int expected_len = 0;

    result_len = s21_sscanf(str, pattern, &result);
    expected_len = sscanf(str, pattern, &expected);

    ck_assert_int_eq(result, expected);
    ck_assert_int_eq(result_len, expected_len);
}
END_TEST

START_TEST(test_s21_sscanf_37) {  // unsigned long
    const char *str = "Hello, my dear friend, 12126, yes its true!!!";
    const char *pattern = "Hello, my dear friend, %lu, yes its true!!!";

    unsigned long result = 0;
    unsigned long expected = 0;
    int result_len = 0;
    int expected_len = 0;

    result_len = s21_sscanf(str, pattern, &result);
    expected_len = sscanf(str, pattern, &expected);

    ck_assert_uint_eq(result, expected);
    ck_assert_int_eq(result_len, expected_len);
}
END_TEST

START_TEST(test_s21_sscanf_38) {  // short
    const char *str = "Hello, my dear friend, 12451, yes its true!!!";
    const char *pattern = "Hello, my dear friend, %hu, yes its true!!!";

    unsigned short result = 0;
    unsigned short expected = 0;
    int result_len = s21_sscanf(str, pattern, &result);
    int expected_len = sscanf(str, pattern, &expected);

    ck_assert_uint_eq(result, expected);
    ck_assert_int_eq(result_len, expected_len);
}
END_TEST

START_TEST(test_s21_sscanf_39) {  // e
    const char *str = "Hello, John,\nmy age\t   is 5661.1e-5";
    const char *pattern = "Hello, John,\nmy age\t   is %e";

    float result = 0;
    float expected = 0;
    int result_len = 0;
    int expected_len = 0;

    result_len = s21_sscanf(str, pattern, &result);
    expected_len = sscanf(str, pattern, &expected);

    ck_assert_float_eq(result, expected);
    ck_assert_int_eq(result_len, expected_len);
}
END_TEST

START_TEST(test_s21_sscanf_40) {  // e
    const char *str = "Hello, John,\nmy age\t   is 51.e+3";
    const char *pattern = "Hello, John,\nmy age\t   is %e";

    float result = 0;
    float expected = 0;
    int result_len = 0;
    int expected_len = 0;

    result_len = s21_sscanf(str, pattern, &result);
    expected_len = sscanf(str, pattern, &expected);

    ck_assert_float_eq(result, expected);
    ck_assert_int_eq(result_len, expected_len);
}
END_TEST

START_TEST(test_s21_sscanf_41) {  // lf
    const char *str = "Hello, my dear friend, 25555.555555, yes its true!!!";
    const char *pattern = "Hello, my dear friend, %lf, yes its true!!!";

    double result = 0;
    double expected = 0;
    int result_len = 0;
    int expected_len = 0;

    result_len = s21_sscanf(str, pattern, &result);
    expected_len = sscanf(str, pattern, &expected);

    ck_assert_ldouble_eq(result, expected);
    ck_assert_int_eq(result_len, expected_len);
}
END_TEST

START_TEST(test_s21_sscanf_42) {  // lf
    const char *str = "Hello, my dear friend, -57238.57945, yes its true!!!";
    const char *pattern = "Hello, my dear friend, %lf, yes its true!!!";

    double result = 0;
    double expected = 0;
    int result_len = 0;
    int expected_len = 0;

    result_len = s21_sscanf(str, pattern, &result);
    expected_len = sscanf(str, pattern, &expected);

    ck_assert_ldouble_eq(result, expected);
    ck_assert_int_eq(result_len, expected_len);
}
END_TEST

START_TEST(test_s21_sscanf_43) {  // negative unsigned
    const char *str = "Hello, my dear friend, -15434, yes its true!!!";
    const char *pattern = "Hello, my dear friend, %hu, yes its true!!!";

    unsigned short result = 0;
    unsigned short expected = 0;
    int result_len = s21_sscanf(str, pattern, &result);
    int expected_len = sscanf(str, pattern, &expected);

    ck_assert_uint_eq(result, expected);
    ck_assert_int_eq(result_len, expected_len);
}
END_TEST

START_TEST(test_s21_sscanf_44) {  // long char
    char str[] = "я";
    char *pattern = "%lc";

    wchar_t result_sym;
    wchar_t expected_sym;

    int result_len = 0;
    int expected_len = 0;

    result_len = s21_sscanf(str, pattern, &result_sym);
    expected_len = sscanf(str, pattern, &expected_sym);

    ck_assert_int_eq(result_sym, expected_sym);
    ck_assert_int_eq(result_len, expected_len);
}
END_TEST

START_TEST(test_s21_sscanf_45) {  // multi scan
    const char *str = "Hello, 100 400 10.45 !!!";
    const char *pattern = "Hello, %d %d %u %d %f";

    int result_1;
    int expected_1;
    int result_2 = 0;
    int expected_2 = 0;
    unsigned int result_3 = 0;
    unsigned int expected_3 = 0;
    int result_4 = 0;
    int expected_4 = 0;
    float result_5 = 0;
    float expected_5 = 0;

    int result_len = 0;
    int expected_len = 0;

    result_len = s21_sscanf(str, pattern, &result_1, &result_2, &result_3,
                            &result_4, &result_5);
    expected_len = sscanf(str, pattern, &expected_1, &expected_2, &expected_3,
                          &expected_4, &expected_5);
    ck_assert_int_eq(result_1, expected_1);
    ck_assert_int_eq(result_2, expected_2);
    ck_assert_uint_eq(result_3, expected_3);
    ck_assert_int_eq(result_4, expected_4);
    ck_assert_float_eq(result_5, expected_5);
    ck_assert_int_eq(result_len, expected_len);
}
END_TEST

START_TEST(test_s21_sscanf_46) {  // long string
    char str[] = "стринги";
    char *pattern = "%ls";

    wchar_t result_str[50];
    wchar_t expected_str[50];

    int result_len = 0;
    int expected_len = 0;

    result_len = s21_sscanf(str, pattern, result_str);
    expected_len = sscanf(str, pattern, expected_str);

    ck_assert_int_eq(result_str[0], expected_str[0]);
    ck_assert_int_eq(result_str[1], expected_str[1]);
    ck_assert_int_eq(result_str[2], expected_str[2]);
    ck_assert_int_eq(result_str[3], expected_str[3]);
    ck_assert_int_eq(result_str[4], expected_str[4]);
    ck_assert_int_eq(result_str[5], expected_str[5]);
    ck_assert_int_eq(result_str[6], expected_str[6]);
    ck_assert_int_eq(result_len, expected_len);
}
END_TEST

START_TEST(test_s21_sscanf_47) {  // combo
    const char *str = "int: 18753, char: W, int int 27/3";
    const char *pattern = "int: %d, char: %c, int int %d%*c%d";
    int result_d = 0;
    char result_c = 0;
    int result_d2 = 0;
    int result_d3 = 0;

    int expected_d = 0;
    char expected_c = 0;
    int expected_d2 = 0;
    int expected_d3 = 0;

    int result_len =
        s21_sscanf(str, pattern, &result_d, &result_c, &result_d2, &result_d3);
    int expected_len = sscanf(str, pattern, &expected_d, &expected_c,
                              &expected_d2, &expected_d3);

    ck_assert_int_eq(result_d, expected_d);
    ck_assert_int_eq(result_c, expected_c);
    ck_assert_int_eq(result_d2, expected_d2);
    ck_assert_int_eq(result_d3, expected_d3);
    ck_assert_int_eq(result_len, expected_len);
}
END_TEST

START_TEST(test_s21_sscanf_48) {  // big
    const char *str = "int: 010753, short: 584, long -2147483649";
    const char *pattern = "int: %o, short: %hd, long %ld";

    unsigned int result_d = 0;
    short result_d2 = 0;
    long result_d3 = 0;

    unsigned int expected_d = 0;
    short expected_d2 = 0;
    long expected_d3 = 0;

    int result_len =
        s21_sscanf(str, pattern, &result_d, &result_d2, &result_d3);
    int expected_len =
        sscanf(str, pattern, &expected_d, &expected_d2, &expected_d3);

    ck_assert_int_eq(result_d, expected_d);
    ck_assert_int_eq(result_d2, expected_d2);
    ck_assert_int_eq(result_d3, expected_d3);
    ck_assert_int_eq(result_len, expected_len);
}
END_TEST

START_TEST(test_s21_sscanf_49) {  // big combo
    const char *str = "long: -2147483649, short: 0X4B8F unsigned 2147483647";
    const char *pattern = "long: %li, short: %hX unsigned %u";

    long result_d = 0;
    unsigned short result_d2 = 0;
    unsigned int result_d3 = 0;

    long expected_d = 0;
    unsigned short expected_d2 = 0;
    unsigned int expected_d3 = 0;

    int result_len =
        s21_sscanf(str, pattern, &result_d, &result_d2, &result_d3);
    int expected_len =
        sscanf(str, pattern, &expected_d, &expected_d2, &expected_d3);

    ck_assert_int_eq(result_d, expected_d);
    ck_assert_uint_eq(result_d2, expected_d2);
    ck_assert_uint_eq(result_d3, expected_d3);
    ck_assert_int_eq(result_len, expected_len);
}
END_TEST

START_TEST(test_s21_sscanf_50) {  // big combo
    const char *str = "long: 01324021762001, short: 0xcd8f, long 012447565621";
    const char *pattern = "long: %7lo%lo, short: %hi, long %li";

    unsigned long result_d = 0;
    unsigned long result_d1 = 0;
    short result_d2 = 0;
    long result_d3 = 0;

    unsigned long expected_d = 0;
    unsigned long expected_d1 = 0;
    short expected_d2 = 0;
    long expected_d3 = 0;

    int result_len =
        s21_sscanf(str, pattern, &result_d, &result_d1, &result_d2, &result_d3);
    int expected_len = sscanf(str, pattern, &expected_d, &expected_d1,
                              &expected_d2, &expected_d3);

    ck_assert_uint_eq(result_d, expected_d);
    ck_assert_uint_eq(result_d1, expected_d1);
    ck_assert_int_eq(result_d2, expected_d2);
    ck_assert_uint_eq(result_d3, expected_d3);
    ck_assert_int_eq(result_len, expected_len);
}
END_TEST

START_TEST(test_s21_sscanf_51) {
    const char *str =
        "Adress: 0x7ffd57a2c4fc, Adress upper: 0x7FFD57A2C4FC, Ja chochu pizzy "
        "256, +25.344";
    const char *pattern =
        "Adress: %p, Adress upper: %p, Ja chochu pizzy %i, %f";

    void *result = 0;
    void *result_1 = 0;
    int result_2 = 0;
    float result_3 = 0;

    void *expected = 0;
    void *expected_1 = 0;
    int expected_2 = 0;
    float expected_3 = 0;

    int res_len =
        s21_sscanf(str, pattern, &result, &result_1, &result_2, &result_3);
    int expected_len =
        sscanf(str, pattern, &expected, &expected_1, &expected_2, &expected_3);

    ck_assert_ptr_eq(result, expected);
    ck_assert_ptr_eq(result_1, expected_1);
    ck_assert_int_eq(result_2, expected_2);
    ck_assert_int_eq(res_len, expected_len);
}
END_TEST

TCase *tcase_s21sscanf(void) {
    TCase *tcase = tcase_create("s21_sscanf");
    tcase_add_test(tcase, test_s21_sscanf_1);
    tcase_add_test(tcase, test_s21_sscanf_2);
    tcase_add_test(tcase, test_s21_sscanf_3);
    tcase_add_test(tcase, test_s21_sscanf_4);
    tcase_add_test(tcase, test_s21_sscanf_5);
    tcase_add_test(tcase, test_s21_sscanf_6);
    tcase_add_test(tcase, test_s21_sscanf_7);
    tcase_add_test(tcase, test_s21_sscanf_8);
    tcase_add_test(tcase, test_s21_sscanf_9);
    tcase_add_test(tcase, test_s21_sscanf_10);
    tcase_add_test(tcase, test_s21_sscanf_11);
    tcase_add_test(tcase, test_s21_sscanf_12);
    tcase_add_test(tcase, test_s21_sscanf_13);
    tcase_add_test(tcase, test_s21_sscanf_14);
    tcase_add_test(tcase, test_s21_sscanf_15);
    tcase_add_test(tcase, test_s21_sscanf_16);
    tcase_add_test(tcase, test_s21_sscanf_17);
    tcase_add_test(tcase, test_s21_sscanf_18);
    tcase_add_test(tcase, test_s21_sscanf_19);
    tcase_add_test(tcase, test_s21_sscanf_20);
    tcase_add_test(tcase, test_s21_sscanf_21);
    tcase_add_test(tcase, test_s21_sscanf_22);
    tcase_add_test(tcase, test_s21_sscanf_23);
    tcase_add_test(tcase, test_s21_sscanf_24);
    tcase_add_test(tcase, test_s21_sscanf_25);
    tcase_add_test(tcase, test_s21_sscanf_26);
    tcase_add_test(tcase, test_s21_sscanf_27);
    tcase_add_test(tcase, test_s21_sscanf_28);
    tcase_add_test(tcase, test_s21_sscanf_29);
    tcase_add_test(tcase, test_s21_sscanf_30);
    tcase_add_test(tcase, test_s21_sscanf_31);
    tcase_add_test(tcase, test_s21_sscanf_32);
    tcase_add_test(tcase, test_s21_sscanf_33);
    tcase_add_test(tcase, test_s21_sscanf_34);
    tcase_add_test(tcase, test_s21_sscanf_35);
    tcase_add_test(tcase, test_s21_sscanf_36);
    tcase_add_test(tcase, test_s21_sscanf_37);
    tcase_add_test(tcase, test_s21_sscanf_38);
    tcase_add_test(tcase, test_s21_sscanf_39);
    tcase_add_test(tcase, test_s21_sscanf_40);
    tcase_add_test(tcase, test_s21_sscanf_41);
    tcase_add_test(tcase, test_s21_sscanf_42);
    tcase_add_test(tcase, test_s21_sscanf_43);
    tcase_add_test(tcase, test_s21_sscanf_44);
    tcase_add_test(tcase, test_s21_sscanf_45);
    tcase_add_test(tcase, test_s21_sscanf_46);
    tcase_add_test(tcase, test_s21_sscanf_47);
    tcase_add_test(tcase, test_s21_sscanf_48);
    tcase_add_test(tcase, test_s21_sscanf_49);
    tcase_add_test(tcase, test_s21_sscanf_50);
    tcase_add_test(tcase, test_s21_sscanf_51);

    return tcase;
}