//
// Created by Patryk Zdral on 19.04.2018.
//

#include <iostream>
#include <zconf.h>
#include "TetrisWindow.h"
#include "Block.h"


TetrisWindow::TetrisWindow(std::mutex &m,  std::mutex &m2, std::condition_variable &c, std::queue<Block> &blocks, int areaWidthFrom, int areaWidthTo, int areaHeightFrom,
                           int areaHeightTo, __useconds_t stepDelay) : blocks(blocks), areaWidthFrom(areaWidthFrom),
                                                                       areaWidthTo(areaWidthTo),
                                                                       areaHeightFrom(areaHeightFrom),
                                                                       areaHeightTo(areaHeightTo),
                                                                       stepDelay(stepDelay), mutexNcurses(m), conditionVariable(c), mutexCondition(m2)  {
}

TetrisWindow::~TetrisWindow() = default;

void TetrisWindow::run() {
    bool blockFalls;


    while (true) {
        fallingBlock.initBlockParts(rand() % 6, rand() % (areaWidthTo - 4));

        std::unique_lock<std::mutex> uniqueLock(mutexNcurses);
        drawFigure();
        uniqueLock.unlock();
        blockFalls = true;
        while (blockFalls) {
            usleep(stepDelay);
            uniqueLock.lock();
            blockFalls = doOneStep();
            drawFigure();
            refresh();
            uniqueLock.unlock();
        }

        std::unique_lock<std::mutex> locker(mutexCondition);
        blocks.push(fallingBlock);
        conditionVariable.notify_all();
        locker.unlock();

        uniqueLock.lock();
        clearFigure();
        uniqueLock.unlock();

        int tmp = getch();
        if (tmp == KEY_UP)
            break;
    }
}

std::thread TetrisWindow::startThread() {
    return std::thread(&TetrisWindow::run, this);
    // t1.join();

    // return std::thread(&TetrisWindow::start, this);
}

bool TetrisWindow::doOneStep() {
    for (auto &blockSegment: fallingBlock.getBlockParts()) {
        mvaddch(blockSegment.y, blockSegment.x, ' ');
        blockSegment.y++;
        if (blockSegment.y == areaHeightTo - 1)
            return false;
        mvaddch(blockSegment.y, blockSegment.x, 'x');
    }

    return true;
}

void TetrisWindow::drawFigure() {
    for (auto &blockSegment : fallingBlock.getBlockParts())
        mvaddch(blockSegment.y, blockSegment.x, 'x');
    refresh();
}

void TetrisWindow::clearFigure() {
    for (auto &blockSegment : fallingBlock.getBlockParts())
        mvaddch(blockSegment.y, blockSegment.x, ' ');
    refresh();
}






