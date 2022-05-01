#include "Jardi.hh"
#include "Texture.hh"
extern SDL_Renderer* gRenderer;
Texture Jardi::terreno;
Texture Jardi::tile_tula;
Texture Jardi::tile_tula_portal;
Texture Jardi::tile_straight;
Texture Jardi::tile_straight_portal;
Texture Jardi::tile_void;
Texture Jardi::tile_l;
Texture Jardi::tile_l_portal;
Texture Jardi::tile_cross;
Texture Jardi::tile_cross_portal;
Texture Jardi::Cyborg_viu;
Texture Jardi::Cyborg_mort;
Texture Jardi::Topo_viu;
Texture Jardi::Topo_mort;
Texture Jardi::Mag_viu;
Texture Jardi::Mag_mort;
SDL_Rect Jardi::terreno1;
SDL_Rect Jardi::tile_tula1;
SDL_Rect Jardi::tile_tula_portal1;
SDL_Rect Jardi::tile_straight1;
SDL_Rect Jardi::tile_straight_portal1;
SDL_Rect Jardi::tile_void1;
SDL_Rect Jardi::tile_l1;
SDL_Rect Jardi::tile_l_portal1;
SDL_Rect Jardi::tile_cross1;
SDL_Rect Jardi::tile_cross_portal1;

Jardi::Jardi() {

}

Jardi::Jardi(int x, int y) {
	this->x = x;
	this->y = y;
	posiciones = vector < vector<pair<int, int>> >(3);
}
	
void Jardi::Draw() {
	/*Graphics::DrawSquare(x - 5, y - 5, 325, {46, 33, 17, 255});
	for (int i = 0; i < 8; ++i) {
		for (int j = 0; j < 8; ++j) {
			taula[i][j].first.Draw(x + 40 * i, y + 40 * j);
		}
	}
	for (int i = 0; i < topos.size(); ++i) {
		topos[i] -> Draw();
	}*/
}

void Jardi::PlaceTopos(SDL_Event& event_handler) {
	//SDL_Event event_handler;
	bool quit = false;
	bool topo_placed = false;
	Texture a("Tula_Tile.png");
	SDL_SetRenderDrawColor(gRenderer, 28, 27, 26, 0xFF);
	SDL_Rect aux{ 0, 0, 1400, 770};
	SDL_RenderFillRect(gRenderer, &aux);
	Mouse mouse;
	mouse.Update();
	SDL_RenderPresent(gRenderer);
	// Events/Inputs in a frame
	SDL_Rect aux1{400,80,640,640};
	SDL_Rect aux2{0,0,terreno.GetWidth(),terreno.GetHeight()};
	SDL_Rect topo_size1{0,0,Topo_viu.GetWidth(), Topo_viu.GetHeight()};
	SDL_Rect topo_size2{ 0,0,Cyborg_viu.GetWidth(), Cyborg_viu.GetHeight() };
	SDL_Rect topo_size3{ 0,0,Mag_viu.GetWidth(), Mag_viu.GetHeight() };
	SDL_Rect topo_place1, topo_place2, topo_place3;
	//Place Topo 1
	mouse.GetTopo();
	while (!quit) {
		SDL_SetRenderDrawColor(gRenderer, 28, 27, 26, 0xFF);
		SDL_RenderFillRect(gRenderer, &aux);

		//Graphics::DrawTextureRect(a, &aux1,&aux2);
		//g.DrawTabla(0, 50);
		Graphics::DrawTextureRect(terreno, &aux1, &aux2);
		mouse.Update();
		if (not topo_placed) mouse.Draw(Topo_viu, &topo_size1);
		else Graphics::DrawTextureRect(Topo_viu, &topo_place1, &topo_size1);
		for (int i = 0; i < int(posiciones[0].size()) - 1; ++i) {
			Graphics::DrawLine(posiciones[0][i].first*80 + 440, posiciones[0][i].second*80 + 120, posiciones[0][i+1].first*80 + 440, posiciones[0][i+1].second*80 + 120, {255,0,0,255});
		}
		SDL_RenderPresent(gRenderer);
		while (SDL_PollEvent(&event_handler) != 0)
		{
			if (event_handler.type == SDL_MOUSEBUTTONDOWN) { //Poner topo
				if (not topo_placed) {
					int new_x = (mouse.Getx()-400)/80;
					int new_y = (mouse.Gety()-80)/80;
					if (mouse.Getx() > 400 and mouse.Getx() < 1040 and mouse.Gety() > 80 and mouse.Gety() < 720) {
							posiciones[0].push_back(make_pair(new_x, new_y));
							topo_place1 = SDL_Rect{posiciones[0][0].first* 80 + 390, posiciones[0][0].second * 80 + 90, 100,50};
							topo_placed = true;
					}
				}
				else { //Generar recorrido
					int new_x = (mouse.Getx()-400)/80;
					int new_y = (mouse.Gety()-80)/80;
					if (abs(new_x - posiciones[0][posiciones[0].size()-1].first)+abs(new_y - posiciones[0][posiciones[0].size()-1].second) == 1) {
						int found = -1;
						for (int i = 0; i < posiciones[0].size() and found == -1; ++i) {
							if (new_x == posiciones[0][i].first and new_y == posiciones[0][i].second) found = i;
						}
						if (found == 0) {
							posiciones[0].push_back(make_pair(new_x,new_y));
							quit = true;
						}
						else if (found == -1) {
							posiciones[0].push_back(make_pair(new_x, new_y));
						}
						
					}

				}
			}
		}
	}

	quit = false;
	topo_placed = false;
	//Place Topo 2
	mouse.GetTopo();
	while (!quit) {
		SDL_SetRenderDrawColor(gRenderer, 28, 27, 26, 0xFF);
		SDL_RenderFillRect(gRenderer, &aux);
		//g.DrawTabla(0, 50);
		
		Graphics::DrawTextureRect(terreno, &aux1, &aux2);
		Graphics::DrawTextureRect(Topo_viu, &topo_place1, &topo_size1);
		mouse.Update();
		
		if (not topo_placed) mouse.Draw(Cyborg_viu, &topo_size2);
		else  Graphics::DrawTextureRect(Cyborg_viu, &topo_place2, &topo_size2);
		for (int i = 0; i < int(posiciones[0].size()) - 1; ++i) {
			Graphics::DrawLine(posiciones[0][i].first*80 + 440, posiciones[0][i].second*80 + 120, posiciones[0][i+1].first*80 + 440, posiciones[0][i+1].second*80 + 120, {255,0,0,255});
		}
		for (int j = 0; j < int(posiciones[1].size()) - 1; ++j) {
			Graphics::DrawLine(posiciones[1][j].first*80 + 440, posiciones[1][j].second*80 + 120, posiciones[1][j+1].first*80 + 440, posiciones[1][j+1].second*80 + 120, {0,0,255,255});
		}
		SDL_RenderPresent(gRenderer);
		while (SDL_PollEvent(&event_handler) != 0)
		{
			if (event_handler.type == SDL_MOUSEBUTTONDOWN) { //Poner topo
				if (not topo_placed) {
					int new_x = (mouse.Getx()-400)/80;
					int new_y = (mouse.Gety()-80)/80;
					if (mouse.Getx() > 400 and mouse.Getx() < 1040 and mouse.Gety() > 80 and mouse.Gety() < 720) {
							posiciones[1].push_back(make_pair(new_x, new_y));
							topo_place2 = SDL_Rect{posiciones[1][0].first* 80 + 390, posiciones[1][0].second * 80 + 90, 100,50};
							topo_placed = true;
					}
				}
				else { //Generar recorrido
					int new_x = (mouse.Getx()-400)/80;
					int new_y = (mouse.Gety()-80)/80;
					if ((abs(new_x - posiciones[1][posiciones[1].size()-1].first) == 2 and new_y == posiciones[1][posiciones[1].size()-1].second ) or (new_x == posiciones[1][posiciones[1].size()-1].first and abs(new_y - posiciones[1][posiciones[1].size()-1].second) == 2)) {
						int found = -1;
						for (int i = 0; i < posiciones[1].size() and found == -1; ++i) {
							if (new_x == posiciones[1][i].first and new_y == posiciones[1][i].second) found = i;
						}
						if (found == 0) {
							posiciones[1].push_back(make_pair(new_x,new_y));
							quit = true;
						}
						else if (found == -1) {
							posiciones[1].push_back(make_pair(new_x, new_y));
						}
						
					}

				}
			}
		}
	}
	quit = false;
	topo_placed = false;
	bool portal_used = false;
	bool portal_usage = false;
	int portal_cord = -1;
	//Place Topo 3
	mouse.GetTopo();
	while (!quit) {
		SDL_SetRenderDrawColor(gRenderer, 28, 27, 26, 0xFF);
		SDL_RenderFillRect(gRenderer, &aux);
		//g.DrawTabla(0, 50);
		Graphics::DrawTextureRect(terreno, &aux1, &aux2);
		Graphics::DrawTextureRect(Topo_viu, &topo_place1, &topo_size1);
		Graphics::DrawTextureRect(Cyborg_viu, &topo_place2, &topo_size2);
		mouse.Update();
		
		if (not topo_placed) mouse.Draw(Mag_viu, &topo_size3);
		else Graphics::DrawTextureRect(Mag_viu, &topo_place3, &topo_size3);
		if (portal_usage) mouse.Draw(Mag_viu, &topo_size3);
		if (portal_used) {
			topo_place3 = SDL_Rect{posiciones[2][portal_cord+1].first* 80 + 390, posiciones[2][portal_cord+1].second * 80 + 90, 100,75};
			Graphics::DrawTextureRect(Mag_viu, &topo_place3, &topo_size3);
		}
		for (int i = 0; i < int(posiciones[0].size()) - 1; ++i) {
			Graphics::DrawLine(posiciones[0][i].first*80 + 440, posiciones[0][i].second*80 + 120, posiciones[0][i+1].first*80 + 440, posiciones[0][i+1].second*80 + 120, {255,0,0,255});
		}
		for (int j = 0; j < int(posiciones[1].size()) - 1; ++j) {
			Graphics::DrawLine(posiciones[1][j].first*80 + 440, posiciones[1][j].second*80 + 120, posiciones[1][j+1].first*80 + 440, posiciones[1][j+1].second*80 + 120, {0,0,255,255});
		}
				for (int j = 0; j < int(posiciones[2].size()) - 1; ++j) {
				if (j != portal_cord) {
			Graphics::DrawLine(posiciones[2][j].first*80 + 440, posiciones[2][j].second*80 + 120, posiciones[2][j+1].first*80 + 440, posiciones[2][j+1].second*80 + 120, {255,255,0,255});
				}
		}
		SDL_RenderPresent(gRenderer);
		while (SDL_PollEvent(&event_handler) != 0)
		{
			if (event_handler.type == SDL_MOUSEBUTTONDOWN) { //Poner topo
				if (not topo_placed) {
					int new_x = (mouse.Getx()-400)/80;
					int new_y = (mouse.Gety()-80)/80;
					if (mouse.Getx() > 400 and mouse.Getx() < 1040 and mouse.Gety() > 80 and mouse.Gety() < 720) {
							posiciones[2].push_back(make_pair(new_x, new_y));
							topo_place3 = SDL_Rect{posiciones[2][0].first* 80 + 390, posiciones[2][0].second * 80 + 90, 100,75};
							topo_placed = true;
					}
				}
				else { //Generar recorrido
					int new_x = (mouse.Getx()-400)/80;
					int new_y = (mouse.Gety()-80)/80;
					if (not portal_used and portal_usage) {
						int found = -1;
						portal_used = true;
						portal_usage = false;
						portal_cord = posiciones[2].size() - 1;
						for (int i = 0; i < posiciones[2].size() and found == -1; ++i) {
							if (new_x == posiciones[2][i].first and new_y == posiciones[2][i].second) found = i;
						}
						if (found == 0) {
							posiciones[2].push_back(make_pair(new_x,new_y));
							quit = true;
						}
						else if (found == -1) {
							posiciones[2].push_back(make_pair(new_x, new_y));
						}
					}
					else if (abs(new_x - posiciones[2][posiciones[2].size()-1].first)+abs(new_y - posiciones[2][posiciones[2].size()-1].second) == 1) {
						int found = -1;
						for (int i = 0; i < posiciones[2].size() and found == -1; ++i) {
							if (new_x == posiciones[2][i].first and new_y == posiciones[2][i].second) found = i;
						}
						if (found == 0) {
							posiciones[2].push_back(make_pair(new_x,new_y));
							quit = true;
						}
						else if (found == -1) {
							posiciones[2].push_back(make_pair(new_x, new_y));
						}
						
					}

				}
			}
			else if (event_handler.type == SDL_KEYDOWN and event_handler.key.keysym.sym == SDLK_SPACE) {
				portal_usage = true;
			}
		}
	}
}
	
void Jardi::Cavar() {

}

void Jardi::Init_Pictures() {
	terreno = Texture("Superior-tile.png");
	tile_tula = Texture("Tula_Tile.png");
	tile_tula_portal = Texture("Tula_Portal_Tile.png");
	tile_straight = Texture("Straight_Tile.png");
	tile_straight_portal = Texture("Straight_Portal_Tile.png");
	tile_void = Texture("Void_Tile.png");
	tile_l = Texture("L_Tile.png");
	tile_l_portal = Texture("L_Portal_Tile.png");
	tile_cross = Texture("Cross_Tile.png");
	tile_cross_portal = Texture("Cross_Portal_Tile.png");
	Cyborg_viu = Texture("Cyborg_Viu.png");
	Cyborg_mort = Texture("Cyborg_Mort.png");
	Mag_viu = Texture("Mag_Viu.png");
	Mag_mort = Texture("Mag_Mort.png");
	Topo_viu = Texture("Default_Viu.png");
	Topo_mort = Texture("Default_Mort.png");

	terreno1 = { 0,0,terreno.GetWidth(), terreno.GetHeight() };
	tile_tula1 = { 0,0,tile_tula.GetWidth(), tile_tula.GetHeight() };
	tile_tula_portal1 = { 0,0,tile_tula_portal.GetWidth(), tile_tula_portal.GetHeight() };
	tile_straight1 = { 0,0,tile_straight.GetWidth(), tile_straight.GetHeight() };
	tile_straight_portal1 = { 0,0,tile_straight_portal.GetWidth(), tile_straight_portal.GetHeight() };
	tile_void1 = { 0,0,tile_void.GetWidth(), tile_void.GetHeight() };
	tile_l1 = { 0,0,tile_l.GetWidth(), tile_l.GetHeight() };
	tile_l_portal1 = { 0,0,tile_l_portal.GetWidth(), tile_l_portal.GetHeight() };
	tile_cross1 = { 0,0,tile_cross.GetWidth(), tile_cross.GetHeight() };
	tile_cross_portal1 = { 0,0,tile_cross_portal.GetWidth(), tile_cross_portal.GetHeight() };
}