#pragma once
#include "EpitoElem.h"
class EgysegNegyzet : public EpitoElem
{
public:
    virtual void update() override;
    virtual void setSurface() override;
};

