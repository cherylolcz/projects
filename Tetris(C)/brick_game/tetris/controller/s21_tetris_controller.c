#include "s21_tetris_controller.h"

static const Transition transitions[] = {
    {STATE_MENU, Start, STATE_PLAYING},
    {STATE_MENU, Terminate, STATE_EXIT},

    {STATE_PLAYING, Pause, STATE_PAUSE},
    {STATE_PLAYING, Terminate, STATE_EXIT},

    {STATE_PAUSE, Start, STATE_PLAYING},
    {STATE_PAUSE, Terminate, STATE_EXIT},

    {STATE_GAME_OVER, Start, STATE_PLAYING},
    {STATE_GAME_OVER, Terminate, STATE_EXIT}};

void userInput(UserAction_t action, bool hold) {
    GameData_t *gd = s21_init_game_data();
    gd->g_a = action;

    if (!hold) {
        for (long unsigned i = 0;
             i < sizeof(transitions) / sizeof(transitions[0]); i++) {
            if (gd->g_s == transitions[i].cur_state &&
                gd->g_a == transitions[i].cur_action) {
                gd->g_s = transitions[i].next_state;
                break;
            }
        }
    }
}

GameInfo_t updateCurrentState() {
    GameData_t *gd = s21_init_game_data();

    s21_save_field(gd->g_i.field, &gd->fig_cur);

    int cleared_lines = s21_delete_full_line(gd->g_i.field);
    if (cleared_lines) {
        gd->g_i.score += s21_set_score(cleared_lines);
        gd->g_i.level = s21_set_level(&gd->g_i);
        gd->g_i.speed = MIN_FALL_DELAY_MS - s21_set_speed(gd->g_i.level);
    }

    return gd->g_i;
}