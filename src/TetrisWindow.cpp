//
// Created by Patryk Zdral on 19.04.2018.
//

#include <iostream>
#include <zconf.h>
#include "TetrisWindow.h"
#include "Window.h"
#include "Block.h"


TetrisWindow::TetrisWindow( int areaWidthFrom, int areaWidthTo, int areaHeightFrom,
                           int areaHeightTo, __useconds_t stepDelay) : Window(areaWidthFrom,areaWidthTo,areaHeightFrom,areaHeightTo)
{
    this->stepDelay=stepDelay;
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
            drawFigure();
            refresh();

        }
        Window::blocks.push(fallingBlock);
        uniqueLock.unlock();
        clearWindow();
        condition_variable.notify_all();
        uniqueLock.lock();
        int tmp = getch();
        uniqueLock.unlock();
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
        if (blockSegment.y == areaHeightTo-1)
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

void TetrisWindow::clearWindow() {
    for (auto &blockSegment : fallingBlock.getBlockParts())
        mvaddch(blockSegment.y, blockSegment.x, ' ');
    refresh();
}






