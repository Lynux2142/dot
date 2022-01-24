#ifndef DOT_CLASS_HPP
# define DOT_CLASS_HPP

# include <dot.hpp>

class				Dot {
	private:
		SDL_Rect	_init_pos;
		int			_init_size;
	public:
		SDL_Rect	pos;
		int			size;

		Dot(void);
		Dot(int x, int y, int size);

		void		up(void);
		void		down(void);
		void		left(void);
		void		right(void);
		void		resize(int size);
		void		reset(void);
};

#endif
