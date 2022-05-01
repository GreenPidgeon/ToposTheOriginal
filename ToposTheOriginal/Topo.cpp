#include "Topo.hh"

void Topo::Draw(SDL_Color color) {
    if (true) {
        Graphics::DrawSquare(x, y, 10, color);
    }
}
    
void Topo::set_init_pos(int x, int y) {
    this->x = x;
    this->y = y;
}
void Topo::set_init_indices(int x, int y) {
    index_x = x;
    index_y = y;
}
int Topo::getix() {return index_x;}
int Topo::getiy() {return index_y;}