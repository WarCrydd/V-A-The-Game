#pragma once
#include <SDL.h>

#include "FizikObj.h"

using namespace std;
class GrafikObj
{
protected:
    SDL_Texture* textura = nullptr;
    SDL_Surface* kinezet = nullptr;
    SDL_Rect* keret = nullptr;
    SDL_Point* kozepPont = nullptr;
    SDL_Point* testKozepPont = nullptr;
    int* forgatas = nullptr;

    bool betoltve = false;

public:
    GrafikObj(FizikObj* _f);

    void setKinezet(SDL_Surface* _kinezet);
    void texturaBe(SDL_Renderer* render);
    void texturaKi();
    void pontokFrisit();
    bool getBetoltve();
    SDL_Texture* getTexture();
    SDL_Rect* getKeret();
    SDL_Rect* getKeret(SDL_Point* pont, int hosz, int magassag);
    SDL_Point* getKozepPont();
    SDL_Point* getForgatasiKozepPont();
    int* getForgatas();
};
