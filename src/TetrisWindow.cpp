//
// Created by Patryk Zdral on 19.04.2018.
//

#include <iostream>
#include <zconf.h>
#include "TetrisWindow.h"
#include "Block.h"


TetrisWindow::TetrisWindow(const std::queue<Block> &blocks, int areaWidthFrom, int areaWidthTo, int areaHeightFrom,
                           int areaHeightTo, __useconds_t stepDelay) : blocks(blocks), areaWidthFrom(areaWidthFrom),
                                                                       areaWidthTo(areaWidthTo),
                                                                       areaHeightFrom(areaHeightFrom),
                                                                       areaHeightTo(areaHeightTo),
                                                                       stepDelay(stepDelay) {
    run();
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
            refresh();
        }

        blocks.push(fallingBlock);
        uniqueLock.unlock();
        condition_variable.notify_all();

        int tmp = getch();
        if (tmp == KEY_UP)
            break;
    }
}

std::thread TetrisWindow::startThread() {
    return std::thread(&TetrisWindow::run, this);
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






