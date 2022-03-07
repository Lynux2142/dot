#ifndef DISPLAY_CLASS_HPP
# define DISPLAY_CLASS_HPP

#include <dot.hpp>

typedef struct			s_image {
	SDL_Texture			*image;
	char				*file_name;
	struct s_image		*prev;
	struct s_image		*next;
}						t_image;

typedef struct			s_image_type {
	t_image				*image_list;
	struct s_image_type	*next;
}						t_image_type;

class					Display {
	public:
		SDL_Window		*window;
		SDL_Renderer	*renderer;
		t_image_type	*image_type;

		Display(void);
		Display(const int width, const int height, const char *image_path);
		~Display(void);

		void			print(SDL_Rect *pos);
		void			next_image(void);
		void			prev_image(void);
		void			switch_image_type(void);
};

#endif
