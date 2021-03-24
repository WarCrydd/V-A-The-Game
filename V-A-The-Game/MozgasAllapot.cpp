#include "MozgasAllapot.h"

MozgasAllapot::MozgasAllapot(int x, int y, int r, MyPoint* _mozgas)
{
    kozepPont = new MyPoint(x, y);

    if (_mozgas == nullptr)
    {
        sebeseg = new MyPoint();
    }
    else
    {
        sebeseg = _mozgas;
    }

    forgas = new int(r);
}

MyPoint* MozgasAllapot::getKozepPont()
{
    return kozepPont;
}

MyPoint* MozgasAllapot::getSebesseg()
{
    return sebeseg;
}

int* MozgasAllapot::getForgas()
{
    return forgas;
}

void MozgasAllapot::update(int ido)
{
    *kozepPont += *sebeseg * ido;
}
