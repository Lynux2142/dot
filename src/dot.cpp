#include <dot.hpp>

void			keyboardEvent(int key, bool *running, Dot *dot, Display *display) {
	switch (key) {
		case QUIT :
			*running = false;
			break;
		case MOVE_UP :
			dot->up();
			break;
		case MOVE_DOWN :
			dot->down();
			break;
		case MOVE_LEFT :
			dot->left();
			break;
		case MOVE_RIGHT :
			dot->right();
			break;
		case DOWN_SCALE :
			dot->downscale();
			break;
		case UP_SCALE :
			dot->upscale();
			break;
		case RESET :
			dot->reset();
			break;
		case NEXT_IMAGE :
			display->next_image();
			break;
		case PREV_IMAGE :
			display->prev_image();
			break;
		case SWITCH_IMAGE_TYPE :
			display->switch_image_type();
			break;
	}
}

int				main(int ac, char **av) {
	Display				*display;
	SDL_DisplayMode		DM;
	SDL_Event			event;
	bool				running(true);
	Dot					dot;
	int					image_w;
	int					image_h;

	if (SDL_Init(SDL_INIT_VIDEO) != 0)
		ft_ExitWithError("Error Initialisation SDL", SDL_GetError());
	SDL_GetCurrentDisplayMode(0, &DM);
	display = new Display(DM.w, DM.h, DOT_PATH);
	SDL_QueryTexture(display->image_type[display->image_type_selected]->image, NULL, NULL, &image_w, &image_h);
	dot = Dot((DM.w - image_w) / 2, (DM.h - image_h) / 2, image_w, image_h);
	while (running) {
		while (SDL_PollEvent(&event)) {
			if (event.type == SDL_QUIT)
				running = false;
			if (event.type == SDL_KEYDOWN)
				keyboardEvent(event.key.keysym.sym, &running, &dot, display);
		}
		display->print((display->image_type_selected == 1) ? NULL : &dot.pos);
		SDL_Delay(10);
	}
	delete display;
	SDL_Quit();
	return (0);
}
