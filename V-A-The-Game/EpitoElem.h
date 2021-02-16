#pragma once
#include "MyObj.h"
class EpitoElem : public MyObj
{
protected:
    
public:

    virtual void update() = 0;
    virtual void setSurface() = 0;
};

