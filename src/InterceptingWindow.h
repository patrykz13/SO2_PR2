//
// Created by mrfarinq on 22.04.18.
//

#ifndef SO2_PR2_INTERCEPTINGWINDOW_H
#define SO2_PR2_INTERCEPTINGWINDOW_H


#include "Block.h"
#include <queue>
#include <thread>
#include <condition_variable>


class InterceptingWindow {
private:
    std::queue<Block> &blocks;
    std::mutex &ncursesMutex;
    std::mutex &conditionVarMutex;
    std::condition_variable &conditionVariable;
    int areaWidthFrom, areaWidthTo, areaHeightFrom, areaHeightTo, windowNumber;

    void run();

public:
    InterceptingWindow(std::mutex &ncursesMutex, std::mutex &conditionVarMutex,
                       std::condition_variable &conditionVariable, std::queue<Block> &blocks,
                       int areaWidthFrom, int areaWidthTo, int areaHeightFrom, int areaHeightTo);

    virtual ~InterceptingWindow();

    std::thread startThread();
};


#endif //SO2_PR2_INTERCEPTINGWINDOW_H
