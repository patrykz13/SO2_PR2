//
// Created by Patryk Zdral on 19.04.2018.
//

#ifndef SO2_PR2_BLOCKSARENA_H
#define SO2_PR2_BLOCKSARENA_H

#include <queue>
#include <thread>
#include <condition_variable>
#include "Block.h"


class BlocksArena {
    void drawDividedScreen(int yFrom, int yTo, int xFrom, int xTo);

public:
    BlocksArena(int xFrom, int xTo, int yFrom, int yTo, __useconds_t stepDelay);

    virtual ~BlocksArena();
};


#endif //SO2_PR2_BLOCKSARENA_H
