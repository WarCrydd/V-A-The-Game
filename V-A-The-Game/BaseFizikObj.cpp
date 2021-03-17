
#include "BaseFizikObj.h"

BaseFizikObj::BaseFizikObj(int x, int y, int r, int h, int w)
{
    befogo = new SDL_Rect();
    befogo->h = h;
    befogo->w = w;
    mozgasAllapot = new MozgasAllapot(x, y, r, nullptr);
}

BaseFizikObj::BaseFizikObj(MozgasAllapot* _m)
{
    mozgasAllapot = _m;
}

SDL_Rect* BaseFizikObj::getBefogo()
{
    return befogo;
}

MozgasAllapot* BaseFizikObj::getMozgasAllapot()
{
    return mozgasAllapot;
}

void BaseFizikObj::setMozgasAllapot(MozgasAllapot* _m)
{
    if (mozgasAllapot != nullptr)
    {
        delete mozgasAllapot;
    }

    mozgasAllapot = _m;
}