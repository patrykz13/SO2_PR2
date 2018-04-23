//
// Created by mrfarinq on 22.04.18.
//
#include <ncurses.h>
#include <iostream>
#include "InterceptingWindow.h"


std::thread InterceptingWindow::startThread() {
    return std::thread(&InterceptingWindow::run, this);
}

void InterceptingWindow::run() {
    while (true) {

        std::unique_lock<std::mutex> locker(mutexCondition);
        condition_variable.wait(locker, [&]{return !blocks.empty();});
        Block b = blocks.back();
        blocks.pop();
        locker.unlock();

        b.setBlockPartsForInterceptingWindow(areaWidthFrom, areaWidthTo, areaHeightFrom, areaHeightTo);
        std::unique_lock<std::mutex> uniqueLock(mutexNcurses);
        drawFigure(b);
        uniqueLock.unlock();

        int tmp = getch();
        if (tmp == KEY_UP)
            break;
    }
}

InterceptingWindow::InterceptingWindow(std::mutex &m,  std::mutex &m2, std::condition_variable &c, std::queue<Block> &blocks, int areaWidthFrom,
                                       int areaWidthTo, int areaHeightFrom,
                                       int areaHeightTo) : blocks(blocks), windowNumber(windowNumber),
                                                           areaWidthFrom(areaWidthFrom),
                                                           areaWidthTo(areaWidthTo), areaHeightFrom(areaHeightFrom),
                                                           areaHeightTo(areaHeightTo), mutexNcurses(m), condition_variable(c), mutexCondition(m2) {


}

void InterceptingWindow::drawFigure(Block p) {
    for (auto &blockSegment : p.getBlockParts())
        mvaddch(blockSegment.y, blockSegment.x, 'x');
    refresh();
}


