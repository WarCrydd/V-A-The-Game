#include "MozgasAllapot.h"

MozgasAllapot::MozgasAllapot(int x, int y, int r, SDL_Point* _mozgas, SDL_Point* _gyorsulas)
{
    kozepPont = new SDL_Point();
    kozepPont->x = x;
    kozepPont->y = y;

    mozgas = _mozgas;
    gyorsulas = _gyorsulas;
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
    return mozgas;
}

void MozgasAllapot::setMozgas(SDL_Point* _m)
{
    if (mozgas != nullptr)
    {
        delete mozgas;
    }

    mozgas = _m;
}

SDL_Point* MozgasAllapot::getGyorsulas()
{
    return gyorsulas;
}

void MozgasAllapot::setGyorsulas(SDL_Point* _gy)
{
    if (gyorsulas != nullptr)
    {
        delete gyorsulas;
    }

    gyorsulas = _gy;
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
