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
    // (result=0) => feladat elv�gezve; (result>0) =>  result = v�rhat� id� az �tk�z�sig
};

