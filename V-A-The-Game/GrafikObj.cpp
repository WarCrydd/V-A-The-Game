
#include "GrafikObj.h"

GrafikObj::GrafikObj(FizikObj* _f)
{
    keret = new SDL_Rect();
    kozepPont = _f->getKozepPont();
    forgatas = _f->getForgatas();
    testKozepPont = new SDL_Point();
}

void GrafikObj::setKinezet(SDL_Surface* _kinezet)
{
    if (kinezet != nullptr)
    {
        SDL_FreeSurface(kinezet);
        kinezet = nullptr;
    }

    kinezet = _kinezet;
}

void GrafikObj::texturaBe(SDL_Renderer* render)
{
    if (!betoltve)
    {
        textura = SDL_CreateTextureFromSurface(render, kinezet);
        betoltve = true;
    }
}

void GrafikObj::texturaKi()
{
    if (textura != nullptr)
    {
        SDL_DestroyTexture(textura);
        textura = nullptr;
        betoltve = false;
    }
}

void GrafikObj::pontokFrisit()
{
    testKozepPont->x = keret->w / 2;
    testKozepPont->y = keret->h / 2;
}

bool GrafikObj::getBetoltve()
{
    return betoltve;
}

SDL_Texture* GrafikObj::getTexture()
{
    if (betoltve)
    {
        return textura;
    }
    return nullptr;
}

SDL_Rect* GrafikObj::getKeret()
{
    return keret;
}

SDL_Rect* GrafikObj::getKeret(SDL_Point* pont, int hosz, int magassag)
{
    keret->x = kozepPont->x - (pont->x - hosz) - keret->w / 2;
    keret->y = kozepPont->y - (pont->y - magassag) - keret->h / 2;
    return keret;
}

SDL_Point* GrafikObj::getKozepPont()
{
    return kozepPont;
}

SDL_Point* GrafikObj::getForgatasiKozepPont()
{
    return testKozepPont;
}

int* GrafikObj::getForgatas()
{
    return forgatas;
}
