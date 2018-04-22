//
// Created by mrfarinq on 22.04.18.
//

#include "InterceptingWindow.h"


InterceptingWindow::InterceptingWindow(int windowNumber,int areaWidthFrom, int areaWidthTo, int areaHeightFrom,
                                       int areaHeightTo) :Window(areaWidthFrom, areaWidthTo,areaHeightFrom, areaHeightTo) {
    this->windowNumber=windowNumber;

}

void InterceptingWindow::drawFigure() {

}
