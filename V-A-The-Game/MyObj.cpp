#include "MyObj.h"

MyObj::MyObj(string _nev, FizikObj* _body)
{
    kinezet = SDL_createSur
    nev = _nev;
    body = _body;
}

MyObj::~MyObj()
{
    SDL_DestroyTexture(textura);
    delete textura;
}

void MyObj::setTexturaAktiv(SDL_Renderer* _renderer)
{
    textura = SDL_CreateTextureFromSurface(_renderer, kinezet);
    betoltot = true;
}

void MyObj::setTexturaInaktiv()
{
    SDL_DestroyTexture(textura);
    betoltot = false;
}

SDL_Texture* MyObj::getTexture()
{
    if (betoltot)
    {
        return textura;
    }
    return nullptr;
}

FizikObj* MyObj::getBody()
{
    return body;
}
