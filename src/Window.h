//
// Created by mrfarinq on 22.04.18.
//

#ifndef SO2_PR2_WINDOW_H
#define SO2_PR2_WINDOW_H

#include <thread>
#include "Block.h"
#include <queue>

class Window
{
protected:
    int areaWidthFrom;
    int areaWidthTo;
    int areaHeightFrom;
    int areaHeightTo;
public:
    Window(int areaWidthFrom,int areaWidthTo,int areaHeightFrom,int areaHeightTo);
    static std::queue<Block> blocks;
    virtual void run() {}

    virtual std::thread startThread() {};
};


#endif //SO2_PR2_WINDOW_H
