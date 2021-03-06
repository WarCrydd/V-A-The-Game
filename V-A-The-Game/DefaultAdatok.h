#pragma once

#include <string>
#include <map>
#include <SDL.h>

#include "Enumok.h"

using namespace std;

namespace Kijelzo
{
    static unsigned int szelesseg = 600;
    static unsigned int magassag = 600;
    static unsigned int max_nagyitas = 5000;
    static unsigned int min_nagyitas = 300;
    static bool fullScreen = false;
    static string felirat = "A valami";
    static unsigned int alapMaxFPS = 100;
}

namespace Render
{
    static int hasznaltDriver = 3;
}

namespace Gui
{
    static unsigned int aranyMagassag = 9;
    static unsigned int aranySzelesseg = 16;
    static unsigned int megjelenitettMerett = 10000;           //A legt�bb k�pkock�t tartalmaz� oldal hossza a ja�t�k t�rben.
}

namespace Jatek
{
    namespace Alkotok
    {
        static unsigned egyseg_meret = 200;
    }
}

namespace Kinezet
{
    namespace Negyzet
    {
        static int r = 255;
        static int g = 0;
        static int b = 0;
        static int a = 0;
    }
}

namespace JoystickAdatok
{
    static int osztas = 5000;
}


namespace Iranyitas
{
    
    static map<SDL_KeyCode, Test> tesztMozgas
    {
        {SDLK_UP, Test::FEL},
        {SDLK_w, Test::FEL},
        {SDLK_RIGHT, Test::JOBRA},
        {SDLK_d, Test::JOBRA},
        {SDLK_LEFT, Test::BALRA},
        {SDLK_a, Test::BALRA},
        {SDLK_DOWN, Test::LE},
        {SDLK_s, Test::LE},
        {SDLK_SPACE, Test::STOP}
    };
}

namespace Fizika
{
    static unsigned int maxKarakterSebeseg = 50;
}