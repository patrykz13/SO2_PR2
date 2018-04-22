//
// Created by mrfarinq on 22.04.18.
//

#ifndef SO2_PR2_INTERCEPTINGWINDOW_H
#define SO2_PR2_INTERCEPTINGWINDOW_H


#include "Window.h"
#include "Block.h"
#include <queue>

class InterceptingWindow: public IWindow {

private:
    int areaWidthFrom, areaWidthTo, areaHeightFrom, areaHeightTo,windowNumber;
    std::queue<Block> blocks;

public:
    InterceptingWindow(std::queue<Block> &blocks,int windowNumber,int areaWidthFrom,int areaWidthTo,int areaHeightFrom,int areaHeightTo);
    void run() override;
    std::thread startThread() override;

};


#endif //SO2_PR2_INTERCEPTINGWINDOW_H
