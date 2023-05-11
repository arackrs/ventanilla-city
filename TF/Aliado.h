#pragma once
#include"Personaje.h"
#include"Barril.h"

class Aliado : public Personaje {
private:

public:
	Aliado(int _w, int _h) : Personaje(x, y, width, height) {
		x = 300;
		y = rand() % 400 + 10;
		dx = dy = 5;
		idx = idy = 0;
		width = _w;
		height = _h;
	}
	~Aliado() {}

	void draw(Graphics^ g, Bitmap^ bmp) {
		Rectangle dimension = Rectangle(x, y, width * 1.0, height * 1.0);
		Rectangle selection = Rectangle(idx * width, idy * height, width, height);
		g->DrawImage(bmp, dimension, selection, GraphicsUnit::Pixel);
	}
	void move(Barril* b) {
		if (!b->get_collision()) {
			if (x == b->get_x()) { x += 0; idy = 2; }
			if (x > b->get_x()) { x -= dx; idy = 1; }
			if (x < b->get_x()) { x += dx; idy = 2; }
			if (y == b->get_y()) { y += 0; idy = 2; }
			if (y > b->get_y()) { y -= dx; idy = 3; }
			if (y < b->get_y()) { y += dx; idy = 0; }
			idx++; if (idx > 3)idx = 0;
		}
	}
};