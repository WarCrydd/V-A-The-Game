#include "GrafikEngine.h"

void GrafikEngine::frame()
{
    SDL_SetRenderDrawColor(main_renderer, 100, 100, 100, 0);
    SDL_RenderClear(main_renderer);
    for (auto elem : *ter)
    {
        SDL_RenderCopyEx(
            main_renderer,
            elem->getTexture(),
            NULL,
            elem->getKeret(kozepPont, ablakSzelesseg / 2, ablakMagassag / 2),
            *elem->getForgatas(),
            elem->getForgatasiKozepPont(),
            SDL_FLIP_HORIZONTAL);
    } 
    SDL_RenderPresent(main_renderer);
}

GrafikEngine::GrafikEngine()
{
    kozepPont = new SDL_Point();
    main_window = SDL_CreateWindow(
        Kijelzo::felirat.c_str(), 
        SDL_WINDOWPOS_UNDEFINED, 
        SDL_WINDOWPOS_UNDEFINED, 
        Kijelzo::szelesseg, 
        Kijelzo::magassag, 
        Kijelzo::fullScreen ? SDL_WINDOW_FULLSCREEN_DESKTOP : 0);

    ablakMagassag = Kijelzo::magassag;
    ablakSzelesseg = Kijelzo::szelesseg;

    main_renderer = SDL_CreateRenderer(main_window, Render::hasznaltDriver, SDL_RENDERER_ACCELERATED);
}

GrafikEngine::~GrafikEngine()
{
    SDL_DestroyRenderer(main_renderer);
    SDL_DestroyWindow(main_window);
}

bool GrafikEngine::start(int fps)
{
    if (aktivalva)
    {
        return false;
    }

    aktivalva = true;

    auto futas = [=]()
    {
        SDL_SetRenderTarget(main_renderer, NULL);
        while (aktivalva)
        {
            auto clStart = chrono::system_clock::now();

            frame();
            //cout << "-";
            auto clEnd = chrono::system_clock::now();
            chrono::duration<double, milli> diff = clEnd - clStart;
            if(diff.count()< 1000 / fps)
            SDL_Delay(1000 / fps - diff.count());
        }    
    };

    if (foSzal != nullptr)
    {
        delete foSzal;
        foSzal = nullptr;
    }

    foSzal = new thread(futas);

    return true;
}

void GrafikEngine::stop()
{
    if (!aktivalva)
    {
        return;
    }

    aktivalva = false;

    foSzal->join();
    delete foSzal;
    foSzal = nullptr;
}

list<GrafikObj*>* GrafikEngine::getTer()
{
    return ter;
}

SDL_Renderer* GrafikEngine::getRenderer()
{
    return main_renderer;
}

SDL_Point* GrafikEngine::getKozepPont()
{
    return kozepPont;
}

void GrafikEngine::setKozepPont(SDL_Point* _pont)
{
    if (kozepPont != nullptr)
    {
        delete kozepPont;
    }

    kozepPont = _pont;
}

void GrafikEngine::addObj(GrafikObj* obj)
{
    obj->texturaBe(main_renderer);
    ter->push_back(obj);
}

void GrafikEngine::removeObj(GrafikObj* obj)
{
    obj->texturaKi();
    ter->remove(obj);
}
