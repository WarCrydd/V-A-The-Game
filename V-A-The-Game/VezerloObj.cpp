#include "VezerloObj.h"

VezerloObj::VezerloObj(ElemiLelek* _eL)
{
    lelek = _eL;
}

void VezerloObj::setLelek(ElemiLelek* _eL)
{
    if (_eL == nullptr)
    {
        return;
    }

    if (lelek == nullptr)
    {
        delete lelek;
    }
    lelek = _eL;
}

ElemiLelek* VezerloObj::getLelek()
{
    return lelek;
}
