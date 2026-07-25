#ifndef FRONTEND_H
#define FRONTEND_H

#include <ncurses.h>

#include "../../brick_game/tetris/controller/s21_tetris_controller.h"
#include "../../brick_game/tetris/s21_backend.h"
#include "../../s21_common.h"

#define F_CHAR 'o'

typedef struct {
    int key_num;
    UserAction_t next_action;
} keyActions;

typedef struct {
    WINDOW *main_win;
    WINDOW *instr;
    WINDOW *next_figure;
    WINDOW *pause;
    WINDOW *game_over;
    WINDOW *stats;
} Windows_t;

typedef struct {
    int wy, wx, iy, ix, goy, gox, sbx;
} WindowsCord;

typedef enum { INSTR, GAME_OVER, PAUSE, STAT, NEXT, NOTHING } ScreenType;

// ОСНОВНЫЕ ФУНКЦИИ (ИГРОВОЙ ЦИКЛ И ПОЛУЧЕНИЕ ДЕЙСТВИЯ ОТ ЮЗЕРА)
void s21_game_loop(Windows_t *wins);
UserAction_t getKey();

// ДЛЯ ИНИЦИАЛИЗАЦИИ
void s21_init_ncurse();
void s21_init_colors();
void s21_init_windows(Windows_t *windows, WindowsCord win_cords);
void s21_calc_start_cords(WindowsCord *win_cords);

// ДЛЯ РАБОТЫ С ОКНАМИ (ЗАПОЛНЕНИЕ И.Т.П)
void s21_fill_window(WINDOW *w, ScreenType type);
void s21_show_window(WINDOW *w, ScreenType type);
void s21_set_subwindow(ScreenType *s_type, GameState_t state);

// ДЛЯ ОТРИСОВКИ
void s21_print_figure(WINDOW *w, Figure_t *fig_cur);
void s21_print_next_figure(WINDOW *w, Figure_t *fig_next);
void s21_set_color(WINDOW *w, int f_index);
void s21_print_field(WINDOW *w, GameInfo_t *g_i);
void s21_update_next_figure(WINDOW *w, Figure_t *fig_next);
void s21_print_stat(WINDOW *w, GameInfo_t *g_i);

#endif  //  FRONTEND_H