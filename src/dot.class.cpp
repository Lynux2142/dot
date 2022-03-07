#include <dot.hpp>

Dot::Dot(void): _init_pos({0, 0, 0, 0,}), _ratio(0) {
	this->pos = {0, 0, 0, 0};
}

Dot::Dot(int x, int y, int w, int h): _init_pos({x, y, w, h}), _ratio((double)h / (double)w) {
	this->pos = {x, y, w, h};
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

void	Dot::upscale(void) {
	const double center_x = (double)this->pos.x + (double)this->pos.w / 2.0;
	const double center_y = (double)this->pos.y + (double)this->pos.h / 2.0;
	this->pos.w += DOT_RESIZE_SPEED;
	this->pos.h = (int)(round((double)this->pos.w * _ratio * 0.5) * 2.0);
	this->pos.x = (int)round(center_x - (double)this->pos.w / 2.0);
	this->pos.y = (int)round(center_y - (double)this->pos.h / 2.0);
}

void	Dot::downscale(void) {
	if (this->pos.w < 5 || this->pos.h < 5)
		return;
	const double center_x = (double)this->pos.x + (double)this->pos.w / 2.0;
	const double center_y = (double)this->pos.y + (double)this->pos.h / 2.0;
	this->pos.w -= DOT_RESIZE_SPEED;
	this->pos.h = (int)(round((double)this->pos.w * _ratio * 0.5) * 2.0);
	this->pos.x = (int)round(center_x - (double)this->pos.w / 2.0);
	this->pos.y = (int)round(center_y - (double)this->pos.h / 2.0);
}

void	Dot::reset(void) {
	*this = Dot(this->_init_pos.x, this->_init_pos.y, this->_init_pos.w, this->_init_pos.h);
}
