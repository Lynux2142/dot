#ifndef DOT_HPP
# define DOT_HPP

# include <SDL2/SDL.h>
# include <SDL2/SDL_image.h>
# include <iostream>
# include <dot.class.hpp>
# include <display.class.hpp>
# include <map>
# include <math.h>
# include <filesystem>
# include <unistd.h>

# define DOT_PATH				"./images/dots"
# define BOARD_PATH				"./images/boards"
# define DOT_SPEED				2
# define DOT_RESIZE_SPEED		4 // MUST BE EVEN
# define DOT_INIT_SIZE			50

# define QUIT					SDLK_ESCAPE
# define MOVE_UP				SDLK_UP
# define MOVE_DOWN				SDLK_DOWN
# define MOVE_LEFT				SDLK_LEFT
# define MOVE_RIGHT				SDLK_RIGHT
# define DOWN_SCALE				SDLK_MINUS
# define UP_SCALE				SDLK_EQUALS
# define RESET					SDLK_SPACE
# define NEXT_IMAGE				SDLK_o
# define PREV_IMAGE				SDLK_u
# define SWITCH_IMAGE_TYPE		SDLK_i
# define DOTS					0
# define BOARDS					1

void	ft_ExitWithError(const char *message, const char *error);

#endif
