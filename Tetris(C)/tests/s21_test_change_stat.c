#include "s21_test_main.h"

START_TEST(set_new_vals_2) {
    GameInfo_t gi = {0};
    gi.field = s21_create_matrix(WIN_Y, WIN_X);
    gi.speed = MIN_FALL_DELAY_MS;
    gi.level = 1;

    for (int y = 20; y > 18; y--) {
        for (int x = 1; x < WIN_X - 1; x++) {
            gi.field[y][x] = 1;
        }
    }
    int cleared_lines = s21_delete_full_line(gi.field);
    gi.score += s21_set_score(cleared_lines);
    gi.level = s21_set_level(&gi);
    gi.speed = MIN_FALL_DELAY_MS - s21_set_speed(gi.level);
    s21_set_record(&gi);

    int stats[4] = {gi.score, gi.level, gi.speed, gi.high_score};
    int stats_test[4] = {300, 1, 500, 300};

    for (int i = 0; i < 4; i++) ck_assert_int_eq(stats[i], stats_test[i]);

    s21_free_matrix(WIN_Y, gi.field);
}
END_TEST

START_TEST(set_new_vals_1) {
    GameInfo_t gi = {0};
    gi.field = s21_create_matrix(WIN_Y, WIN_X);
    gi.speed = MIN_FALL_DELAY_MS;
    gi.level = 1;

    for (int y = 20; y > 19; y--) {
        for (int x = 1; x < WIN_X - 1; x++) {
            gi.field[y][x] = 1;
        }
    }
    int cleared_lines = s21_delete_full_line(gi.field);
    gi.score += s21_set_score(cleared_lines);
    gi.level = s21_set_level(&gi);
    gi.speed = MIN_FALL_DELAY_MS - s21_set_speed(gi.level);
    s21_set_record(&gi);

    int stats[4] = {gi.score, gi.level, gi.speed, gi.high_score};
    int stats_test[4] = {100, 1, 500, 300};

    for (int i = 0; i < 4; i++) ck_assert_int_eq(stats[i], stats_test[i]);

    s21_free_matrix(WIN_Y, gi.field);
}
END_TEST

START_TEST(set_new_vals_3) {
    GameInfo_t gi = {0};
    gi.field = s21_create_matrix(WIN_Y, WIN_X);
    gi.speed = MIN_FALL_DELAY_MS;
    gi.level = 1;

    for (int y = 20; y > 17; y--) {
        for (int x = 1; x < WIN_X - 1; x++) {
            gi.field[y][x] = 1;
        }
    }
    int cleared_lines = s21_delete_full_line(gi.field);
    gi.score += s21_set_score(cleared_lines);
    gi.level = s21_set_level(&gi);
    gi.speed = MIN_FALL_DELAY_MS - s21_set_speed(gi.level);
    s21_set_record(&gi);

    int stats[4] = {gi.score, gi.level, gi.speed, gi.high_score};
    int stats_test[4] = {700, 2, 460, 700};

    for (int i = 0; i < 4; i++) ck_assert_int_eq(stats[i], stats_test[i]);

    s21_free_matrix(WIN_Y, gi.field);
}
END_TEST

START_TEST(set_new_vals_4) {
    GameInfo_t gi = {0};
    gi.field = s21_create_matrix(WIN_Y, WIN_X);
    gi.speed = MIN_FALL_DELAY_MS;
    gi.level = 1;

    for (int y = 20; y > 16; y--) {
        for (int x = 1; x < WIN_X - 1; x++) {
            gi.field[y][x] = 1;
        }
    }
    int cleared_lines = s21_delete_full_line(gi.field);
    gi.score += s21_set_score(cleared_lines);
    gi.level = s21_set_level(&gi);
    gi.speed = MIN_FALL_DELAY_MS - s21_set_speed(gi.level);
    s21_set_record(&gi);

    int stats[4] = {gi.score, gi.level, gi.speed, gi.high_score};
    int stats_test[4] = {1500, 3, 420, 1500};

    for (int i = 0; i < 4; i++) ck_assert_int_eq(stats[i], stats_test[i]);

    s21_free_matrix(WIN_Y, gi.field);
}
END_TEST

TCase *test_change_stat() {
    TCase *tcase = tcase_create("change_stat");

    tcase_add_test(tcase, set_new_vals_2);
    tcase_add_test(tcase, set_new_vals_1);
    tcase_add_test(tcase, set_new_vals_3);
    tcase_add_test(tcase, set_new_vals_4);

    return tcase;
}