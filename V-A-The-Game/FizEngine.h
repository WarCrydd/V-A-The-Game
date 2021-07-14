#pragma once

#include <list>
#include <algorithm>
#include <thread>
#include <chrono>
#include <iostream>

#include "BaseFizikObj.h"

using namespace std;

class FizEngine
{
protected:
    list<BaseFizikObj*>* entitasok;
    thread* main_szal;
    bool fut = false;

public:
    FizEngine();
    ~FizEngine();

    void addEntitas(BaseFizikObj* _entiti);
    bool removEntitas(BaseFizikObj* _entiti);

    void start();
    void stop();

    bool getFut();
};
