#pragma once
#include <iostream>
#include <string>
#include <exception>
#include <utility>
//Using SDL and standard IO
#include <SDL.h>
#include <stdio.h>

// Per poder fer imatges sense tot el rato fent arxius BMP com un mono dardero
#include <SDL_image.h>

// includes 
#include "Jardi.hh"
#include "Mouse.hh"

//Starts up SDL and creates window
bool init();

//Frees media and shuts down SDL
void close();

//The window we'll be rendering to
SDL_Window* gWindow = NULL;
//The surface contained by the window
SDL_Surface* gScreenSurface = NULL;
SDL_Renderer* gRenderer = NULL;

Jardi jug1_joc(10, 50), jug2_joc(10, 50);
Jardi jug1_mapa, jug2_mapa;

bool init()
{
	//Initialization flag
	bool success = true;

	//Initialize SDL
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
		success = false;
	}
	else
	{
		//Create window
		gWindow = SDL_CreateWindow("Topos", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 1400, 770, SDL_WINDOW_SHOWN);
		if (gWindow == NULL)
		{
			printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
			success = false;
		}
		else
		{
			//Get window surface
			gScreenSurface = SDL_GetWindowSurface(gWindow);
		}
		// Create renderer(sense error checking, em fa pal)
		gRenderer = SDL_CreateRenderer(gWindow, -1, SDL_RENDERER_ACCELERATED);

		// Init SDL_Image(amb error checking, que peti si fa falta)
		if (IMG_Init(IMG_INIT_PNG) == 0) throw std::exception("buaa");
	}
	return success;
}

void close()
{

	SDL_DestroyWindow(gWindow);
	gWindow = NULL;

	SDL_DestroyRenderer(gRenderer);
	gRenderer = NULL;

	IMG_Quit();
	SDL_Quit();
}

//Jardi jug1_joc(10, 50), jug2_joc;
//Jardi jug1_mapa, jug2_mapa;
int main () {
	//Start up SDL and create window
	if (!init()){
		printf("Failed to initialize!\n");
	}
	else{

		SDL_Event event_handler;
		Jardi::Init_Pictures();
		//Pantalla con el mensaje: Inicializar Jugador 1 (presionar key)
		jug1_joc.PlaceTopos(event_handler);
		jug1_mapa = jug1_joc;
		//Pantalla con el mensaje: Inicializar Jugador 2 (presionar key)
		jug2_joc.PlaceTopos(event_handler);
		jug2_mapa = jug2_joc;

		//Pantalla con el mensaje: comienza el juego (presionar key)
		//JUEGO

		bool quit = false;
		bool torn_jug1 = true;
			//Pantalla 1
		//SDL_Event event_handler;
		/*Texture a("Tula_Tile.png");
		SDL_SetRenderDrawColor(gRenderer, 28, 27, 26, 0xFF);
		SDL_Rect aux{0, 0, 700, 770};
		SDL_RenderFillRect(gRenderer, &aux);
		Mouse mouse;
		mouse.Update();
		SDL_RenderPresent(gRenderer);
		// Events/Inputs in a frame
		SDL_Rect aux1{ 400,80,640,640 };
		Texture
		SDL_Rect aux2{ 0,0,terreno.GetWidth(),terreno.GetHeight() };
		SDL_Rect topo_size{ 0,0,Topo_viu.GetWidth(), Topo_viu.GetHeight() };
		SDL_Rect topo_place1, topo_place2, topo_place3;*/
			//Pantalla 2
		
		//Iteraciones con el mensaje: Turno Jugador 1 (o 2) alternadamente (presionar key)
		//Pantalla con el mensaje: ha ganado el jugador x (presionar key)
	}

	//Free resources and close SDL
	close();

	return 0;
}