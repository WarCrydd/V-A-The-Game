#include "MozgasAllapot.h"

MozgasAllapot::MozgasAllapot(int x, int y, int r, SDL_Point* _mozgas)
{
    kozepPont = new SDL_Point();
    kozepPont->x = x;
    kozepPont->y = y;

    forgas = new int(r);
}

SDL_Point* MozgasAllapot::getKozepPont()
{
    return kozepPont;
}

void MozgasAllapot::setKozepPont(SDL_Point* _p)
{
    if (kozepPont != nullptr)
    {
        delete kozepPont;
    }
    kozepPont = _p;
}

SDL_Point* MozgasAllapot::getMozgas()
{
    return sebeseg;
}

void MozgasAllapot::setMozgas(SDL_Point* _m)
{
    if (sebeseg != nullptr)
    {
        delete sebeseg;
    }

    sebeseg = _m;
}

int* MozgasAllapot::getForgas()
{
    return forgas;
}

void MozgasAllapot::setForgas(int* _f)
{
    if (forgas != nullptr)
    {
        delete forgas;
    }

    forgas = _f;
}

void MozgasAllapot::update(double ido)
{
    kozepPont->x += sebeseg->x * ido;
    kozepPont->y += sebeseg->y * ido;
}
