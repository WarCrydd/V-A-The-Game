#include "TestLelek.h"

TestLelek::TestLelek(BaseFizikObj* _b) : ElemiLelek(_b)
{
}

void TestLelek::mozgasIgeny(SDL_Point* vector)
{
    SDL_Point* gyorsulas = test->getMozgasAllapot()->getSebesseg();

    gyorsulas->x += vector->x;
    gyorsulas->y += vector->y;
}
