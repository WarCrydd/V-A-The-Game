#pragma once

#include <SDL.h>

#include "BaseFizikObj.h"
#include "BaseObj.h"

using namespace std;
class ElemiLelek : public BaseObj
{
protected:
    BaseFizikObj* test;

public:
    ElemiLelek(BaseFizikObj* _test);

    virtual void mozgasIgeny(MyPoint* vector) = 0;
};
