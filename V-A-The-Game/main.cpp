#include <SDL.h>
#include <stdio.h>
#include <list>
#include <iostream>

#include "MyObj.h"

#define DRIVER 0				// a használt driver (-1-nél kisebb értéknél ki irja a lehetõségeket)

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

	cout << "A futás sikeres volt" << endl;
	return 0;
}