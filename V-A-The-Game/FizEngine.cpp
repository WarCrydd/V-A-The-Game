#include "FizEngine.h"

FizEngine::FizEngine()
{
    entitasok = new list<FizikObj*>();
}

FizEngine::~FizEngine()
{
    delete[] entitasok;
    delete entitasok;
}

void FizEngine::addEntitas(FizikObj* _entiti)
{
    entitasok->push_back(_entiti);
}

bool FizEngine::removEntitas(FizikObj* _entiti)
{
    entitasok->remove(_entiti);
    return true;
}

void FizEngine::start()
{
    auto futas = [=]() 
    {
        while (fut)
        {
            for (auto elem : *entitasok)
            {
                elem->update();
            }
        }
    };

    fut = true;
    main_szal = new thread(futas);
}

void FizEngine::stop()
{
    fut = false;
    main_szal->join();
    delete main_szal;
    main_szal = nullptr;
}
