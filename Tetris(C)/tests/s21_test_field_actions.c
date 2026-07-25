#include "s21_test_main.h"

START_TEST(delete_line_4) {
    GameInfo_t g_i;
    g_i.field = s21_create_matrix(WIN_Y, WIN_X);
    GameInfo_t g_i_test;
    g_i_test.field = s21_create_matrix(WIN_Y, WIN_X);

    for (int y = 20; y > 16; y--) {
        for (int x = 1; x < WIN_X - 1; x++) {
            g_i.field[y][x] = 1;
        }
    }

    int cleared_lines = s21_delete_full_line(g_i.field);

    int code = s21_cmp_matrix(g_i.field, g_i_test.field);
    ck_assert_int_eq(code, SUCCESS);
    ck_assert_int_eq(cleared_lines, 4);

    s21_free_matrix(WIN_Y, g_i.field);
    s21_free_matrix(WIN_Y, g_i_test.field);
}
END_TEST

START_TEST(delete_line_3) {
    GameInfo_t g_i;
    g_i.field = s21_create_matrix(WIN_Y, WIN_X);
    GameInfo_t g_i_test;
    g_i_test.field = s21_create_matrix(WIN_Y, WIN_X);

    for (int y = 20; y > 17; y--) {
        for (int x = 1; x < WIN_X - 1; x++) {
            g_i.field[y][x] = 1;
        }
    }

    int cleared_lines = s21_delete_full_line(g_i.field);

    int code = s21_cmp_matrix(g_i.field, g_i_test.field);
    ck_assert_int_eq(code, SUCCESS);
    ck_assert_int_eq(cleared_lines, 3);

    s21_free_matrix(WIN_Y, g_i.field);
    s21_free_matrix(WIN_Y, g_i_test.field);
}
END_TEST

START_TEST(delete_line_2) {
    GameInfo_t g_i;
    g_i.field = s21_create_matrix(WIN_Y, WIN_X);
    GameInfo_t g_i_test;
    g_i_test.field = s21_create_matrix(WIN_Y, WIN_X);

    for (int y = 20; y > 18; y--) {
        for (int x = 1; x < WIN_X - 1; x++) {
            g_i.field[y][x] = 1;
        }
    }

    int cleared_lines = s21_delete_full_line(g_i.field);

    int code = s21_cmp_matrix(g_i.field, g_i_test.field);
    ck_assert_int_eq(code, SUCCESS);
    ck_assert_int_eq(cleared_lines, 2);

    s21_free_matrix(WIN_Y, g_i.field);
    s21_free_matrix(WIN_Y, g_i_test.field);
}
END_TEST

START_TEST(delete_line_1) {
    GameInfo_t g_i;
    g_i.field = s21_create_matrix(WIN_Y, WIN_X);
    GameInfo_t g_i_test;
    g_i_test.field = s21_create_matrix(WIN_Y, WIN_X);

    for (int y = 20; y > 19; y--) {
        for (int x = 1; x < WIN_X - 1; x++) {
            g_i.field[y][x] = 1;
        }
    }

    int cleared_lines = s21_delete_full_line(g_i.field);

    int code = s21_cmp_matrix(g_i.field, g_i_test.field);
    ck_assert_int_eq(code, SUCCESS);
    ck_assert_int_eq(cleared_lines, 1);

    s21_free_matrix(WIN_Y, g_i.field);
    s21_free_matrix(WIN_Y, g_i_test.field);
}
END_TEST

START_TEST(reset_vals) {
    GameData_t gd = {0};

    int prev_next_type = 3;

    int matrix_to_fill[FIGURE_SIZE][FIGURE_SIZE] = {
        {0, 0, 0, 0}, {0, 1, 0, 0}, {0, 1, 1, 1}, {0, 0, 0, 0}};
    int **test_matrix_to_cmp = s21_create_and_fill(matrix_to_fill);

    gd.g_i.next = test_matrix_to_cmp;
    gd.fig_next.type = prev_next_type;
    gd.fig_next.shape = gd.g_i.next;

    gd.fig_cur.shape = s21_create_matrix(FIGURE_SIZE, FIGURE_SIZE);

    s21_fill_figure_loop(gd.figure);

    gd.fig_cur.cord.y = 5;
    gd.fig_cur.cord.x = 10;

    s21_reset_vals(&gd);

    int code1 = s21_cmp_matrix(gd.fig_cur.shape, gd.figure[prev_next_type]);
    int code2 = s21_cmp_matrix(gd.fig_next.shape, gd.figure[gd.fig_next.type]);

    ck_assert_int_eq(gd.fig_cur.cord.y, 1);
    ck_assert_int_eq(gd.fig_cur.cord.x, (WIN_X - FIGURE_SIZE) / 2);
    ck_assert_int_eq(code1, SUCCESS);
    ck_assert_int_eq(code2, SUCCESS);

    for (int i = 0; i < FIGURE_COUNT; i++)
        s21_free_matrix(FIGURE_SIZE, gd.figure[i]);
    s21_free_two_matrices(gd.fig_cur.shape, test_matrix_to_cmp);
}
END_TEST

TCase *test_field_actions() {
    TCase *tcase = tcase_create("field_actions");

    tcase_add_test(tcase, delete_line_4);
    tcase_add_test(tcase, delete_line_3);
    tcase_add_test(tcase, delete_line_2);
    tcase_add_test(tcase, delete_line_1);
    tcase_add_test(tcase, reset_vals);

    return tcase;
}