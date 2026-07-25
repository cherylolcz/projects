#include "s21_backend.h"

int s21_set_score(int cleared) {
    int new_score = 0;
    int scores[] = {100, 300, 700, 1500};

    if (cleared >= 1 && cleared <= 4) new_score += scores[cleared - 1];

    return new_score;
}

// 0 600 1200 1800 2400 3000 3600 4200 4800 5400
// 1 2   3    4    5    6    7    8    9    10

int s21_set_level(GameInfo_t *g_i) {
    int new_level = 1;
    int scores[10];
    for (int i = 0; i < 10; i++) {
        scores[i] = (i + 1) * 600;
    }

    for (int i = 10 - 1; i >= 0; i--) {
        if (g_i->score >= scores[i]) {
            new_level = (i + 1) + 1;
            break;
        }
    }

    return new_level;
}

int s21_set_speed(int level) { return (level - 1) * 40; }

void s21_set_record(GameInfo_t *g_i) {
    FILE *file = fopen("record.bin", "rb+");
    if (file == NULL) {
        file = fopen("record.bin", "wb+");
    }

    int last_high_score = s21_read_bin_file(file);
    rewind(file);
    if (g_i->score > last_high_score) {
        g_i->high_score = g_i->score;

        fclose(file);
        file = fopen("record.bin", "wb");

        fwrite(&g_i->high_score, sizeof(int), 1, file);
        fclose(file);
    } else {
        fclose(file);
        g_i->high_score = last_high_score;
    }
}

int s21_read_bin_file(FILE *file) {
    int val_to_return;

    fseek(file, 0, SEEK_END);
    int file_len = ftell(file);
    rewind(file);

    if (file_len == 0)
        val_to_return = 0;
    else
        fread(&val_to_return, sizeof(int), 1, file);

    return val_to_return;
}
