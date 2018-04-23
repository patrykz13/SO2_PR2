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
    //std::unique_lock<std::mutex> uniqueLock(mutex);
   // condition_variable.wait(uniqueLock, [&]{return !blocks.empty();});
    //Block b = blocks.back();
   // blocks.pop();
    while (true){
        std::unique_lock<std::mutex> uniqueLock(mutex);
    drawFigure();
    uniqueLock.unlock();
    }
    //uniqueLock.unlock();

}

InterceptingWindow::InterceptingWindow(std::mutex &m, std::queue<Block> &blocks,int windowNumber, int areaWidthFrom, int areaWidthTo, int areaHeightFrom,
                                       int areaHeightTo):blocks(blocks),windowNumber(windowNumber),areaWidthFrom(areaWidthFrom),
                                                         areaWidthTo(areaWidthTo),areaHeightFrom(areaHeightFrom),
                                                         areaHeightTo(areaHeightTo), mutex(m){


}

void InterceptingWindow::drawFigure() {
    mvaddch(28, 50, 'x');
    mvaddch(21, 5, 'x');
    mvaddch(11, 61, 'x');
    mvaddch(15, 54, 'x');
    refresh();
}


