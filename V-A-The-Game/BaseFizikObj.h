#pragma once

#include <SDL.h>
#include <chrono>

#include "MozgasAllapot.h"
#include "BaseObj.h"

class BaseFizikObj : public BaseObj
{
protected:
    MozgasAllapot* mozgasAllapot = nullptr;
    SDL_Rect* befogo = nullptr;

public:
    BaseFizikObj(int x, int y, int r, int h, int w);

    BaseFizikObj(MozgasAllapot* _m);

    SDL_Rect* getBefogo();

    MozgasAllapot* getMozgasAllapot();
    void setMozgasAllapot(MozgasAllapot* _m);

    virtual void update(double ido) = 0;

};
