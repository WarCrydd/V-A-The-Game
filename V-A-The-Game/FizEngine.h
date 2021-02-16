#pragma once
#include <list>
#include <algorithm>

#include "FizikObj.h"

using namespace std;

class FizEngine
{
protected:
    list<FizikObj*>* entitasok;
public:
    FizEngine();
    ~FizEngine();

    void addEntitas(FizikObj* _entiti);
    bool removEntitas(FizikObj* _entiti);
};

