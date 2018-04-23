//
// Created by mrfarinq on 22.04.18.
//

#ifndef SO2_PR2_INTERCEPTINGWINDOW_H
#define SO2_PR2_INTERCEPTINGWINDOW_H


#include "Block.h"
#include <queue>
#include <thread>

class InterceptingWindow {

private:
    int areaWidthFrom, areaWidthTo, areaHeightFrom, areaHeightTo,windowNumber;
    std::queue<Block> blocks;

public:
    InterceptingWindow(std::queue<Block> &blocks,int windowNumber,int areaWidthFrom,int areaWidthTo,int areaHeightFrom,int areaHeightTo);
    void run();
    std::thread startThread();

};


#endif //SO2_PR2_INTERCEPTINGWINDOW_H
