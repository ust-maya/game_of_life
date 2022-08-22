#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define ALIVE 'O'
#define DEAD '.'
#define HEIGHT_X_25 25
#define WIDTH_Y_80 150

void initField(char field[][WIDTH_Y_80],
               char field_next_generation[][WIDTH_Y_80]);
void renderGeneration(char field[][WIDTH_Y_80]);
void initFirstGeneration(char field[][WIDTH_Y_80]);
int countNeighbors(char field[][WIDTH_Y_80], int x, int y);
void aliveOrDead(char field[][WIDTH_Y_80],
                 char field_next_generation[][WIDTH_Y_80]);
void updateField(char field[][WIDTH_Y_80],
                 char field_next_generation[][WIDTH_Y_80]);

int main() {
    char field[HEIGHT_X_25][WIDTH_Y_80];
    char field_next_generation[HEIGHT_X_25][WIDTH_Y_80];
    initField(field, field_next_generation);
    initFirstGeneration(field);
    renderGeneration(field);
    int flag = 10000;
    while (flag != 0) {
        usleep(10000);
        system("clear");
        aliveOrDead(field, field_next_generation);
        updateField(field, field_next_generation);
        renderGeneration(field);
        flag--;
    }
    return 0;
}

void initField(char field[][WIDTH_Y_80],
               char field_next_generation[][WIDTH_Y_80]) {
    for (int x = 0; x < HEIGHT_X_25; x++) {
        for (int y = 0; y < WIDTH_Y_80; y++) {
            field[x][y] = DEAD;
            field_next_generation[x][y] = DEAD;
        }
    }
}

void initFirstGeneration(char field[][WIDTH_Y_80]) {
    field[4][5] = ALIVE;
    field[5][6] = ALIVE;
    field[6][4] = ALIVE;
    field[6][5] = ALIVE;
    field[6][6] = ALIVE;

    field[10][10] = ALIVE;
    field[9][10] = ALIVE;
    field[11][10] = ALIVE;

    field[11][40] = ALIVE;
    field[12][40] = ALIVE;
    field[12][41] = ALIVE;
    field[13][39] = ALIVE;
    field[13][40] = ALIVE;

    field[6][17] = ALIVE;
    field[6][20] = ALIVE;
    field[7][16] = ALIVE;
    field[7][18] = ALIVE;
    field[7][19] = ALIVE;
    field[7][21] = ALIVE;
    field[8][17] = ALIVE;
    field[8][20] = ALIVE;
    field[9][17] = ALIVE;
    field[9][20] = ALIVE;
    field[10][16] = ALIVE;
    field[10][18] = ALIVE;
    field[10][19] = ALIVE;
    field[10][21] = ALIVE;
    field[11][17] = ALIVE;
    field[11][10] = ALIVE;
}

void renderGeneration(char field[][WIDTH_Y_80]) {
    for (int x = 0; x < HEIGHT_X_25; x++) {
        for (int y = 0; y < WIDTH_Y_80; y++) { printf("%c", field[x][y]); }
        printf("\n");
    }
}

int countNeighbors(char field[][WIDTH_Y_80], int x, int y) {
    int count = 0;
    int up = -1;
    int down = 1;
    int left = -1;
    int right = 1;

    if (x == 0) { up = 24; }
    if (x == 24) { down = -24; }
    if (y == 0) { left = 79; }
    if (y == 79) { right = -79; }

    if (field[x + up][y + left] == ALIVE) { count++; }
    if (field[x + up][y] == ALIVE) { count++; }
    if (field[x + up][y + right] == ALIVE) { count++; }
    if (field[x][y + left] == ALIVE) { count++; }
    if (field[x][y + right] == ALIVE) { count++; }
    if (field[x + down][y + left] == ALIVE) { count++; }
    if (field[x + down][y] == ALIVE) { count++; }
    if (field[x + down][y + right] == ALIVE) { count++; }

    return count;
}

void aliveOrDead(char field[][WIDTH_Y_80],
                 char field_next_generation[][WIDTH_Y_80]) {
    for (int i = 0; i < HEIGHT_X_25; ++i) {
        for (int j = 0; j < WIDTH_Y_80; ++j) {
            int counter = countNeighbors(field, i, j);
            if (field[i][j] == ALIVE && (counter == 2 || counter == 3)) {
                field_next_generation[i][j] = ALIVE;
            }
            if (field[i][j] == ALIVE && (counter > 3 || counter < 2)) {
                field_next_generation[i][j] = DEAD;
            }
            if (field[i][j] == DEAD && counter == 3) {
                field_next_generation[i][j] = ALIVE;
            }
        }
    }
}

void updateField(char field[][WIDTH_Y_80],
                 char field_next_generation[][WIDTH_Y_80]) {
    for (int i = 0; i < HEIGHT_X_25; ++i) {
        for (int j = 0; j < WIDTH_Y_80; ++j) {
            field[i][j] = field_next_generation[i][j];
        }
    }

    for (int i = 0; i < HEIGHT_X_25; ++i) {
        for (int j = 0; j < WIDTH_Y_80; ++j) {
            field_next_generation[i][j] = DEAD;
        }
    }

    //void gameMenu() {
    //
    //}
}