#include "GrafikEngine.h"

void GrafikEngine::frame()
{
    SDL_SetRenderDrawColor(main_renderer, 100, 100, 100, 0);
    SDL_RenderClear(main_renderer);

#pragma region Vonalazas
    int vonalPTavolsag = vonalakTavolsaga / nagyitas;
    int xKezdet = ((kozepPont->x % vonalakTavolsaga) / nagyitas);
    int yKezdet = ((kozepPont->y % vonalakTavolsaga) / nagyitas);
    
    SDL_SetRenderDrawColor(main_renderer, 255, 255, 255, 0);
    for (xKezdet *= -1; xKezdet < ablakSzelesseg; xKezdet += vonalPTavolsag)
    {
        SDL_RenderDrawLine(main_renderer, xKezdet, 0, xKezdet, ablakMagassag);
    }// X tengely

    for (yKezdet *= -1; yKezdet < ablakMagassag; yKezdet += vonalPTavolsag)
    {
        SDL_RenderDrawLine(main_renderer, 0, yKezdet, ablakSzelesseg, yKezdet);
    }// Y tengely

#pragma endregion

    for (auto elem : *ter)
    {
        elem->pontokFrisit(nagyitas);
        SDL_RenderCopyEx(
            main_renderer,
            elem->getTexture(),
            NULL,
            elem->getKeret(kozepPont, ablakSzelesseg / 2, ablakMagassag / 2, nagyitas),
            *elem->getForgatas(),
            elem->getForgatasiKozepPont(),
            SDL_FLIP_HORIZONTAL);
    } 
    SDL_RenderPresent(main_renderer);
}

GrafikEngine::GrafikEngine()
{
    kozepPont = new MyPoint();
    main_window = SDL_CreateWindow(
        Kijelzo::felirat.c_str(), 
        SDL_WINDOWPOS_UNDEFINED, 
        SDL_WINDOWPOS_UNDEFINED, 
        Kijelzo::szelesseg, 
        Kijelzo::magassag, 
        Kijelzo::fullScreen ? SDL_WINDOW_FULLSCREEN_DESKTOP : 0);

    if (Kijelzo::fullScreen)
    {
        SDL_GetWindowSize(main_window, &ablakSzelesseg, &ablakMagassag);
    }
    else
    {
        ablakMagassag = Kijelzo::magassag;
        ablakSzelesseg = Kijelzo::szelesseg;
    }

    vonalakTavolsaga = ablakSzelesseg * Kijelzo::min_nagyitas / megjelenitendoVonalak;

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

int* GrafikEngine::getNagyitas()
{
    return &nagyitas;
}

list<GrafikObj*>* GrafikEngine::getTer()
{
    return ter;
}

SDL_Renderer* GrafikEngine::getRenderer()
{
    return main_renderer;
}

MyPoint* GrafikEngine::getKozepPont()
{
    return kozepPont;
}

void GrafikEngine::setKozepPont(MyPoint* _pont)
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
