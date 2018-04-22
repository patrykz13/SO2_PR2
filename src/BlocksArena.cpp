//
// Created by Patryk Zdral on 19.04.2018.
//

#include <ncurses.h>
#include <cstdlib>
#include <ctime>
#include "BlocksArena.h"
#include "Block.h"

BlocksArena::BlocksArena(int xFrom, int xTo, int yFrom, int yTo) {
    nodelay(stdscr, true);
    keypad(stdscr, true);
    noecho();
    curs_set(0);
    drawDividedScreen(0, yTo, 0, xTo);
    refresh();
    srand(static_cast<unsigned int>(time(nullptr)));

    Block block(12, 12, 'x', xTo, yTo);
    block.start();
}

BlocksArena::~BlocksArena() = default;

void BlocksArena::drawDividedScreen(int yFrom, int yTo, int xFrom, int xTo) {
    clear();

    for (auto i = 0; i < xTo; i++) {
        move(0, i);
        if (i == 0) {
            addch(ACS_ULCORNER);
            move(yTo - 1, i);
            addch(ACS_LLCORNER);
        } else if (i == xTo - 1) {
            addch(ACS_URCORNER);
            move(yTo - 1, i);
            addch(ACS_LRCORNER);
        } else {
            addch(ACS_HLINE);
            move(yTo - 1, i);
            addch(ACS_HLINE);
        }
    }

    for (auto i = 1; i < yTo - 1; i++) {
        move(i, 0);
        addch(ACS_VLINE);

        move(i, xTo - 1);
        addch(ACS_VLINE);
    }

    for (auto i = yFrom; i < yTo; i++) {
        move(i, xTo / 2);
        if (i == yFrom)
            addch(ACS_TTEE);
        else if (i == yTo - 1)
            addch(ACS_BTEE);
        else
            addch(ACS_VLINE);
    }

    for (auto i = xFrom; i < xTo; i++) {
        move(yTo / 2, i);
        if (i == xFrom)
            addch(ACS_LTEE);
        else if (i == xTo - 1)
            addch(ACS_RTEE);
        else if (i == xTo / 2)
            addch(ACS_PLUS);
        else
            addch(ACS_HLINE);
    }

    refresh();
}

