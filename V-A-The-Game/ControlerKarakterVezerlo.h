#pragma once
#include <list>
#include <iostream>

#include "VezerloObj.h"
#include "DefaultAdatok.h"

using namespace std;
using namespace Iranyitas;
class ControlerKarakterVezerlo : public VezerloObj
{
protected:
    SDL_Joystick* game;
    SDL_Point* mozgatas;

public:
    ControlerKarakterVezerlo(ElemiLelek* _f);

    virtual void objUpdate(SDL_Event& e) override;
};

