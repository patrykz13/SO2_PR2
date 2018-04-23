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

class TetrisWindow {
private:
    Block fallingBlock;
    std::queue<Block> &blocks;
    std::mutex &ncursesMutex;
    std::mutex &conditionVarMutex;
    std::condition_variable &conditionVariable;
    int areaWidthFrom, areaWidthTo, areaHeightFrom, areaHeightTo;
    __useconds_t stepDelay;

    void run();

public:
    TetrisWindow(std::mutex &ncursesMutex, std::mutex &conditionVarMutex, std::condition_variable &conditionVariable,
                 std::queue<Block> &blocks, int areaWidthFrom, int areaWidthTo, int areaHeightFrom,
                 int areaHeightTo, __useconds_t stepDelay);

    ~TetrisWindow();

    std::thread startThread();
};


#endif //SO2_PR1_TETRISWINDOW_H
