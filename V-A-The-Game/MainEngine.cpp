#include "MainEngine.h"

MainEngine::MainEngine()
{
    gEngine = new GrafikEngine();
    fEngine = new FizEngine(); 
}

MainEngine::~MainEngine()
{

}

void MainEngine::addTestElem(MyObj* _obj)
{
    univerzum.push_back(_obj);
    fEngine->addEntitas(_obj->getBody());
    gEngine->addObj(_obj->getMegjelenes());
}

int MainEngine::start()
{
    fut = true;

    SDL_Event e;

    fEngine->start();
    gEngine->start(Kijelzo::alapMaxFPS);

    while (fut)
    {
        if (SDL_PollEvent(&e) != 1)
        {
            SDL_WaitEvent(&e);
        }

        if (e.type == SDL_QUIT)
        {
            fut = false;
        }
    }

    fEngine->stop();
    gEngine->stop();

    return 0;
}

void MainEngine::setKameraKozepPont(SDL_Point* _p)
{
    gEngine->setKozepPont(_p);
}
