#include <stdio.h>

#define ALIVE 'o'
#define DEAD '.'
#define HEIGHT_X_25 25
#define WIDTH_Y_80 80

void initField(char field[][WIDTH_Y_80], char field_next_generation[][WIDTH_Y_80]);
void renderGeneration(char field[][WIDTH_Y_80]);
void initFirstGeneration(char field[][WIDTH_Y_80]);

int main() {
    char field[HEIGHT_X_25][WIDTH_Y_80];
    char field_next_generation[HEIGHT_X_25][WIDTH_Y_80];
    initField(field, field_next_generation);
    initFirstGeneration(field);
    renderGeneration(field);
    return 0;
}

void initField(char field[][WIDTH_Y_80], char field_next_generation[][WIDTH_Y_80]) {
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
}

void renderGeneration(char field[][WIDTH_Y_80]) {
    for (int x = 0; x < HEIGHT_X_25; x++) {
        for (int y = 0; y < WIDTH_Y_80; y++) {
            printf("%c", field[x][y]);
        }
        printf("\n");
    }
}

int countNeighbors(char field[][WIDTH_Y_80], int x, int y) {
    int count = 0;

    if (field[x][y] == ALIVE) { count++ }
    if (field[x][y] == ALIVE) { count++ }
    if (field[x][y] == ALIVE) { count++ }
    if (field[x][y] == ALIVE) { count++ }
    if (field[x][y] == ALIVE) { count++ }
    if (field[x][y] == ALIVE) { count++ }
    if (field[x][y] == ALIVE) { count++ }
    if (field[x][y] == ALIVE) { count++ }

    return count;
}

void aliveOrDead(char field[][WIDTH_Y_80], char field_next_generation[][WIDTH_Y_80]) {

}

void updateField(char field[][WIDTH_Y_80], char field_next_generation[][WIDTH_Y_80]) {

}

void gameMenu() {

}