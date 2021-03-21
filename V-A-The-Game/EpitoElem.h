#pragma once

#include "MyObj.h"
class EpitoElem : public MyObj
{
protected:
    
public:
    EpitoElem(BaseFizikObj* _body, GrafikObj* _megjelenes);

    virtual void update() = 0;
};

