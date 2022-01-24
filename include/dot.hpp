#ifndef DOT_HPP
# define DOT_HPP

# include <SDL2/SDL.h>
# include <SDL2/SDL_image.h>
# include <iostream>
# include <dot.class.hpp>
# include <display.class.hpp>
# include <map>

# define DOT_PATH				"./images/dot.png"
# define DOT_SIZE				50
# define DOT_SPEED				2
# define DOT_RESIZE_SPEED		2

void	ft_ExitWithError(const char *message, const char *error);

#endif
