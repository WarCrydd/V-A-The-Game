#include "MainEngine.h"

MainEngine::MainEngine()
{
    SDL_Init(SDL_INIT_AUDIO);
    SDL_Init(SDL_INIT_EVENTS);
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

        for (auto elem : vezerlok)
        {
            elem->objUpdate(e);
        }
    }

    fEngine->stop();
    gEngine->stop();

    return 0;
}

void MainEngine::setKameraKozepPont(MyPoint* _p)
{
    gEngine->setKozepPont(_p);
}

void MainEngine::addVezereltTestElem(MyObj* _obj, MyObj* _obj2)
{
    TestLelek* t = new TestLelek(_obj->getBody());
    TestLelek* t2 = new TestLelek(_obj2->getBody());
    ControlerKarakterVezerlo* vezerlo1 = new ControlerKarakterVezerlo(t);
    KeyboardKarakterVezerlo* vezerlo = new KeyboardKarakterVezerlo(t2, Iranyitas::tesztMozgas);
    vezerlok.push_back(vezerlo);
    vezerlok.push_back(vezerlo1);

    addTestElem(_obj);
}
