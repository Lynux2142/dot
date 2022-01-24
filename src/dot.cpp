#include <dot.hpp>

void			keyboardEvent(std::map<int, bool> keys, bool *running, Dot *dot) {
		if (keys[SDLK_ESCAPE])
			*running = false;
		if (keys[SDLK_UP])
			dot->up();
		if (keys[SDLK_DOWN])
			dot->down();
		if (keys[SDLK_LEFT])
			dot->left();
		if (keys[SDLK_RIGHT])
			dot->right();
		if (keys[SDLK_MINUS])
			dot->resize(-DOT_RESIZE_SPEED);
		if (keys[SDLK_EQUALS])
			dot->resize(DOT_RESIZE_SPEED);
		if (keys[SDLK_SPACE])
			dot->reset();
}

int				main(int ac, char **av) {
	Display				*display;
	SDL_DisplayMode		DM;
	SDL_Event			event;
	bool				running(true);
	Dot					dot;
	std::map<int, bool>	keys;

	if (SDL_Init(SDL_INIT_VIDEO) != 0)
		ft_ExitWithError("Error Initialisation SDL", SDL_GetError());
	SDL_GetCurrentDisplayMode(0, &DM);
	display = new Display(DM.w, DM.h, DOT_PATH);
	dot = Dot((DM.w - DOT_SIZE) / 2, (DM.h - DOT_SIZE) / 2, DOT_SIZE);
	while (running) {
		while (SDL_PollEvent(&event)) {
			if (event.type == SDL_QUIT)
				running = false;
			if (event.type == SDL_KEYDOWN)
				keys[event.key.keysym.sym] = true;
			if (event.type == SDL_KEYUP)
				keys[event.key.keysym.sym] = false;
		}
		keyboardEvent(keys, &running, &dot);
		display->print(dot.pos);
		SDL_Delay(10);
	}
	delete display;
	SDL_Quit();
	return (0);
}
