#pragma once
#include "Graphics.hh"

class Topo {
public:
    void Draw(SDL_Color color);
    void set_init_pos(int x, int y);
    void set_init_indices(int x, int y);
    int getix();
    int getiy();
    int x, y, index_x, index_y;
};