//
// Created by Patryk Zdral on 19.04.2018.
//

#include <iostream>
#include <zconf.h>
#include "TetrisWindow.h"
#include "Block.h"


TetrisWindow::TetrisWindow(std::mutex &ncursesMutex, std::mutex &conditionVarMutex,
                           std::condition_variable &conditionVariable, std::queue<Block> &blocks, int areaWidthFrom,
                           int areaWidthTo, int areaHeightFrom, int areaHeightTo, __useconds_t stepDelay)
        : blocks(blocks), areaWidthFrom(areaWidthFrom),
          areaWidthTo(areaWidthTo),
          areaHeightFrom(areaHeightFrom),
          areaHeightTo(areaHeightTo),
          stepDelay(stepDelay), ncursesMutex(ncursesMutex),
          conditionVariable(conditionVariable),
          conditionVarMutex(conditionVarMutex) {
}

TetrisWindow::~TetrisWindow() = default;

void TetrisWindow::run() {
    bool blockFalls;

    while (true) {
        fallingBlock.initBlockParts(rand() % 6, rand() % (areaWidthTo - 4));

        std::unique_lock<std::mutex> uniqueLock(ncursesMutex);
        fallingBlock.drawFigure();
        uniqueLock.unlock();

        blockFalls = true;
        while (blockFalls) {
            usleep(stepDelay);

            uniqueLock.lock();
            blockFalls = fallingBlock.doOneStep(areaHeightTo);
            fallingBlock.drawFigure();
            refresh();
            uniqueLock.unlock();
        }

        std::unique_lock<std::mutex> locker(conditionVarMutex);
        blocks.push(fallingBlock);
        conditionVariable.notify_all();
        locker.unlock();

        uniqueLock.lock();
        fallingBlock.clearFigure();
        uniqueLock.unlock();

        int tmp = getch();
        if (tmp == KEY_UP)
            break;
    }
}

std::thread TetrisWindow::startThread() {
    return std::thread(&TetrisWindow::run, this);
}






