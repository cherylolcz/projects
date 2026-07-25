#include "s21_frontend.h"

int main() {
    srand(time(NULL));

    SCREEN *s = newterm(NULL, stdout, stdin);
    set_term(s);
    refresh();

    s21_init_ncurse();
    s21_init_colors();

    GameData_t *gd = s21_init_game_data();

    Windows_t windows;
    WindowsCord win_cords = {0};

    s21_calc_start_cords(&win_cords);
    s21_init_windows(&windows, win_cords);

    s21_print_stat(windows.stats, &gd->g_i);

    s21_game_loop(&windows);
    s21_free_all_matrix(gd);

    endwin();
    delscreen(s);

    return 0;
}

void s21_game_loop(Windows_t *wins) {
    GameData_t *gd = s21_init_game_data();
    ScreenType screen;

    clock_t last_fall = clock();
    while (gd->g_s != STATE_EXIT) {
        werase(wins->main_win);
        box(wins->main_win, 0, 0);

        s21_print_field(wins->main_win, &gd->g_i);
        if (gd->g_s == STATE_PLAYING) {
            s21_print_figure(wins->main_win, &gd->fig_cur);
            s21_print_next_figure(wins->next_figure, &gd->fig_next);
        }

        gd->g_a = getKey();
        if (gd->g_a != Nothing) userInput(gd->g_a, false);

        s21_print_stat(wins->stats, &gd->g_i);
        s21_set_subwindow(&screen, gd->g_s);

        switch (gd->g_s) {
            case STATE_GAME_OVER:
                s21_show_window(wins->game_over, GAME_OVER);
                s21_set_record(&gd->g_i);
                s21_reset_matrix(gd->g_i.field, WIN_Y, WIN_X);
                break;
            case STATE_PAUSE:
                s21_show_window(wins->pause, PAUSE);
                break;
            case STATE_PLAYING:
                s21_change_figure_pos(gd);
                s21_timer(gd, &last_fall);
                break;
            default:
                break;
        }

        wrefresh(wins->main_win);
        refresh();
    }
}
// {65, Action}, {97, Action}
UserAction_t getKey() {
    static const keyActions key[] = {
        {82, Start},     {114, Start},     {80, Pause}, {112, Pause},
        {81, Terminate}, {113, Terminate}, {258, Down}, {259, Action},
        {260, Left},     {261, Right},     {32, Drop}};

    int ch = getch();
    if (ch == ERR) return Nothing;

    for (long unsigned i = 0; i < sizeof(key) / sizeof(key[0]); i++) {
        if (ch == key[i].key_num) return key[i].next_action;
    }

    return Nothing;
}