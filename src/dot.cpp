#include <dot.hpp>

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
}

void			keyboardEvent(SDL_Event event, bool *running, Dot *dot) {
	switch (event.key.keysym.sym) {
		case SDLK_ESCAPE:
			*running = false;
			break;
		case SDLK_UP:
			dot->up();
			break;
		case SDLK_DOWN:
			dot->down();
			break;
		case SDLK_LEFT:
			dot->left();
			break;
		case SDLK_RIGHT:
			dot->right();
			break;
		case SDLK_MINUS:
			dot->resize(-DOT_RESIZE_SPEED);
			break;
		case SDLK_EQUALS:
			dot->resize(DOT_RESIZE_SPEED);
			break;
		case SDLK_LEFTBRACKET:
			dot->rethickness(-DOT_RETHICKNESS_SPEED);
			break;
		case SDLK_RIGHTBRACKET:
			dot->rethickness(DOT_RETHICKNESS_SPEED);
			break;
	}
}

int				main(int ac, char **av) {
	SDL_Window		*window = NULL;
	SDL_Renderer	*renderer = NULL;
	SDL_Event		event;
	bool			running = true;
	Dot				dot(DOT_POS_X, DOT_POS_Y, DOT_SIZE, DOT_THICKNESS);

	initialisation(&window, &renderer);
	while (running) {
		while (SDL_PollEvent(&event)) {
			if (event.type == SDL_QUIT)
				running = false;
			if (event.type == SDL_KEYDOWN) {
				keyboardEvent(event, &running, &dot);
			}
		}
		SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0xff);
		SDL_RenderClear(renderer);
		dot.drawDot(renderer);
		SDL_RenderPresent(renderer);
	}
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
	return (0);
}
