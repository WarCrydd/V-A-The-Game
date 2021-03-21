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
// a haszn�lt driver (-1-n�l kisebb �rt�kn�l ki irja a lehet�s�geket)

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
	
	BaseFizikObj* fobj = new ElemiFizikObj(0, 0, 0, 8000, 8000);
	GrafikObj* gobj = new GrafikObj(fobj);
	EgysegNegyzet* probaelem = new EgysegNegyzet(fobj, gobj);

	SDL_Surface* surf = TestObjKeszito::surfaceKeszito(50, 50, 255, 255, 0);

	probaelem->getMegjelenes()->setKinezet(surf);

	MainEngine* jatek = new MainEngine();
	jatek->setKameraKozepPont(probaelem->getBody()->getMozgasAllapot()->getKozepPont());
	jatek->addTestElem(probaelem);
	jatek->start();

	cout << "A fut�s sikeres volt" << endl;

	return 0;
}