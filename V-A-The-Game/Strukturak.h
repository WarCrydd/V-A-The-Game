#pragma once
#include <math.h>
#include <SDL.h>

using namespace std;
struct MyPoint
{
    int x;
    int y;

    MyPoint(int _x, int _y)
    {
        x = _x;
        y = _y;
    }

    MyPoint()
    {
        x = 0;
        y = 0;
    }

    MyPoint operator +(const MyPoint& pont) const
    {
        return MyPoint(pont.x + x, pont.y + y);
    }

    void operator +=(const MyPoint& pont)
    {
        x += pont.x;
        y += pont.y;
    }

    MyPoint operator -(const MyPoint& pont) const
    {
        return MyPoint(x - pont.x, y - pont.y);
    }

    int operator >>(const MyPoint& pont) const 
    {
        int result = pow(x - pont.x, 2) + pow(y - pont.y, 2);
        return sqrt(result);
    } //Távolság

    void toSDL_Point(SDL_Point* pont)
    {
        pont->x = x;
        pont->y = y;
    }

    SDL_Point toSDL_Point()
    {
        SDL_Point a;
        a.x = x;
        a.y = y;
        return a;
    }

    MyPoint operator *(const int szorzo)
    {
        return MyPoint(x * szorzo, y * szorzo);
    }
};
