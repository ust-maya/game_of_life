#include <ncurses.h>
#include <stdlib.h>
#include <unistd.h>

#include "field.h"

int main() {
    char field[HEIGHT_X_25][WIDTH_Y_80];
    char field_next_generation[HEIGHT_X_25][WIDTH_Y_80];
    int ch = 0;
    int speed = 100000;
    initField(field, field_next_generation);
    initFirstGeneration(field);
    initscr();
    keypad(stdscr, TRUE);
    raw();
    noecho();
    nodelay(stdscr, TRUE);
    curs_set(0);
    while (ch != 'q') {
        ch = getch();
        if (ch == 'w') { speed -= 10000; }
        if (ch == 's') { speed += 10000; }
        if (speed < 10000) { speed = 10000; }
        if (speed > 100000) { speed = 100000; }
        usleep(speed);
        erase();
        aliveOrDead(field, field_next_generation);
        updateField(field, field_next_generation);
        renderGeneration(field);
    }
    curs_set(1);
    endwin();
    return 0;
}
