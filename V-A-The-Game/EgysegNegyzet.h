#pragma once

#include "EpitoElem.h"

class EgysegNegyzet : public EpitoElem
{
public:
    EgysegNegyzet(BaseFizikObj* _body, GrafikObj* _megjelenes);

    virtual void update() override;
};
