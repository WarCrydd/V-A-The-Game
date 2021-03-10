#include "ElemiFizikObj.h"

ElemiFizikObj::ElemiFizikObj(int x, int y, int r, int h, int w) : FizikObj(x, y, r, h ,w)
{
    
}

void ElemiFizikObj::update(double ido)
{
    ido += ido_maradek;
    ido_maradek = ido - ((int)ido / 1);
    ido -= ido_maradek;
    if (ido != 0)
    {
        mozgasAllapot->update(ido);
    }
}
