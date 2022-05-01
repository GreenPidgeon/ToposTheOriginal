#pragma once
#include <iostream>
#include <vector>
#include <SDL.h>
#include <stdio.h>
#include "Topo.hh"
#include "Cuadrao.hh"
#include "Mouse.hh"
#include "Texture.hh"
using namespace std;
class Jardi {
public:
	Jardi();
	Jardi(int x, int y);
	void Draw();
	void PlaceTopos(SDL_Event& event_handler); //inicialitzar
	void Cavar(); //comprovar lo que hay debajo
	static void Init_Pictures();
	static Texture terreno, tile_tula, tile_tula_portal, tile_straight, tile_straight_portal, tile_void, tile_l, tile_l_portal, tile_cross, tile_cross_portal, Cyborg_viu, Cyborg_mort, Mag_viu, Mag_mort, Topo_viu, Topo_mort;
	static SDL_Rect terreno1, tile_tula1, tile_tula_portal1, tile_straight1, tile_straight_portal1, tile_void1, tile_l1, tile_l_portal1, tile_cross1, tile_cross_portal1;
private:
	Graphics g;
	int x, y;
	vector < vector<pair<int, int>> > posiciones; //num topos
};
