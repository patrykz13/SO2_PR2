//
// Created by Patryk Zdral on 19.04.2018.
//

#include <iostream>
#include "TetrisWindow.h"
#include "Block.h"


TetrisWindow::TetrisWindow(const std::queue<Block> &blocks, int areaWidthFrom, int areaWidthTo, int areaHeightFrom,
                           int areaHeightTo, __useconds_t stepDelay) : blocks(blocks), areaWidthFrom(areaWidthFrom),
                                                                       areaWidthTo(areaWidthTo),
                                                                       areaHeightFrom(areaHeightFrom),
                                                                       areaHeightTo(areaHeightTo),
                                                                       stepDelay(stepDelay) {}

TetrisWindow::~TetrisWindow() = default;

void TetrisWindow::run() {
    fallingBlock.initBlockParts(rand() % 6, rand() % (areaWidthTo - 4));
    drawFigure();
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
}






