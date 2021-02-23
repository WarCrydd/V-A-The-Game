#pragma once

#include <SDL.h>
#include <list>
#include <thread>

#include "DefaultAdatok.h"
#include "MyObj.h"
#include "GrafikObj.h"

using namespace std;
class GrafikEngine
{
private:
    SDL_Window* main_window;
    SDL_Renderer* main_renderer;
    SDL_Point* kozepPont;
    list<GrafikObj*>* ter = new list<GrafikObj*>();
    thread* foSzal = nullptr;

    int ablakMagassag = 0;
    int ablakSzelesseg = 0;
    bool aktivalva = false;
    int fps = 60;
   
    void frame();

public:
    GrafikEngine();
    ~GrafikEngine();

    bool start(int fps);
    void stop();

    list<GrafikObj*>* getTer();
    SDL_Renderer* getRenderer();
    SDL_Point* getKozepPont();
    void setKozepPont(SDL_Point* _pont);

    void addObj(GrafikObj* obj);
    void removeObj(GrafikObj* obj);
};