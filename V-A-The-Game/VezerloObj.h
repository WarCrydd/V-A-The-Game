#pragma once

#include <list>
#include <map>
#include <string>
#include <SDL.h>

#include "Enumok.h"

using namespace std;
using namespace Iranyitas;

class VezerloObj
{
protected:
    map<SDL_KeyCode, Test> utasitasok;
    //A test nem jo!!!

public:
    VezerloObj();
};

