#include <SDL.h>
#include <stdio.h>

struct SDLWindow
{
	SDL_Window* window;
	SDL_Renderer* renderer;
	int windowPosX;
	int windowPosY;
	int windowW;
	int windowH;
	int flags;
	int index;
	Uint32 rendererFlag;
};

struct Drawer
{
	SDL_Surface* imageSurface ;
	SDL_Surface* windowSurface;
};

void DrawToWindow(struct Drawer* drawer, struct SDLWindow* win)
{

	drawer->windowSurface = SDL_GetWindowSurface(win->window);
	drawer->imageSurface = SDL_LoadBMP("toon.bmp");
	if (drawer->imageSurface == NULL)
	{
		printf("Error Loading: %s", SDL_GetError());
	} else
	{
		SDL_BlitSurface(drawer->windowSurface, NULL, drawer->windowSurface, NULL);
	}
}
void Run(struct SDLWindow* win, struct Drawer* drawer)
{
	win->window = SDL_CreateWindow(	"Test",
									win->windowPosX,
									win->windowPosY,
									win->windowW,
									win->windowH,
									win->flags);
	// win->renderer = SDL_CreateRenderer(win->window, win->index, win->rendererFlag);
	// SDL_RenderClear(win->renderer);
	// SDL_SetRenderDrawColor(win->renderer, 255, 0, 100, 255);
	DrawToWindow(drawer, win);
	SDL_UpdateWindowSurface(win->window);
	SDL_Delay(5000);
	SDL_FreeSurface(drawer->imageSurface);
	SDL_DestroyWindow(win->window);
	SDL_Quit();
}


