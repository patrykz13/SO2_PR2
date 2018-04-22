//
// Created by mrfarinq on 22.04.18.
//

#include "InterceptingWindow.h"


std::thread InterceptingWindow::startThread() {
    return std::thread(&InterceptingWindow::run, this);
}

void InterceptingWindow::run() {

}

InterceptingWindow::InterceptingWindow(std::queue<Block> &blocks,int windowNumber, int areaWidthFrom, int areaWidthTo, int areaHeightFrom,
                                       int areaHeightTo):blocks(blocks),windowNumber(windowNumber),areaWidthFrom(areaWidthFrom),
                                                         areaWidthTo(areaWidthTo),areaHeightFrom(areaHeightFrom),
                                                         areaHeightTo(areaHeightTo){

}
