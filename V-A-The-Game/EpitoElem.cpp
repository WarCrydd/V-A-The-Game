#include "EpitoElem.h"

EpitoElem::EpitoElem(int _m, int _h, FizikObj* _body, GrafikObj* _megjelenes) : MyObj( _body, _megjelenes)
{
    tMagassag = _m;
    tHossz = _h;
    SDL_Rect* befogo = megjelenes->getKeret();
    befogo->h = tMagassag;
    befogo->w = tHossz;
    befogo->x = 0;
    befogo->y = 0;
}

void EpitoElem::update()
{

}
