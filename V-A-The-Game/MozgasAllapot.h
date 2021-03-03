#pragma once
#include <SDL.h>
class MozgasAllapot
{
protected:
    SDL_Point* kozepPont = nullptr;
    SDL_Point* sebeseg = nullptr;
    int* forgas = nullptr;

public:
    MozgasAllapot(int x, int y, int r, SDL_Point* _mozgas);

    SDL_Point* getKozepPont();
    void setKozepPont(SDL_Point* _p);

    SDL_Point* getMozgas();
    void setMozgas(SDL_Point* _m);

    int* getForgas();
    void setForgas(int* _f);

    void update(double ido);
};

