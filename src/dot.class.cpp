#include <dot.hpp>

Dot::Dot(void) {
	this->pos.x = 0;
	this->pos.y = 0;
	this->pos.w = 0;
	this->pos.h = 0;
	this->size = 0;
}

Dot::Dot(int x, int y, int size) {
	this->pos.x = x;
	this->pos.y = y;
	this->pos.w = size;
	this->pos.h = size;
	this->size = size;
}

void	Dot::up(void) {
	this->pos.y -= DOT_SPEED;
}

void	Dot::down(void) {
	this->pos.y += DOT_SPEED;
}

void	Dot::left(void) {
	this->pos.x -= DOT_SPEED;
}

void	Dot::right(void) {
	this->pos.x += DOT_SPEED;
}

void	Dot::resize(int size) {
	size = (size < 0 && this->size <= 2 ? 0 : size);
	this->size += size;
	this->pos.x -= size / 2;
	this->pos.y -= size / 2;
	this->pos.w = this->size;
	this->pos.h = this->size;
}
