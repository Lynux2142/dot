#include <dot.hpp>

void			SDL_ExitWithError(const char *message, const char *error) {
	SDL_Log("%s: %s\n", message, error);
	exit(1);
}

void			init(SDL_Window **window, SDL_Renderer **renderer, SDL_Surface **surface, SDL_Texture **texture, Dot *dot) {
	SDL_DisplayMode	DM;

	SDL_GetCurrentDisplayMode(0, &DM);
	if ((*window = SDL_CreateWindow("Dot", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, DM.w, DM.h, SDL_WINDOW_FULLSCREEN)) == NULL)
		SDL_ExitWithError("Error Window creation", SDL_GetError());
	if ((*renderer = SDL_CreateRenderer(*window, -1, 0)) == NULL)
		SDL_ExitWithError("Error Renderer creation", SDL_GetError());
	if ((*surface = IMG_Load(DOT_PATH)) == NULL)
		SDL_ExitWithError("Error Image load", IMG_GetError());
	if ((*texture = SDL_CreateTextureFromSurface(*renderer, *surface)) == NULL)
		SDL_ExitWithError("Error Texture creation", SDL_GetError());
	*dot = Dot(DM.w / 2, DM.h / 2, DOT_SIZE);
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
	}
}

int				main(int ac, char **av) {
	SDL_Window		*window = NULL;
	SDL_Renderer	*renderer = NULL;
	SDL_Surface		*surface = NULL;
	SDL_Texture		*texture = NULL;
	SDL_Event		event;
	bool			running = true;
	Dot				dot;

	if (SDL_Init(SDL_INIT_VIDEO) != 0)
		SDL_ExitWithError("Error Initialisation SDL", SDL_GetError());
	init(&window, &renderer, &surface, &texture, &dot);
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
		SDL_RenderCopy(renderer, texture, NULL, &dot.pos);
		SDL_RenderPresent(renderer);
	}
	SDL_DestroyTexture(texture);
	SDL_FreeSurface(surface);
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
	return (0);
}
