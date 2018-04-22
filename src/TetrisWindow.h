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
#include <stdint.h>
#include "Block.h"
#include "Window.h"


class TetrisWindow: public Window {
private:
    std::mutex mutex;
    std::condition_variable condition_variable;

    Block fallingBlock;

    int areaWidthFrom, areaWidthTo, areaHeightFrom, areaHeightTo;
    __useconds_t stepDelay;

    bool doOneStep();

    void drawFigure();

    void clearWindow();

public:
    TetrisWindow(int areaWidthFrom, int areaWidthTo, int areaHeightFrom,
                 int areaHeightTo, __useconds_t stepDelay);

    ~TetrisWindow();

    void run() override;

    std::thread startThread() override;
};


#endif //SO2_PR1_TETRISWINDOW_H
