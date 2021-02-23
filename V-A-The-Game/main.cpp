#include <SDL.h>
#include <stdio.h>
#include <list>
#include <iostream>
#include <vector>

#include "MyObj.h"
#include "GrafikEngine.h"
#include "GrafikObj.h"
#include "EgysegNegyzet.h"
#include "EpitoElem.h"
#include "FizikObj.h"

#define DRIVER 3
// a haszn�lt driver (-1-n�l kisebb �rt�kn�l ki irja a lehet�s�geket)

using namespace std;

int main(int argc, char* args[])
{
	if (DRIVER < -1)
	{
		int a = SDL_GetNumRenderDrivers();
		SDL_RendererInfo* info = new SDL_RendererInfo();
		for (int i = 0; i < a; i++)
		{
			SDL_GetRenderDriverInfo(i, info);
			cout << "[" << i << "] ---> " << info->name << endl;
		}
		return 0;
	}

	GrafikEngine* g = new GrafikEngine();
	
	FizikObj* fobj = new FizikObj(0, 0, 0);
	GrafikObj* gobj = new GrafikObj(fobj);
	EgysegNegyzet* probaelem = new EgysegNegyzet(200, 60, fobj, gobj);
	g->setKozepPont(probaelem->getBody()->getKozepPont());
	SDL_Color color;
	SDL_Renderer* renderer = g->getRenderer();
#pragma region m

	SDL_Surface* surf = SDL_CreateRGBSurface(0, 60, 60, 32, 0, 0, 0, 0);
	SDL_Rect r;
	r.x = 0;
	r.y = 0;
	r.w = 60;
	r.h = 60;
	SDL_FillRect(surf, &r, SDL_MapRGBA(surf->format, 255, 255, 0, 0));

#pragma endregion
	probaelem->getMegjelenes()->setKinezet(surf);

	g->addObj(probaelem->getMegjelenes());

	cout << g->start(120) << endl;
	SDL_Delay(2000);
	int* forog = probaelem->getBody()->getForgatas();

	for (int i = 0; i < 10000; i++)
	{
		*forog += 17;
		SDL_Delay(4);
	}
	g->removeObj(probaelem->getMegjelenes());
	SDL_Delay(2000);
	g->stop();
	delete g;
	SDL_Quit();
	cout << "A fut�s sikeres volt" << endl;
	return 0;
}