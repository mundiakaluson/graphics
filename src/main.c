#include <stdio.h>
#include <SDL.h>
#include "Engine.c"
#include <string.h>

int main(int argc, char* argv[])
{
	SDL_Window* window;
	SDL_Renderer* renderer;
	SDL_Surface* image;
	SDL_Surface* windowSurface;
	struct SDLWindow Window = {window, renderer, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 640, 480, 0, -1, SDL_RENDERER_ACCELERATED};
	struct Drawer Draw = {image, windowSurface};

	Run(&Window, &Draw);

	return 0x0;
}
