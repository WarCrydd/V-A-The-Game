
#include "GrafikObj.h"

GrafikObj::GrafikObj(BaseFizikObj* _f)
{
    testKeret = new SDL_Rect();
    testKozepPont = new SDL_Point();

    kozepPont = _f->getMozgasAllapot()->getKozepPont();
    keret = _f->getBefogo();
    forgatas = _f->getMozgasAllapot()->getForgas();
    
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

void GrafikObj::pontokFrisit(int arany)
{
    testKeret->h = keret->h / arany;
    testKeret->w = keret->w / arany;

    testKozepPont->x = testKeret->w / 2;
    testKozepPont->y = testKeret->h / 2;
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
    return testKeret;
}

SDL_Rect* GrafikObj::getKeret(SDL_Point* pont, int hosz, int magassag, int arany)
{
    testKeret->x = (kozepPont->x - (pont->x - hosz * arany) - testKeret->w / 2) / arany;
    testKeret->y = (kozepPont->y - (pont->y - magassag * arany) - testKeret->h / 2) / arany;
    return testKeret;
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
