#include "s21_test_main.h"

START_TEST(fill_figure) {
    int **test_matrix = s21_create_matrix(FIGURE_SIZE, FIGURE_SIZE);

    int matrix_to_fill[FIGURE_SIZE][FIGURE_SIZE] = {
        {0, 0, 0, 0}, {0, 1, 0, 0}, {0, 1, 1, 1}, {0, 0, 0, 0}};
    int **test_matrix_to_cmp = s21_create_and_fill(matrix_to_fill);

    s21_fill_figures(test_matrix, FIGURE_TYPE);
    ck_assert_int_eq(SUCCESS, s21_cmp_matrix(test_matrix, test_matrix_to_cmp));

    s21_free_two_matrices(test_matrix, test_matrix_to_cmp);
}
END_TEST

START_TEST(can_move_down) {
    GameInfo_t g_i;
    g_i.field = s21_create_matrix(WIN_Y, WIN_X);

    int matrix_to_fill[FIGURE_SIZE][FIGURE_SIZE] = {
        {0, 0, 0, 0}, {0, 1, 0, 0}, {0, 1, 1, 1}, {0, 0, 0, 0}};
    int **test_matrix_to_cmp = s21_create_and_fill(matrix_to_fill);

    Figure_t test_fig = {test_matrix_to_cmp, FIGURE_TYPE, {18, 3}};
    f_cords new_cords = {++test_fig.cord.y, test_fig.cord.x};

    int code = s21_can_move(&new_cords, test_fig.shape, g_i.field);
    ck_assert_int_eq(code, FAIL);

    s21_free_matrix(WIN_Y, g_i.field);
    s21_free_matrix(FIGURE_SIZE, test_matrix_to_cmp);
}
END_TEST

START_TEST(can_move_figure) {
    GameInfo_t g_i;
    g_i.field = s21_create_matrix(WIN_Y, WIN_X);
    g_i.field[21][1] = 1;
    g_i.field[21][2] = 1;
    g_i.field[20][1] = 1;
    g_i.field[20][2] = 1;

    int matrix_to_fill[FIGURE_SIZE][FIGURE_SIZE] = {
        {0, 0, 0, 0}, {0, 1, 0, 0}, {0, 1, 1, 1}, {0, 0, 0, 0}};
    int **test_matrix_to_cmp = s21_create_and_fill(matrix_to_fill);

    Figure_t test_fig = {test_matrix_to_cmp, FIGURE_TYPE, {17, 1}};
    f_cords new_cords = {++test_fig.cord.y, test_fig.cord.x};

    int code = s21_can_move(&new_cords, test_fig.shape, g_i.field);
    ck_assert_int_eq(code, FAIL);

    s21_free_matrix(WIN_Y, g_i.field);
    s21_free_matrix(FIGURE_SIZE, test_matrix_to_cmp);
}
END_TEST

START_TEST(can_move_left) {
    GameInfo_t g_i;
    g_i.field = s21_create_matrix(WIN_Y, WIN_X);

    int matrix_to_fill[FIGURE_SIZE][FIGURE_SIZE] = {
        {0, 0, 0, 0}, {1, 0, 0, 0}, {1, 1, 1, 0}, {0, 0, 0, 0}};
    int **test_matrix_to_cmp = s21_create_and_fill(matrix_to_fill);

    Figure_t test_fig = {test_matrix_to_cmp, FIGURE_TYPE, {10, 1}};
    f_cords new_cords = {test_fig.cord.y, --test_fig.cord.x};

    int code = s21_can_move(&new_cords, test_fig.shape, g_i.field);
    ck_assert_int_eq(code, FAIL);

    s21_free_matrix(WIN_Y, g_i.field);
    s21_free_matrix(FIGURE_SIZE, test_matrix_to_cmp);
}
END_TEST

START_TEST(can_move_right) {
    GameInfo_t g_i;
    g_i.field = s21_create_matrix(WIN_Y, WIN_X);

    int matrix_to_fill[FIGURE_SIZE][FIGURE_SIZE] = {
        {0, 0, 0, 0}, {0, 1, 0, 0}, {0, 1, 1, 1}, {0, 0, 0, 0}};
    int **test_matrix_to_cmp = s21_create_and_fill(matrix_to_fill);

    Figure_t test_fig = {
        test_matrix_to_cmp, FIGURE_TYPE, {10, WIN_X - FIGURE_SIZE - 1}};
    f_cords new_cords = {test_fig.cord.y, ++test_fig.cord.x};

    int code = s21_can_move(&new_cords, test_fig.shape, g_i.field);
    ck_assert_int_eq(code, FAIL);

    s21_free_matrix(WIN_Y, g_i.field);
    s21_free_matrix(FIGURE_SIZE, test_matrix_to_cmp);
}
END_TEST

START_TEST(rotate) {
    GameData_t gd_test = {0};

    gd_test.g_i.field = s21_create_matrix(WIN_Y, WIN_X);
    gd_test.g_a = Action;

    int matrix_to_fill[FIGURE_SIZE][FIGURE_SIZE] = {
        {0, 0, 0, 0}, {0, 1, 1, 0}, {0, 1, 0, 0}, {0, 1, 0, 0}};
    int **test_matrix_to_cmp = s21_create_and_fill(matrix_to_fill);

    gd_test.fig_cur = s21_create_test_figure(3, (WIN_X - FIGURE_SIZE) / 2);

    s21_change_figure_pos(&gd_test);
    int code = s21_cmp_matrix(gd_test.fig_cur.shape, test_matrix_to_cmp);

    ck_assert_int_eq(code, SUCCESS);

    s21_free_two_matrices(test_matrix_to_cmp, gd_test.fig_cur.shape);
    s21_free_matrix(WIN_Y, gd_test.g_i.field);
}
END_TEST

START_TEST(move_fig_left) {
    GameData_t gd_test = {0};

    gd_test.g_i.field = s21_create_matrix(WIN_Y, WIN_X);
    gd_test.g_a = Left;

    int matrix_to_fill[FIGURE_SIZE][FIGURE_SIZE] = {
        {0, 0, 0, 0}, {0, 1, 0, 0}, {0, 1, 1, 1}, {0, 0, 0, 0}};
    int **test_matrix_to_cmp = s21_create_and_fill(matrix_to_fill);

    gd_test.fig_cur.shape = test_matrix_to_cmp;
    gd_test.fig_cur.cord.y = 10;
    gd_test.fig_cur.cord.x = (WIN_X - FIGURE_SIZE) / 2;

    f_cords test_cords_x_right = {10, (WIN_X - FIGURE_SIZE) / 2 - 1};

    s21_change_figure_pos(&gd_test);
    ck_assert_int_eq(gd_test.fig_cur.cord.x, test_cords_x_right.x);

    s21_free_matrix(FIGURE_SIZE, gd_test.fig_cur.shape);
    s21_free_matrix(WIN_Y, gd_test.g_i.field);
}
END_TEST

START_TEST(move_fig_right) {
    GameData_t gd_test = {0};

    gd_test.g_i.field = s21_create_matrix(WIN_Y, WIN_X);
    gd_test.g_a = Right;

    int matrix_to_fill[FIGURE_SIZE][FIGURE_SIZE] = {
        {0, 0, 0, 0}, {0, 1, 0, 0}, {0, 1, 1, 1}, {0, 0, 0, 0}};
    int **test_matrix_to_cmp = s21_create_and_fill(matrix_to_fill);

    gd_test.fig_cur.shape = test_matrix_to_cmp;
    gd_test.fig_cur.cord.y = 10;
    gd_test.fig_cur.cord.x = (WIN_X - FIGURE_SIZE) / 2;

    f_cords test_cords_x_right = {10, (WIN_X - FIGURE_SIZE) / 2 + 1};

    s21_change_figure_pos(&gd_test);
    ck_assert_int_eq(gd_test.fig_cur.cord.x, test_cords_x_right.x);

    s21_free_matrix(FIGURE_SIZE, gd_test.fig_cur.shape);
    s21_free_matrix(WIN_Y, gd_test.g_i.field);
}
END_TEST

START_TEST(move_fig_down) {
    GameData_t gd_test = {0};

    gd_test.g_i.field = s21_create_matrix(WIN_Y, WIN_X);
    gd_test.g_a = Down;

    int matrix_to_fill[FIGURE_SIZE][FIGURE_SIZE] = {
        {0, 0, 0, 0}, {0, 1, 0, 0}, {0, 1, 1, 1}, {0, 0, 0, 0}};
    int **test_matrix_to_cmp = s21_create_and_fill(matrix_to_fill);

    gd_test.fig_cur.shape = test_matrix_to_cmp;
    gd_test.fig_cur.cord.y = 10;
    gd_test.fig_cur.cord.x = (WIN_X - FIGURE_SIZE) / 2;

    f_cords test_cords_x_right = {11, (WIN_X - FIGURE_SIZE) / 2};

    s21_change_figure_pos(&gd_test);
    ck_assert_int_eq(gd_test.fig_cur.cord.y, test_cords_x_right.y);

    s21_free_matrix(FIGURE_SIZE, gd_test.fig_cur.shape);
    s21_free_matrix(WIN_Y, gd_test.g_i.field);
}
END_TEST

START_TEST(move_fig_drop) {
    GameData_t gd_test = {0};

    gd_test.g_i.field = s21_create_matrix(WIN_Y, WIN_X);
    gd_test.g_a = Drop;

    int matrix_to_fill[FIGURE_SIZE][FIGURE_SIZE] = {
        {0, 0, 0, 0}, {0, 1, 0, 0}, {0, 1, 1, 1}, {0, 0, 0, 0}};
    int **test_matrix_to_cmp = s21_create_and_fill(matrix_to_fill);

    gd_test.fig_cur.shape = test_matrix_to_cmp;
    gd_test.fig_cur.cord.y = 10;
    gd_test.fig_cur.cord.x = (WIN_X - FIGURE_SIZE) / 2;

    f_cords test_cords_drop = {18, (WIN_X - FIGURE_SIZE) / 2};

    s21_change_figure_pos(&gd_test);
    ck_assert_int_eq(gd_test.fig_cur.cord.y, test_cords_drop.y);

    s21_free_matrix(FIGURE_SIZE, gd_test.fig_cur.shape);
    s21_free_matrix(WIN_Y, gd_test.g_i.field);
}
END_TEST

TCase *test_figure_actions() {
    TCase *tcase = tcase_create("move_figure");
    tcase_add_test(tcase, fill_figure);
    tcase_add_test(tcase, rotate);
    tcase_add_test(tcase, move_fig_left);
    tcase_add_test(tcase, move_fig_right);
    tcase_add_test(tcase, move_fig_down);
    tcase_add_test(tcase, can_move_down);
    tcase_add_test(tcase, can_move_left);
    tcase_add_test(tcase, can_move_right);
    tcase_add_test(tcase, can_move_figure);
    tcase_add_test(tcase, move_fig_drop);

    return tcase;
}