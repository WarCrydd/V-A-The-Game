#include "ControlerKarakterVezerlo.h"

ControlerKarakterVezerlo::ControlerKarakterVezerlo(ElemiLelek* _f) : VezerloObj(_f)
{
    SDL_Init(SDL_INIT_GAMECONTROLLER);
    SDL_Init(SDL_INIT_JOYSTICK);
    mozgatas = new MyPoint();

    if (SDL_NumJoysticks() < 1)
    {
        cout << "Szar van a levesben! nincs Controller!" << endl;
        return;
    }
    game = SDL_JoystickOpen(0);
}

void ControlerKarakterVezerlo::objUpdate(SDL_Event& e)
{
    if (e.type != SDL_JOYAXISMOTION)
    {
        return;
    }

    cout << e.jaxis.which << "; " << (int)e.jaxis.axis << "; " << e.jaxis.value << endl;

    if (e.jaxis.axis >= 2)
    {
        return;
    }

    if (e.jaxis.axis == 0)
    {
        mozgatas->x = e.jaxis.value / JoystickAdatok::osztas;
    }
    else if (e.jaxis.axis == 1)
    {
        mozgatas->y = e.jaxis.value / JoystickAdatok::osztas;
    }
    
    lelek->mozgasIgeny(mozgatas);
}
