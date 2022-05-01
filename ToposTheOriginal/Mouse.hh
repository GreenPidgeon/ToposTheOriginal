#pragma once
//Using SDL and standard IO
#include <SDL.h>
#include <stdio.h>
#include "Topo.hh"

class Mouse {
public:
	Mouse() { }
	void Update();
	void Draw(Texture& a, SDL_Rect* src);
    void GetTopo();
    int Getx();
    int Gety();
    Topo* get();
private:
	Topo* picked_topo = NULL;
	int mouse_x, mouse_y;
};