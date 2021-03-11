#pragma once

#include <SDL.h>
#include <chrono>
#include <iostream>
#include <thread>

using namespace std;
class EventEngine
{
protected:
    bool fut = false;
    thread* main_szal = nullptr;

public:
    EventEngine();

    void start();
    void stop();

    bool getFut();
};

