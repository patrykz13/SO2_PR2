//
// Created by Patryk Zdral on 19.04.2018.
//

#ifndef SO2_PR2_BLOCK_H
#define SO2_PR2_BLOCK_H


#include <thread>
#include <mutex>
#include <vector>
#include <ncurses.h>

typedef struct BlockSegment{
    int x;
    int y;
    char letter;

} BlockSegment;
class Block {
public:
    Block(int xPosition,  __useconds_t stepDelay,chtype segmentChar,int screenWidth,int screenHeight);
    ~Block();
    void start();
    bool moveBlock();
    std::thread startThread();
private:
    void initBlocks();
    void createRandomShape();
    int xPosition;
    int screenWidth;
    int screenHeight;
    std::vector<BlockSegment> blockSegments;
    static std::mutex mutex;
    __useconds_t stepDelay;
    const chtype segmentChar;
    //std::vector<std::vector<BlockSegment>> blocks;
    BlockSegment figures[7][4];
    std::vector<BlockSegment> fallingFigure;
    void drawFigure();
    void initFallingFigure(int nr,int pos);

    //const chtype segmentChar;


};


#endif //SO2_PR2_BLOCK_H
