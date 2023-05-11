#pragma once
#include"Personaje.h"
#include"Objeto.h"
#include"Jugador.h"
#include"Barril.h"
#include"Aliado.h"
#include<vector>
using namespace std;
using namespace System::Media;

class Controller {

private:
	Jugador* player1;
	vector<Barril*> barril;
	vector<Aliado*> aliado;
	int cont;

public:
	Controller(Bitmap^ bmpPlayer1) {
		player1 = new Jugador(bmpPlayer1->Width / 3.8, bmpPlayer1->Width / 3.8);
		cont = 0;
	}
	~Controller() {}
	
	void add_barrel(Bitmap^ bmpBarrel) {
		//AGREGA UNA NUEVA CLASE DEL OBJETO "BARRIL"
		barril.push_back(new Barril(bmpBarrel->Width / 10, bmpBarrel->Height / 2));
	}
	void add_allied(Bitmap^ bmpAllied) {
		//AGREGA UNA NUEVA CLASE DEL PERSONAJE "ALIADO"
		aliado.push_back(new Aliado(bmpAllied->Width / 4, bmpAllied->Height / 4));
	}
	void deleted_allied() {
		//ELIMINA UNA CLASE DEL PERSONAJE "ALIADO"
		for (int i = 0; i < aliado.size(); ++i)aliado.erase(aliado.begin() + i);
	}
	void draw_all(Graphics^ g, Bitmap^ bmpPlayer1, Bitmap^ bmpBarrel, Bitmap^ bmpImpact, Bitmap^ bmpLimit, Bitmap^ bmpAllied, Bitmap^ bmpBala) {
		//DIBUJA TODO LO QUE TENGA "ANIMACION"
		player1->draw(g, bmpPlayer1);
		for (int i = 0; i < barril.size(); ++i)barril[i]->draw(g, bmpBarrel, bmpImpact, bmpLimit);
		for (int i = 0; i < aliado.size(); ++i) if(i < 2)aliado[i]->draw(g, bmpAllied);
	}
	void move_all(Graphics^ g) {
		//MUEVE TODO LO QUE TENGA "ANIMACION"
		player1->move(g);
		for (int i = 0; i < barril.size(); ++i) { barril[i]->move(g); }
		for (int i = 0; i < aliado.size(); ++i) if (i < 2)aliado[i]->move(barril[i]);
	}
	void collisions(SoundPlayer^ puntos, SoundPlayer^ agua) {

		//VERIFICA SI EL BARRIL HA COLISIONADO CON EL "JUGADOR"
		for (int i = 0; i < barril.size(); ++i) {
			if (barril[i]->get_rectangle().IntersectsWith(player1->get_rectangle()) ||
				player1->get_rectangle().IntersectsWith(barril[i]->get_rectangle())) {
				barril[i]->set_collision(true);
				barril[i]->set_impact(true);
				puntos->Play();
			}
		}	
		//VERIFICA SI EL BARRIL HA COLISIONADO CON EL "ALIADO"
		for (int i = 0; i < aliado.size(); ++i) {
			for (int j = 0; j < barril.size(); ++j) {
				if (barril[j]->get_rectangle().IntersectsWith(aliado[i]->get_rectangle()) ||
					aliado[i]->get_rectangle().IntersectsWith(barril[j]->get_rectangle())) {
					barril[i]->set_collision(true);
					barril[i]->set_impact(true);
					puntos->Play();
				}
			}
		}
		//VERIFICA SI EL BARRIL HA COLISIONADO CON EL "LIMITE"
		for (int i = 0; i < barril.size(); ++i) {
			if (barril[i]->get_x() <= 130) {
				barril[i]->set_collision(true);
				barril[i]->set_limit(true);
				cont++; agua->Play();
			}
		}
	}
	void erase() {

		//ELIMINA SOLO SI HUBO "COLISION" CON EL BARRIL
		for (int i = 0; i < barril.size(); ++i) {
			if (barril[i]->get_erase()) {
				if (barril.size() > 2)barril.erase(barril.begin() + i);
				
			}
		}
	}
	Jugador* get_player1() { return player1; }
	int get_cont() { return cont; }
};