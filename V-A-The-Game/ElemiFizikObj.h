#pragma once
#include <chrono>

#include "BaseFizikObj.h"

using namespace std;
class ElemiFizikObj : public BaseFizikObj
{
protected:
    double ido_maradek = 0;

public:
    ElemiFizikObj(int x, int y, int r, int h, int w);

    virtual void update(double ido) override;
};
