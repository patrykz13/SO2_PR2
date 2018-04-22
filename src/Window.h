//
// Created by mrfarinq on 22.04.18.
//

#ifndef SO2_PR2_WINDOW_H
#define SO2_PR2_WINDOW_H

#include <thread>

class IWindow
{
public:
    virtual void run() {}

    virtual std::thread startThread() {};
};

#endif //SO2_PR2_WINDOW_H
