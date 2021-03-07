
#include "FizikObj.h"

FizikObj::FizikObj(int x, int y, int r)
{
    SDL_Point* a = new SDL_Point();
    a->x = 0;
    a->y = 0;
    SDL_Point* pp = new SDL_Point();
    pp->x = 0;
    pp->y = 0;
    mozgasAllapot = new MozgasAllapot(x, y, r, pp);
}

FizikObj::FizikObj(MozgasAllapot* _m)
{
    mozgasAllapot = _m;
}

MozgasAllapot* FizikObj::getMozgasAllapot()
{
    return nullptr;
}

void FizikObj::setMozgasAllapot(MozgasAllapot* _m)
{
    if (mozgasAllapot != nullptr)
    {
        delete mozgasAllapot;
    }

    mozgasAllapot = _m;
}

void FizikObj::setKozepPont(SDL_Point* _kozepPont)
{
    mozgasAllapot->setKozepPont(_kozepPont);
}

SDL_Point* FizikObj::getKozepPont()
{
    return mozgasAllapot->getKozepPont();
}

int* FizikObj::getForgatas()
{
    return mozgasAllapot->getForgas();
}