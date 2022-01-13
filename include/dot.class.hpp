#ifndef DOT_CLASS_HPP
# define DOT_CLASS_HPP

# include <dot.hpp>

class				Dot {
	public:
		SDL_Rect	vert;
		SDL_Rect	hori;
		Dot(int x, int y, int size, int thickness);
		void		drawDot(SDL_Renderer *renderer);
		void		up(void);
		void		down(void);
		void		left(void);
		void		right(void);
};

#endif
