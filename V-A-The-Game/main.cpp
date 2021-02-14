#include <SDL.h>
#include <stdio.h>
#include <list>
#include <iostream>

#include "MyObj.h"

#define DRIVER 0				// a haszn�lt driver (-1-n�l kisebb �rt�kn�l ki irja a lehet�s�geket)

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

	cout << "A fut�s sikeres volt" << endl;
	return 0;
}