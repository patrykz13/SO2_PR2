//
// Created by Patryk Zdral on 19.04.2018.
//

#ifndef SO2_PR2_BLOCK_H
#define SO2_PR2_BLOCK_H


#include <thread>
#include <mutex>
#include <vector>
#include <ncurses.h>

struct BlockSegment {
    int x, y;
    char letter;

    BlockSegment(int x, int y);
};
class Block {
public:
    Block(int xPosition,  __useconds_t stepDelay);
    ~Block();
    void start();
    bool moveBlock();
    std::thread startThread();
private:
    void initBlocks();
    void createRandomShape();
    int xPosition;
    std::vector<BlockSegment> blockSegments;
    static std::mutex mutex;
    __useconds_t stepDelay;
    std::vector<std::vector<BlockSegment>> blocks;

    //const chtype segmentChar;


};


#endif //SO2_PR2_BLOCK_H
