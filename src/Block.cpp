//
// Created by mrfarinq on 22.04.18.
//

#include <ncurses.h>
#include "Block.h"


BlockSegment::BlockSegment(int x, int y) : x(x), y(y) {}

Block::Block() = default;

Block::~Block() = default;

void Block::initBlockParts(int blockType, int shift) {
    blockParts.clear();

    switch (blockType) {
        case 0:
            blockParts.emplace_back(1 + shift, 1);
            blockParts.emplace_back(2 + shift, 1);
            blockParts.emplace_back(3 + shift, 1);
            blockParts.emplace_back(4 + shift, 1);
            break;

        case 1:
            blockParts.emplace_back(1 + shift, 1);
            blockParts.emplace_back(2 + shift, 1);
            blockParts.emplace_back(3 + shift, 1);
            blockParts.emplace_back(2 + shift, 2);
            break;

        case 2:
            blockParts.emplace_back(1 + shift, 1);
            blockParts.emplace_back(2 + shift, 1);
            blockParts.emplace_back(1 + shift, 2);
            blockParts.emplace_back(2 + shift, 2);
            break;

        case 3:
            blockParts.emplace_back(1 + shift, 1);
            blockParts.emplace_back(1 + shift, 2);
            blockParts.emplace_back(1 + shift, 3);
            blockParts.emplace_back(2 + shift, 3);
            break;

        case 4:
            blockParts.emplace_back(2 + shift, 1);
            blockParts.emplace_back(2 + shift, 2);
            blockParts.emplace_back(2 + shift, 3);
            blockParts.emplace_back(1 + shift, 3);
            break;

        case 5:
            blockParts.emplace_back(1 + shift, 2);
            blockParts.emplace_back(2 + shift, 2);
            blockParts.emplace_back(2 + shift, 1);
            blockParts.emplace_back(3 + shift, 1);
            break;

        case 6:
            blockParts.emplace_back(1 + shift, 1);
            blockParts.emplace_back(2 + shift, 1);
            blockParts.emplace_back(2 + shift, 2);
            blockParts.emplace_back(3 + shift, 2);
            break;
        default:
            break;
    }
}

std::vector<BlockSegment> &Block::getBlockParts() {
    return blockParts;
}

void
Block::setBlockPartsForInterceptingWindow(int areaWidthFrom, int areaWidthTo, int areaHeightFrom, int areaHeightTo) {

}


