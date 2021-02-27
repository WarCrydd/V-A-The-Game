
#include "FizikObj.h"

FizikObj::FizikObj(int x, int y, int r)
{
    mozgasAllapot = new MozgasAllapot(x, y, r, nullptr, nullptr);
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

void FizikObj::update()
{
}
