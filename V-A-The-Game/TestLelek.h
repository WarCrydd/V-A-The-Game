#pragma once
#include "ElemiLelek.h"
#include "BaseFizikObj.h"

using namespace std;
class TestLelek : public ElemiLelek
{
protected:

public:
    TestLelek(BaseFizikObj* _b);

    virtual void mozgasIgeny(SDL_Point* vector) override;
};

