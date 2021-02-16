#pragma once
#include <string>
#include <SDL.h>

#include "FizikObj.h"

using namespace std;
class MyObj
{
protected:
    string nev = "";
    SDL_Texture* textura;
    SDL_Surface* kinezet;
    bool betoltot = false;
    FizikObj* body;
public:
    MyObj(string _nev, FizikObj* _body);
    ~MyObj();

    void setTexturaAktiv(SDL_Renderer* _renderer);
    void setTexturaInaktiv();
    SDL_Texture* getTexture();
    FizikObj* getBody();

    virtual void setSurface() = 0;
    virtual void update() = 0;
};

