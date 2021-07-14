#pragma once

#include "BaseObj.h"
#include "BaseFizikObj.h"

using namespace std;

class Utkozes : public BaseObj
{
protected:
    BaseFizikObj* a;
    BaseFizikObj* b;

    bool redundancia = false;

    pair<int, int> varhatoIdo;

public:
    Utkozes(BaseFizikObj* _a, BaseFizikObj* _b);
    ~Utkozes();

    pair<int, int> update();
    // (result=0) => feladat elvégezve; (result>0) =>  result = várható idõ az ütközésig
};

