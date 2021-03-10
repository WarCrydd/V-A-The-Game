#pragma once

#include <SDL.h>
#include <chrono>

#include "MozgasAllapot.h"
class FizikObj
{
protected:
    MozgasAllapot* mozgasAllapot = nullptr;
    SDL_Rect* befogo = nullptr;

public:
    FizikObj(int x, int y, int r, int h, int w);

    FizikObj(MozgasAllapot* _m);

    SDL_Rect* getBefogo();

    MozgasAllapot* getMozgasAllapot();
    void setMozgasAllapot(MozgasAllapot* _m);

    virtual void update(double ido) = 0;

};
