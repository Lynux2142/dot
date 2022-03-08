#ifndef DISPLAY_CLASS_HPP
# define DISPLAY_CLASS_HPP

#include <dot.hpp>
#include <deque>

class								Display {
	public:
		SDL_Window					*window;
		SDL_Renderer				*renderer;
		std::deque<SDL_Texture*>	*image;
		int							image_type;

		Display(void);
		Display(const int width, const int height, const char *image_path);
		~Display(void);

		void						print(SDL_Rect *pos);
		void						next_image(void);
		void						prev_image(void);
		void						switch_image_type(void);
};

#endif
