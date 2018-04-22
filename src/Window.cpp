//
// Created by patrykzdral on 22.04.18.
//

#include "Window.h"
#include <queue>

std::queue<Block> Window::blocks;
Window::Window(int areaWidthFrom, int areaWidthTo, int areaHeightFrom, int areaHeightTo): areaHeightFrom(areaHeightFrom), areaHeightTo(areaHeightTo), areaWidthFrom(areaWidthFrom), areaWidthTo(areaWidthTo){

}
