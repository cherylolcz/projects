#include "s21_test_main.h"

START_TEST(change_state) {
    GameData_t *gd = s21_init_game_data();
    gd->g_s = STATE_PLAYING;

    int expected_state = STATE_PAUSE;
    userInput(Pause, false);
    ck_assert_int_eq(gd->g_s, expected_state);

    expected_state = STATE_PLAYING;
    userInput(Start, false);
    ck_assert_int_eq(gd->g_s, expected_state);

    expected_state = STATE_EXIT;
    userInput(Terminate, false);
    ck_assert_int_eq(gd->g_s, expected_state);

    gd->g_s = STATE_MENU;
    expected_state = STATE_PLAYING;
    userInput(Start, false);
    ck_assert_int_eq(gd->g_s, expected_state);
}
END_TEST

START_TEST(update_g_i) {
    GameData_t *gd = s21_init_game_data();

    for (int y = 20; y > 17; y--) {
        for (int x = 1; x < WIN_X - 1; x++) {
            gd->g_i.field[y][x] = 1;
        }
    }

    updateCurrentState();

    int stats[4] = {gd->g_i.score, gd->g_i.level, gd->g_i.speed,
                    gd->g_i.high_score};
    int stats_test[4] = {700, 2, 460, 1500};

    for (int i = 0; i < 4; i++) ck_assert_int_eq(stats[i], stats_test[i]);

    s21_free_all_matrix(gd);
}
END_TEST

TCase *test_controller() {
    TCase *tcase = tcase_create("controller");

    tcase_add_test(tcase, change_state);
    tcase_add_test(tcase, update_g_i);

    return tcase;
}