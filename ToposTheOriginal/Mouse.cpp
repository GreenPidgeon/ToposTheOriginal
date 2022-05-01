#include "Mouse.hh"

void Mouse::Update()
{
	SDL_GetMouseState(&mouse_x, &mouse_y);
    if (picked_topo != NULL)
    picked_topo->set_init_pos(mouse_x, mouse_y);
}

void Mouse::Draw(Texture& a, SDL_Rect* src)
{
    SDL_Rect aux = SDL_Rect{mouse_x-50, mouse_y-25, 100, 50};
    Graphics::DrawTextureRect(a,&aux, src);
}
void Mouse::GetTopo() 
{
        picked_topo = new Topo();
        picked_topo->set_init_pos(mouse_x, mouse_y);
}


int Mouse::Getx() { return mouse_x; }
int Mouse::Gety() { return mouse_y; }
Topo* Mouse::get() { 
    Topo* a = picked_topo;
    picked_topo = NULL;
    return a;
    }