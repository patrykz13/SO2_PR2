//
// Created by Patryk Zdral on 19.04.2018.
//

#include <iostream>
#include <zconf.h>
#include "TetrisWindow.h"
#include "Block.h"

std::mutex TetrisWindow::mutex;
std::condition_variable TetrisWindow::conditionVariable;
TetrisWindow::TetrisWindow(std::queue<Block> &blocks, int areaWidthFrom, int areaWidthTo, int areaHeightFrom,
                           int areaHeightTo, __useconds_t stepDelay) : blocks(blocks), areaWidthFrom(areaWidthFrom),
                                                                       areaWidthTo(areaWidthTo),
                                                                       areaHeightFrom(areaHeightFrom),
                                                                       areaHeightTo(areaHeightTo),
                                                                       stepDelay(stepDelay) {
}

TetrisWindow::~TetrisWindow() = default;

void TetrisWindow::run() {
    bool blockFalls;

    while(true){
        fallingBlock.initBlockParts(rand() % 6, rand() % (areaWidthTo - 4));

        std::unique_lock<std::mutex> uniqueLock(mutex);
        drawFigure();
        blockFalls = true;
        while (blockFalls){
            usleep(stepDelay);
            blockFalls = doOneStep();
            drawFigure();
            refresh();
        }

        blocks.push(fallingBlock);
        clearFigure();
        uniqueLock.unlock();
        conditionVariable.notify_all();

        int tmp = getch();
        if (tmp == KEY_UP)
            break;
    }
}

std::thread TetrisWindow::startThread() {
    std::thread t1(&TetrisWindow::run, this);
    t1.join();
    return t1;
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






