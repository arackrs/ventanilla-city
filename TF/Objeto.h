#pragma once
#include<iostream>
using namespace System::Drawing;

class Objeto {

protected:
	int x, y;
	int dx, dy;
	int idx, idy;
	int width, height;
	bool collision;
	bool erase;

public:
	Objeto(int _x, int _y, int width, int height) {
		x = _x;
		y = _y;
		dx = dy = 20;
		idx = idy = 0;
		this->width = width;
		this->height = height;
		collision = false;
		erase = false;
	}
	~Objeto() {}

	virtual void draw() {}
	virtual void move() {}
	virtual int get_collision() { return collision; }
	virtual void set_collision(bool _c) { collision = _c; }
	virtual int get_erase() { return erase; }
	virtual void set_erase(bool _e) { erase = _e; }
	virtual int get_x() { return x; }
	virtual void set_x(bool _x) { x = _x; }
	virtual int get_y() { return y; }
	virtual void set_y(bool _y) { x = _y; }
	virtual Rectangle get_rectangle() { return Rectangle(x, y, width * 0.25, height * 0.25); }
};