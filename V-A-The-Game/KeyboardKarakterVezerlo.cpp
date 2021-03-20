#include "KeyboardKarakterVezerlo.h"

KeyboardKarakterVezerlo::KeyboardKarakterVezerlo(ElemiLelek* _f, map<SDL_KeyCode, Test> _valto) : VezerloObj(_f)
{
	valtoTabla = _valto;
}

void KeyboardKarakterVezerlo::objUpdate(SDL_Event& e)
{
	int x = 0, y = 0;

	if (e.type == SDL_KEYDOWN)
	{
		switch (valtoTabla.at(SDL_KeyCode(e.key.keysym.sym)))
		{
		case Iranyitas::Test::FEL:
			x = -1 * Fizika::maxKarakterSebeseg;
			break;

		case Iranyitas::Test::LE:
			x = 1 * Fizika::maxKarakterSebeseg;
			break;

		case Iranyitas::Test::BALRA:
			y = -1 * Fizika::maxKarakterSebeseg;
			break;

		case Iranyitas::Test::JOBRA:
			y = 1 * Fizika::maxKarakterSebeseg;
			break;

		default:
			break;
		}
	}
	else if (e.type == SDL_KEYUP)
	{
		switch (valtoTabla.at(SDL_KeyCode(e.key.keysym.sym)))
		{
		case Iranyitas::Test::FEL:
			x = 0;
			break;

		case Iranyitas::Test::LE:
			x = 0;
			break;

		case Iranyitas::Test::BALRA:
			y = 0;
			break;

		case Iranyitas::Test::JOBRA:
			y = 0;
			break;

		default:
			break;
		}
	}

	SDL_Point p;
	p.x = x;
	p.y = y;

	lelek->mozgasIgeny(&p);

	return;
}
