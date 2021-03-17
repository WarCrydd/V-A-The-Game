#pragma once

#include <list>
#include <map>
#include <string>
#include <SDL.h>

#include "Enumok.h"
#include "BaseFizikObj.h"

using namespace std;
using namespace Iranyitas;

class VezerloObj
{
protected:
    
public:
    VezerloObj();

    virtual void objUpdate(SDL_Event& e) = 0;
};
