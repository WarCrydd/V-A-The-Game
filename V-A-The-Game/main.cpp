#include <SDL.h>
#include <stdio.h>
#include <list>
#include <SDL_image.h>

#include "GrafikE.h"
#include "MyObj.h"

using namespace std;

int main(int argc, char* args[])
{
	list<MyObj>* jatek_ter = new list<MyObj>();
	SDL_Window* ablak = SDL_CreateWindow("Valami", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 640, 700, SDL_WINDOW_SHOWN);
	GrafikE* grafikus_motor = new GrafikE(ablak, jatek_ter);
	SDL_Renderer* rendere = SDL_GetRenderer(ablak);
	SDL_Surface* surf = 
	SDL_Delay(2000);
	SDL_DestroyWindow(ablak);
	SDL_Quit();
	return 0;
}