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
    int megjelenitendoVonalak = 3;
    int vonalakTavolsaga;

    SDL_Window* main_window;
    SDL_Renderer* main_renderer;
    MyPoint* kozepPont;

    list<GrafikObj*>* ter = new list<GrafikObj*>();
    thread* foSzal = nullptr;

    int ablakMagassag = 0;
    int ablakSzelesseg = 0;
    int nagyitas = 1000;
    bool aktivalva = false;
    int fps = 60;
   
    void frame();

public:
    GrafikEngine();
    ~GrafikEngine();

    bool start(int fps);
    void stop();


    int* getNagyitas();
    list<GrafikObj*>* getTer();
    SDL_Renderer* getRenderer();
    MyPoint* getKozepPont();
    void setKozepPont(MyPoint* _pont);

    void addObj(GrafikObj* obj);
    void removeObj(GrafikObj* obj);
};
