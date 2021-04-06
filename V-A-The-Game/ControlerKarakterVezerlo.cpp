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

    if (e.jaxis.axis == 0)
    {
        mozgatas->x = e.jaxis.value / JoystickAdatok::osztas;
    }
    else if (e.jaxis.axis == 1)
    {
        mozgatas->y = e.jaxis.value / JoystickAdatok::osztas;
    }
    
    lelek->mozgasIgeny(mozgatas);

    cout << "Engedely: " << nagytasEngedely << endl;

    if (nagytasEngedely)
    {
        if (e.jaxis.axis == 3)
        {
            if (axis4Aktív)
            {
                if (e.jaxis.value < 16000 && e.jaxis.value > -16000)
                {
                    axis4Aktív = false;
                    cout << "kozepen" << endl;
                }
            }
            else
            {
                using namespace Kijelzo;
                if (e.jaxis.value > 16000)
                {
                    *nagyitas += (max_nagyitas - min_nagyitas) / 20;
                    if (*nagyitas > max_nagyitas) *nagyitas = max_nagyitas;
                    cout << "fent" << endl;
                    axis4Aktív = true;
                }
                else if (e.jaxis.value < -16000)
                {
                    *nagyitas -= (max_nagyitas - min_nagyitas) / 20;
                    if (*nagyitas < min_nagyitas) *nagyitas = min_nagyitas;
                    cout << "lent" << endl;
                    axis4Aktív = true;
                }
            }
        }
    }
}

void ControlerKarakterVezerlo::setNagyitasValtas(int* _nagyitas)
{
    nagyitas = _nagyitas;
    nagytasEngedely = true;
}
