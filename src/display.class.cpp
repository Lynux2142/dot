#include <dot.hpp>

Display::Display(void) {
	this->window = NULL;
	this->renderer = NULL;
	this->image_type = NULL;
}

t_image		*fetch_images(SDL_Renderer *renderer, const char *dir_path) {
	t_image			first;
	t_image			*current = &first;
	t_image			*new_node;
	SDL_Surface		*surface;
	char			*file_name;

	first.file_name = NULL;
	for (const auto & entry : std::filesystem::directory_iterator(dir_path)) {
		file_name = (char*)entry.path().string().c_str();
		new_node = (t_image*)malloc(sizeof(t_image));
		if ((surface = IMG_Load(file_name)) == NULL)
			ft_ExitWithError("Error Image Load", SDL_GetError());
		if ((new_node->image = SDL_CreateTextureFromSurface(renderer, surface)) == NULL)
			ft_ExitWithError("Error Renderer Texture", SDL_GetError());
		SDL_FreeSurface(surface);
		memcpy(&new_node->file_name, &file_name, strlen(file_name));
		new_node->next = NULL;
		new_node->prev = current;
		current->next = new_node;
		current = current->next;
	}
	first.next->prev = current;
	current->next = first.next;
	return (first.next);
}

Display::Display(const int width, const int height, const char *image_path) {
	t_image	*dots;
	t_image	*boards;

	if ((this->window = SDL_CreateWindow("Dot", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, SDL_WINDOW_FULLSCREEN)) == NULL)
		ft_ExitWithError("Error Window Creation", SDL_GetError());
	if ((this->renderer = SDL_CreateRenderer(this->window, -1, 0)) == NULL)
		ft_ExitWithError("Error Renderer Creation", SDL_GetError());
	boards = fetch_images(this->renderer, BOARD_PATH);
	dots = fetch_images(this->renderer, DOT_PATH);
	this->image_type = (t_image**)malloc(sizeof(t_image*) * 2);
	this->image_type[0] = dots;
	this->image_type[1] = boards;
}

Display::~Display(void) {
	t_image			**current_image_type = this->image_type;
	t_image			*current_image;
	t_image			*tmp_image;

	for (int i = 0; i < 2; ++i) {
		current_image = current_image_type[i];
		while (current_image) {
			tmp_image = current_image;
			current_image = current_image->next;
			free(tmp_image->image);
			free(tmp_image->file_name);
			tmp_image->next = NULL;
			tmp_image->prev = NULL;
			free(tmp_image);
		}
		free(current_image_type[i]);
	}
	if (this->renderer)
		SDL_DestroyRenderer(this->renderer);
	if (this->window)
		SDL_DestroyWindow(this->window);
}

void		Display::print(SDL_Rect *pos) {
	SDL_SetRenderDrawColor(this->renderer, 0, 0, 0, 0);
	SDL_RenderClear(this->renderer);
	SDL_RenderCopy(this->renderer, this->image_type[this->image_type_selected]->image, NULL, pos);
	SDL_RenderPresent(this->renderer);
}

void		Display::next_image(void) {
	this->image_type[this->image_type_selected] = this->image_type[this->image_type_selected]->next;
}

void		Display::prev_image(void) {
	this->image_type[this->image_type_selected] = this->image_type[this->image_type_selected]->prev;
}

void		Display::switch_image_type(void) {
	this->image_type_selected = !this->image_type_selected;
}
