#pragma once
#include"Objeto.h"

class Barril : public Objeto {

private:
	bool impact;
	bool limit;

public:
	Barril(int _w, int _h) : Objeto(x, y, width, height) {
		x = 1000;
		y = rand() % 450 + 30;
		dx = dy = 10;
		idx = 6;
		idy = 0;
		width = _w;
		height = _h;
		impact = limit = false;
	}
	~Barril() {}

	void draw(Graphics^ g, Bitmap^ bmpBarrel, Bitmap^ bmpImpact, Bitmap^ bmpLimit) {

		Bitmap^ bmp = bmpBarrel;
		float pixel = 0.25;
		int vX = 0, vY = 0;

		if (collision) {
			
			if (impact) {
				width = bmpImpact->Width / 7;
				height = bmpImpact->Height;
				idy = 0; vX = 30; vY = 25;
				bmp = bmpImpact;
				pixel = 0.5;
			}
			if (limit) {
				width = bmpLimit->Width / 4;
				height = bmpLimit->Height / 4;
				idy = 0; vX = 30; vY = 15;
				bmp = bmpLimit;
				pixel = 1.0;
			}
		}
		Rectangle dimension = Rectangle(x - vX, y - vY, width * pixel, height * pixel);
		Rectangle selection = Rectangle(idx * width, idy * height, width, height);
		g->DrawImage(bmp, dimension, selection, GraphicsUnit::Pixel);
	}
	void move(Graphics^ g) {

		idx++;
		if (collision) {

			if (impact) {
				if (idx > 6) { erase = true; }
			}
			if (limit) {
				if (idx > 3 ) { erase = true; }
			}
		}
		else {
			if (idx > 9 && idy == 0) { idx = 0; idy = 1; }
			if (idx > 3 && idy == 1) { idx = 6; idy = 0; }
			x -= dx;
		}
	}
	void set_impact(bool _i) { impact = _i; }
	void set_limit(bool _l) { limit = _l; }
};