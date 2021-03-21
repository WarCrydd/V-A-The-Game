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

    auto VANKOZOSPONT = [](SDL_Point* A, SDL_Point* B, SDL_Point* C, SDL_Point* D, SDL_Point* result)
    {
        // Line AB represented as a1x + b1y = c1 
        double a1 = B->y - A->y;
        double b1 = A->x - B->x;
        double c1 = a1 * (A->x) + b1 * (A->y);

        // Line CD represented as a2x + b2y = c2 
        double a2 = D->y - C->y;
        double b2 = C->x - D->x;
        double c2 = a2 * (C->x) + b2 * (C->y);

        double d = a1 * b2 - a2 * b1;
        if (d == 0)
        {
            return result;
        }
        else
        {
            int x = (b2 * c1 - b1 * c2) / d;
            int y = (a1 * c2 - a2 * c1) / d;

            result->x = x;
            result->y = y;
            return result;
        }
    };
}

namespace TestObjKeszito
{
    auto surfaceKeszito = [](int w, int h, int r, int g, int b, int x = 0, int y = 0)
    {
        SDL_Surface* surf = SDL_CreateRGBSurface(0, w, h, 32, 0, 0, 0, 0);
        SDL_Rect rect;
        rect.x = x;
        rect.y = y; 
        rect.w = w;
        rect.h = h;
        SDL_FillRect(surf, &rect, SDL_MapRGBA(surf->format, r, g, b, 0));

        return surf;
    };
}