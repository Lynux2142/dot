#include <dot.hpp>

Dot::Dot(int x, int y, int size, int thickness) {
	this->pos.x = x;
	this->pos.y = y;
	this->size = size % 2 == 0 ? size + 1 : size;
	this->thickness = thickness % 2 == 0 ? thickness + 1 : thickness;

	this->vert.x = this->pos.x - this->thickness / 2;
	this->vert.y = this->pos.y - this->size / 2;
	this->vert.w = this->thickness;
	this->vert.h = this->size;

	this->hori.x = this->pos.x - this->size / 2;
	this->hori.y = this->pos.y - this->thickness / 2;
	this->hori.w = this->size;
	this->hori.h = this->thickness;
}

void	Dot::drawDot(SDL_Renderer *renderer) {
	SDL_SetRenderDrawColor(renderer, (char)(DOT_COLOR >> 16), (char)((DOT_COLOR >> 8) && 0xff), (char)(DOT_COLOR & 0xff), 0xff);
	SDL_RenderDrawRect(renderer, &this->vert);
	SDL_RenderFillRect(renderer, &this->vert);
	SDL_RenderDrawRect(renderer, &this->hori);
	SDL_RenderFillRect(renderer, &this->hori);
}

void	Dot::up(void) {
	this->pos.y -= DOT_SPEED;
	this->vert.y -= DOT_SPEED;
	this->hori.y -= DOT_SPEED;
}

void	Dot::down(void) {
	this->pos.y += DOT_SPEED;
	this->vert.y += DOT_SPEED;
	this->hori.y += DOT_SPEED;
}

void	Dot::left(void) {
	this->pos.x -= DOT_SPEED;
	this->vert.x -= DOT_SPEED;
	this->hori.x -= DOT_SPEED;
}

void	Dot::right(void) {
	this->pos.x += DOT_SPEED;
	this->vert.x += DOT_SPEED;
	this->hori.x += DOT_SPEED;
}

void	Dot::resize(int size) {
	this->size += (size < 0 && this->size <= 3) ? 0 : size;
	this->vert.y = this->pos.y - this->size / 2;
	this->vert.h = this->size;
	this->hori.x = this->pos.x - this->size / 2;
	this->hori.w = this->size;
}

void	Dot::rethickness(int thickness) {
	this->thickness += ((thickness < 0 && this->thickness <= 1) ||
		(thickness > 0 && this->thickness == this->size)) ? 0 : thickness;
	this->vert.x = this->pos.x - this->thickness / 2;
	this->vert.w = this->thickness;
	this->hori.y = this->pos.y - this->thickness / 2;
	this->hori.h = this->thickness;
}
