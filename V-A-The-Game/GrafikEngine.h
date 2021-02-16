#pragma once

#include <SDL.h>
#include <list>

#include "DefaultAdatok.h"
#include "MyObj.h"

using namespace std;
class GrafikEngine
{
private:
    SDL_Window* main_window;
    list<MyObj*>* ter;
public:
    GrafikEngine();
    ~GrafikEngine();
};