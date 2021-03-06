#pragma once
#include <SDL.h>
#include <list>

#include "VezerloObj.h"
#include "GrafikEngine.h"
#include "FizEngine.h"
#include "KeyboardKarakterVezerlo.h"
#include "TestLelek.h"
#include "ControlerKarakterVezerlo.h"

using namespace std;
class MainEngine
{
private:
    bool fut = false;
    list<VezerloObj*> vezerlok;
    GrafikEngine* gEngine;
    FizEngine* fEngine;

    list<MyObj*> univerzum;

public:
    MainEngine();
    ~MainEngine();

    void addTestElem(MyObj* _obj);
    void setKameraKozepPont(MyPoint* _p);
    void addVezereltTestElem(MyObj* _obj, MyObj* _obj2);

    int start();
};

