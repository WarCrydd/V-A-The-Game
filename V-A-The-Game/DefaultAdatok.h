#pragma once

#include <string>

using namespace std;

namespace Kijelzo
{
    unsigned int szelesseg = 800;
    unsigned int magassag = 600;
    bool fullScreen = false;
    string felirat = "A valami";
}

namespace Gui
{
    unsigned int aranyMagassag = 9;
    unsigned int aranySzelesseg = 16;
    unsigned int megjelenitettMerett = 10000;           //A legt�bb k�pkock�t tartalmaz� oldal hossza a ja�t�k t�rben.
}

namespace Jatek
{
    namespace Alkotok
    {
        unsigned egyseg_meret = 200;
    }
}