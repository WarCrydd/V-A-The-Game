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

    forgas = new int(r);
}

SDL_Point* MozgasAllapot::getKozepPont()
{
    return kozepPont;
}

SDL_Point* MozgasAllapot::getSebesseg()
{
    return sebeseg;
}

int* MozgasAllapot::getForgas()
{
    return forgas;
}

void MozgasAllapot::update(int ido)
{
    kozepPont->x += sebeseg->x * ido;
    kozepPont->y += sebeseg->y * ido;
}
