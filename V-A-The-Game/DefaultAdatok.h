#pragma once

#include <string>

using namespace std;

namespace Kijelzo
{
    static unsigned int szelesseg = 800;
    static unsigned int magassag = 600;
    static bool fullScreen = false;
    static string felirat = "A valami";
}

namespace Render
{
    static int hasznaltDriver = 0;
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