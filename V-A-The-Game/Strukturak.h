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

    void operator -=(const MyPoint& pont)
    {
        x -= pont.x;
        y -= pont.y;
    }

    int operator >>(const MyPoint& pont) const
    {
        int result = pow(x - pont.x, 2) + pow(y - pont.y, 2);
        return sqrt(result);
    }//Távolság

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

struct MyLine
{
    MyPoint* a;
    MyPoint* b;

    MyLine(MyPoint* _a, MyPoint* _b)
    {
        a = _a;
        b = _b;
    }

    MyLine()
    {
        a = new MyPoint();
        b = new MyPoint();
    }

    ~MyLine()
    {
        delete a;
        delete b;
    }

    pair<bool, MyPoint> operator |(const MyLine& _vonal)
    {
        pair<bool, MyPoint> result;

        double a1 = (double)b->y - a->y;
        double b1 = (double)a->x - b->x;
        double c1 = a1 * (a->x) + b1 * (a->y);

        double a2 = (double)_vonal.b->y - _vonal.a->y;
        double b2 = (double)_vonal.a->x - _vonal.b->x;
        double c2 = a2 * (_vonal.a->x) + b2 * (_vonal.a->y);

        double d = a1 * b2 - a2 * b1;
        if (d == 0)
        {
            result.first = false;
            return result;
        }
        else
        {
            result.first = true;
            int x = (b2 * c1 - b1 * c2) / d;
            int y = (a1 * c2 - a2 * c1) / d;

            result.second.x = x;
            result.second.y = y;
            return result;
        }
    }
};

struct MyKeret
{
    Uint16 oldalak;
    MyPoint* sarkok;
    MyPoint* kozepPont;

    MyKeret(Uint16 _oldalak, MyPoint* _pont)
    {
        oldalak = _oldalak;
        kozepPont = _pont;

        sarkok = new MyPoint[_oldalak];
    }

    ~MyKeret()
    {
        delete[oldalak] sarkok;
    }

    MyPoint sulyPontRelativ() const
    {
        MyPoint p;

        for (int i = 0; i < oldalak; i++)
        {
            p += sarkok[i];
        }

        return p;
    }

    MyPoint sulyPontAbszolut() const
    {
        MyPoint p = sulyPontRelativ();
        p += *kozepPont;
        return p;
    } 

    int legnagyobbKiterjedes() const
    {
        int result = 0;
        for (int i = 0; i < oldalak; i++)
        {
            if (result > *kozepPont >> sarkok[i])
            {
                result = *kozepPont >> sarkok[i];
            }
        }

        return result;
    }

    pair<bool ,MyPoint> operator |(const MyKeret& _k)
    {
        MyPoint utkozoPont;
        pair<bool, MyPoint> result;

        int a = 0, b = 0;

        a = this->legnagyobbKiterjedes();
        b = _k.legnagyobbKiterjedes();

        if (*kozepPont >> *_k.kozepPont > a + b)
        {
            result.first = false;
            result.second = utkozoPont;
            return result;
        }

    }
};
