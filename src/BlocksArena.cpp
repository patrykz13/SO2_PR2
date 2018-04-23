//
// Created by Patryk Zdral on 19.04.2018.
//

#include <ncurses.h>
#include <cstdlib>
#include <ctime>
#include "BlocksArena.h"
#include "TetrisWindow.h"
#include "InterceptingWindow.h"

BlocksArena::BlocksArena(int xFrom, int xTo, int yFrom, int yTo, __useconds_t stepDelay) {
    nodelay(stdscr, true);
    keypad(stdscr, true);
    noecho();
    curs_set(0);
    drawDividedScreen(0, yTo, 0, xTo);
    refresh();
    srand(static_cast<unsigned int>(time(nullptr)));

    std::mutex mutexNcurses;
    std::mutex mutexCondition;
    std::condition_variable c;

    std::shared_ptr<TetrisWindow> tetrisWindow(new TetrisWindow(mutexNcurses, mutexCondition, c, blocks, xFrom, xTo / 2, yFrom, yTo / 2, 500000));
    std::shared_ptr<InterceptingWindow> t1(new InterceptingWindow(mutexNcurses, mutexCondition, c, blocks, xTo / 2, xTo - 1, yTo / 2, yTo - 1));
    std::shared_ptr<InterceptingWindow> t2(new InterceptingWindow(mutexNcurses, mutexCondition, c, blocks, xFrom, xTo / 2, yTo / 2, yTo - 1));
    std::shared_ptr<InterceptingWindow> t3(new InterceptingWindow(mutexNcurses, mutexCondition, c, blocks, xTo / 2, xTo - 1, yFrom, yTo / 2));


    std::thread th1 = tetrisWindow->startThread();
    std::thread th2 = t1->startThread();
    std::thread th3 = t2->startThread();
    std::thread th4 = t3->startThread();

    th1.join();
    th2.join();
    th3.join();
    th4.join();
    // t1.startThread();
    //t2.startThread();
    // t3.startThread();

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

