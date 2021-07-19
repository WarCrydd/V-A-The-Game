#include "FizEngine.h"

FizEngine::FizEngine()
{
    entitasok = new list<BaseFizikObj*>();
}

FizEngine::~FizEngine()
{
    delete[] entitasok;
    delete entitasok;
}

void FizEngine::addEntitas(BaseFizikObj* _entiti)
{
    entitasok->push_back(_entiti);
}

bool FizEngine::removEntitas(BaseFizikObj* _entiti)
{
    entitasok->remove(_entiti);
    return true;
}

void FizEngine::start()
{
    auto futas = [=]() 
    {
        chrono::system_clock::time_point clStart = chrono::system_clock().now();
        chrono::system_clock::time_point clEnd;
        chrono::duration<double, milli> diff;
        while (fut)
        {
            clEnd = chrono::system_clock().now();
            diff = clEnd - clStart;
            double eltelt_ido = diff.count();
            for (auto elem : *entitasok)
            {
                elem->update(eltelt_ido);
            }

            clStart = clEnd;
            clEnd = chrono::system_clock().now();
            diff = clEnd - clStart;
            if (diff.count() < 2)
            {
                int ido = 2 - diff.count();
                this_thread::sleep_for(chrono::milliseconds(ido));
                //cout << diff.count() << endl;
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

bool FizEngine::getFut()
{
    return fut;
}
