//
// Created by mrfarinq on 22.04.18.
//

#ifndef SO2_PR2_INTERCEPTINGWINDOW_H
#define SO2_PR2_INTERCEPTINGWINDOW_H


#include "Block.h"
#include <queue>
#include <thread>
#include <condition_variable>


class InterceptingWindow{

private:
    static std::mutex mutex;
    std::condition_variable condition_variable;
    int areaWidthFrom, areaWidthTo, areaHeightFrom, areaHeightTo,windowNumber;
    std::queue<Block> blocks;

public:
    InterceptingWindow(std::queue<Block> &blocks,int windowNumber,int areaWidthFrom,int areaWidthTo,int areaHeightFrom,int areaHeightTo);
    void run();
    std::thread startThread();
    void drawFigure();

};


#endif //SO2_PR2_INTERCEPTINGWINDOW_H
