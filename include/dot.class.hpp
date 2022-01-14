#ifndef DOT_CLASS_HPP
# define DOT_CLASS_HPP

# include <dot.hpp>

typedef struct		s_coord {
	int				x;
	int				y;
}					t_coord;

class				Dot {
	public:
		t_coord		pos;
		int			size;
		int			thickness;
		SDL_Rect	vert;
		SDL_Rect	hori;
		Dot(int x, int y, int size, int thickness);
		void		drawDot(SDL_Renderer *renderer);
		void		up(void);
		void		down(void);
		void		left(void);
		void		right(void);
		void		resize(int size);
		void		rethickness(int thickness);
};

#endif
