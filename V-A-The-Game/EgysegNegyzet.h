#pragma once
#include "EpitoElem.h"
class EgysegNegyzet : public EpitoElem
{
public:
    EgysegNegyzet(int _m, int _h, FizikObj* _body, GrafikObj* _megjelenes);

    virtual void update() override;
};

