//
// Created by mrfarinq on 22.04.18.
//

#ifndef SO2_PR2_BLOCK_H
#define SO2_PR2_BLOCK_H


#include <vector>

struct BlockSegment {
    int x, y;

    BlockSegment(int x, int y);
};

class Block {
private:
    int blockType;
    std::vector<BlockSegment> blockParts;

public:
    explicit Block();

    virtual ~Block();

    void initBlockParts(int blockType, int shift);

    void setBlockPartsForInterceptingWindow(int areaWidthFrom, int areaWidthTo, int areaHeightFrom, int areaHeightTo);

    void drawFigure();

    void clearFigure();

    bool doOneStep(int areaHeightTo);
};


#endif //SO2_PR2_BLOCK_H
