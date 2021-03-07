#pragma once
#include <chrono>

#include "FizikObj.h"

using namespace std;
class ElemiFizikObj : public FizikObj
{
protected:
    double ido_maradek = 0;

public:
    ElemiFizikObj(int x, int y, int r);

    virtual void update(double ido) override;
};

