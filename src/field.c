#include "field.h"

void initField(char field[][WIDTH_Y_80], char field_next_generation[][WIDTH_Y_80]) {
  for (int x = 0; x < HEIGHT_X_25; x++) {
    for (int y = 0; y < WIDTH_Y_80; y++) {
      field[x][y] = DEAD;
      field_next_generation[x][y] = DEAD;
    }
  }
}

void initFirstGeneration(char field[][WIDTH_Y_80]) {
  FILE *file = fopen("presets/preset.txt", "r");
  for (int i = 0; i < HEIGHT_X_25; i++) {
    for (int j = 0; j < WIDTH_Y_80; j++) {
      fscanf(file, "%c", &field[i][j]);
    }
  }
  fclose(file);
}

void renderGeneration(char field[][WIDTH_Y_80], int speed) {
  printw("###############################|Game of Life|#####################################\n");
  for (int x = 0; x < HEIGHT_X_25; x++) {
    printw("#");
    for (int y = 0; y < WIDTH_Y_80; y++) {
      printw("%c", field[x][y]);
    }
    printw("#\n");
  }
  printw("##################################################################################\n");
  printw("Speed: %d\n", speed);
  printw("Control:\n");
  printw("Speed up - \'W\'\n");
  printw("Speed down - \'S\'\n");
  printw("Exit game - \'Q\'\n");
}

int countNeighbors(char field[][WIDTH_Y_80], int x, int y) {
  int count = 0;
  int up = -1;
  int down = 1;
  int left = -1;
  int right = 1;

  if (x == 0) {
    up = 24;
  }
  if (x == 24) {
    down = -24;
  }
  if (y == 0) {
    left = 79;
  }
  if (y == 79) {
    right = -79;
  }

  if (field[x + up][y + left] == ALIVE) {
    count++;
  }
  if (field[x + up][y] == ALIVE) {
    count++;
  }
  if (field[x + up][y + right] == ALIVE) {
    count++;
  }
  if (field[x][y + left] == ALIVE) {
    count++;
  }
  if (field[x][y + right] == ALIVE) {
    count++;
  }
  if (field[x + down][y + left] == ALIVE) {
    count++;
  }
  if (field[x + down][y] == ALIVE) {
    count++;
  }
  if (field[x + down][y + right] == ALIVE) {
    count++;
  }

  return count;
}

void aliveOrDead(char field[][WIDTH_Y_80], char field_next_generation[][WIDTH_Y_80]) {
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

void updateField(char field[][WIDTH_Y_80], char field_next_generation[][WIDTH_Y_80]) {
  for (int i = 0; i < HEIGHT_X_25; ++i) {
    for (int j = 0; j < WIDTH_Y_80; ++j) {
      field[i][j] = field_next_generation[i][j];
    }
  }
}
