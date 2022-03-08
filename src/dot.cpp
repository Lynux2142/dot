#include <dot.hpp>

void	keyboardEvent(std::map<int, bool> keys, bool *running, Dot *dot, Display *display) {
	if (keys[QUIT])
		*running = false;
	if (keys[MOVE_UP])
		dot->up();
	if (keys[MOVE_DOWN])
		dot->down();
	if (keys[MOVE_LEFT])
		dot->left();
	if (keys[MOVE_RIGHT])
		dot->right();
	if (keys[DOWN_SCALE])
		dot->downscale();
	if (keys[UP_SCALE])
		dot->upscale();
	if (keys[RESET])
		dot->reset();
	if (keys[NEXT_IMAGE]) {
		display->next_image();
			SDL_WaitEvent(NULL);
	}
	if (keys[PREV_IMAGE]) {
		display->prev_image();
			SDL_WaitEvent(NULL);
	}
	if (keys[SWITCH_IMAGE_TYPE]) {
		display->switch_image_type();
			SDL_WaitEvent(NULL);
	}
}

int		main(int ac, char **av) {
	Display				*display;
	SDL_DisplayMode		DM;
	SDL_Event			event;
	bool				running(true);
	Dot					dot;
	int					image_w;
	int					image_h;
	std::map<int, bool>	keys;

	if (SDL_Init(SDL_INIT_VIDEO) != 0)
		ft_ExitWithError("Error Initialisation SDL", SDL_GetError());
	SDL_GetCurrentDisplayMode(0, &DM);
	display = new Display(DM.w, DM.h, DOT_PATH);
	SDL_QueryTexture(display->image[display->image_type].front(), NULL, NULL, &image_w, &image_h);
	dot = Dot((DM.w - image_w) / 2, (DM.h - image_h) / 2, image_w, image_h);
	while (running) {
		while (SDL_PollEvent(&event)) {
			if (event.type == SDL_QUIT)
				running = false;
			if (event.type == SDL_KEYDOWN)
				keys[event.key.keysym.sym] = true;
			if (event.type == SDL_KEYUP)
				keys[event.key.keysym.sym] = false;
		}
		keyboardEvent(keys, &running, &dot, display);
		display->print((display->image_type == BOARDS) ? NULL : &dot.pos);
		SDL_Delay(10);
	}
	delete display;
	SDL_Quit();
	return (0);
}
