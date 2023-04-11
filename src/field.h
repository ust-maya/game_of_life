#ifndef FIELD_H
#define FIELD_H

#include <ncurses.h>
#include <stdlib.h>
#include <unistd.h>

#define ALIVE 'O'
#define DEAD '.'
#define HEIGHT_X_25 25
#define WIDTH_Y_80 80

void initField(char field[][WIDTH_Y_80], char field_next_generation[][WIDTH_Y_80]);
void renderGeneration(char field[][WIDTH_Y_80], int speed);
void initFirstGeneration(char field[][WIDTH_Y_80]);
int countNeighbors(char field[][WIDTH_Y_80], int x, int y);
void aliveOrDead(char field[][WIDTH_Y_80], char field_next_generation[][WIDTH_Y_80]);
void updateField(char field[][WIDTH_Y_80], char field_next_generation[][WIDTH_Y_80]);

#endif  // FIELD_H