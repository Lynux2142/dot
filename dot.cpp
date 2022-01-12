#include <SDL2/SDL.h>
#include <iostream>

#define DOT_SIZE 10

typedef struct	s_coord {
	int			x;
	int			y;
}				t_coord;

void			SDL_ExitWithError(const char *error) {
	SDL_Log("%s: %s\n", error, SDL_GetError());
	exit(1);
}

void			initialisation(SDL_Window **window, SDL_Renderer **renderer) {
	if (SDL_Init(SDL_INIT_VIDEO < 0))
		SDL_ExitWithError("Error Initialisation SDL");
	*window = SDL_CreateWindow("Dot", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, SDL_WINDOW_FULLSCREEN);
	SDL_SetWindowFullscreen(*window, SDL_WINDOW_FULLSCREEN_DESKTOP);
	if (*window == NULL)
		SDL_ExitWithError("Error Window creation");
	*renderer = SDL_CreateRenderer(*window, -1, 0);
	if (*renderer == NULL)
		SDL_ExitWithError("Error Renderer creation");
	if (*renderer == NULL) {
		std::cout << "bonjour" << std::endl;
	}
}

int				main(int ac, char **av) {
	SDL_Window		*window = NULL;
	SDL_Renderer	*renderer = NULL;
	SDL_Event		event;
	bool			running = true;
	t_coord			dotPos;

	initialisation(&window, &renderer);

	dotPos.x = 100;
	dotPos.y = 100;
	while (running) {
		while (SDL_PollEvent(&event)) {
			if (event.type == SDL_QUIT)
				running = false;
			if (event.type == SDL_KEYDOWN) {
				if (event.key.keysym.sym == SDLK_ESCAPE)
					running = false;
				if (event.key.keysym.sym == SDLK_UP)
					dotPos.y -= 10;
				if (event.key.keysym.sym == SDLK_DOWN)
					dotPos.y += 10;
				if (event.key.keysym.sym == SDLK_LEFT)
					dotPos.x -= 10;
				if (event.key.keysym.sym == SDLK_RIGHT)
					dotPos.x += 10;
			}
		}
		SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0xff);
		SDL_RenderClear(renderer);
		SDL_SetRenderDrawColor(renderer, 200, 0, 0, 0xff);
		SDL_RenderDrawLine(renderer, dotPos.x - DOT_SIZE, dotPos.y, dotPos.x + DOT_SIZE, dotPos.y);
		SDL_RenderDrawLine(renderer, dotPos.x, dotPos.y - DOT_SIZE, dotPos.x, dotPos.y + DOT_SIZE);
		SDL_RenderPresent(renderer);
	}

	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
	return (0);
}
