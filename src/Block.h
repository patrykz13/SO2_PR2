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
    std::vector<BlockSegment> blockParts;
    int blockType;

    void initBlockParts(int blockType, int shift);

public:
    explicit Block(int blockType, int shift);

    virtual ~Block();
};


#endif //SO2_PR2_BLOCK_H
