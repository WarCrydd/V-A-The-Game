#include "MozgasAllapot.h"

MozgasAllapot::MozgasAllapot(int x, int y, int r, SDL_Point* _mozgas)
{
    kozepPont = new SDL_Point();
    kozepPont->x = x;
    kozepPont->y = y;
    if (_mozgas == nullptr)
    {
        sebeseg = new SDL_Point();
        sebeseg->x = 0;
        sebeseg->y = 0;
    }
    else
    {
        sebeseg = _mozgas;
    }

    sebeseg = _mozgas;
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

SDL_Point* MozgasAllapot::getSebesseg()
{
    return sebeseg;
}

void MozgasAllapot::setSebesseg(SDL_Point* _m)
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

void MozgasAllapot::update(int ido)
{
    kozepPont->x += sebeseg->x * ido;
    kozepPont->y += sebeseg->y * ido;
}
