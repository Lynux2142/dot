#ifndef DOT_CLASS_HPP
# define DOT_CLASS_HPP

# include <dot.hpp>

class				Dot {
	private:
		SDL_Rect	_init_pos;
		double		_ratio;
	public:
		SDL_Rect	pos;

		Dot(void);
		Dot(int x, int y, int w, int h);

		void		up(void);
		void		down(void);
		void		left(void);
		void		right(void);
		void		upscale(void);
		void		downscale(void);
		void		reset(void);
};

#endif
