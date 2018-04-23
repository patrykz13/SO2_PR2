//
// Created by mrfarinq on 22.04.18.
//

#include <ncurses.h>
#include <cstdlib>
#include "Block.h"


BlockSegment::BlockSegment(int x, int y) : x(x), y(y) {}

Block::Block() = default;

Block::~Block() = default;

void Block::initBlockParts(int blockType, int shift) {
    this->blockType = blockType;
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
    blockParts.clear();
    int shiftWidth = areaWidthFrom + rand() % (( areaWidthTo + 1 ) - areaWidthFrom), shiftHeight = areaHeightFrom + rand() % (( areaHeightTo + 1 ) - areaHeightFrom);

    switch (blockType) {
        case 0:
            blockParts.emplace_back(1 + shiftWidth, 1 + shiftHeight);
            blockParts.emplace_back(2 + shiftWidth, 1 + shiftHeight);
            blockParts.emplace_back(3 + shiftWidth, 1 + shiftHeight);
            blockParts.emplace_back(4 + shiftWidth, 1 + shiftHeight);
            break;

        case 1:
            blockParts.emplace_back(1 + shiftWidth, 1 + shiftHeight);
            blockParts.emplace_back(2 + shiftWidth, 1 + shiftHeight);
            blockParts.emplace_back(3 + shiftWidth, 1 + shiftHeight);
            blockParts.emplace_back(2 + shiftWidth, 2 + shiftHeight);
            break;

        case 2:
            blockParts.emplace_back(1 + shiftWidth, 1 + shiftHeight);
            blockParts.emplace_back(2 + shiftWidth, 1 + shiftHeight);
            blockParts.emplace_back(1 + shiftWidth, 2 + shiftHeight);
            blockParts.emplace_back(2 + shiftWidth, 2 + shiftHeight);
            break;

        case 3:
            blockParts.emplace_back(1 + shiftWidth, 1 + shiftHeight);
            blockParts.emplace_back(1 + shiftWidth, 2 + shiftHeight);
            blockParts.emplace_back(1 + shiftWidth, 3 + shiftHeight);
            blockParts.emplace_back(2 + shiftWidth, 3 + shiftHeight);
            break;

        case 4:
            blockParts.emplace_back(2 + shiftWidth, 1 + shiftHeight);
            blockParts.emplace_back(2 + shiftWidth, 2 + shiftHeight);
            blockParts.emplace_back(2 + shiftWidth, 3 + shiftHeight);
            blockParts.emplace_back(1 + shiftWidth, 3 + shiftHeight);
            break;

        case 5:
            blockParts.emplace_back(1 + shiftWidth, 2 + shiftHeight);
            blockParts.emplace_back(2 + shiftWidth, 2 + shiftHeight);
            blockParts.emplace_back(2 + shiftWidth, 1 + shiftHeight);
            blockParts.emplace_back(3 + shiftWidth, 1 + shiftHeight);
            break;

        case 6:
            blockParts.emplace_back(1 + shiftWidth, 1 + shiftHeight);
            blockParts.emplace_back(2 + shiftWidth, 1 + shiftHeight);
            blockParts.emplace_back(2 + shiftWidth, 2 + shiftHeight);
            blockParts.emplace_back(3 + shiftWidth, 2 + shiftHeight);
            break;
        default:
            break;
    }
}


