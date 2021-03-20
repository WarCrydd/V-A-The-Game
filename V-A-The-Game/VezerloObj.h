#pragma once

#include <list>
#include <map>
#include <string>
#include <SDL.h>

#include "Enumok.h"
#include "BaseFizikObj.h"
#include "ElemiLelek.h"

using namespace std;
using namespace Iranyitas;

class VezerloObj : public BaseObj
{
protected:
    ElemiLelek* lelek;
    
public:
    VezerloObj(ElemiLelek* _eL);

    virtual void objUpdate(SDL_Event& e) = 0;

    void setLelek(ElemiLelek* _eL);

    ElemiLelek* getLelek();
};
