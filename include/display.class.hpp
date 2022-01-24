#ifndef DISPLAY_CLASS_HPP
# define DISPLAY_CLASS_HPP

#include <dot.hpp>

class					Display {
	public:
		SDL_Window		*window;
		SDL_Renderer	*renderer;
		SDL_Texture		*image;

		Display(void);
		Display(const int width, const int height, const char *image_path);
		~Display(void);

		void			print(SDL_Rect pos);
};

#endif
