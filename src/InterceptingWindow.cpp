//
// Created by mrfarinq on 22.04.18.
//

#include <ncurses.h>
#include <iostream>
#include "InterceptingWindow.h"
#include <cassert>


InterceptingWindow::InterceptingWindow(std::mutex &ncursesMutex, std::mutex &conditionVarMutex,
                                       std::condition_variable &conditionVariable, std::queue<Block> &blocks,
                                       int areaWidthFrom,
                                       int areaWidthTo, int areaHeightFrom, int areaHeightTo)
        : blocks(blocks), windowNumber(windowNumber),
          areaWidthFrom(areaWidthFrom),
          areaWidthTo(areaWidthTo), areaHeightFrom(areaHeightFrom),
          areaHeightTo(areaHeightTo), ncursesMutex(ncursesMutex),
          conditionVariable(conditionVariable),
          conditionVarMutex(conditionVarMutex) {}

InterceptingWindow::~InterceptingWindow() = default;

std::thread InterceptingWindow::startThread() {
    return std::thread(&InterceptingWindow::run, this);
}

void InterceptingWindow::run() {
    while (true) {
        std::unique_lock<std::mutex> locker(conditionVarMutex);
        conditionVariable.wait(locker, [this] { return !blocks.empty(); });
        assert(!blocks.empty());
        Block block = blocks.back();
        blocks.pop();
        locker.unlock();

        block.setBlockPartsForInterceptingWindow(areaWidthFrom, areaWidthTo, areaHeightFrom, areaHeightTo);

        std::unique_lock<std::mutex> uniqueLock(ncursesMutex);
        block.drawFigure();
        uniqueLock.unlock();

        int tmp = getch();
        if (tmp == KEY_UP)
            break;
    }
}



