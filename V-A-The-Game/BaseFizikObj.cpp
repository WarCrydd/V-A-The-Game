
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

void BaseFizikObj::addUtkozo(BaseFizikObj* _new)
{
    utkozok.push_back(_new);
}

void BaseFizikObj::removeUtkozo(BaseFizikObj* _old)
{
    utkozok.remove(_old);
}

bool BaseFizikObj::utkozoE(BaseFizikObj* _elem)
{
    if (find(utkozok.begin(), utkozok.end(), _elem) == utkozok.end())
    {
        return false;
    }

    return true;
}
