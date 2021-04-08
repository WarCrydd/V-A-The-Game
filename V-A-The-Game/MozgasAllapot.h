#pragma once
#include <SDL.h>

#include "BaseObj.h"
#include "Strukturak.h"

using namespace std;
using namespace MyStructs;
class MozgasAllapot : public BaseObj
{
protected:
    MyPoint* kozepPont = nullptr;
    MyPoint* sebeseg = nullptr;
    int* forgas = nullptr;
    int* tomeg = nullptr;
    //g-ban

public:
    MozgasAllapot(int x, int y, int r, MyPoint* _mozgas);

    MyPoint* getKozepPont();

    MyPoint* getSebesseg();

    int* getForgas();
    
    void update(int ido);
};
