#include "test_hub.h"

//-------------------------------

START_TEST(test_s21_sprintf_1) {
    char buffer1[4000] = {0};
    char buffer2[4000] = {0};
    char *str3 = "Значение - %c";
    char variable = 'q';
    s21_sprintf(buffer1, str3, variable);
    sprintf(buffer2, str3, variable);
    ck_assert_str_eq(buffer1, buffer2);

    //-------------------------------
}
END_TEST

START_TEST(test_s21_sprintf_2) {
    char buffer1[4000] = {0};
    char buffer2[4000] = {0};
    char *str3 = "Значение - %d";
    int variable = 123;
    s21_sprintf(buffer1, str3, variable);
    sprintf(buffer2, str3, variable);
    ck_assert_str_eq(buffer1, buffer2);

    //-------------------------------
}
END_TEST

START_TEST(test_s21_sprintf_3) {
    char buffer1[4000] = {0};
    char buffer2[4000] = {0};
    char *str3 = "Значение - %d";
    int variable = -123;
    s21_sprintf(buffer1, str3, variable);
    sprintf(buffer2, str3, variable);
    ck_assert_str_eq(buffer1, buffer2);

    //-------------------------------
}
END_TEST

START_TEST(test_s21_sprintf_4) {
    char buffer1[4000] = {0};
    char buffer2[4000] = {0};
    char *str3 = "Значение - %f";
    float variable = 76.756589367;

    int res1 = s21_sprintf(buffer1, str3, variable);
    int res2 = sprintf(buffer2, str3, variable);

    ck_assert_str_eq(buffer1, buffer2);
    ck_assert_int_eq(res1, res2);

    //-------------------------------
}
END_TEST

START_TEST(test_s21_sprintf_5) {
    char buffer1[4000] = {0};
    char buffer2[4000] = {0};
    char *str3 = "Значение - %o";
    int variable = 123;

    int res1 = s21_sprintf(buffer1, str3, variable);
    int res2 = sprintf(buffer2, str3, variable);

    ck_assert_str_eq(buffer1, buffer2);
    ck_assert_int_eq(res1, res2);

    //-------------------------------
}
END_TEST

START_TEST(test_s21_sprintf_6) {
    char buffer1[4000] = {0};
    char buffer2[4000] = {0};
    char *str3 = "Значение - %s";
    char *variable = "qwerty";

    int res1 = s21_sprintf(buffer1, str3, variable);
    int res2 = sprintf(buffer2, str3, variable);

    ck_assert_str_eq(buffer1, buffer2);
    ck_assert_int_eq(res1, res2);

    //-------------------------------
}
END_TEST

START_TEST(test_s21_sprintf_7) {
    char buffer1[4000] = {0};
    char buffer2[4000] = {0};
    char *str3 = "Значение - %u";
    unsigned int variable = 123;

    int res1 = s21_sprintf(buffer1, str3, variable);
    int res2 = sprintf(buffer2, str3, variable);

    ck_assert_str_eq(buffer1, buffer2);
    ck_assert_int_eq(res1, res2);

    //-------------------------------
}
END_TEST

START_TEST(test_s21_sprintf_8) {
    char buffer1[4000] = {0};
    char buffer2[4000] = {0};
    char *str3 = "Значение - %x";
    int variable = 123;

    int res1 = s21_sprintf(buffer1, str3, variable);
    int res2 = sprintf(buffer2, str3, variable);

    ck_assert_str_eq(buffer1, buffer2);
    ck_assert_int_eq(res1, res2);

    //-------------------------------
}
END_TEST

START_TEST(test_s21_sprintf_9) {
    char buffer1[4000] = {0};
    char buffer2[4000] = {0};
    char *str3 = "Значение - %X";
    int variable = 123;

    int res1 = s21_sprintf(buffer1, str3, variable);
    int res2 = sprintf(buffer2, str3, variable);

    ck_assert_str_eq(buffer1, buffer2);
    ck_assert_int_eq(res1, res2);

    //-------------------------------
}
END_TEST

START_TEST(test_s21_sprintf_10) {
    char buffer1[4000] = {0};
    char buffer2[4000] = {0};
    char *str3 = "Значение - %p";
    int variable = 123;

    int res1 = s21_sprintf(buffer1, str3, &variable);
    int res2 = sprintf(buffer2, str3, &variable);

    ck_assert_str_eq(buffer1, buffer2);
    ck_assert_int_eq(res1, res2);

    //-------------------------------
}
END_TEST

START_TEST(test_s21_sprintf_11) {
    char buffer1[4000] = {0};
    char buffer2[4000] = {0};
    char *str3 = "Значение - %d";

    int res1 = s21_sprintf(buffer1, str3, 1);
    int res2 = sprintf(buffer2, str3, 1);

    ck_assert_str_eq(buffer1, buffer2);
    ck_assert_int_eq(res1, res2);

    //--------------------------------------------------- c
    //--------------------------------------------------- c
    //--------------------------------------------------- c
    //--------------------------------------------------- c
}
END_TEST

START_TEST(test_s21_sprintf_12_c) {
    char buffer1[4000] = {0};
    char buffer2[4000] = {0};
    char *str3 = "Значение - %-c";
    char variable = 'q';

    int res1 = s21_sprintf(buffer1, str3, variable);
    int res2 = sprintf(buffer2, str3, variable);

    ck_assert_str_eq(buffer1, buffer2);
    ck_assert_int_eq(res1, res2);

    //--------------------------------------------------- c
}
END_TEST

START_TEST(test_s21_sprintf_13_c) {
    char buffer1[4000] = {0};
    char buffer2[4000] = {0};
    char *str3 = "Значение - %+c";
    char variable = 'q';

    int res1 = s21_sprintf(buffer1, str3, variable);
    int res2 = sprintf(buffer2, str3, variable);

    ck_assert_str_eq(buffer1, buffer2);
    ck_assert_int_eq(res1, res2);

    //--------------------------------------------------- c
}
END_TEST

START_TEST(test_s21_sprintf_14_c) {
    char buffer1[4000] = {0};
    char buffer2[4000] = {0};
    char *str3 = "Значение - % c";
    char variable = 'q';
    int res1 = s21_sprintf(buffer1, str3, variable);
    int res2 = sprintf(buffer2, str3, variable);
    ck_assert_str_eq(buffer1, buffer2);
    ck_assert_int_eq(res1, res2);

    //--------------------------------------------------- c
}
END_TEST

START_TEST(test_s21_sprintf_15_c) {
    char buffer1[4000] = {0};
    char buffer2[4000] = {0};
    char *str3 = "Значение - %#c";
    char variable = 'q';
    int res1 = s21_sprintf(buffer1, str3, variable);
    int res2 = sprintf(buffer2, str3, variable);
    ck_assert_str_eq(buffer1, buffer2);
    ck_assert_int_eq(res1, res2);

    //--------------------------------------------------- c
}
END_TEST

START_TEST(test_s21_sprintf_16_c) {
    char buffer1[4000] = {0};
    char buffer2[4000] = {0};
    char *str3 = "Значение - %0c";
    char variable = 'q';
    int res1 = s21_sprintf(buffer1, str3, variable);
    int res2 = sprintf(buffer2, str3, variable);
    ck_assert_str_eq(buffer1, buffer2);
    ck_assert_int_eq(res1, res2);

    //--------------------------------------------------- c
}
END_TEST

START_TEST(test_s21_sprintf_17_c) {
    char buffer1[4000] = {0};
    char buffer2[4000] = {0};
    char *str3 = "Значение - %15c";
    char variable = 'q';
    int res1 = s21_sprintf(buffer1, str3, variable);
    int res2 = sprintf(buffer2, str3, variable);
    ck_assert_str_eq(buffer1, buffer2);
    ck_assert_int_eq(res1, res2);

    //--------------------------------------------------- c
}
END_TEST

START_TEST(test_s21_sprintf_18_c) {
    char buffer1[4000] = {0};
    char buffer2[4000] = {0};
    char *str3 = "Значение - %*c";
    char variable = 'q';
    int res1 = s21_sprintf(buffer1, str3, variable, 15);
    int res2 = sprintf(buffer2, str3, variable, 15);
    ck_assert_str_eq(buffer1, buffer2);
    ck_assert_int_eq(res1, res2);

    //--------------------------------------------------- c
}
END_TEST

START_TEST(test_s21_sprintf_19_c) {
    char buffer1[4000] = {0};
    char buffer2[4000] = {0};
    char *str3 = "Значение - %.15c";
    char variable = 'q';
    int res1 = s21_sprintf(buffer1, str3, variable);
    int res2 = sprintf(buffer2, str3, variable);
    ck_assert_str_eq(buffer1, buffer2);
    ck_assert_int_eq(res1, res2);

    //--------------------------------------------------- c
}
END_TEST

START_TEST(test_s21_sprintf_20_c) {
    char buffer1[4000] = {0};
    char buffer2[4000] = {0};
    char *str3 = "Значение - %.*c";
    char variable = 'q';
    int res1 = s21_sprintf(buffer1, str3, variable, 15);
    int res2 = sprintf(buffer2, str3, variable, 15);
    ck_assert_str_eq(buffer1, buffer2);
    ck_assert_int_eq(res1, res2);

    //--------------------------------------------------- c
}
END_TEST

START_TEST(test_s21_sprintf_21_c) {
    char buffer1[4000] = {0};
    char buffer2[4000] = {0};
    char *str3 = "Значение - %1c";
    char variable = 'q';
    int res1 = s21_sprintf(buffer1, str3, variable);
    int res2 = sprintf(buffer2, str3, variable);
    ck_assert_str_eq(buffer1, buffer2);
    ck_assert_int_eq(res1, res2);

    //--------------------------------------------------- c
}
END_TEST

START_TEST(test_s21_sprintf_22_c) {
    char buffer1[4000] = {0};
    char buffer2[4000] = {0};
    char *str3 = "Значение - %*c";
    char variable = 'q';
    int res1 = s21_sprintf(buffer1, str3, variable, 1);
    int res2 = sprintf(buffer2, str3, variable, 1);
    ck_assert_str_eq(buffer1, buffer2);
    ck_assert_int_eq(res1, res2);

    //--------------------------------------------------- c
}
END_TEST

START_TEST(test_s21_sprintf_23_c) {
    char buffer1[4000] = {0};
    char buffer2[4000] = {0};
    char *str3 = "Значение - %.1c";
    char variable = 'q';
    int res1 = s21_sprintf(buffer1, str3, variable);
    int res2 = sprintf(buffer2, str3, variable);
    ck_assert_str_eq(buffer1, buffer2);
    ck_assert_int_eq(res1, res2);

    //--------------------------------------------------- c
}
END_TEST

START_TEST(test_s21_sprintf_24_c) {
    char buffer1[4000] = {0};
    char buffer2[4000] = {0};
    char *str3 = "Значение - %.*c";
    char variable = 'q';
    int res1 = s21_sprintf(buffer1, str3, variable, 1);
    int res2 = sprintf(buffer2, str3, variable, 1);
    ck_assert_str_eq(buffer1, buffer2);
    ck_assert_int_eq(res1, res2);

    //--------------------------------------------------- c
}
END_TEST

START_TEST(test_s21_sprintf_25_c) {
    char buffer1[4000] = {0};
    char buffer2[4000] = {0};
    char *str3 = "Значение - %0c";
    char variable = 'q';
    int res1 = s21_sprintf(buffer1, str3, variable);
    int res2 = sprintf(buffer2, str3, variable);
    ck_assert_str_eq(buffer1, buffer2);
    ck_assert_int_eq(res1, res2);

    //--------------------------------------------------- c
}
END_TEST

START_TEST(test_s21_sprintf_26_c) {
    char buffer1[4000] = {0};
    char buffer2[4000] = {0};
    char *str3 = "Значение - %*c";
    char variable = 'q';
    int res1 = s21_sprintf(buffer1, str3, 0, variable);
    int res2 = sprintf(buffer2, str3, 0, variable);
    ck_assert_str_eq(buffer1, buffer2);
    ck_assert_int_eq(res1, res2);

    //--------------------------------------------------- c
}
END_TEST

START_TEST(test_s21_sprintf_27_c) {
    char buffer1[4000] = {0};
    char buffer2[4000] = {0};
    char *str3 = "Значение - %.0c";
    char variable = 'q';
    int res1 = s21_sprintf(buffer1, str3, variable);
    int res2 = sprintf(buffer2, str3, variable);
    ck_assert_str_eq(buffer1, buffer2);
    ck_assert_int_eq(res1, res2);

    //--------------------------------------------------- c
}
END_TEST

START_TEST(test_s21_sprintf_28_c) {
    char buffer1[4000] = {0};
    char buffer2[4000] = {0};
    char *str3 = "Значение - %.*c";
    char variable = 'q';
    int res1 = s21_sprintf(buffer1, str3, 0, variable);
    int res2 = sprintf(buffer2, str3, 0, variable);
    ck_assert_str_eq(buffer1, buffer2);
    ck_assert_int_eq(res1, res2);

    //--------------------------------------------------- c
}
END_TEST

START_TEST(test_s21_sprintf_29_c) {
    char buffer1[4000] = {0};
    char buffer2[4000] = {0};
    char *str3 = "Значение - %-5c";
    char variable = 'q';
    int res1 = s21_sprintf(buffer1, str3, variable);
    int res2 = sprintf(buffer2, str3, variable);
    ck_assert_str_eq(buffer1, buffer2);
    ck_assert_int_eq(res1, res2);

    //--------------------------------------------------- c
}
END_TEST

START_TEST(test_s21_sprintf_30_c) {
    char buffer1[4000] = {0};
    char buffer2[4000] = {0};
    char *str3 = "Значение - %*c";
    char variable = 'q';
    int res1 = s21_sprintf(buffer1, str3, -5, variable);
    int res2 = sprintf(buffer2, str3, -5, variable);
    ck_assert_str_eq(buffer1, buffer2);
    ck_assert_int_eq(res1, res2);

    //--------------------------------------------------- c
}
END_TEST

START_TEST(test_s21_sprintf_31_c) {
    char buffer1[4000] = {0};
    char buffer2[4000] = {0};
    char *str3 = "Значение - %.*c";
    char variable = 'q';
    int res1 = s21_sprintf(buffer1, str3, 5, variable);
    int res2 = sprintf(buffer2, str3, 5, variable);
    ck_assert_str_eq(buffer1, buffer2);
    ck_assert_int_eq(res1, res2);

    //--------------------------------------------------- c
}
END_TEST

START_TEST(test_s21_sprintf_32_c) {
    char buffer1[4000] = {0};
    char buffer2[4000] = {0};
    char *str3 = "Значение - %.c";
    char variable = 'q';
    int res1 = s21_sprintf(buffer1, str3, variable);
    int res2 = sprintf(buffer2, str3, variable);
    ck_assert_str_eq(buffer1, buffer2);
    ck_assert_int_eq(res1, res2);

    //--------------------------------------------------- d
    //--------------------------------------------------- d
    //--------------------------------------------------- d
    //--------------------------------------------------- d
}
END_TEST

START_TEST(test_s21_sprintf_33_d) {
    char buffer1[4000] = {0};
    char buffer2[4000] = {0};
    char *str3 = "Значение - %-d";
    int variable = 123;
    int res1 = s21_sprintf(buffer1, str3, variable);
    int res2 = sprintf(buffer2, str3, variable);
    ck_assert_str_eq(buffer1, buffer2);
    ck_assert_int_eq(res1, res2);

    //--------------------------------------------------- d
}
END_TEST

START_TEST(test_s21_sprintf_34_d) {
    char buffer1[4000] = {0};
    char buffer2[4000] = {0};
    char *str3 = "Значение - %+d";
    int variable = 123;
    int res1 = s21_sprintf(buffer1, str3, variable);
    int res2 = sprintf(buffer2, str3, variable);
    ck_assert_str_eq(buffer1, buffer2);
    ck_assert_int_eq(res1, res2);

    //--------------------------------------------------- d
}
END_TEST

START_TEST(test_s21_sprintf_35_d) {
    char buffer1[4000] = {0};
    char buffer2[4000] = {0};
    char *str3 = "Значение - % d";
    int variable = 123;
    int res1 = s21_sprintf(buffer1, str3, variable);
    int res2 = sprintf(buffer2, str3, variable);
    ck_assert_str_eq(buffer1, buffer2);
    ck_assert_int_eq(res1, res2);

    //--------------------------------------------------- d
}
END_TEST

START_TEST(test_s21_sprintf_36_d) {
    char buffer1[4000] = {0};
    char buffer2[4000] = {0};
    char *str3 = "Значение - %#d";
    int variable = 123;
    int res1 = s21_sprintf(buffer1, str3, variable);
    int res2 = sprintf(buffer2, str3, variable);
    ck_assert_str_eq(buffer1, buffer2);
    ck_assert_int_eq(res1, res2);

    //--------------------------------------------------- d
}
END_TEST

START_TEST(test_s21_sprintf_37_d) {
    char buffer1[4000] = {0};
    char buffer2[4000] = {0};
    char *str3 = "Значение - %0d";
    int variable = 123;
    int res1 = s21_sprintf(buffer1, str3, variable);
    int res2 = sprintf(buffer2, str3, variable);
    ck_assert_str_eq(buffer1, buffer2);
    ck_assert_int_eq(res1, res2);

    //--------------------------------------------------- d
}
END_TEST

START_TEST(test_s21_sprintf_38_d) {
    char buffer1[4000] = {0};
    char buffer2[4000] = {0};
    char *str3 = "Значение - %15d";
    int variable = 123;
    int res1 = s21_sprintf(buffer1, str3, variable);
    int res2 = sprintf(buffer2, str3, variable);
    ck_assert_str_eq(buffer1, buffer2);
    ck_assert_int_eq(res1, res2);

    //--------------------------------------------------- d
}
END_TEST

START_TEST(test_s21_sprintf_39_d) {
    char buffer1[4000] = {0};
    char buffer2[4000] = {0};
    char *str3 = "Значение - %*d";
    int variable = 123;
    int res1 = s21_sprintf(buffer1, str3, variable, 15);
    int res2 = sprintf(buffer2, str3, variable, 15);
    ck_assert_str_eq(buffer1, buffer2);
    ck_assert_int_eq(res1, res2);

    //--------------------------------------------------- d
}
END_TEST

START_TEST(test_s21_sprintf_40_d) {
    char buffer1[4000] = {0};
    char buffer2[4000] = {0};
    char *str3 = "Значение - %1d";
    int variable = 123;
    int res1 = s21_sprintf(buffer1, str3, variable);
    int res2 = sprintf(buffer2, str3, variable);
    ck_assert_str_eq(buffer1, buffer2);
    ck_assert_int_eq(res1, res2);

    //--------------------------------------------------- d
}
END_TEST

START_TEST(test_s21_sprintf_41_d) {
    char buffer1[4000] = {0};
    char buffer2[4000] = {0};
    char *str3 = "Значение - %*d";
    int variable = 123;
    int res1 = s21_sprintf(buffer1, str3, variable, 1);
    int res2 = sprintf(buffer2, str3, variable, 1);
    ck_assert_str_eq(buffer1, buffer2);
    ck_assert_int_eq(res1, res2);

    //--------------------------------------------------- d
}
END_TEST

START_TEST(test_s21_sprintf_42_d) {
    char buffer1[4000] = {0};
    char buffer2[4000] = {0};
    char *str3 = "Значение - %0d";
    int variable = 123;
    int res1 = s21_sprintf(buffer1, str3, variable);
    int res2 = sprintf(buffer2, str3, variable);
    ck_assert_str_eq(buffer1, buffer2);
    ck_assert_int_eq(res1, res2);

    //--------------------------------------------------- d
}
END_TEST

START_TEST(test_s21_sprintf_43_d) {
    char buffer1[4000] = {0};
    char buffer2[4000] = {0};
    char *str3 = "Значение - %*d";
    int variable = 123;
    int res1 = s21_sprintf(buffer1, str3, variable, 0);
    int res2 = sprintf(buffer2, str3, variable, 0);
    ck_assert_str_eq(buffer1, buffer2);
    ck_assert_int_eq(res1, res2);

    //--------------------------------------------------- d
}
END_TEST

START_TEST(test_s21_sprintf_44_d) {
    char buffer1[4000] = {0};
    char buffer2[4000] = {0};
    char *str3 = "Значение - %-15d";
    int variable = 123;
    int res1 = s21_sprintf(buffer1, str3, variable);
    int res2 = sprintf(buffer2, str3, variable);
    ck_assert_str_eq(buffer1, buffer2);
    ck_assert_int_eq(res1, res2);

    //--------------------------------------------------- d
}
END_TEST

START_TEST(test_s21_sprintf_45_d) {
    char buffer1[4000] = {0};
    char buffer2[4000] = {0};
    char *str3 = "Значение - %*d";
    int variable = 123;
    int res1 = s21_sprintf(buffer1, str3, -15, variable);
    int res2 = sprintf(buffer2, str3, -15, variable);
    ck_assert_str_eq(buffer1, buffer2);
    ck_assert_int_eq(res1, res2);

    //--------------------------------------------------- d
}
END_TEST

START_TEST(test_s21_sprintf_46_d) {
    char buffer1[4000] = {0};
    char buffer2[4000] = {0};
    char *str3 = "Значение - %.15d";
    int variable = 123;
    int res1 = s21_sprintf(buffer1, str3, variable);
    int res2 = sprintf(buffer2, str3, variable);
    ck_assert_str_eq(buffer1, buffer2);
    ck_assert_int_eq(res1, res2);

    //--------------------------------------------------- d
}
END_TEST

START_TEST(test_s21_sprintf_47_d) {
    char buffer1[4000] = {0};
    char buffer2[4000] = {0};
    char *str3 = "Значение - %.*d";
    int variable = 123;
    int res1 = s21_sprintf(buffer1, str3, variable, 15);
    int res2 = sprintf(buffer2, str3, variable, 15);
    ck_assert_str_eq(buffer1, buffer2);
    ck_assert_int_eq(res1, res2);

    //--------------------------------------------------- d
}
END_TEST

START_TEST(test_s21_sprintf_48_d) {
    char buffer1[4000] = {0};
    char buffer2[4000] = {0};
    char *str3 = "Значение - %.1d";
    int variable = 123;
    int res1 = s21_sprintf(buffer1, str3, variable);
    int res2 = sprintf(buffer2, str3, variable);
    ck_assert_str_eq(buffer1, buffer2);
    ck_assert_int_eq(res1, res2);

    //--------------------------------------------------- d
}
END_TEST

START_TEST(test_s21_sprintf_49_d) {
    char buffer1[4000] = {0};
    char buffer2[4000] = {0};
    char *str3 = "Значение - %.*d";
    int variable = 123;
    int res1 = s21_sprintf(buffer1, str3, variable, 1);
    int res2 = sprintf(buffer2, str3, variable, 1);
    ck_assert_str_eq(buffer1, buffer2);
    ck_assert_int_eq(res1, res2);

    //--------------------------------------------------- d
}
END_TEST

START_TEST(test_s21_sprintf_50_d) {
    char buffer1[4000] = {0};
    char buffer2[4000] = {0};
    char *str3 = "Значение - %.0d";
    int variable = 123;
    int res1 = s21_sprintf(buffer1, str3, variable);
    int res2 = sprintf(buffer2, str3, variable);
    ck_assert_str_eq(buffer1, buffer2);
    ck_assert_int_eq(res1, res2);

    //--------------------------------------------------- d
}
END_TEST

START_TEST(test_s21_sprintf_51_d) {
    char buffer1[4000] = {0};
    char buffer2[4000] = {0};
    char *str3 = "Значение - %.*d";
    int variable = 123;
    int res1 = s21_sprintf(buffer1, str3, variable, 0);
    int res2 = sprintf(buffer2, str3, variable, 0);
    ck_assert_str_eq(buffer1, buffer2);
    ck_assert_int_eq(res1, res2);

    //--------------------------------------------------- d
}
END_TEST

START_TEST(test_s21_sprintf_52_d) {
    char buffer1[4000] = {0};
    char buffer2[4000] = {0};
    char *str3 = "Значение - %+07d";
    int variable = -123;
    int res1 = s21_sprintf(buffer1, str3, variable, 0);
    int res2 = sprintf(buffer2, str3, variable, 0);
    ck_assert_str_eq(buffer1, buffer2);
    ck_assert_int_eq(res1, res2);

    //--------------------------------------------------- d
}
END_TEST

START_TEST(test_s21_sprintf_53_d) {
    char buffer1[4000] = {0};
    char buffer2[4000] = {0};
    char *str3 = "Значение - %.*d";
    int variable = 123;
    int res1 = s21_sprintf(buffer1, str3, -15, variable);
    int res2 = sprintf(buffer2, str3, -15, variable);
    ck_assert_str_eq(buffer1, buffer2);
    ck_assert_int_eq(res1, res2);

    //--------------------------------------------------- d
}
END_TEST

START_TEST(test_s21_sprintf_54_d) {
    char buffer1[4000] = {0};
    char buffer2[4000] = {0};
    char *str3 = "Значение - %hd";
    short int variable = 123;
    int res1 = s21_sprintf(buffer1, str3, variable);
    int res2 = sprintf(buffer2, str3, variable);
    ck_assert_str_eq(buffer1, buffer2);
    ck_assert_int_eq(res1, res2);

    //--------------------------------------------------- d
}
END_TEST

START_TEST(test_s21_sprintf_55_d) {
    char buffer1[4000] = {0};
    char buffer2[4000] = {0};
    char *str3 = "Значение - %ld";
    long int variable = 123;
    int res1 = s21_sprintf(buffer1, str3, variable);
    int res2 = sprintf(buffer2, str3, variable);
    ck_assert_str_eq(buffer1, buffer2);
    ck_assert_int_eq(res1, res2);

    //--------------------------------------------------- i
    //--------------------------------------------------- i
    //--------------------------------------------------- i
    //--------------------------------------------------- i
}
END_TEST

START_TEST(test_s21_sprintf_56_f) {
    char buffer1[4000] = {0};
    char buffer2[4000] = {0};
    char *str3 = "Значение - %-f";
    float variable = 76.756589367;

    int res1 = s21_sprintf(buffer1, str3, variable);
    int res2 = sprintf(buffer2, str3, variable);

    ck_assert_str_eq(buffer1, buffer2);
    ck_assert_int_eq(res1, res2);

    //--------------------------------------------------- f
}
END_TEST

START_TEST(test_s21_sprintf_57_f) {
    char buffer1[4000] = {0};
    char buffer2[4000] = {0};
    char *str3 = "Значение - %+f";
    float variable = 76.756589367;

    int res1 = s21_sprintf(buffer1, str3, variable);
    int res2 = sprintf(buffer2, str3, variable);

    ck_assert_str_eq(buffer1, buffer2);
    ck_assert_int_eq(res1, res2);

    //--------------------------------------------------- f
}
END_TEST

START_TEST(test_s21_sprintf_58_f) {
    char buffer1[4000] = {0};
    char buffer2[4000] = {0};
    char *str3 = "Значение - % f";
    float variable = 76.756589367;

    int res1 = s21_sprintf(buffer1, str3, variable);
    int res2 = sprintf(buffer2, str3, variable);

    ck_assert_str_eq(buffer1, buffer2);
    ck_assert_int_eq(res1, res2);

    //--------------------------------------------------- f
}
END_TEST

START_TEST(test_s21_sprintf_59_f) {
    char buffer1[4000] = {0};
    char buffer2[4000] = {0};
    char *str3 = "Значение - %#f";
    float variable = 76.756589367;

    int res1 = s21_sprintf(buffer1, str3, variable);
    int res2 = sprintf(buffer2, str3, variable);

    ck_assert_str_eq(buffer1, buffer2);
    ck_assert_int_eq(res1, res2);

    //--------------------------------------------------- f
}
END_TEST

START_TEST(test_s21_sprintf_60_f) {
    char buffer1[4000] = {0};
    char buffer2[4000] = {0};
    char *str3 = "Значение - %0f";
    float variable = 76.756589367;

    int res1 = s21_sprintf(buffer1, str3, variable);
    int res2 = sprintf(buffer2, str3, variable);

    ck_assert_str_eq(buffer1, buffer2);
    ck_assert_int_eq(res1, res2);

    //--------------------------------------------------- f
}
END_TEST

START_TEST(test_s21_sprintf_61_f) {
    char buffer1[4000] = {0};
    char buffer2[4000] = {0};
    char *str3 = "Значение - %15f";
    float variable = 76.756589367;

    int res1 = s21_sprintf(buffer1, str3, variable);
    int res2 = sprintf(buffer2, str3, variable);

    ck_assert_str_eq(buffer1, buffer2);
    ck_assert_int_eq(res1, res2);

    //--------------------------------------------------- f
}
END_TEST

START_TEST(test_s21_sprintf_62_f) {
    char buffer1[4000] = {0};
    char buffer2[4000] = {0};
    char *str3 = "Значение - %*f";
    float variable = 76.756589367;

    int res1 = s21_sprintf(buffer1, str3, variable, 15);
    int res2 = sprintf(buffer2, str3, variable, 15);

    ck_assert_str_eq(buffer1, buffer2);
    ck_assert_int_eq(res1, res2);

    //--------------------------------------------------- f
}
END_TEST

START_TEST(test_s21_sprintf_63_f) {
    char buffer1[4000] = {0};
    char buffer2[4000] = {0};
    char *str3 = "Значение - %.15f";
    float variable = 76.756589367;

    int res1 = s21_sprintf(buffer1, str3, variable);
    int res2 = sprintf(buffer2, str3, variable);

    ck_assert_str_eq(buffer1, buffer2);
    ck_assert_int_eq(res1, res2);

    //--------------------------------------------------- f
}
END_TEST

START_TEST(test_s21_sprintf_64_f) {
    char buffer1[4000] = {0};
    char buffer2[4000] = {0};
    char *str3 = "Значение - %.*f";
    float variable = 76.756589367;

    int res1 = s21_sprintf(buffer1, str3, variable, 15);
    int res2 = sprintf(buffer2, str3, variable, 15);

    ck_assert_str_eq(buffer1, buffer2);
    ck_assert_int_eq(res1, res2);

    //--------------------------------------------------- f
}
END_TEST

START_TEST(test_s21_sprintf_65_f) {
    char buffer1[4000] = {0};
    char buffer2[4000] = {0};
    char *str3 = "Значение - %-15f";
    float variable = 76.756589367;

    int res1 = s21_sprintf(buffer1, str3, variable);
    int res2 = sprintf(buffer2, str3, variable);

    ck_assert_str_eq(buffer1, buffer2);
    ck_assert_int_eq(res1, res2);

    //--------------------------------------------------- f
}
END_TEST

START_TEST(test_s21_sprintf_66_f) {
    char buffer1[4000] = {0};
    char buffer2[4000] = {0};
    char *str3 = "Значение - %*f";
    float variable = 76.756589367;

    int res1 = s21_sprintf(buffer1, str3, -15, variable);
    int res2 = sprintf(buffer2, str3, -15, variable);

    ck_assert_str_eq(buffer1, buffer2);
    ck_assert_int_eq(res1, res2);

    //--------------------------------------------------- f
}
END_TEST

START_TEST(test_s21_sprintf_67_f) {
    char buffer1[4000] = {0};
    char buffer2[4000] = {0};
    char *str3 = "Значение - %0f";
    float variable = 76.756589367;

    int res1 = s21_sprintf(buffer1, str3, variable);
    int res2 = sprintf(buffer2, str3, variable);

    ck_assert_str_eq(buffer1, buffer2);
    ck_assert_int_eq(res1, res2);

    //--------------------------------------------------- f
}
END_TEST

START_TEST(test_s21_sprintf_68_f) {
    char buffer1[4000] = {0};
    char buffer2[4000] = {0};
    char *str3 = "Значение - %*f";
    float variable = 76.756589367;

    int res1 = s21_sprintf(buffer1, str3, variable, 0);
    int res2 = sprintf(buffer2, str3, variable, 0);

    ck_assert_str_eq(buffer1, buffer2);
    ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(test_s21_sprintf_69_f) {
    char buffer1[4000] = {0};
    char buffer2[4000] = {0};
    char *str3 = "Значение - %.0f";
    float variable = 76.756589367;

    int res1 = s21_sprintf(buffer1, str3, variable);
    int res2 = sprintf(buffer2, str3, variable);

    ck_assert_str_eq(buffer1, buffer2);
    ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(test_s21_sprintf_70_f) {
    char buffer1[4000] = {0};
    char buffer2[4000] = {0};
    char *str3 = "Значение - %.*f";
    float variable = 76.756589367;

    int res1 = s21_sprintf(buffer1, str3, variable, 0);
    int res2 = sprintf(buffer2, str3, variable, 0);

    ck_assert_str_eq(buffer1, buffer2);
    ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(test_s21_sprintf_71_f) {
    char buffer1[4000] = {0};
    char buffer2[4000] = {0};
    char *str3 = "Значение - %Lf";
    long double variable = 76.756589367;

    int res1 = s21_sprintf(buffer1, str3, variable);
    int res2 = sprintf(buffer2, str3, variable);

    ck_assert_str_eq(buffer1, buffer2);
    ck_assert_int_eq(res1, res2);

    //--------------------------------------------------- o
    //--------------------------------------------------- o
    //--------------------------------------------------- o
    //--------------------------------------------------- o
}
END_TEST

START_TEST(test_s21_sprintf_72_o) {
    char buffer1[4000] = {0};
    char buffer2[4000] = {0};
    char *str3 = "Значение - %-o";
    int variable = 123;

    int res1 = s21_sprintf(buffer1, str3, variable);
    int res2 = sprintf(buffer2, str3, variable);

    ck_assert_str_eq(buffer1, buffer2);
    ck_assert_int_eq(res1, res2);

    //--------------------------------------------------- o
}
END_TEST

START_TEST(test_s21_sprintf_73_o) {
    char buffer1[4000] = {0};
    char buffer2[4000] = {0};
    char *str3 = "Значение - %+o";
    int variable = 123;

    int res1 = s21_sprintf(buffer1, str3, variable);
    int res2 = sprintf(buffer2, str3, variable);

    ck_assert_str_eq(buffer1, buffer2);
    ck_assert_int_eq(res1, res2);

    //--------------------------------------------------- o
}
END_TEST

START_TEST(test_s21_sprintf_74_o) {
    char buffer1[4000] = {0};
    char buffer2[4000] = {0};
    char *str3 = "Значение - % o";
    int variable = 123;

    int res1 = s21_sprintf(buffer1, str3, variable);
    int res2 = sprintf(buffer2, str3, variable);

    ck_assert_str_eq(buffer1, buffer2);
    ck_assert_int_eq(res1, res2);

    //--------------------------------------------------- o
}
END_TEST

START_TEST(test_s21_sprintf_75_o) {
    char buffer1[4000] = {0};
    char buffer2[4000] = {0};
    char *str3 = "Значение - %#o";
    int variable = 123;

    int res1 = s21_sprintf(buffer1, str3, variable);
    int res2 = sprintf(buffer2, str3, variable);

    ck_assert_str_eq(buffer1, buffer2);
    ck_assert_int_eq(res1, res2);

    //--------------------------------------------------- o
}
END_TEST

START_TEST(test_s21_sprintf_76_o) {
    char buffer1[4000] = {0};
    char buffer2[4000] = {0};
    char *str3 = "Значение - %0o";
    int variable = 123;

    int res1 = s21_sprintf(buffer1, str3, variable);
    int res2 = sprintf(buffer2, str3, variable);

    ck_assert_str_eq(buffer1, buffer2);
    ck_assert_int_eq(res1, res2);

    //--------------------------------------------------- o
}
END_TEST

START_TEST(test_s21_sprintf_77_o) {
    char buffer1[4000] = {0};
    char buffer2[4000] = {0};
    char *str3 = "Значение - %15o";
    int variable = 123;

    int res1 = s21_sprintf(buffer1, str3, variable);
    int res2 = sprintf(buffer2, str3, variable);

    ck_assert_str_eq(buffer1, buffer2);
    ck_assert_int_eq(res1, res2);

    //--------------------------------------------------- o
}
END_TEST

START_TEST(test_s21_sprintf_78_o) {
    char buffer1[4000] = {0};
    char buffer2[4000] = {0};
    char *str3 = "Значение - %*o";
    int variable = 123;

    int res1 = s21_sprintf(buffer1, str3, variable, 15);
    int res2 = sprintf(buffer2, str3, variable, 15);

    ck_assert_str_eq(buffer1, buffer2);
    ck_assert_int_eq(res1, res2);

    //--------------------------------------------------- o
}
END_TEST

START_TEST(test_s21_sprintf_79_o) {
    char buffer1[4000] = {0};
    char buffer2[4000] = {0};
    char *str3 = "Значение - %.15o";
    int variable = 123;

    int res1 = s21_sprintf(buffer1, str3, variable);
    int res2 = sprintf(buffer2, str3, variable);

    ck_assert_str_eq(buffer1, buffer2);
    ck_assert_int_eq(res1, res2);

    //--------------------------------------------------- o
}
END_TEST

START_TEST(test_s21_sprintf_80_o) {
    char buffer1[4000] = {0};
    char buffer2[4000] = {0};
    char *str3 = "Значение - %.*o";
    int variable = 123;

    int res1 = s21_sprintf(buffer1, str3, variable, 15);
    int res2 = sprintf(buffer2, str3, variable, 15);

    ck_assert_str_eq(buffer1, buffer2);
    ck_assert_int_eq(res1, res2);

    //--------------------------------------------------- o
}
END_TEST

START_TEST(test_s21_sprintf_81_o) {
    char buffer1[4000] = {0};
    char buffer2[4000] = {0};
    char *str3 = "Значение - %1o";
    int variable = 123;

    int res1 = s21_sprintf(buffer1, str3, variable);
    int res2 = sprintf(buffer2, str3, variable);

    ck_assert_str_eq(buffer1, buffer2);
    ck_assert_int_eq(res1, res2);

    //--------------------------------------------------- o
}
END_TEST

START_TEST(test_s21_sprintf_82_o) {
    char buffer1[4000] = {0};
    char buffer2[4000] = {0};
    char *str3 = "Значение - %*o";
    int variable = 123;

    int res1 = s21_sprintf(buffer1, str3, variable, 1);
    int res2 = sprintf(buffer2, str3, variable, 1);

    ck_assert_str_eq(buffer1, buffer2);
    ck_assert_int_eq(res1, res2);

    //--------------------------------------------------- o
}
END_TEST

START_TEST(test_s21_sprintf_83_o) {
    char buffer1[4000] = {0};
    char buffer2[4000] = {0};
    char *str3 = "Значение - %.1o";
    int variable = 123;

    int res1 = s21_sprintf(buffer1, str3, variable);
    int res2 = sprintf(buffer2, str3, variable);

    ck_assert_str_eq(buffer1, buffer2);
    ck_assert_int_eq(res1, res2);

    //--------------------------------------------------- o
}
END_TEST

START_TEST(test_s21_sprintf_84_o) {
    char buffer1[4000] = {0};
    char buffer2[4000] = {0};
    char *str3 = "Значение - %.*o";
    int variable = 123;

    int res1 = s21_sprintf(buffer1, str3, variable, 1);
    int res2 = sprintf(buffer2, str3, variable, 1);

    ck_assert_str_eq(buffer1, buffer2);
    ck_assert_int_eq(res1, res2);

    //--------------------------------------------------- o
}
END_TEST

START_TEST(test_s21_sprintf_85_o) {
    char buffer1[4000] = {0};
    char buffer2[4000] = {0};
    char *str3 = "Значение - %0o";
    int variable = 123;

    int res1 = s21_sprintf(buffer1, str3, variable);
    int res2 = sprintf(buffer2, str3, variable);

    ck_assert_str_eq(buffer1, buffer2);
    ck_assert_int_eq(res1, res2);

    //--------------------------------------------------- o
}
END_TEST

START_TEST(test_s21_sprintf_86_o) {
    char buffer1[4000] = {0};
    char buffer2[4000] = {0};
    char *str3 = "Значение - %*o";
    int variable = 123;

    int res1 = s21_sprintf(buffer1, str3, variable, 0);
    int res2 = sprintf(buffer2, str3, variable, 0);

    ck_assert_str_eq(buffer1, buffer2);
    ck_assert_int_eq(res1, res2);

    //--------------------------------------------------- o
}
END_TEST

START_TEST(test_s21_sprintf_87_o) {
    char buffer1[4000] = {0};
    char buffer2[4000] = {0};
    char *str3 = "Значение - %.0o";
    int variable = 123;

    int res1 = s21_sprintf(buffer1, str3, variable);
    int res2 = sprintf(buffer2, str3, variable);

    ck_assert_str_eq(buffer1, buffer2);
    ck_assert_int_eq(res1, res2);

    //--------------------------------------------------- o
}
END_TEST

START_TEST(test_s21_sprintf_88_o) {
    char buffer1[4000] = {0};
    char buffer2[4000] = {0};
    char *str3 = "Значение - %.*o";
    int variable = 123;

    int res1 = s21_sprintf(buffer1, str3, variable, 0);
    int res2 = sprintf(buffer2, str3, variable, 0);

    ck_assert_str_eq(buffer1, buffer2);
    ck_assert_int_eq(res1, res2);

    //--------------------------------------------------- o
}
END_TEST

START_TEST(test_s21_sprintf_89_o) {
    char buffer1[4000] = {0};
    char buffer2[4000] = {0};
    char *str3 = "Значение - %-15o";
    int variable = 123;

    int res1 = s21_sprintf(buffer1, str3, variable);
    int res2 = sprintf(buffer2, str3, variable);

    ck_assert_str_eq(buffer1, buffer2);
    ck_assert_int_eq(res1, res2);

    //--------------------------------------------------- o
}
END_TEST

START_TEST(test_s21_sprintf_90_o) {
    char buffer1[4000] = {0};
    char buffer2[4000] = {0};
    char *str3 = "Значение - %*o";
    int variable = 123;

    int res1 = s21_sprintf(buffer1, str3, -15, variable);
    int res2 = sprintf(buffer2, str3, -15, variable);

    ck_assert_str_eq(buffer1, buffer2);
    ck_assert_int_eq(res1, res2);

    //--------------------------------------------------- o
}
END_TEST

START_TEST(test_s21_sprintf_91_o) {
    char buffer1[4000] = {0};
    char buffer2[4000] = {0};
    char *str3 = "Значение - %.*o";
    int variable = 123;

    int res1 = s21_sprintf(buffer1, str3, -15, variable);
    int res2 = sprintf(buffer2, str3, -15, variable);

    ck_assert_str_eq(buffer1, buffer2);
    ck_assert_int_eq(res1, res2);

    //--------------------------------------------------- o
}
END_TEST

START_TEST(test_s21_sprintf_92_o) {
    char buffer1[4000] = {0};
    char buffer2[4000] = {0};
    char *str3 = "Значение - %.*ho";
    short int variable = 123;

    int res1 = s21_sprintf(buffer1, str3, -15, variable);
    int res2 = sprintf(buffer2, str3, -15, variable);

    ck_assert_str_eq(buffer1, buffer2);
    ck_assert_int_eq(res1, res2);

    //--------------------------------------------------- o
}
END_TEST

START_TEST(test_s21_sprintf_93_o) {
    char buffer1[4000] = {0};
    char buffer2[4000] = {0};
    char *str3 = "Значение - %.*lo";
    long int variable = 123;

    int res1 = s21_sprintf(buffer1, str3, -15, variable);
    int res2 = sprintf(buffer2, str3, -15, variable);

    ck_assert_str_eq(buffer1, buffer2);
    ck_assert_int_eq(res1, res2);

    //--------------------------------------------------- s
    //--------------------------------------------------- s
    //--------------------------------------------------- s
    //--------------------------------------------------- s
}
END_TEST

START_TEST(test_s21_sprintf_94_s) {
    char buffer1[4000] = {0};
    char buffer2[4000] = {0};
    char *str3 = "Значение - %-s";
    char *variable = "qwerty";

    int res1 = s21_sprintf(buffer1, str3, variable);
    int res2 = sprintf(buffer2, str3, variable);

    ck_assert_str_eq(buffer1, buffer2);
    ck_assert_int_eq(res1, res2);

    //--------------------------------------------------- s
}
END_TEST

START_TEST(test_s21_sprintf_95_s) {
    char buffer1[4000] = {0};
    char buffer2[4000] = {0};
    char *str3 = "Значение - %+s";
    char *variable = "qwerty";

    int res1 = s21_sprintf(buffer1, str3, variable);
    int res2 = sprintf(buffer2, str3, variable);

    ck_assert_str_eq(buffer1, buffer2);
    ck_assert_int_eq(res1, res2);

    //--------------------------------------------------- s
}
END_TEST

START_TEST(test_s21_sprintf_96_s) {
    char buffer1[4000] = {0};
    char buffer2[4000] = {0};
    char *str3 = "Значение - % s";
    char *variable = "qwerty";

    int res1 = s21_sprintf(buffer1, str3, variable);
    int res2 = sprintf(buffer2, str3, variable);

    ck_assert_str_eq(buffer1, buffer2);
    ck_assert_int_eq(res1, res2);

    //--------------------------------------------------- s
}
END_TEST

START_TEST(test_s21_sprintf_97_s) {
    char buffer1[4000] = {0};
    char buffer2[4000] = {0};
    char *str3 = "Значение - %#s";
    char *variable = "qwerty";

    int res1 = s21_sprintf(buffer1, str3, variable);
    int res2 = sprintf(buffer2, str3, variable);

    ck_assert_str_eq(buffer1, buffer2);
    ck_assert_int_eq(res1, res2);

    //--------------------------------------------------- s
}
END_TEST

START_TEST(test_s21_sprintf_98_s) {
    char buffer1[4000] = {0};
    char buffer2[4000] = {0};
    char *str3 = "Значение - %0s";
    char *variable = "qwerty";

    int res1 = s21_sprintf(buffer1, str3, variable);
    int res2 = sprintf(buffer2, str3, variable);

    ck_assert_str_eq(buffer1, buffer2);
    ck_assert_int_eq(res1, res2);

    //--------------------------------------------------- s
}
END_TEST

START_TEST(test_s21_sprintf_99_s) {
    char buffer1[4000] = {0};
    char buffer2[4000] = {0};
    char *str3 = "Значение - %15s";
    char *variable = "qwerty";

    int res1 = s21_sprintf(buffer1, str3, variable);
    int res2 = sprintf(buffer2, str3, variable);

    ck_assert_str_eq(buffer1, buffer2);
    ck_assert_int_eq(res1, res2);

    //--------------------------------------------------- s
}
END_TEST

START_TEST(test_s21_sprintf_100_s) {
    char buffer1[4000] = {0};
    char buffer2[4000] = {0};
    char *str3 = "Значение - %*s";
    char *variable = "qwerty";

    int res1 = s21_sprintf(buffer1, str3, 15, variable);
    int res2 = sprintf(buffer2, str3, 15, variable);

    ck_assert_str_eq(buffer1, buffer2);
    ck_assert_int_eq(res1, res2);

    //--------------------------------------------------- s
}
END_TEST

START_TEST(test_s21_sprintf_101_s) {
    char buffer1[4000] = {0};
    char buffer2[4000] = {0};
    char *str3 = "Значение - %.15s";
    char *variable = "qwerty";

    int res1 = s21_sprintf(buffer1, str3, variable);
    int res2 = sprintf(buffer2, str3, variable);

    ck_assert_str_eq(buffer1, buffer2);
    ck_assert_int_eq(res1, res2);

    //--------------------------------------------------- s
}
END_TEST

START_TEST(test_s21_sprintf_102_s) {
    char buffer1[4000] = {0};
    char buffer2[4000] = {0};
    char *str3 = "Значение - %.*s";
    char *variable = "qwerty";

    int res1 = s21_sprintf(buffer1, str3, 15, variable);
    int res2 = sprintf(buffer2, str3, 15, variable);

    ck_assert_str_eq(buffer1, buffer2);
    ck_assert_int_eq(res1, res2);

    //--------------------------------------------------- s
}
END_TEST

START_TEST(test_s21_sprintf_103_s) {
    char buffer1[4000] = {0};
    char buffer2[4000] = {0};
    char *str3 = "Значение - %1s";
    char *variable = "qwerty";

    int res1 = s21_sprintf(buffer1, str3, variable);
    int res2 = sprintf(buffer2, str3, variable);

    ck_assert_str_eq(buffer1, buffer2);
    ck_assert_int_eq(res1, res2);

    //--------------------------------------------------- s
}
END_TEST

START_TEST(test_s21_sprintf_104_s) {
    char buffer1[4000] = {0};
    char buffer2[4000] = {0};
    char *str3 = "Значение - %*s";
    char *variable = "qwerty";

    int res1 = s21_sprintf(buffer1, str3, 1, variable);
    int res2 = sprintf(buffer2, str3, 1, variable);

    ck_assert_str_eq(buffer1, buffer2);
    ck_assert_int_eq(res1, res2);

    //--------------------------------------------------- s
}
END_TEST

START_TEST(test_s21_sprintf_105_s) {
    char buffer1[4000] = {0};
    char buffer2[4000] = {0};
    char *str3 = "Значение - %.1s";
    char *variable = "qwerty";

    int res1 = s21_sprintf(buffer1, str3, variable);
    int res2 = sprintf(buffer2, str3, variable);

    ck_assert_str_eq(buffer1, buffer2);
    ck_assert_int_eq(res1, res2);

    //--------------------------------------------------- s
}
END_TEST

START_TEST(test_s21_sprintf_106_s) {
    char buffer1[4000] = {0};
    char buffer2[4000] = {0};
    char *str3 = "Значение - %.*s";
    char *variable = "qwerty";

    int res1 = s21_sprintf(buffer1, str3, 1, variable);
    int res2 = sprintf(buffer2, str3, 1, variable);

    ck_assert_str_eq(buffer1, buffer2);
    ck_assert_int_eq(res1, res2);

    //--------------------------------------------------- s
}
END_TEST

START_TEST(test_s21_sprintf_107_s) {
    char buffer1[4000] = {0};
    char buffer2[4000] = {0};
    char *str3 = "Значение - %0s";
    char *variable = "qwerty";

    int res1 = s21_sprintf(buffer1, str3, variable);
    int res2 = sprintf(buffer2, str3, variable);

    ck_assert_str_eq(buffer1, buffer2);
    ck_assert_int_eq(res1, res2);

    //--------------------------------------------------- s
}
END_TEST

START_TEST(test_s21_sprintf_108_s) {
    char buffer1[4000] = {0};
    char buffer2[4000] = {0};
    char *str3 = "Значение - %*s";
    char *variable = "qwerty";

    int res1 = s21_sprintf(buffer1, str3, 0, variable);
    int res2 = sprintf(buffer2, str3, 0, variable);

    ck_assert_str_eq(buffer1, buffer2);
    ck_assert_int_eq(res1, res2);

    //--------------------------------------------------- s
}
END_TEST

START_TEST(test_s21_sprintf_109_s) {
    char buffer1[4000] = {0};
    char buffer2[4000] = {0};
    char *str3 = "Значение - %-15s";
    char *variable = "qwerty";

    int res1 = s21_sprintf(buffer1, str3, variable);
    int res2 = sprintf(buffer2, str3, variable);

    ck_assert_str_eq(buffer1, buffer2);
    ck_assert_int_eq(res1, res2);

    //--------------------------------------------------- s
}
END_TEST

START_TEST(test_s21_sprintf_110_s) {
    char buffer1[4000] = {0};
    char buffer2[4000] = {0};
    char *str3 = "Значение -";
    char *variable = "qwerty";

    int res1 = s21_sprintf(buffer1, str3, variable);
    int res2 = sprintf(buffer2, str3, variable);

    ck_assert_str_eq(buffer1, buffer2);
    ck_assert_int_eq(res1, res2);

    //--------------------------------------------------- u
    //--------------------------------------------------- u
    //--------------------------------------------------- u
    //--------------------------------------------------- u
}
END_TEST

START_TEST(test_s21_sprintf_111_u) {
    char buffer1[4000] = {0};
    char buffer2[4000] = {0};
    char *str3 = "Значение - %-u";
    unsigned int variable = 123;

    int res1 = s21_sprintf(buffer1, str3, variable);
    int res2 = sprintf(buffer2, str3, variable);

    ck_assert_str_eq(buffer1, buffer2);
    ck_assert_int_eq(res1, res2);

    //--------------------------------------------------- u
}
END_TEST

START_TEST(test_s21_sprintf_112_u) {
    char buffer1[4000] = {0};
    char buffer2[4000] = {0};
    char *str3 = "Значение - %+u";
    unsigned int variable = 123;

    int res1 = s21_sprintf(buffer1, str3, variable);
    int res2 = sprintf(buffer2, str3, variable);

    ck_assert_str_eq(buffer1, buffer2);
    ck_assert_int_eq(res1, res2);

    //--------------------------------------------------- u
}
END_TEST

START_TEST(test_s21_sprintf_113_u) {
    char buffer1[4000] = {0};
    char buffer2[4000] = {0};
    char *str3 = "Значение - % u";
    unsigned int variable = 123;

    int res1 = s21_sprintf(buffer1, str3, variable);
    int res2 = sprintf(buffer2, str3, variable);

    ck_assert_str_eq(buffer1, buffer2);
    ck_assert_int_eq(res1, res2);

    //--------------------------------------------------- u
}
END_TEST

START_TEST(test_s21_sprintf_114_u) {
    char buffer1[4000] = {0};
    char buffer2[4000] = {0};
    char *str3 = "Значение - %#u";
    unsigned int variable = 123;

    int res1 = s21_sprintf(buffer1, str3, variable);
    int res2 = sprintf(buffer2, str3, variable);

    ck_assert_str_eq(buffer1, buffer2);
    ck_assert_int_eq(res1, res2);

    //--------------------------------------------------- u
}
END_TEST

START_TEST(test_s21_sprintf_115_u) {
    char buffer1[4000] = {0};
    char buffer2[4000] = {0};
    char *str3 = "Значение - %0u";
    unsigned int variable = 123;

    int res1 = s21_sprintf(buffer1, str3, variable);
    int res2 = sprintf(buffer2, str3, variable);

    ck_assert_str_eq(buffer1, buffer2);
    ck_assert_int_eq(res1, res2);

    //--------------------------------------------------- u
}
END_TEST

START_TEST(test_s21_sprintf_116_u) {
    char buffer1[4000] = {0};
    char buffer2[4000] = {0};
    char *str3 = "Значение - %15u";
    unsigned int variable = 123;

    int res1 = s21_sprintf(buffer1, str3, variable);
    int res2 = sprintf(buffer2, str3, variable);

    ck_assert_str_eq(buffer1, buffer2);
    ck_assert_int_eq(res1, res2);

    //--------------------------------------------------- u
}
END_TEST

START_TEST(test_s21_sprintf_117_u) {
    char buffer1[4000] = {0};
    char buffer2[4000] = {0};
    char *str3 = "Значение - %*u";
    unsigned int variable = 123;

    int res1 = s21_sprintf(buffer1, str3, 15, variable);
    int res2 = sprintf(buffer2, str3, 15, variable);

    ck_assert_str_eq(buffer1, buffer2);
    ck_assert_int_eq(res1, res2);

    //--------------------------------------------------- u
}
END_TEST

START_TEST(test_s21_sprintf_118_u) {
    char buffer1[4000] = {0};
    char buffer2[4000] = {0};
    char *str3 = "Значение - %.15u";
    unsigned int variable = 123;

    int res1 = s21_sprintf(buffer1, str3, variable);
    int res2 = sprintf(buffer2, str3, variable);

    ck_assert_str_eq(buffer1, buffer2);
    ck_assert_int_eq(res1, res2);

    //--------------------------------------------------- u
}
END_TEST

START_TEST(test_s21_sprintf_119_u) {
    char buffer1[4000] = {0};
    char buffer2[4000] = {0};
    char *str3 = "Значение - %.*u";
    unsigned int variable = 123;

    int res1 = s21_sprintf(buffer1, str3, 15, variable);
    int res2 = sprintf(buffer2, str3, 15, variable);

    ck_assert_str_eq(buffer1, buffer2);
    ck_assert_int_eq(res1, res2);

    //--------------------------------------------------- u
}
END_TEST

START_TEST(test_s21_sprintf_120_u) {
    char buffer1[4000] = {0};
    char buffer2[4000] = {0};
    char *str3 = "Значение - %1u";
    unsigned int variable = 123;

    int res1 = s21_sprintf(buffer1, str3, variable);
    int res2 = sprintf(buffer2, str3, variable);

    ck_assert_str_eq(buffer1, buffer2);
    ck_assert_int_eq(res1, res2);

    //--------------------------------------------------- u
}
END_TEST

START_TEST(test_s21_sprintf_121_u) {
    char buffer1[4000] = {0};
    char buffer2[4000] = {0};
    char *str3 = "Значение - %*u";
    unsigned int variable = 123;

    int res1 = s21_sprintf(buffer1, str3, 1, variable);
    int res2 = sprintf(buffer2, str3, 1, variable);

    ck_assert_str_eq(buffer1, buffer2);
    ck_assert_int_eq(res1, res2);

    //--------------------------------------------------- u
}
END_TEST

START_TEST(test_s21_sprintf_122_u) {
    char buffer1[4000] = {0};
    char buffer2[4000] = {0};
    char *str3 = "Значение - %.1u";
    unsigned int variable = 123;

    int res1 = s21_sprintf(buffer1, str3, variable);
    int res2 = sprintf(buffer2, str3, variable);

    ck_assert_str_eq(buffer1, buffer2);
    ck_assert_int_eq(res1, res2);

    //--------------------------------------------------- u
}
END_TEST

START_TEST(test_s21_sprintf_123_u) {
    char buffer1[4000] = {0};
    char buffer2[4000] = {0};
    char *str3 = "Значение - %.*u";
    unsigned int variable = 123;

    int res1 = s21_sprintf(buffer1, str3, 1, variable);
    int res2 = sprintf(buffer2, str3, 1, variable);

    ck_assert_str_eq(buffer1, buffer2);
    ck_assert_int_eq(res1, res2);

    //--------------------------------------------------- u
}
END_TEST

START_TEST(test_s21_sprintf_124_u) {
    char buffer1[4000] = {0};
    char buffer2[4000] = {0};
    char *str3 = "Значение - %0u";
    unsigned int variable = 123;

    int res1 = s21_sprintf(buffer1, str3, variable);
    int res2 = sprintf(buffer2, str3, variable);

    ck_assert_str_eq(buffer1, buffer2);
    ck_assert_int_eq(res1, res2);

    //--------------------------------------------------- u
}
END_TEST

START_TEST(test_s21_sprintf_125_u) {
    char buffer1[4000] = {0};
    char buffer2[4000] = {0};
    char *str3 = "Значение - %*u";
    unsigned int variable = 123;

    int res1 = s21_sprintf(buffer1, str3, 0, variable);
    int res2 = sprintf(buffer2, str3, 0, variable);

    ck_assert_str_eq(buffer1, buffer2);
    ck_assert_int_eq(res1, res2);

    //--------------------------------------------------- u
}
END_TEST

START_TEST(test_s21_sprintf_126_u) {
    char buffer1[4000] = {0};
    char buffer2[4000] = {0};
    char *str3 = "Значение - %.0u";
    unsigned int variable = 123;

    int res1 = s21_sprintf(buffer1, str3, variable);
    int res2 = sprintf(buffer2, str3, variable);

    ck_assert_str_eq(buffer1, buffer2);
    ck_assert_int_eq(res1, res2);

    //--------------------------------------------------- u
}
END_TEST

START_TEST(test_s21_sprintf_127_u) {
    char buffer1[4000] = {0};
    char buffer2[4000] = {0};
    char *str3 = "Значение - %.*u";
    unsigned int variable = 123;

    int res1 = s21_sprintf(buffer1, str3, 0, variable);
    int res2 = sprintf(buffer2, str3, 0, variable);

    ck_assert_str_eq(buffer1, buffer2);
    ck_assert_int_eq(res1, res2);

    //--------------------------------------------------- u
}
END_TEST

START_TEST(test_s21_sprintf_128_u) {
    char buffer1[4000] = {0};
    char buffer2[4000] = {0};
    char *str3 = "Значение - %-15u";
    unsigned int variable = 123;

    int res1 = s21_sprintf(buffer1, str3, variable);
    int res2 = sprintf(buffer2, str3, variable);

    ck_assert_str_eq(buffer1, buffer2);
    ck_assert_int_eq(res1, res2);

    //--------------------------------------------------- u
}
END_TEST

START_TEST(test_s21_sprintf_129_u) {
    char buffer1[4000] = {0};
    char buffer2[4000] = {0};
    char *str3 = "Значение - %*u";
    unsigned int variable = 123;

    int res1 = s21_sprintf(buffer1, str3, -15, variable);
    int res2 = sprintf(buffer2, str3, -15, variable);

    ck_assert_str_eq(buffer1, buffer2);
    ck_assert_int_eq(res1, res2);

    //--------------------------------------------------- u
}
END_TEST

START_TEST(test_s21_sprintf_130_u) {
    char buffer1[4000] = {0};
    char buffer2[4000] = {0};
    char *str3 = "Значение - %.*u";
    unsigned int variable = 123;

    int res1 = s21_sprintf(buffer1, str3, -15, variable);
    int res2 = sprintf(buffer2, str3, -15, variable);

    ck_assert_str_eq(buffer1, buffer2);
    ck_assert_int_eq(res1, res2);

    //--------------------------------------------------- u
}
END_TEST

START_TEST(test_s21_sprintf_131_u) {
    char buffer1[4000] = {0};
    char buffer2[4000] = {0};
    char *str3 = "Значение - %hu";
    unsigned short int variable = 123;

    int res1 = s21_sprintf(buffer1, str3, variable);
    int res2 = sprintf(buffer2, str3, variable);

    ck_assert_str_eq(buffer1, buffer2);
    ck_assert_int_eq(res1, res2);

    //--------------------------------------------------- u
}
END_TEST

START_TEST(test_s21_sprintf_132_u) {
    char buffer1[4000] = {0};
    char buffer2[4000] = {0};
    char *str3 = "Значение - %lu";
    unsigned long int variable = 123;

    int res1 = s21_sprintf(buffer1, str3, variable);
    int res2 = sprintf(buffer2, str3, variable);

    ck_assert_str_eq(buffer1, buffer2);
    ck_assert_int_eq(res1, res2);

    //--------------------------------------------------- x
    //--------------------------------------------------- x
    //--------------------------------------------------- x
    //--------------------------------------------------- x
}
END_TEST

START_TEST(test_s21_sprintf_133_x) {
    char buffer1[4000] = {0};
    char buffer2[4000] = {0};
    char *str3 = "Значение - %-x";
    int variable = 123;

    int res1 = s21_sprintf(buffer1, str3, variable);
    int res2 = sprintf(buffer2, str3, variable);

    ck_assert_str_eq(buffer1, buffer2);
    ck_assert_int_eq(res1, res2);

    //--------------------------------------------------- x
}
END_TEST

START_TEST(test_s21_sprintf_134_x) {
    char buffer1[4000] = {0};
    char buffer2[4000] = {0};
    char *str3 = "Значение - %+x";
    int variable = 123;

    int res1 = s21_sprintf(buffer1, str3, variable);
    int res2 = sprintf(buffer2, str3, variable);

    ck_assert_str_eq(buffer1, buffer2);
    ck_assert_int_eq(res1, res2);

    //--------------------------------------------------- x
}
END_TEST

START_TEST(test_s21_sprintf_135_x) {
    char buffer1[4000] = {0};
    char buffer2[4000] = {0};
    char *str3 = "Значение - % x";
    int variable = 123;

    int res1 = s21_sprintf(buffer1, str3, variable);
    int res2 = sprintf(buffer2, str3, variable);

    ck_assert_str_eq(buffer1, buffer2);
    ck_assert_int_eq(res1, res2);

    //--------------------------------------------------- x
}
END_TEST

START_TEST(test_s21_sprintf_136_x) {
    char buffer1[4000] = {0};
    char buffer2[4000] = {0};
    char *str3 = "Значение - %#x";
    int variable = 123;

    int res1 = s21_sprintf(buffer1, str3, variable);
    int res2 = sprintf(buffer2, str3, variable);

    ck_assert_str_eq(buffer1, buffer2);
    ck_assert_int_eq(res1, res2);

    //--------------------------------------------------- x
}
END_TEST

START_TEST(test_s21_sprintf_137_x) {
    char buffer1[4000] = {0};
    char buffer2[4000] = {0};
    char *str3 = "Значение - %0x";
    int variable = 123;

    int res1 = s21_sprintf(buffer1, str3, variable);
    int res2 = sprintf(buffer2, str3, variable);

    ck_assert_str_eq(buffer1, buffer2);
    ck_assert_int_eq(res1, res2);

    //--------------------------------------------------- x
}
END_TEST

START_TEST(test_s21_sprintf_138_x) {
    char buffer1[4000] = {0};
    char buffer2[4000] = {0};
    char *str3 = "Значение - %15x";
    int variable = 123;

    int res1 = s21_sprintf(buffer1, str3, variable);
    int res2 = sprintf(buffer2, str3, variable);

    ck_assert_str_eq(buffer1, buffer2);
    ck_assert_int_eq(res1, res2);

    //--------------------------------------------------- x
}
END_TEST

START_TEST(test_s21_sprintf_139_x) {
    char buffer1[4000] = {0};
    char buffer2[4000] = {0};
    char *str3 = "Значение - %*x";
    int variable = 123;

    int res1 = s21_sprintf(buffer1, str3, 15, variable);
    int res2 = sprintf(buffer2, str3, 15, variable);

    ck_assert_str_eq(buffer1, buffer2);
    ck_assert_int_eq(res1, res2);

    //--------------------------------------------------- x
}
END_TEST

START_TEST(test_s21_sprintf_140_x) {
    char buffer1[4000] = {0};
    char buffer2[4000] = {0};
    char *str3 = "Значение - %.1x";
    int variable = 123;

    int res1 = s21_sprintf(buffer1, str3, variable);
    int res2 = sprintf(buffer2, str3, variable);

    ck_assert_str_eq(buffer1, buffer2);
    ck_assert_int_eq(res1, res2);

    //--------------------------------------------------- x
}
END_TEST

START_TEST(test_s21_sprintf_141_x) {
    char buffer1[4000] = {0};
    char buffer2[4000] = {0};
    char *str3 = "Значение - %.*x";
    int variable = 123;

    int res1 = s21_sprintf(buffer1, str3, 1, variable);
    int res2 = sprintf(buffer2, str3, 1, variable);

    ck_assert_str_eq(buffer1, buffer2);
    ck_assert_int_eq(res1, res2);

    //--------------------------------------------------- x
}
END_TEST

START_TEST(test_s21_sprintf_142_x) {
    char buffer1[4000] = {0};
    char buffer2[4000] = {0};
    char *str3 = "Значение - %1x";
    int variable = 123;

    int res1 = s21_sprintf(buffer1, str3, variable);
    int res2 = sprintf(buffer2, str3, variable);

    ck_assert_str_eq(buffer1, buffer2);
    ck_assert_int_eq(res1, res2);

    //--------------------------------------------------- x
}
END_TEST

START_TEST(test_s21_sprintf_143_x) {
    char buffer1[4000] = {0};
    char buffer2[4000] = {0};
    char *str3 = "Значение - %*x";
    int variable = 123;

    int res1 = s21_sprintf(buffer1, str3, 1, variable);
    int res2 = sprintf(buffer2, str3, 1, variable);

    ck_assert_str_eq(buffer1, buffer2);
    ck_assert_int_eq(res1, res2);

    //--------------------------------------------------- x
}
END_TEST

START_TEST(test_s21_sprintf_144_x) {
    char buffer1[4000] = {0};
    char buffer2[4000] = {0};
    char *str3 = "Значение - %0x";
    int variable = 123;

    int res1 = s21_sprintf(buffer1, str3, variable);
    int res2 = sprintf(buffer2, str3, variable);

    ck_assert_str_eq(buffer1, buffer2);
    ck_assert_int_eq(res1, res2);

    //--------------------------------------------------- x
}
END_TEST

START_TEST(test_s21_sprintf_145_x) {
    char buffer1[4000] = {0};
    char buffer2[4000] = {0};
    char *str3 = "Значение - %*x";
    int variable = 123;

    int res1 = s21_sprintf(buffer1, str3, 0, variable);
    int res2 = sprintf(buffer2, str3, 0, variable);

    ck_assert_str_eq(buffer1, buffer2);
    ck_assert_int_eq(res1, res2);

    //--------------------------------------------------- x
}
END_TEST

START_TEST(test_s21_sprintf_146_x) {
    char buffer1[4000] = {0};
    char buffer2[4000] = {0};
    char *str3 = "Значение - %.0x";
    int variable = 123;

    int res1 = s21_sprintf(buffer1, str3, variable);
    int res2 = sprintf(buffer2, str3, variable);

    ck_assert_str_eq(buffer1, buffer2);
    ck_assert_int_eq(res1, res2);

    //--------------------------------------------------- x
}
END_TEST

START_TEST(test_s21_sprintf_147_x) {
    char buffer1[4000] = {0};
    char buffer2[4000] = {0};
    char *str3 = "Значение - %.*x";
    int variable = 123;

    int res1 = s21_sprintf(buffer1, str3, 0, variable);
    int res2 = sprintf(buffer2, str3, 0, variable);

    ck_assert_str_eq(buffer1, buffer2);
    ck_assert_int_eq(res1, res2);

    //--------------------------------------------------- x
}
END_TEST

START_TEST(test_s21_sprintf_148_x) {
    char buffer1[4000] = {0};
    char buffer2[4000] = {0};
    char *str3 = "Значение - %-15x";
    int variable = 123;

    int res1 = s21_sprintf(buffer1, str3, variable);
    int res2 = sprintf(buffer2, str3, variable);

    ck_assert_str_eq(buffer1, buffer2);
    ck_assert_int_eq(res1, res2);

    //--------------------------------------------------- x
}
END_TEST

START_TEST(test_s21_sprintf_149_x) {
    char buffer1[4000] = {0};
    char buffer2[4000] = {0};
    char *str3 = "Значение - %*x";
    int variable = 123;

    int res1 = s21_sprintf(buffer1, str3, -15, variable);
    int res2 = sprintf(buffer2, str3, -15, variable);

    ck_assert_str_eq(buffer1, buffer2);
    ck_assert_int_eq(res1, res2);

    //--------------------------------------------------- x
}
END_TEST

START_TEST(test_s21_sprintf_150_x) {
    char buffer1[4000] = {0};
    char buffer2[4000] = {0};
    char *str3 = "Значение - %hx";
    unsigned short variable = 12;

    int res1 = s21_sprintf(buffer1, str3, variable);
    int res2 = sprintf(buffer2, str3, variable);

    ck_assert_str_eq(buffer1, buffer2);
    ck_assert_int_eq(res1, res2);

    //--------------------------------------------------- x
}
END_TEST

START_TEST(test_s21_sprintf_151_x) {
    char buffer1[4000] = {0};
    char buffer2[4000] = {0};
    char *str3 = "Значение - %lx";
    long int variable = 123;

    int res1 = s21_sprintf(buffer1, str3, variable);
    int res2 = sprintf(buffer2, str3, variable);

    ck_assert_str_eq(buffer1, buffer2);
    ck_assert_int_eq(res1, res2);

    //--------------------------------------------------- X
    //--------------------------------------------------- X
    //--------------------------------------------------- X
    //--------------------------------------------------- X
}
END_TEST

START_TEST(test_s21_sprintf_152_X) {
    char buffer1[4000] = {0};
    char buffer2[4000] = {0};
    char *str3 = "Значение - %-X";
    int variable = 123;

    int res1 = s21_sprintf(buffer1, str3, variable);
    int res2 = sprintf(buffer2, str3, variable);

    ck_assert_str_eq(buffer1, buffer2);
    ck_assert_int_eq(res1, res2);

    //--------------------------------------------------- x
}
END_TEST

START_TEST(test_s21_sprintf_153_X) {
    char buffer1[4000] = {0};
    char buffer2[4000] = {0};
    char *str3 = "Значение - %+X";
    int variable = 123;

    int res1 = s21_sprintf(buffer1, str3, variable);
    int res2 = sprintf(buffer2, str3, variable);

    ck_assert_str_eq(buffer1, buffer2);
    ck_assert_int_eq(res1, res2);

    //--------------------------------------------------- x
}
END_TEST

START_TEST(test_s21_sprintf_154_X) {
    char buffer1[4000] = {0};
    char buffer2[4000] = {0};
    char *str3 = "Значение - % X";
    int variable = 123;

    int res1 = s21_sprintf(buffer1, str3, variable);
    int res2 = sprintf(buffer2, str3, variable);

    ck_assert_str_eq(buffer1, buffer2);
    ck_assert_int_eq(res1, res2);

    //--------------------------------------------------- x
}
END_TEST

START_TEST(test_s21_sprintf_155_X) {
    char buffer1[4000] = {0};
    char buffer2[4000] = {0};
    char *str3 = "Значение - %#X";
    int variable = 123;

    int res1 = s21_sprintf(buffer1, str3, variable);
    int res2 = sprintf(buffer2, str3, variable);

    ck_assert_str_eq(buffer1, buffer2);
    ck_assert_int_eq(res1, res2);

    //--------------------------------------------------- x
}
END_TEST

START_TEST(test_s21_sprintf_156_X) {
    char buffer1[4000] = {0};
    char buffer2[4000] = {0};
    char *str3 = "Значение - %0X";
    int variable = 123;

    int res1 = s21_sprintf(buffer1, str3, variable);
    int res2 = sprintf(buffer2, str3, variable);

    ck_assert_str_eq(buffer1, buffer2);
    ck_assert_int_eq(res1, res2);

    //--------------------------------------------------- x
}
END_TEST

START_TEST(test_s21_sprintf_157_X) {
    char buffer1[4000] = {0};
    char buffer2[4000] = {0};
    char *str3 = "Значение - %15X";
    int variable = 123;

    int res1 = s21_sprintf(buffer1, str3, variable);
    int res2 = sprintf(buffer2, str3, variable);

    ck_assert_str_eq(buffer1, buffer2);
    ck_assert_int_eq(res1, res2);

    //--------------------------------------------------- x
}
END_TEST

START_TEST(test_s21_sprintf_158_X) {
    char buffer1[4000] = {0};
    char buffer2[4000] = {0};
    char *str3 = "Значение - %*X";
    int variable = 123;

    int res1 = s21_sprintf(buffer1, str3, 15, variable);
    int res2 = sprintf(buffer2, str3, 15, variable);

    ck_assert_str_eq(buffer1, buffer2);
    ck_assert_int_eq(res1, res2);

    //--------------------------------------------------- x
}
END_TEST

START_TEST(test_s21_sprintf_159_X) {
    char buffer1[4000] = {0};
    char buffer2[4000] = {0};
    char *str3 = "Значение - %.1X";
    int variable = 123;

    int res1 = s21_sprintf(buffer1, str3, variable);
    int res2 = sprintf(buffer2, str3, variable);

    ck_assert_str_eq(buffer1, buffer2);
    ck_assert_int_eq(res1, res2);

    //--------------------------------------------------- x
}
END_TEST

START_TEST(test_s21_sprintf_160_X) {
    char buffer1[4000] = {0};
    char buffer2[4000] = {0};
    char *str3 = "Значение - %.*X";
    int variable = 123;

    int res1 = s21_sprintf(buffer1, str3, 1, variable);
    int res2 = sprintf(buffer2, str3, 1, variable);

    ck_assert_str_eq(buffer1, buffer2);
    ck_assert_int_eq(res1, res2);

    //--------------------------------------------------- x
}
END_TEST

START_TEST(test_s21_sprintf_161_X) {
    char buffer1[4000] = {0};
    char buffer2[4000] = {0};
    char *str3 = "Значение - %1X";
    int variable = 123;

    int res1 = s21_sprintf(buffer1, str3, variable);
    int res2 = sprintf(buffer2, str3, variable);

    ck_assert_str_eq(buffer1, buffer2);
    ck_assert_int_eq(res1, res2);

    //--------------------------------------------------- x
}
END_TEST

START_TEST(test_s21_sprintf_162_X) {
    char buffer1[4000] = {0};
    char buffer2[4000] = {0};
    char *str3 = "Значение - %*X";
    int variable = 123;

    int res1 = s21_sprintf(buffer1, str3, 1, variable);
    int res2 = sprintf(buffer2, str3, 1, variable);

    ck_assert_str_eq(buffer1, buffer2);
    ck_assert_int_eq(res1, res2);

    //--------------------------------------------------- x
}
END_TEST

START_TEST(test_s21_sprintf_163_X) {
    char buffer1[4000] = {0};
    char buffer2[4000] = {0};
    char *str3 = "Значение - %0X";
    int variable = 123;

    int res1 = s21_sprintf(buffer1, str3, variable);
    int res2 = sprintf(buffer2, str3, variable);

    ck_assert_str_eq(buffer1, buffer2);
    ck_assert_int_eq(res1, res2);

    //--------------------------------------------------- x
}
END_TEST

START_TEST(test_s21_sprintf_164_X) {
    char buffer1[4000] = {0};
    char buffer2[4000] = {0};
    char *str3 = "Значение - %*X";
    int variable = 123;

    int res1 = s21_sprintf(buffer1, str3, 0, variable);
    int res2 = sprintf(buffer2, str3, 0, variable);

    ck_assert_str_eq(buffer1, buffer2);
    ck_assert_int_eq(res1, res2);

    //--------------------------------------------------- x
}
END_TEST

START_TEST(test_s21_sprintf_165_X) {
    char buffer1[4000] = {0};
    char buffer2[4000] = {0};
    char *str3 = "Значение - %.0X";
    int variable = 123;

    int res1 = s21_sprintf(buffer1, str3, variable);
    int res2 = sprintf(buffer2, str3, variable);

    ck_assert_str_eq(buffer1, buffer2);
    ck_assert_int_eq(res1, res2);

    //--------------------------------------------------- x
}
END_TEST

START_TEST(test_s21_sprintf_166_X) {
    char buffer1[4000] = {0};
    char buffer2[4000] = {0};
    char *str3 = "Значение - %.*X";
    int variable = 123;

    int res1 = s21_sprintf(buffer1, str3, 0, variable);
    int res2 = sprintf(buffer2, str3, 0, variable);

    ck_assert_str_eq(buffer1, buffer2);
    ck_assert_int_eq(res1, res2);

    //--------------------------------------------------- x
}
END_TEST

START_TEST(test_s21_sprintf_167_X) {
    char buffer1[4000] = {0};
    char buffer2[4000] = {0};
    char *str3 = "Значение - %-15X";
    int variable = 123;

    int res1 = s21_sprintf(buffer1, str3, variable);
    int res2 = sprintf(buffer2, str3, variable);

    ck_assert_str_eq(buffer1, buffer2);
    ck_assert_int_eq(res1, res2);

    //--------------------------------------------------- x
}
END_TEST

START_TEST(test_s21_sprintf_168_X) {
    char buffer1[4000] = {0};
    char buffer2[4000] = {0};
    char *str3 = "Значение - %*X";
    int variable = 123;

    int res1 = s21_sprintf(buffer1, str3, -15, variable);
    int res2 = sprintf(buffer2, str3, -15, variable);

    ck_assert_str_eq(buffer1, buffer2);
    ck_assert_int_eq(res1, res2);

    //--------------------------------------------------- x
}
END_TEST

START_TEST(test_s21_sprintf_169_X) {
    char buffer1[4000] = {0};
    char buffer2[4000] = {0};
    char *str3 = "Значение - %hX";
    unsigned short variable = 12;

    int res1 = s21_sprintf(buffer1, str3, variable);
    int res2 = sprintf(buffer2, str3, variable);

    ck_assert_str_eq(buffer1, buffer2);
    ck_assert_int_eq(res1, res2);

    //--------------------------------------------------- x
}
END_TEST

START_TEST(test_s21_sprintf_170_X) {
    char buffer1[4000] = {0};
    char buffer2[4000] = {0};
    char *str3 = "Значение - %lx";
    int variable = 123;

    int res1 = s21_sprintf(buffer1, str3, variable);
    int res2 = sprintf(buffer2, str3, variable);

    ck_assert_str_eq(buffer1, buffer2);
    ck_assert_int_eq(res1, res2);

    //--------------------------------------------------- p
    //--------------------------------------------------- p
    //--------------------------------------------------- p
    //--------------------------------------------------- p
}
END_TEST

START_TEST(test_s21_sprintf_171_p) {
    char buffer1[4000] = {0};
    char buffer2[4000] = {0};
    char *str3 = "Значение - %-p";
    int variable = 123;

    int res1 = s21_sprintf(buffer1, str3, &variable);
    int res2 = sprintf(buffer2, str3, &variable);

    ck_assert_str_eq(buffer1, buffer2);
    ck_assert_int_eq(res1, res2);

    //--------------------------------------------------- p
}
END_TEST

START_TEST(test_s21_sprintf_172_p) {
    char buffer1[4000] = {0};
    char buffer2[4000] = {0};
    char *str3 = "Значение - %+p";
    int variable = 123;

    int res1 = s21_sprintf(buffer1, str3, &variable);
    int res2 = sprintf(buffer2, str3, &variable);

    ck_assert_str_eq(buffer1, buffer2);
    ck_assert_int_eq(res1, res2);

    //--------------------------------------------------- p
}
END_TEST

START_TEST(test_s21_sprintf_173_p) {
    char buffer1[4000] = {0};
    char buffer2[4000] = {0};
    char *str3 = "Значение - % p";
    int variable = 123;

    int res1 = s21_sprintf(buffer1, str3, &variable);
    int res2 = sprintf(buffer2, str3, &variable);

    ck_assert_str_eq(buffer1, buffer2);
    ck_assert_int_eq(res1, res2);

    //--------------------------------------------------- p
}
END_TEST

START_TEST(test_s21_sprintf_174_p) {
    char buffer1[4000] = {0};
    char buffer2[4000] = {0};
    char *str3 = "Значение - %#p";
    int variable = 123;

    int res1 = s21_sprintf(buffer1, str3, &variable);
    int res2 = sprintf(buffer2, str3, &variable);

    ck_assert_str_eq(buffer1, buffer2);
    ck_assert_int_eq(res1, res2);

    //--------------------------------------------------- p
}
END_TEST

START_TEST(test_s21_sprintf_175_p) {
    char buffer1[4000] = {0};
    char buffer2[4000] = {0};
    char *str3 = "Значение - %0p";
    int variable = 123;

    int res1 = s21_sprintf(buffer1, str3, &variable);
    int res2 = sprintf(buffer2, str3, &variable);

    ck_assert_str_eq(buffer1, buffer2);
    ck_assert_int_eq(res1, res2);

    //--------------------------------------------------- p
}
END_TEST

START_TEST(test_s21_sprintf_176_p) {
    char buffer1[4000] = {0};
    char buffer2[4000] = {0};
    char *str3 = "Значение - %15p";
    int variable = 123;

    int res1 = s21_sprintf(buffer1, str3, &variable);
    int res2 = sprintf(buffer2, str3, &variable);

    ck_assert_str_eq(buffer1, buffer2);
    ck_assert_int_eq(res1, res2);

    //--------------------------------------------------- p
}
END_TEST

START_TEST(test_s21_sprintf_177_p) {
    char buffer1[4000] = {0};
    char buffer2[4000] = {0};
    char *str3 = "Значение - %*p";
    int variable = 123;

    int res1 = s21_sprintf(buffer1, str3, 15, &variable);
    int res2 = sprintf(buffer2, str3, 15, &variable);

    ck_assert_str_eq(buffer1, buffer2);
    ck_assert_int_eq(res1, res2);

    //--------------------------------------------------- p
}
END_TEST

START_TEST(test_s21_sprintf_178_p) {
    char buffer1[4000] = {0};
    char buffer2[4000] = {0};
    char *str3 = "Значение - %.15p";
    int variable = 123;

    int res1 = s21_sprintf(buffer1, str3, &variable);
    int res2 = sprintf(buffer2, str3, &variable);

    ck_assert_str_eq(buffer1, buffer2);
    ck_assert_int_eq(res1, res2);

    //--------------------------------------------------- p
}
END_TEST

START_TEST(test_s21_sprintf_179_p) {
    char buffer1[4000] = {0};
    char buffer2[4000] = {0};
    char *str3 = "Значение - %.*p";
    int variable = 123;

    int res1 = s21_sprintf(buffer1, str3, 15, &variable);
    int res2 = sprintf(buffer2, str3, 15, &variable);

    ck_assert_str_eq(buffer1, buffer2);
    ck_assert_int_eq(res1, res2);

    //--------------------------------------------------- p
}
END_TEST

START_TEST(test_s21_sprintf_180_p) {
    char buffer1[4000] = {0};
    char buffer2[4000] = {0};
    char *str3 = "Значение - %1p";
    int variable = 123;

    int res1 = s21_sprintf(buffer1, str3, &variable);
    int res2 = sprintf(buffer2, str3, &variable);

    ck_assert_str_eq(buffer1, buffer2);
    ck_assert_int_eq(res1, res2);

    //--------------------------------------------------- p
}
END_TEST

START_TEST(test_s21_sprintf_181_p) {
    char buffer1[4000] = {0};
    char buffer2[4000] = {0};
    char *str3 = "Значение - %*p";
    int variable = 123;

    int res1 = s21_sprintf(buffer1, str3, 1, &variable);
    int res2 = sprintf(buffer2, str3, 1, &variable);

    ck_assert_str_eq(buffer1, buffer2);
    ck_assert_int_eq(res1, res2);

    //--------------------------------------------------- p
}
END_TEST

START_TEST(test_s21_sprintf_182_p) {
    char buffer1[4000] = {0};
    char buffer2[4000] = {0};
    char *str3 = "Значение - %.1p";
    int variable = 123;

    int res1 = s21_sprintf(buffer1, str3, &variable);
    int res2 = sprintf(buffer2, str3, &variable);

    ck_assert_str_eq(buffer1, buffer2);
    ck_assert_int_eq(res1, res2);

    //--------------------------------------------------- p
}
END_TEST

START_TEST(test_s21_sprintf_183_p) {
    char buffer1[4000] = {0};
    char buffer2[4000] = {0};
    char *str3 = "Значение - %.*p";
    int variable = 123;

    int res1 = s21_sprintf(buffer1, str3, 1, &variable);
    int res2 = sprintf(buffer2, str3, 1, &variable);

    ck_assert_str_eq(buffer1, buffer2);
    ck_assert_int_eq(res1, res2);

    //--------------------------------------------------- p
}
END_TEST

START_TEST(test_s21_sprintf_184_p) {
    char buffer1[4000] = {0};
    char buffer2[4000] = {0};
    char *str3 = "Значение - %0p";
    int variable = 123;

    int res1 = s21_sprintf(buffer1, str3, &variable);
    int res2 = sprintf(buffer2, str3, &variable);

    ck_assert_str_eq(buffer1, buffer2);
    ck_assert_int_eq(res1, res2);

    //--------------------------------------------------- p
}
END_TEST

START_TEST(test_s21_sprintf_185_p) {
    char buffer1[4000] = {0};
    char buffer2[4000] = {0};
    char *str3 = "Значение - %*p";
    int variable = 123;

    int res1 = s21_sprintf(buffer1, str3, 0, &variable);
    int res2 = sprintf(buffer2, str3, 0, &variable);

    ck_assert_str_eq(buffer1, buffer2);
    ck_assert_int_eq(res1, res2);

    //--------------------------------------------------- p
}
END_TEST

START_TEST(test_s21_sprintf_186_p) {
    char buffer1[4000] = {0};
    char buffer2[4000] = {0};
    char *str3 = "Значение - %.0p";
    int variable = 123;

    int res1 = s21_sprintf(buffer1, str3, &variable);
    int res2 = sprintf(buffer2, str3, &variable);

    ck_assert_str_eq(buffer1, buffer2);
    ck_assert_int_eq(res1, res2);

    //--------------------------------------------------- p
}
END_TEST

START_TEST(test_s21_sprintf_187_p) {
    char buffer1[4000] = {0};
    char buffer2[4000] = {0};
    char *str3 = "Значение - %.*p";
    int variable = 123;

    int res1 = s21_sprintf(buffer1, str3, 0, &variable);
    int res2 = sprintf(buffer2, str3, 0, &variable);

    ck_assert_str_eq(buffer1, buffer2);
    ck_assert_int_eq(res1, res2);

    //--------------------------------------------------- p
}
END_TEST

START_TEST(test_s21_sprintf_188_p) {
    char buffer1[4000] = {0};
    char buffer2[4000] = {0};
    char *str3 = "Значение - %-15p";
    int variable = 123;

    int res1 = s21_sprintf(buffer1, str3, &variable);
    int res2 = sprintf(buffer2, str3, &variable);

    ck_assert_str_eq(buffer1, buffer2);
    ck_assert_int_eq(res1, res2);

    //--------------------------------------------------- p
}
END_TEST

START_TEST(test_s21_sprintf_189_p) {
    char buffer1[4000] = {0};
    char buffer2[4000] = {0};
    char *str3 = "Значение - %*p";
    int variable = 123;

    int res1 = s21_sprintf(buffer1, str3, -15, &variable);
    int res2 = sprintf(buffer2, str3, -15, &variable);

    ck_assert_str_eq(buffer1, buffer2);
    ck_assert_int_eq(res1, res2);

    //--------------------------------------------------- p
}
END_TEST

START_TEST(test_s21_sprintf_190_p) {
    char buffer1[4000] = {0};
    char buffer2[4000] = {0};
    char *str3 = "Значение - %.*p";
    int variable = 123;

    int res1 = s21_sprintf(buffer1, str3, -15, &variable);
    int res2 = sprintf(buffer2, str3, -15, &variable);

    ck_assert_str_eq(buffer1, buffer2);
    ck_assert_int_eq(res1, res2);

    //--------------------------------------------------- n
    //--------------------------------------------------- n
    //--------------------------------------------------- n
    //--------------------------------------------------- n
}
END_TEST

START_TEST(test_s21_sprintf_191) {
    char buffer1[4000] = {0};
    char buffer2[4000] = {0};
    char *str3 = "Значение - %c - %d - %f - %o - %s - %u - %x - %X - %p";
    int variable_1 = 0;
    int variable_2 = 0;
    char variable_3 = 'q';
    unsigned int spec_u = 123;

    int res1 = s21_sprintf(buffer1, str3, variable_3, 123, 123.25, 255,
                           "Stroka", spec_u, 255, 255, &variable_1);
    int res2 = sprintf(buffer2, str3, variable_3, 123, 123.25, 255, "Stroka",
                       spec_u, 255, 255, &variable_1);
    ck_assert_str_eq(buffer1, buffer2);
    ck_assert_int_eq(res1, res2);
    ck_assert_int_eq(variable_1, variable_2);

    //---------------------------------------------------
}
END_TEST

START_TEST(test_s21_sprintf_192) {
    char buffer1[4000] = {0};
    char buffer2[4000] = {0};
    char *str3 =
        "Значение - %5c - %5d - %5f - %5o - %5s - %5u - %5x - %5X - %5p";
    int variable_1 = 0;
    int variable_2 = 0;
    char variable_3 = 'q';
    unsigned int spec_u = 123;

    int res1 = s21_sprintf(buffer1, str3, variable_3, 123, 123.25, 255,
                           "Stroka", spec_u, 255, 255, &variable_1);
    int res2 = sprintf(buffer2, str3, variable_3, 123, 123.25, 255, "Stroka",
                       spec_u, 255, 255, &variable_1);
    ck_assert_str_eq(buffer1, buffer2);
    ck_assert_int_eq(res1, res2);
    ck_assert_int_eq(variable_1, variable_2);

    //---------------------------------------------------
}
END_TEST

START_TEST(test_s21_sprintf_193) {
    char buffer1[4000] = {0};
    char buffer2[4000] = {0};
    char *str3 =
        "Значение - %.5c - %.5d - %.5f - %.5o - %.5s - %.5u - %.5x - %.5X "
        "- %.5p";
    int variable_1 = 5;
    char variable_3 = 'q';
    unsigned int spec_u = 123;

    int res1 = s21_sprintf(buffer1, str3, variable_3, 123, 123.25, 255,
                           "Stroka", spec_u, 255, 255, &variable_1);
    int res2 = sprintf(buffer2, str3, variable_3, 123, 123.25, 255, "Stroka",
                       spec_u, 255, 255, &variable_1);
    ck_assert_str_eq(buffer1, buffer2);
    ck_assert_int_eq(res1, res2);

    //---------------------------------------------------
}
END_TEST

START_TEST(test_s21_sprintf_194) {
    char buffer1[4000] = {0};
    char buffer2[4000] = {0};
    char *str3 =
        "Значение - %-5c - %-5d - %-5f - %-5o - %-5s - %-5u - %-5x - %-5X "
        "- %-5p";
    int variable_1 = 0;
    int variable_2 = 0;
    char variable_3 = 'q';
    unsigned int spec_u = 123;

    int res1 = s21_sprintf(buffer1, str3, variable_3, 123, 123.25, 255,
                           "Stroka", spec_u, 255, 255, &variable_1);
    int res2 = sprintf(buffer2, str3, variable_3, 123, 123.25, 255, "Stroka",
                       spec_u, 255, 255, &variable_1);
    ck_assert_str_eq(buffer1, buffer2);
    ck_assert_int_eq(res1, res2);
    ck_assert_int_eq(variable_1, variable_2);
}
END_TEST

START_TEST(test_s21_sprintf_195) {
    char buffer1[4000] = {0};
    char buffer2[4000] = {0};
    char *str = "Значение - %g %e %g %e";
    double var = 12345678.9;
    double var1 = 0.00000345;

    int res1 = s21_sprintf(buffer1, str, var, var, var1, var1);
    int res2 = sprintf(buffer2, str, var, var, var1, var1);

    ck_assert_int_eq(res1, res2);
    ck_assert_str_eq(buffer1, buffer2);
}
END_TEST

START_TEST(test_s21_sprintf_196) {
    char buffer1[4000] = {0};
    char buffer2[4000] = {0};
    char *str = "Значение - %#g %#e %#g %#e";
    double var = 12345678.9;
    double var1 = 0.00000345;

    int res1 = s21_sprintf(buffer1, str, var, var, var1, var1);
    int res2 = sprintf(buffer2, str, var, var, var1, var1);

    ck_assert_int_eq(res1, res2);
    ck_assert_str_eq(buffer1, buffer2);
}
END_TEST

START_TEST(test_s21_sprintf_197) {
    char buffer1[4000] = {0};
    char buffer2[4000] = {0};
    char *str = "Значение - %#+.5g %#.5e %#.5g %#.5e";
    double var = 12345678.9;
    double var1 = 0.00000345;

    int res1 = s21_sprintf(buffer1, str, var, var, var1, var1);
    int res2 = sprintf(buffer2, str, var, var, var1, var1);

    ck_assert_int_eq(res1, res2);
    ck_assert_str_eq(buffer1, buffer2);
}
END_TEST

START_TEST(test_s21_sprintf_198) {
    char buffer1[4000] = {0};
    char buffer2[4000] = {0};
    char *str = "Значение - %+0#10.5g %+0#10.5e %+0#10.5g %+0#10.5e";
    double var = 12345678.9;
    double var1 = 0.00000345;

    int res1 = s21_sprintf(buffer1, str, var, var, var1, var1);
    int res2 = sprintf(buffer2, str, var, var, var1, var1);

    ck_assert_int_eq(res1, res2);
    ck_assert_str_eq(buffer1, buffer2);
}
END_TEST

START_TEST(test_s21_sprintf_199) {
    char buffer1[4000] = {0};
    char buffer2[4000] = {0};
    char *str = "Значение - %+0-#10.4g %+0-#10.4e %+0-#10.4g %+0-#10.4e";
    double var = 12345678.9;
    double var1 = 0.00000345;

    int res1 = s21_sprintf(buffer1, str, var, var, var1, var1);
    int res2 = sprintf(buffer2, str, var, var, var1, var1);

    ck_assert_int_eq(res1, res2);
    ck_assert_str_eq(buffer1, buffer2);
}
END_TEST

START_TEST(test_s21_sprintf_200) {
    char buffer1[4000] = {0};
    char buffer2[4000] = {0};
    char *str = "%% %d";

    int res1 = s21_sprintf(buffer1, str, 5);
    int res2 = sprintf(buffer2, str, 5);

    ck_assert_int_eq(res1, res2);
    ck_assert_str_eq(buffer1, buffer2);
}
END_TEST

START_TEST(test_s21_sprintf_201) {
    char buffer1[4000] = {0};
    char buffer2[4000] = {0};
    char *str = "Значение - %+0-#10g %+0-#10e %+0-#10g %+0-#10e";
    double var = 12.233;
    double var1 = 0.453;

    int res1 = s21_sprintf(buffer1, str, var, var, var1, var1);
    int res2 = sprintf(buffer2, str, var, var, var1, var1);

    ck_assert_int_eq(res1, res2);
    ck_assert_str_eq(buffer1, buffer2);
}
END_TEST

START_TEST(test_s21_sprintf_202) {
    char buffer1[4000] = {0};
    char buffer2[4000] = {0};
    char *str = "Значение - %g";
    double var = 25.0;

    int res1 = s21_sprintf(buffer1, str, var);
    int res2 = sprintf(buffer2, str, var);

    ck_assert_int_eq(res1, res2);
    ck_assert_str_eq(buffer1, buffer2);
}
END_TEST

START_TEST(test_s21_sprintf_203) {
    char buffer1[4000] = {0};
    char buffer2[4000] = {0};
    char *str = "Значение - %Lf";
    double var = 1.2;

    int res1 = s21_sprintf(buffer1, str, var);
    int res2 = sprintf(buffer2, str, var);

    ck_assert_int_eq(res1, res2);
    ck_assert_str_eq(buffer1, buffer2);
}
END_TEST

TCase *tcase_s21sprintf(void) {
    TCase *tcase = tcase_create("s21sprintf");

    tcase_add_test(tcase, test_s21_sprintf_1);
    tcase_add_test(tcase, test_s21_sprintf_2);
    tcase_add_test(tcase, test_s21_sprintf_3);
    tcase_add_test(tcase, test_s21_sprintf_4);
    tcase_add_test(tcase, test_s21_sprintf_5);
    tcase_add_test(tcase, test_s21_sprintf_6);
    tcase_add_test(tcase, test_s21_sprintf_7);
    tcase_add_test(tcase, test_s21_sprintf_8);
    tcase_add_test(tcase, test_s21_sprintf_9);
    tcase_add_test(tcase, test_s21_sprintf_10);
    tcase_add_test(tcase, test_s21_sprintf_11);
    tcase_add_test(tcase, test_s21_sprintf_12_c);
    tcase_add_test(tcase, test_s21_sprintf_13_c);
    tcase_add_test(tcase, test_s21_sprintf_14_c);
    tcase_add_test(tcase, test_s21_sprintf_15_c);
    tcase_add_test(tcase, test_s21_sprintf_16_c);
    tcase_add_test(tcase, test_s21_sprintf_17_c);
    tcase_add_test(tcase, test_s21_sprintf_18_c);
    tcase_add_test(tcase, test_s21_sprintf_19_c);
    tcase_add_test(tcase, test_s21_sprintf_20_c);
    tcase_add_test(tcase, test_s21_sprintf_21_c);
    tcase_add_test(tcase, test_s21_sprintf_22_c);
    tcase_add_test(tcase, test_s21_sprintf_23_c);
    tcase_add_test(tcase, test_s21_sprintf_24_c);
    tcase_add_test(tcase, test_s21_sprintf_25_c);
    tcase_add_test(tcase, test_s21_sprintf_26_c);
    tcase_add_test(tcase, test_s21_sprintf_27_c);
    tcase_add_test(tcase, test_s21_sprintf_28_c);
    tcase_add_test(tcase, test_s21_sprintf_29_c);
    tcase_add_test(tcase, test_s21_sprintf_30_c);
    tcase_add_test(tcase, test_s21_sprintf_31_c);
    tcase_add_test(tcase, test_s21_sprintf_32_c);
    tcase_add_test(tcase, test_s21_sprintf_33_d);
    tcase_add_test(tcase, test_s21_sprintf_34_d);
    tcase_add_test(tcase, test_s21_sprintf_35_d);
    tcase_add_test(tcase, test_s21_sprintf_36_d);
    tcase_add_test(tcase, test_s21_sprintf_37_d);
    tcase_add_test(tcase, test_s21_sprintf_38_d);
    tcase_add_test(tcase, test_s21_sprintf_39_d);
    tcase_add_test(tcase, test_s21_sprintf_40_d);
    tcase_add_test(tcase, test_s21_sprintf_41_d);
    tcase_add_test(tcase, test_s21_sprintf_42_d);
    tcase_add_test(tcase, test_s21_sprintf_43_d);
    tcase_add_test(tcase, test_s21_sprintf_44_d);
    tcase_add_test(tcase, test_s21_sprintf_45_d);
    tcase_add_test(tcase, test_s21_sprintf_46_d);
    tcase_add_test(tcase, test_s21_sprintf_47_d);
    tcase_add_test(tcase, test_s21_sprintf_48_d);
    tcase_add_test(tcase, test_s21_sprintf_49_d);
    tcase_add_test(tcase, test_s21_sprintf_50_d);
    tcase_add_test(tcase, test_s21_sprintf_51_d);
    tcase_add_test(tcase, test_s21_sprintf_52_d);
    tcase_add_test(tcase, test_s21_sprintf_53_d);
    tcase_add_test(tcase, test_s21_sprintf_54_d);
    tcase_add_test(tcase, test_s21_sprintf_55_d);
    tcase_add_test(tcase, test_s21_sprintf_56_f);
    tcase_add_test(tcase, test_s21_sprintf_57_f);
    tcase_add_test(tcase, test_s21_sprintf_58_f);
    tcase_add_test(tcase, test_s21_sprintf_59_f);
    tcase_add_test(tcase, test_s21_sprintf_60_f);
    tcase_add_test(tcase, test_s21_sprintf_61_f);
    tcase_add_test(tcase, test_s21_sprintf_62_f);
    tcase_add_test(tcase, test_s21_sprintf_63_f);
    tcase_add_test(tcase, test_s21_sprintf_64_f);
    tcase_add_test(tcase, test_s21_sprintf_65_f);
    tcase_add_test(tcase, test_s21_sprintf_66_f);
    tcase_add_test(tcase, test_s21_sprintf_67_f);
    tcase_add_test(tcase, test_s21_sprintf_68_f);
    tcase_add_test(tcase, test_s21_sprintf_69_f);
    tcase_add_test(tcase, test_s21_sprintf_70_f);
    tcase_add_test(tcase, test_s21_sprintf_71_f);
    tcase_add_test(tcase, test_s21_sprintf_72_o);
    tcase_add_test(tcase, test_s21_sprintf_73_o);
    tcase_add_test(tcase, test_s21_sprintf_74_o);
    tcase_add_test(tcase, test_s21_sprintf_75_o);
    tcase_add_test(tcase, test_s21_sprintf_76_o);
    tcase_add_test(tcase, test_s21_sprintf_77_o);
    tcase_add_test(tcase, test_s21_sprintf_78_o);
    tcase_add_test(tcase, test_s21_sprintf_79_o);
    tcase_add_test(tcase, test_s21_sprintf_80_o);
    tcase_add_test(tcase, test_s21_sprintf_81_o);
    tcase_add_test(tcase, test_s21_sprintf_82_o);
    tcase_add_test(tcase, test_s21_sprintf_83_o);
    tcase_add_test(tcase, test_s21_sprintf_84_o);
    tcase_add_test(tcase, test_s21_sprintf_85_o);
    tcase_add_test(tcase, test_s21_sprintf_86_o);
    tcase_add_test(tcase, test_s21_sprintf_87_o);
    tcase_add_test(tcase, test_s21_sprintf_88_o);
    tcase_add_test(tcase, test_s21_sprintf_89_o);
    tcase_add_test(tcase, test_s21_sprintf_90_o);
    tcase_add_test(tcase, test_s21_sprintf_91_o);
    tcase_add_test(tcase, test_s21_sprintf_92_o);
    tcase_add_test(tcase, test_s21_sprintf_93_o);
    tcase_add_test(tcase, test_s21_sprintf_94_s);
    tcase_add_test(tcase, test_s21_sprintf_95_s);
    tcase_add_test(tcase, test_s21_sprintf_96_s);
    tcase_add_test(tcase, test_s21_sprintf_97_s);
    tcase_add_test(tcase, test_s21_sprintf_98_s);
    tcase_add_test(tcase, test_s21_sprintf_99_s);
    tcase_add_test(tcase, test_s21_sprintf_100_s);
    tcase_add_test(tcase, test_s21_sprintf_101_s);
    tcase_add_test(tcase, test_s21_sprintf_102_s);
    tcase_add_test(tcase, test_s21_sprintf_103_s);
    tcase_add_test(tcase, test_s21_sprintf_104_s);
    tcase_add_test(tcase, test_s21_sprintf_105_s);
    tcase_add_test(tcase, test_s21_sprintf_106_s);
    tcase_add_test(tcase, test_s21_sprintf_107_s);
    tcase_add_test(tcase, test_s21_sprintf_108_s);
    tcase_add_test(tcase, test_s21_sprintf_109_s);
    tcase_add_test(tcase, test_s21_sprintf_110_s);
    tcase_add_test(tcase, test_s21_sprintf_111_u);
    tcase_add_test(tcase, test_s21_sprintf_112_u);
    tcase_add_test(tcase, test_s21_sprintf_113_u);
    tcase_add_test(tcase, test_s21_sprintf_114_u);
    tcase_add_test(tcase, test_s21_sprintf_115_u);
    tcase_add_test(tcase, test_s21_sprintf_116_u);
    tcase_add_test(tcase, test_s21_sprintf_117_u);
    tcase_add_test(tcase, test_s21_sprintf_118_u);
    tcase_add_test(tcase, test_s21_sprintf_119_u);
    tcase_add_test(tcase, test_s21_sprintf_120_u);
    tcase_add_test(tcase, test_s21_sprintf_121_u);
    tcase_add_test(tcase, test_s21_sprintf_122_u);
    tcase_add_test(tcase, test_s21_sprintf_123_u);
    tcase_add_test(tcase, test_s21_sprintf_124_u);
    tcase_add_test(tcase, test_s21_sprintf_125_u);
    tcase_add_test(tcase, test_s21_sprintf_126_u);
    tcase_add_test(tcase, test_s21_sprintf_127_u);
    tcase_add_test(tcase, test_s21_sprintf_128_u);
    tcase_add_test(tcase, test_s21_sprintf_129_u);
    tcase_add_test(tcase, test_s21_sprintf_130_u);
    tcase_add_test(tcase, test_s21_sprintf_131_u);
    tcase_add_test(tcase, test_s21_sprintf_132_u);
    tcase_add_test(tcase, test_s21_sprintf_133_x);
    tcase_add_test(tcase, test_s21_sprintf_134_x);
    tcase_add_test(tcase, test_s21_sprintf_135_x);
    tcase_add_test(tcase, test_s21_sprintf_136_x);
    tcase_add_test(tcase, test_s21_sprintf_137_x);
    tcase_add_test(tcase, test_s21_sprintf_138_x);
    tcase_add_test(tcase, test_s21_sprintf_139_x);
    tcase_add_test(tcase, test_s21_sprintf_140_x);
    tcase_add_test(tcase, test_s21_sprintf_141_x);
    tcase_add_test(tcase, test_s21_sprintf_142_x);
    tcase_add_test(tcase, test_s21_sprintf_143_x);
    tcase_add_test(tcase, test_s21_sprintf_144_x);
    tcase_add_test(tcase, test_s21_sprintf_145_x);
    tcase_add_test(tcase, test_s21_sprintf_146_x);
    tcase_add_test(tcase, test_s21_sprintf_147_x);
    tcase_add_test(tcase, test_s21_sprintf_148_x);
    tcase_add_test(tcase, test_s21_sprintf_149_x);
    tcase_add_test(tcase, test_s21_sprintf_150_x);
    tcase_add_test(tcase, test_s21_sprintf_151_x);
    tcase_add_test(tcase, test_s21_sprintf_152_X);
    tcase_add_test(tcase, test_s21_sprintf_153_X);
    tcase_add_test(tcase, test_s21_sprintf_154_X);
    tcase_add_test(tcase, test_s21_sprintf_155_X);
    tcase_add_test(tcase, test_s21_sprintf_156_X);
    tcase_add_test(tcase, test_s21_sprintf_157_X);
    tcase_add_test(tcase, test_s21_sprintf_158_X);
    tcase_add_test(tcase, test_s21_sprintf_159_X);
    tcase_add_test(tcase, test_s21_sprintf_160_X);
    tcase_add_test(tcase, test_s21_sprintf_161_X);
    tcase_add_test(tcase, test_s21_sprintf_162_X);
    tcase_add_test(tcase, test_s21_sprintf_163_X);
    tcase_add_test(tcase, test_s21_sprintf_164_X);
    tcase_add_test(tcase, test_s21_sprintf_165_X);
    tcase_add_test(tcase, test_s21_sprintf_166_X);
    tcase_add_test(tcase, test_s21_sprintf_167_X);
    tcase_add_test(tcase, test_s21_sprintf_168_X);
    tcase_add_test(tcase, test_s21_sprintf_169_X);
    tcase_add_test(tcase, test_s21_sprintf_170_X);
    tcase_add_test(tcase, test_s21_sprintf_171_p);
    tcase_add_test(tcase, test_s21_sprintf_172_p);
    tcase_add_test(tcase, test_s21_sprintf_173_p);
    tcase_add_test(tcase, test_s21_sprintf_174_p);
    tcase_add_test(tcase, test_s21_sprintf_175_p);
    tcase_add_test(tcase, test_s21_sprintf_176_p);
    tcase_add_test(tcase, test_s21_sprintf_177_p);
    tcase_add_test(tcase, test_s21_sprintf_178_p);
    tcase_add_test(tcase, test_s21_sprintf_179_p);
    tcase_add_test(tcase, test_s21_sprintf_180_p);
    tcase_add_test(tcase, test_s21_sprintf_181_p);
    tcase_add_test(tcase, test_s21_sprintf_182_p);
    tcase_add_test(tcase, test_s21_sprintf_183_p);
    tcase_add_test(tcase, test_s21_sprintf_184_p);
    tcase_add_test(tcase, test_s21_sprintf_185_p);
    tcase_add_test(tcase, test_s21_sprintf_186_p);
    tcase_add_test(tcase, test_s21_sprintf_187_p);
    tcase_add_test(tcase, test_s21_sprintf_188_p);
    tcase_add_test(tcase, test_s21_sprintf_189_p);
    tcase_add_test(tcase, test_s21_sprintf_190_p);
    tcase_add_test(tcase, test_s21_sprintf_191);
    tcase_add_test(tcase, test_s21_sprintf_192);
    tcase_add_test(tcase, test_s21_sprintf_193);
    tcase_add_test(tcase, test_s21_sprintf_194);
    tcase_add_test(tcase, test_s21_sprintf_195);
    tcase_add_test(tcase, test_s21_sprintf_196);
    tcase_add_test(tcase, test_s21_sprintf_197);
    tcase_add_test(tcase, test_s21_sprintf_198);
    tcase_add_test(tcase, test_s21_sprintf_199);
    tcase_add_test(tcase, test_s21_sprintf_200);
    tcase_add_test(tcase, test_s21_sprintf_201);
    tcase_add_test(tcase, test_s21_sprintf_202);
    tcase_add_test(tcase, test_s21_sprintf_203);

    return tcase;
}