#include <dot.hpp>

Display::Display(void) {
	this->window = NULL;
	this->renderer = NULL;
	this->image = NULL;
}

std::deque<SDL_Texture*>	fetch_images(SDL_Renderer *renderer, const char *dir_path) {
	SDL_Surface			*surface;
	SDL_Texture			*texture;
	std::deque<SDL_Texture*>	image_list;

	for (const auto & entry : std::filesystem::directory_iterator(dir_path)) {
		if ((surface = IMG_Load((char*)entry.path().string().c_str())) == NULL)
			ft_ExitWithError("Error Image Load", SDL_GetError());
		if ((texture = SDL_CreateTextureFromSurface(renderer, surface)) == NULL)
			ft_ExitWithError("Error Renderer Texture", SDL_GetError());
		SDL_FreeSurface(surface);
		image_list.push_back(texture);
	}
	return (image_list);
}

Display::Display(const int width, const int height, const char *image_path) {
	if ((this->window = SDL_CreateWindow("Dot", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, SDL_WINDOW_FULLSCREEN)) == NULL)
		ft_ExitWithError("Error Window Creation", SDL_GetError());
	if ((this->renderer = SDL_CreateRenderer(this->window, -1, 0)) == NULL)
		ft_ExitWithError("Error Renderer Creation", SDL_GetError());
	this->image = new std::deque<SDL_Texture*>[2];
	this->image[0] = fetch_images(this->renderer, DOT_PATH);
	this->image[1] = fetch_images(this->renderer, BOARD_PATH);
}

Display::~Display(void) {
	for (int i = 0; i < 2; ++i) {
		while (!this->image[this->image_type].empty()) {
			SDL_DestroyTexture(this->image[this->image_type].front());
			this->image[this->image_type].pop_front();
		}
	}
	delete this->image;
	if (this->renderer)
		SDL_DestroyRenderer(this->renderer);
	if (this->window)
		SDL_DestroyWindow(this->window);
}

void						Display::print(SDL_Rect *pos) {
	SDL_SetRenderDrawColor(this->renderer, 0, 0, 0, 0);
	SDL_RenderClear(this->renderer);
	SDL_RenderCopy(this->renderer, this->image[this->image_type].front(), NULL, pos);
	SDL_RenderPresent(this->renderer);
}

void						Display::next_image(void) {
	this->image[this->image_type].push_back(this->image[this->image_type].front());
	this->image[this->image_type].pop_front();
}

void						Display::prev_image(void) {
	this->image[this->image_type].push_front(this->image[this->image_type].back());
	this->image[this->image_type].pop_back();
}

void						Display::switch_image_type(void) {
	this->image_type = !this->image_type;
}
