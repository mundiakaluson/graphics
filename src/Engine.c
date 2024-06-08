#include <SDL.h>

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

void Run(struct SDLWindow* win)
{
	win->window = SDL_CreateWindow(	"Test",
									win->windowPosX,
									win->windowPosY,
									win->windowW,
									win->windowH,
									win->flags);
	win->renderer = SDL_CreateRenderer(win->window, win->index, win->rendererFlag);
	SDL_RenderClear(win->renderer);
	SDL_SetRenderDrawColor(win->renderer, 255, 255, 255, 255);
	SDL_Delay(5000);
	SDL_DestroyWindow(win->window);
	SDL_Quit();
}


