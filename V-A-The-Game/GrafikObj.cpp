
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

SDL_Rect* GrafikObj::getKeret(MyPoint* pont, int hosz, int magassag, int arany)
{
    pontokFrisit(arany);
    testKeret->x = ((kozepPont->x - pont->x) / arany) - (testKeret->w / 2) + hosz;

    //cout << "az x koordinata: "
    //    << kozepPont->x << "; "
    //    << pont->x << "; "
    //    << arany << "; "
    //    << testKeret->w << "; "
    //    << hosz << "; "
    //    << testKeret->x << endl;

    testKeret->y = ((kozepPont->y - pont->y) / arany) - (testKeret->h / 2) + magassag;

    //cout << "az y koordinata: "
    //    << kozepPont->y << "; "
    //    << pont->y << "; "
    //    << arany << "; "
    //    << testKeret->h << "; "
    //    << magassag << "; "
    //    << testKeret->y << endl;

    return testKeret;
}

MyPoint* GrafikObj::getKozepPont()
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
