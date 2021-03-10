
#include "FizikObj.h"

FizikObj::FizikObj(int x, int y, int r, int h, int w)
{
    befogo = new SDL_Rect();
    befogo->h = h;
    befogo->w = w;
    mozgasAllapot = new MozgasAllapot(x, y, r, nullptr);
}

FizikObj::FizikObj(MozgasAllapot* _m)
{
    mozgasAllapot = _m;
}

SDL_Rect* FizikObj::getBefogo()
{
    return befogo;
}

MozgasAllapot* FizikObj::getMozgasAllapot()
{
    return mozgasAllapot;
}

void FizikObj::setMozgasAllapot(MozgasAllapot* _m)
{
    if (mozgasAllapot != nullptr)
    {
        delete mozgasAllapot;
    }

    mozgasAllapot = _m;
}