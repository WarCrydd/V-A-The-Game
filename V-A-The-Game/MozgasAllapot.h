#pragma once

#include <SDL.h>
#include "BaseObj.h"
#include "Strukturak.h"
#include "BaseFizikObj.h"

using namespace std;
using namespace MyStructs;

class MozgasAllapot : public BaseObj
{
protected:
    MyPoint* kozepPont = nullptr;
    MyPoint* sebeseg = nullptr;
    BaseFizikObj* felulet = nullptr;
    int* forgas = nullptr;
    int* tomeg = nullptr;
    
public:
    MozgasAllapot(int x, int y, int r, MyPoint* _mozgas, BaseFizikObj* _f);

    MyPoint* getKozepPont();
    MyPoint* getSebesseg();
    int* getForgas();
    void update(int ido);
};
