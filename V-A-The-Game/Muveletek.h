#pragma once
#include <SDL.h>
namespace Eltolasok
{
    auto PONTTALELTOLAS = [](SDL_Point* _eltolas, SDL_Rect* _rect)
    {
        _rect->x += _eltolas->x;
        _rect->y += _eltolas->y;
    };

    auto PONTOKTAVOLSAG = [](SDL_Point* a, SDL_Point* b) 
    {
        int y = a->y - b->y;
        int x = a->x - b->y;
        return x + y;
    };

    auto PONTOKABSZOLUTTAVOLSAG = [](SDL_Point* a, SDL_Point* b) 
    {
        int szam = PONTOKTAVOLSAG(a, b);
        if (szam < 0)
        {
            szam *= -1;
        }
        return szam;
    };

    auto KOZEPPONT = [](SDL_Rect* negyzet, SDL_Point* pont)
    {
        pont -> x = negyzet->x + negyzet->w / 2;
        pont -> y = negyzet->y + negyzet->h / 2;
    };
}