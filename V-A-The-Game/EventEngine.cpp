#include "EventEngine.h"

EventEngine::EventEngine()
{
    SDL_Init(SDL_INIT_JOYSTICK);
    if (SDL_NumJoysticks() < 1)
    {

    }
    cout << "Joystikok száma: " << SDL_NumJoysticks() << endl;
}

void EventEngine::start()
{
    auto szal = [=]()
    {
        SDL_Event e;

        while (fut)
        {

        }
    };
}

void EventEngine::stop()
{
}

bool EventEngine::getFut()
{
    return fut;
}
