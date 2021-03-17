#pragma once

#include <SDL.h>
#include <chrono>
#include <iostream>
#include <thread>

#include "VezerloObj.h"

using namespace std;
class EventEngine
{
protected:
    bool fut = false;
    thread* main_szal = nullptr;
    list<VezerloObj*> vezerlok;

public:
    EventEngine();

    void start();
    void stop();

    bool getFut();

    void addVezerlo(VezerloObj* _vezerlo);

    void removeVezerlo(VezerloObj* _vezerlo);
};
