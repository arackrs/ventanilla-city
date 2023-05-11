#pragma once
#include"Personaje.h"

class Jugador : public Personaje {

private:
	char key;

public:
	Jugador(int _w, int _h) : Personaje(x, y, width, height) {
		x = 300;
		y = 100;
		dx = dy = 20;
		idx = idy = 0;
		width = _w;
		height = _h;
		key = ' ';
	}
	~Jugador() {}

	void draw(Graphics^ g, Bitmap^ bmp) {
		Rectangle dimension = Rectangle(x, y, width * 1.0, height * 1.0);
		Rectangle selection = Rectangle(idx * width, idy * height, width, height);
		g->DrawImage(bmp, dimension, selection, GraphicsUnit::Pixel);
	}
	void move(Graphics^ g) {

		dx = dy = 20;
		if (key == 'A') {
			if (x > 160) { idy = 1; x -= dx; }
		}
		if (key == 'D') {
			if (x + width * 1.0 < g->VisibleClipBounds.Width - 200) { idy = 2; x += dx; }
		}
		if (key == 'W') {
			if (y > 0) { idy = 3; y -= dy; }
		}
		if (key == 'S') {
			if (y + height * 1.0 < g->VisibleClipBounds.Height) { idy = 0; y += dy; }
		}
		if (key != ' ') { idx++; if (idx > 3) idx = 0; }
		
	}
	void stop() {

		//DETENER JUGADOR
		idy = 2; idx = 0; dx = 0; dy = 0;
		key = ' ';
	}
	void set_key(char _k) { key = _k; }
	char get_key() { return key; }
};