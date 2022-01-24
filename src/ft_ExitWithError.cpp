#include <dot.hpp>

void	ft_ExitWithError(const char *message, const char *error) {
	SDL_Log("%s: %s\n", message, error);
	exit(1);
}
