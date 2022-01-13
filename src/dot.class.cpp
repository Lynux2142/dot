#include <dot.hpp>

Dot::Dot(int x, int y, int size, int thickness) {
	size += (size % 2 == 0 ? 1 : 0);
	thickness += (thickness % 2 == 0 ? 1 : 0);

	this->vert.x = x - thickness / 2;
	this->vert.y = y - size / 2;
	this->vert.w = thickness;
	this->vert.h = size;

	this->hori.x = x - size / 2;
	this->hori.y = y - thickness / 2;
	this->hori.w = size;
	this->hori.h = thickness;
}

void	Dot::drawDot(SDL_Renderer *renderer) {
	SDL_SetRenderDrawColor(renderer, (char)(DOT_COLOR >> 16), (char)((DOT_COLOR >> 8) && 0xff), (char)(DOT_COLOR & 0xff), 0xff);
	SDL_RenderDrawRect(renderer, &this->vert);
	SDL_RenderFillRect(renderer, &this->vert);
	SDL_RenderDrawRect(renderer, &this->hori);
	SDL_RenderFillRect(renderer, &this->hori);
}

void	Dot::up(void) {
	this->vert.y -= DOT_SPEED;
	this->hori.y -= DOT_SPEED;
}

void	Dot::down(void) {
	this->vert.y += DOT_SPEED;
	this->hori.y += DOT_SPEED;
}

void	Dot::left(void) {
	this->vert.x -= DOT_SPEED;
	this->hori.x -= DOT_SPEED;
}

void	Dot::right(void) {
	this->vert.x += DOT_SPEED;
	this->hori.x += DOT_SPEED;
}
