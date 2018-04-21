//
// Created by Patryk Zdral on 19.04.2018.
//

#include <iostream>
#include "Block.h"



Block::Block(int xPosition, __useconds_t stepDelay,chtype segmentChar,int screenWidth,int screenHeight): stepDelay(stepDelay),xPosition(xPosition),
                                                                                                         segmentChar(segmentChar),screenWidth(screenWidth),
                                                                                                         screenHeight(screenHeight)
{
}

Block::~Block() {

}

void Block::start() {
    initBlocks();
    initFallingFigure((rand() % 7) + 1,(rand() % (screenWidth/2)) -3);
    drawFigure();


}

std::thread Block::startThread() {
    return std::thread(&Block::start, this);
}

void Block::createRandomShape() {

}

bool Block::moveBlock() {
    for (int i=0;i<4;i++){
        mvaddch(fallingFigure[i].y,fallingFigure[i].x, ' ');
        fallingFigure[i].y++;
        if (fallingFigure[i].y==screenHeight/2-1)
            return false;
        mvaddch(fallingFigure[i].y,fallingFigure[i].x, segmentChar);
    }
    return true;
}

void Block::initBlocks() {

    // std::vector<std::vector<BlockSegment> > blocks(4,std::vector<BlockSegment>(4, 0)); //creates 4x4 nested vector
    //blocks=buff;
    // I
    // I
    figures[0][0].x=1; figures[0][0].y=1; figures[0][1].x=2; figures[0][1].y=1; figures[0][2].x=3; figures[0][2].y=1;
    figures[0][3].x=4; figures[0][3].y=1;
    figures[0][0].letter='I';

    //T
    figures[1][0].x=1; figures[1][0].y=1; figures[1][1].x=2; figures[1][1].y=1; figures[1][2].x=3; figures[1][2].y=1;
    figures[1][3].x=2; figures[1][3].y=2;
    figures[1][0].letter='T';

    //O
    figures[2][0].x=1; figures[2][0].y=1; figures[2][1].x=2; figures[2][1].y=1; figures[2][2].x=1; figures[2][2].y=2;
    figures[2][3].x=2; figures[2][3].y=2;
    figures[2][0].letter='O';

    //L
    figures[3][0].x=1; figures[3][0].y=1; figures[3][1].x=1; figures[3][1].y=2; figures[3][2].x=1; figures[3][2].y=3;
    figures[3][3].x=2; figures[3][3].y=3;
    figures[3][0].letter='L';

    //J
    figures[4][0].x=2; figures[4][0].y=1; figures[4][1].x=2; figures[4][1].y=2; figures[4][2].x=2; figures[4][2].y=3;
    figures[4][3].x=1; figures[4][3].y=3;
    figures[4][0].letter='J';

    //S
    figures[5][0].x=1; figures[5][0].y=2; figures[5][1].x=2; figures[5][1].y=2; figures[5][2].x=2; figures[5][2].y=1;
    figures[5][3].x=3; figures[5][3].y=1;
    figures[5][0].letter='S';

    //Z
    figures[6][0].x=1; figures[6][0].y=1; figures[6][1].x=2; figures[6][1].y=1; figures[6][2].x=2; figures[6][2].y=2;
    figures[6][3].x=3; figures[6][3].y=2;
    figures[6][0].letter='Z';
}

void Block::drawFigure() { // narysowanie figury (w opadającym oknie)
    for (auto &i : fallingFigure) {
        move(i.y, i.x);
        addch(segmentChar);
    }
}
void Block::initFallingFigure(int nr,int pos){  //inicjacja figury do opadania w 1 oknie

    std::cout<<nr;
    for (int i=0;i<4;i++){
        figures[nr-1][i].x+=pos;
    }
    for (int i=0;i<4;i++){
        fallingFigure.push_back(figures[nr-1][i]);
    }

}

