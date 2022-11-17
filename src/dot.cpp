#include <dot.hpp>

void	fastKeyboardEvent(std::map<int, bool> keys, bool *running, Dot *dot, Display *display) {
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
}

void	slowKeyboardEvent(int keyValue, Display *display) {
	if (keyValue == NEXT_IMAGE)
		display->next_image();
	if (keyValue == PREV_IMAGE)
		display->prev_image();
	if (keyValue == SWITCH_IMAGE_TYPE)
		display->switch_image_type();
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
//	dot = Dot((DM.w - image_w) / 2, (DM.h - image_h) / 2, image_w, image_h);
	dot = Dot((DM.w - DOT_INIT_SIZE) / 2, (DM.h - DOT_INIT_SIZE) / 2, DOT_INIT_SIZE, DOT_INIT_SIZE);
	while (running) {
		while (SDL_PollEvent(&event)) {
			if (event.type == SDL_QUIT)
				running = false;
			if (event.type == SDL_KEYDOWN) {
				keys[event.key.keysym.sym] = true;
				slowKeyboardEvent(event.key.keysym.sym, display);
			}
			if (event.type == SDL_KEYUP)
				keys[event.key.keysym.sym] = false;
		}
		fastKeyboardEvent(keys, &running, &dot, display);
		display->print((display->image_type == BOARDS) ? NULL : &dot.pos);
		SDL_Delay(10);
	}
	delete display;
	SDL_Quit();
	return (0);
}
