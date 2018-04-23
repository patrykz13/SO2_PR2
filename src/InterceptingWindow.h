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
    std::mutex& mutexNcurses;
    std::mutex& mutexCondition;
    std::condition_variable& condition_variable;
    int areaWidthFrom, areaWidthTo, areaHeightFrom, areaHeightTo,windowNumber;
    std::queue<Block>& blocks;

public:
    InterceptingWindow(std::mutex &m, std::mutex &m2, std::condition_variable &c, std::queue<Block> &blocks,int areaWidthFrom,int areaWidthTo,int areaHeightFrom,int areaHeightTo);
    void run();
    std::thread startThread();
    void drawFigure(Block p);

};


#endif //SO2_PR2_INTERCEPTINGWINDOW_H
