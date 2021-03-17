#pragma once
#include <string>
#include <SDL.h>
#include <iostream>

#include "BaseFizikObj.h"
#include "Muveletek.h"
#include "GrafikObj.h"
#include "BaseObj.h"

using namespace std;
class MyObj : public BaseObj 
{
protected:
    BaseFizikObj* body = nullptr;
    GrafikObj* megjelenes = nullptr;

    bool betoltot = false;

public:
    MyObj(BaseFizikObj* _body, GrafikObj* _megjelenes);
    ~MyObj();

    BaseFizikObj* getBody();
    GrafikObj* getMegjelenes();

    virtual void update() = 0;
};
