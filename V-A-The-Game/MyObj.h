#pragma once
#include <string>
#include <SDL.h>
#include <iostream>

#include "FizikObj.h"
#include "Muveletek.h"
#include "GrafikObj.h"

using namespace std;
class MyObj
{
protected:
    FizikObj* body = nullptr;
    GrafikObj* megjelenes = nullptr;

    bool betoltot = false;

public:
    MyObj(FizikObj* _body, GrafikObj* _megjelenes);
    ~MyObj();

    FizikObj* getBody();
    GrafikObj* getMegjelenes();

    virtual void update() = 0;
};

