//
// Created by Patryk Zdral on 19.04.2018.
//

#ifndef SO2_PR1_TETRISWINDOW_H
#define SO2_PR1_TETRISWINDOW_H


#include <thread>
#include <mutex>
#include <vector>
#include <ncurses.h>
#include <queue>
#include <condition_variable>
#include "Block.h"

class TetrisWindow{
private:
    static std::mutex mutex;
    static std::condition_variable conditionVariable;

    std::queue<Block> blocks;
    Block fallingBlock;

    int areaWidthFrom, areaWidthTo, areaHeightFrom, areaHeightTo;
    __useconds_t stepDelay;

    bool doOneStep();

    void drawFigure();

    void clearFigure();


public:
    TetrisWindow(std::queue<Block> &blocks, int areaWidthFrom, int areaWidthTo, int areaHeightFrom,
                 int areaHeightTo, __useconds_t stepDelay);

    ~TetrisWindow();

    void run();
    std::thread startThread();
};


#endif //SO2_PR1_TETRISWINDOW_H
