#pragma once
#include "VezerloObj.h"
#include "DefaultAdatok.h"
#include "ElemiFizikObj.h"

using namespace std;
class KeyboardKarakterVezerlo : public VezerloObj
{
protected:
    map<SDL_KeyCode, Test> valtoTabla;

public:
    KeyboardKarakterVezerlo(ElemiLelek* _f, map<SDL_KeyCode, Test> _valto);

    virtual void objUpdate(SDL_Event& e) override;
};

