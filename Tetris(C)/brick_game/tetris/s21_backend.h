#ifndef S21_BACKEND_H
#define S21_BACKEND_H

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "../../s21_common.h"

#define MAX_FALL_DELAY_MS 100
#define MIN_FALL_DELAY_MS 500

typedef enum {
    Start,
    Pause,
    Terminate,
    Left,
    Right,
    Up,
    Down,
    Action,
    Drop,
    Nothing
} UserAction_t;

typedef enum {
    STATE_MENU,
    STATE_PLAYING,
    STATE_PAUSE,
    STATE_GAME_OVER,
    STATE_EXIT
} GameState_t;

typedef struct {
    int **field;
    int **next;
    int score;
    int high_score;
    int level;
    int speed;
    int pause;
} GameInfo_t;

typedef struct {
    int y, x;
} f_cords;

typedef struct {
    int **shape;
    int type;
    f_cords cord;
} Figure_t;

typedef struct {
    int **figure[FIGURE_COUNT];
    Figure_t fig_cur;
    Figure_t fig_next;
    GameInfo_t g_i;
    GameState_t g_s;
    UserAction_t g_a;
} GameData_t;

typedef enum { SUCCESS, FAIL } code;

// ДЛЯ ИНИЦИАЛИЗАЦИИ
GameData_t *s21_init_game_data();
void s21_fill_figure_loop(int **figure[FIGURE_COUNT]);
GameInfo_t s21_init_game_info();
Figure_t s21_init_cur_fig();
Figure_t s21_init_next_fig(int ***shape);

// ДЛЯ РАБОТЫ С ПОЛЕМ
int s21_delete_full_line(int **field);
void s21_reset_vals(GameData_t *gd);
void s21_save_field(int **field, Figure_t *fig);
void s21_timer(GameData_t *gd, clock_t *last_fall);

// ДЛЯ РАБОТЫ С МАТРИЦАМИ
int **s21_create_matrix(int row, int col);
int s21_free_matrix(int row, int **matrix);
void s21_reset_matrix(int **matrix, int row, int col);
void s21_copy_matrix(int **src, int **dst);
void s21_free_all_matrix(GameData_t *gd);

// ДЛЯ РАБОТЫ С ФИГУРАМИ
int s21_can_move(f_cords *cord, int **shape, int **field);
void s21_change_figure_pos(GameData_t *gd);
void s21_fill_figures(int **figure, int index);
void s21_move_figure(Figure_t *fig, UserAction_t action, int **field);
void s21_rotate_figure(Figure_t *fig, int **field);

// ДЛЯ РАБОТЫ СО СТАТИСТИКОЙ ИГРЫ
int s21_set_score(int cleared);
int s21_set_level(GameInfo_t *g_i);
int s21_set_speed(int level);
int s21_read_bin_file(FILE *file);
void s21_set_record(GameInfo_t *g_i);

#endif  //  S21_BACKEND_H