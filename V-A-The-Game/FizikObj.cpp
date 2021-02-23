
#include "FizikObj.h"

FizikObj::FizikObj(int x, int y, int r)
{
    forgatas = new int(r);
    kozepPont = new SDL_Point();
    kozepPont->x = x;
    kozepPont->y = y;
}

void FizikObj::setKozepPont(SDL_Point* _kozepPont)
{
    kozepPont = _kozepPont;
}

SDL_Point* FizikObj::getKozepPont()
{
    return kozepPont;
}

int* FizikObj::getForgatas()
{
    return forgatas;
}

void FizikObj::update()
{
}
