#include <SDL.h>
#include <stdio.h>
#include <list>
#include <iostream>
#include <vector>

#include "DefaultAdatok.h"
#include "MyObj.h"
#include "MainEngine.h"
#include "GrafikEngine.h"
#include "GrafikObj.h"
#include "EgysegNegyzet.h"
#include "EpitoElem.h"
#include "BaseFizikObj.h"
#include "ElemiFizikObj.h" 
#include "Muveletek.h"
#include "FizEngine.h"
#include "KeyboardKarakterVezerlo.h"
#include "TestLelek.h"

#define DRIVER 3
// a használt driver (-1-nél kisebb értéknél ki irja a lehetõségeket)

using namespace std;

int main(int argc, char* args[])
{
#pragma region driver

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
#pragma endregion
	
	SDL_Surface* surf = TestObjKeszito::surfaceKeszito(50, 50, 255, 255, 0);
	SDL_Surface* surf2 = TestObjKeszito::surfaceKeszito(50, 50, 0, 127, 255);

	BaseFizikObj* fobj = new ElemiFizikObj(0, 0, 0, 80000, 80000);
	GrafikObj* gobj = new GrafikObj(fobj);
	EgysegNegyzet* probaelem = new EgysegNegyzet(fobj, gobj);
	probaelem->getMegjelenes()->setKinezet(surf);

	BaseFizikObj* fobj2 = new ElemiFizikObj(80000, 80000, 45, 80000, 80000);
	GrafikObj* gobj2 = new GrafikObj(fobj2);
	EgysegNegyzet* probaelem2 = new EgysegNegyzet(fobj2, gobj2);
	probaelem2->getMegjelenes()->setKinezet(surf2);

	MainEngine* jatek = new MainEngine();
	SDL_Point* p = new SDL_Point();
	p->x = 0;
	p->y = 0;

	jatek->setKameraKozepPont(p);
	//jatek->setKameraKozepPont(probaelem->getBody()->getMozgasAllapot()->getKozepPont());
	jatek->addTestElem(probaelem2);
	jatek->addVezereltTestElem(probaelem);
	jatek->start();

	cout << "A futas sikeres volt" << endl;

	return 0;
}