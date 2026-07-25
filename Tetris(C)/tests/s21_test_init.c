#include "s21_test_main.h"

START_TEST(init) {
    GameData_t *gd = s21_init_game_data();

    ck_assert_int_eq(gd->g_a, Nothing);
    ck_assert_int_eq(gd->g_s, STATE_MENU);
    ck_assert_int_eq(gd->g_i.level, 1);
    ck_assert_int_eq(gd->g_i.score, 0);
    ck_assert_int_eq(gd->g_i.speed, MIN_FALL_DELAY_MS);

    ck_assert_int_eq(gd->fig_cur.cord.y, 0);
    ck_assert_int_eq(gd->fig_next.cord.y, 0);
    ck_assert_int_eq(gd->fig_cur.cord.x, (WIN_X - FIGURE_SIZE) / 2);
    ck_assert_int_eq(gd->fig_next.cord.x, (INSTR_X - FIGURE_SIZE) / 2);

    ck_assert_ptr_nonnull(gd->g_i.field);
    ck_assert_ptr_nonnull(gd->g_i.next);
    ck_assert_ptr_nonnull(gd->fig_cur.shape);
    ck_assert_ptr_nonnull(gd->fig_next.shape);

    for (int i = 0; i < WIN_Y; i++) {
        for (int j = 0; j < WIN_X; j++) {
            ck_assert_int_eq(gd->g_i.field[i][j], 0);
        }
    }

    s21_free_all_matrix(gd);
}
END_TEST

TCase *test_init() {
    TCase *tcase = tcase_create("init");

    tcase_add_test(tcase, init);

    return tcase;
}