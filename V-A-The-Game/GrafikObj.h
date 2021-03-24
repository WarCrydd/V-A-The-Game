#pragma once
#include <SDL.h>
#include <iostream>

#include "BaseFizikObj.h"
#include "MozgasAllapot.h"

using namespace std;
class GrafikObj : public BaseObj
{
protected:
    SDL_Texture* textura = nullptr;
    SDL_Surface* kinezet = nullptr;

    SDL_Rect* keret = nullptr;
    SDL_Rect* testKeret = nullptr;

    SDL_Point* testKozepPont = nullptr;
    MyPoint* kozepPont = nullptr;

    int* forgatas = nullptr;

    bool betoltve = false;

public:
    GrafikObj(BaseFizikObj* _f);

    void setKinezet(SDL_Surface* _kinezet);
    void texturaBe(SDL_Renderer* render);
    void texturaKi();
    void pontokFrisit(int arany);
    bool getBetoltve();

    SDL_Texture* getTexture();

    SDL_Rect* getKeret();
    SDL_Rect* getKeret(MyPoint* pont, int hosz, int magassag, int arany);
    MyPoint* getKozepPont();
    SDL_Point* getForgatasiKozepPont();
    int* getForgatas();
};
