#pragma once

#include <SDL.h>
#include <chrono>

#include "MozgasAllapot.h"
class FizikObj
{
protected:
    MozgasAllapot* mozgasAllapot = nullptr;

public:
    FizikObj(int x, int y, int r);

    FizikObj(MozgasAllapot* _m);

    MozgasAllapot* getMozgasAllapot();
    void setMozgasAllapot(MozgasAllapot* _m);

    void setKozepPont(SDL_Point* _kozepPont);
    SDL_Point* getKozepPont();
    int* getForgatas();

    virtual void update(double ido) = 0;

};
