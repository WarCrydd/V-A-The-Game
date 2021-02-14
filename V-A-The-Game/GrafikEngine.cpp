#include "GrafikEngine.h"

GrafikEngine::GrafikEngine()
{
    main_window = SDL_CreateWindow(Kijelzo::felirat.c_str(), SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, Kijelzo::szelesseg, Kijelzo::magassag, Kijelzo::fullScreen ? SDL_WINDOW_FULLSCREEN : 0);
}
