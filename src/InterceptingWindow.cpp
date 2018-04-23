//
// Created by mrfarinq on 22.04.18.
//
#include <ncurses.h>
#include <iostream>
#include "InterceptingWindow.h"

std::mutex InterceptingWindow::mutex;
std::condition_variable InterceptingWindow::condition_variable;

std::thread InterceptingWindow::startThread() {
    std::thread t1(&InterceptingWindow::run, this);
    t1.join();
    return t1;
}

void InterceptingWindow::run() {
    std::unique_lock<std::mutex> uniqueLock(mutex);
    condition_variable.wait(uniqueLock, [&]{return !blocks.empty();});
    Block b = blocks.back();
    blocks.pop();
    drawFigure(b);
    uniqueLock.unlock();

}

InterceptingWindow::InterceptingWindow(std::queue<Block> &blocks,int windowNumber, int areaWidthFrom, int areaWidthTo, int areaHeightFrom,
                                       int areaHeightTo):blocks(blocks),windowNumber(windowNumber),areaWidthFrom(areaWidthFrom),
                                                         areaWidthTo(areaWidthTo),areaHeightFrom(areaHeightFrom),
                                                         areaHeightTo(areaHeightTo){


}

void InterceptingWindow::drawFigure(Block b) {
    mvaddch(50, 50, 'x');
    refresh();
}


