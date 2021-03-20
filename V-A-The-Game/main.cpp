#include <SDL.h>
#include <stdio.h>
#include <list>
#include <iostream>
#include <vector>

#include "DefaultAdatok.h"
#include "MyObj.h"
#include "GrafikEngine.h"
#include "GrafikObj.h"
#include "EgysegNegyzet.h"
#include "EpitoElem.h"
#include "EventEngine.h"
#include "BaseFizikObj.h"
#include "ElemiFizikObj.h" 
#include "Muveletek.h"
#include "FizEngine.h"
#include "EventEngine.h"
#include "KeyboardKarakterVezerlo.h"
#include "TestLelek.h"

#define DRIVER 3
// a használt driver (-1-nél kisebb értéknél ki irja a lehetõségeket)

using namespace std;

int main(int argc, char* args[])
{
	Render::hasznaltDriver = DRIVER;
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
	
	BaseFizikObj* fobj = new ElemiFizikObj(0, 0, 0, 8000, 8000);
	GrafikObj* gobj = new GrafikObj(fobj);
	EgysegNegyzet* probaelem = new EgysegNegyzet(40, 40, fobj, gobj);

	g->setKozepPont(probaelem->getBody()->getMozgasAllapot()->getKozepPont());

#pragma region Surface létrehozása

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
	SDL_Delay(10);

	cout << g->start(60) << endl;
	FizEngine* f = new FizEngine();
	f->addEntitas(probaelem->getBody());
	f->start();

	TestLelek* lelek = new TestLelek(probaelem->getBody());

	EventEngine* eventEngine = new EventEngine();
	KeyboardKarakterVezerlo* vezerlo = new KeyboardKarakterVezerlo(lelek, Iranyitas::tesztMozgas);
	
	eventEngine->addVezerlo(vezerlo);
	eventEngine->start();

	SDL_Delay(4000);

	SDL_Delay(4000);

	g->removeObj(probaelem->getMegjelenes());

	g->stop();
	f->stop();
	eventEngine->stop();

	delete g;

	SDL_Quit();

	cout << "A futás sikeres volt" << endl;

	return 0;
}