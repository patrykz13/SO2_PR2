//
// Created by mrfarinq on 22.04.18.
//

#ifndef SO2_PR2_INTERCEPTINGWINDOW_H
#define SO2_PR2_INTERCEPTINGWINDOW_H


#include "Window.h"
#include <iostream>

class InterceptingWindow: public Window {

public:
    int windowNumber;
    InterceptingWindow(int window,int areaWidthFrom, int areaWidthTo, int areaHeightFrom,
                                int areaHeightTo);
private:
    void drawFigure();
    std::pair<int, int> randPlace(int windowNumber);

};


#endif //SO2_PR2_INTERCEPTINGWINDOW_H
