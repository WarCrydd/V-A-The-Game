#pragma once
#include <list>
#include <algorithm>
#include <thread>
#include <chrono>

#include "FizikObj.h"

using namespace std;

class FizEngine
{
protected:
    list<FizikObj*>* entitasok;
    thread* main_szal;
    bool fut = false;

public:
    FizEngine();
    ~FizEngine();

    void addEntitas(FizikObj* _entiti);
    bool removEntitas(FizikObj* _entiti);

    void start();
    void stop();

    bool getFut();
};

