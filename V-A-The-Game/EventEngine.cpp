#include "EventEngine.h"

EventEngine::EventEngine()
{

}

void EventEngine::start()
{
    if (fut)
    {
        return;
    }

    auto szal = [=]()
    {
        SDL_Event e;

        while (fut)
        {
            SDL_WaitEvent(&e);
            for (auto elem : vezerlok)
            {
                elem->objUpdate(e);
            }
        }
    };

    fut = true;
    main_szal = new thread(szal);
}

void EventEngine::stop()
{
    fut = false;
    main_szal->join();
    delete main_szal;
    main_szal = nullptr;
}

bool EventEngine::getFut()
{
    return fut;
}

void EventEngine::addVezerlo(VezerloObj* _vezerlo)
{
    vezerlok.push_back(_vezerlo);
}

void EventEngine::removeVezerlo(VezerloObj* _vezerlo)
{
    vezerlok.remove(_vezerlo);
}
