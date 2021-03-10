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

    SDL_Point* getSebesseg();

    int* getForgas();
    
    void update(int ido);
};

