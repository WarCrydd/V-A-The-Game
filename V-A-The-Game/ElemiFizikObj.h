#pragma once
#include <chrono>

#include "FizikObj.h"

using namespace std;
class ElemiFizikObj : public FizikObj
{
protected:
    chrono::system_clock::time_point start = chrono::system_clock().now();
    chrono::system_clock::time_point end = chrono::system_clock().now();

public:
    ElemiFizikObj(int x, int y, int r);

    virtual void update() override;
};

