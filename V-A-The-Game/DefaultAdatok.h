#pragma once

#include <string>
#include <map>
#include <SDL.h>

#include "Enumok.h"

using namespace std;

namespace Kijelzo
{
    static unsigned int szelesseg = 900;
    static unsigned int magassag = 900;
    static unsigned int max_nagyitas = 1000;
    static unsigned int min_agyitas = 500;
    static bool fullScreen = false;
    static string felirat = "A valami";
}

namespace Render
{
    static int hasznaltDriver = 3;
}

namespace Gui
{
    static unsigned int aranyMagassag = 9;
    static unsigned int aranySzelesseg = 16;
    static unsigned int megjelenitettMerett = 10000;           //A legtöbb képkockát tartalmazó oldal hossza a jaáték térben.
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

namespace Iranyitas
{
    using namespace Iranyitas;
    static map<SDL_KeyCode, Test> tesztMozgas
    {
        {SDLK_UP, Test::FEL},
        {SDLK_RIGHT, Test::JOBRA},
        {SDLK_LEFT, Test::BALRA},
        {SDLK_DOWN, Test::LE},
        {SDLK_SPACE, Test::STOP}
    };
}

namespace Fizika
{
    static unsigned int maxKarakterSebeseg = 10;
}