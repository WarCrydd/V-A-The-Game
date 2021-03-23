#include "KeyboardKarakterVezerlo.h"

KeyboardKarakterVezerlo::KeyboardKarakterVezerlo(ElemiLelek* _f, map<SDL_KeyCode, Test> _valto) : VezerloObj(_f)
{
	valtoTabla = _valto;
}

void KeyboardKarakterVezerlo::objUpdate(SDL_Event& e)
{
	int x = 0, y = 0;

	if (valtoTabla.find(SDL_KeyCode(e.key.keysym.sym)) == valtoTabla.end() || e.key.repeat != 0)
	{
		return;
	}

	if (e.type == SDL_KEYDOWN)
	{
		switch (valtoTabla.find(SDL_KeyCode(e.key.keysym.sym))->second)
		{
		case Iranyitas::Test::FEL:
			y += -1 * Fizika::maxKarakterSebeseg;
			break;

		case Iranyitas::Test::LE:
			y += 1 * Fizika::maxKarakterSebeseg;
			break;

		case Iranyitas::Test::BALRA:
			x += -1 * Fizika::maxKarakterSebeseg;
			break;

		case Iranyitas::Test::JOBRA:
			x += 1 * Fizika::maxKarakterSebeseg;
			break;

		default:
			break;
		}
	}
	else if (e.type == SDL_KEYUP)
	{
		switch (valtoTabla.find(SDL_KeyCode(e.key.keysym.sym))->second)
		{
		case Iranyitas::Test::FEL:
			y += 1 * Fizika::maxKarakterSebeseg;;
			break;

		case Iranyitas::Test::LE:
			y -= 1 * Fizika::maxKarakterSebeseg;;
			break;

		case Iranyitas::Test::BALRA:
			x += 1 * Fizika::maxKarakterSebeseg;;
			break;

		case Iranyitas::Test::JOBRA:
			x -= 1 * Fizika::maxKarakterSebeseg;;
			break;

		default:
			break;
		}
	}

	SDL_Point p;
	p.x = x;
	p.y = y;

	lelek->mozgasIgeny(&p);

	cout << "keyboard event" << endl;

	return;
}
