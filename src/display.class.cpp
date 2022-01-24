#include <dot.hpp>

Display::Display(void) {
	this->window = NULL;
	this->renderer = NULL;
	this->image = NULL;
}

Display::Display(const int width, const int height, const char *image_path) {
	SDL_Surface		*surface;

	if ((this->window = SDL_CreateWindow("Dot", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, SDL_WINDOW_FULLSCREEN)) == NULL)
		ft_ExitWithError("Error Window Creation", SDL_GetError());
	if ((this->renderer = SDL_CreateRenderer(this->window, -1, 0)) == NULL)
		ft_ExitWithError("Error Renderer Creation", SDL_GetError());
	if ((surface = IMG_Load(DOT_PATH)) == NULL)
		ft_ExitWithError("Error Renderer Surface", SDL_GetError());
	if ((this->image = SDL_CreateTextureFromSurface(this->renderer, surface)) == NULL)
		ft_ExitWithError("Error Renderer Texture", SDL_GetError());
	SDL_FreeSurface(surface);
}

Display::~Display(void) {
	if (this->image)
		SDL_DestroyTexture(this->image);
	if (this->renderer)
		SDL_DestroyRenderer(this->renderer);
	if (this->window)
		SDL_DestroyWindow(this->window);
}

void	Display::print(SDL_Rect pos) {
	SDL_SetRenderDrawColor(this->renderer, 0, 0, 0, 0);
	SDL_RenderClear(this->renderer);
	SDL_RenderCopy(this->renderer, this->image, NULL, &pos);
	SDL_RenderPresent(this->renderer);
}
