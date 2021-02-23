#pragma once

#include "MyObj.h"
class EpitoElem : public MyObj
{
protected:
    int tMagassag = 0;
    int tHossz = 0;
public:
    EpitoElem(int _m, int _h, FizikObj* _body, GrafikObj* _megjelenes);

    virtual void update() = 0;
};

