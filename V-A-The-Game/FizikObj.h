#pragma once

#include <SDL.h>
#include <chrono>

class FizikObj
{
protected:
    SDL_Point* kozepPont = nullptr;
    int* forgatas = nullptr;

public:
    FizikObj(int x, int y, int r);

    void setKozepPont(SDL_Point* _kozepPont);
    SDL_Point* getKozepPont();
    int* getForgatas();

    void update();

};
