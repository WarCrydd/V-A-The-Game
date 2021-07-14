#pragma once
#include "Utkozes.h"

Utkozes::Utkozes(BaseFizikObj* _a, BaseFizikObj* _b)
{
    a = _a;
    b = _b;

    if (a->utkozoE(b) || b->utkozoE(a))
    {
        redundancia = true;
        return;
    }

    a->addUtkozo(b);
    b->addUtkozo(a);
}

Utkozes::~Utkozes()
{
    if (redundancia)
    {
        return;
    }

    a->removeUtkozo(b);
    b->removeUtkozo(a);
}

pair<int, int> Utkozes::update()
{
    MyPoint aA = *a->getMozgasAllapot()->getKozepPont();
    MyPoint aB = aA + *a->getMozgasAllapot()->getSebesseg() * 10000;
    MyLine lineA = MyLine(&aA, &aB);

    MyPoint bA = *b->getMozgasAllapot()->getKozepPont();
    MyPoint bB = bA + *b->getMozgasAllapot()->getSebesseg() * 10000;
    MyLine lineB = MyLine(&bA, &bB);

    auto result = lineA | lineB;

    if (!result.first)
    {
        varhatoIdo.first = 3;
        varhatoIdo.second = 10;
        return varhatoIdo;
    }

    int sebesegA = *a->getMozgasAllapot()->getSebesseg() >> MyPoint();
    int sebesegB = *b->getMozgasAllapot()->getSebesseg() >> MyPoint();

    int idoA = (*a->getMozgasAllapot()->getKozepPont() >> result.second) / sebesegA;
    int idoB = (*b->getMozgasAllapot()->getKozepPont() >> result.second) / sebesegB;

    int idoKisebb;

    if (idoA > idoB)
    {
        idoKisebb = idoB;
    }
    else
    {
        idoKisebb = idoA;
    }

    int helyiertek = 0;

    while (idoKisebb > 10)
    {
        idoKisebb /= 10;
        helyiertek++;
    }

    varhatoIdo.first = helyiertek;
    varhatoIdo.second = idoKisebb;
    return varhatoIdo;
}
