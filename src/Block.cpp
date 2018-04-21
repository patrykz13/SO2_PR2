//
// Created by Patryk Zdral on 19.04.2018.
//

#include "Block.h"

BlockSegment::BlockSegment(int x, int y) {

}

Block::Block(int xPosition, __useconds_t stepDelay): stepDelay(stepDelay),xPosition(xPosition)
{

}

Block::~Block() {

}

void Block::start() {
    initBlocks();

}

std::thread Block::startThread() {
    return std::thread(&Block::start, this);
}

void Block::createRandomShape() {

}

bool Block::moveBlock() {
    return false;
}

void Block::initBlocks() {
   // std::vector<std::vector<BlockSegment> > blocks(4,std::vector<BlockSegment>(4, 0)); //creates 4x4 nested vector
    //blocks=buff;
    // I
    blocks[0][0].x=30; blocks[0][0].y=1; blocks[0][1].x=31; blocks[0][1].y=1; blocks[0][2].x=32; blocks[0][2].y=1;
    blocks[0][3].x=33; blocks[0][3].y=1;
    blocks[0][0].letter='I';

    //T
    blocks[1][0].x=30; blocks[1][0].y=1; blocks[1][1].x=31; blocks[1][1].y=1; blocks[1][2].x=32; blocks[1][2].y=1;
    blocks[1][3].x=31; blocks[1][3].y=2;
    blocks[1][0].letter='T';

    //O
    blocks[2][0].x=30; blocks[2][0].y=1; blocks[2][1].x=31; blocks[2][1].y=1; blocks[2][2].x=30; blocks[2][2].y=2;
    blocks[2][3].x=31; blocks[2][3].y=2;
    blocks[2][0].letter='O';

    //L
    blocks[3][0].x=30; blocks[3][0].y=1; blocks[3][1].x=30; blocks[3][1].y=2; blocks[3][2].x=30; blocks[3][2].y=3;
    blocks[3][3].x=31; blocks[3][3].y=3;
    blocks[3][0].letter='L';

    //J
    blocks[4][0].x=31; blocks[4][0].y=1; blocks[4][1].x=31; blocks[4][1].y=2; blocks[4][2].x=31; blocks[4][2].y=3;
    blocks[4][3].x=30; blocks[4][3].y=3;
    blocks[4][0].letter='J';

    //S
    blocks[5][0].x=30; blocks[5][0].y=2; blocks[5][1].x=31; blocks[5][1].y=2; blocks[5][2].x=31; blocks[5][2].y=1;
    blocks[5][3].x=32; blocks[5][3].y=1;
    blocks[5][0].letter='S';

    //Z
    blocks[6][0].x=30; blocks[6][0].y=1; blocks[6][1].x=31; blocks[6][1].y=1; blocks[6][2].x=31; blocks[6][2].y=2;
    blocks[6][3].x=32; blocks[6][3].y=2;
    blocks[6][0].letter='Z';
}
