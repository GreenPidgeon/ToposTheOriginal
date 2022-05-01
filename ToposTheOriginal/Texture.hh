#pragma once
//Using SDL and standard IO
#include <SDL.h>
#include <stdio.h>
#include <string>
// Per poder fer imatges sense tot el rato fent arxius BMP com un mono dardero
#include <SDL_image.h>
#include <iostream>

extern SDL_Renderer* gRenderer;

class Texture {

public:
	Texture()
	{}

	Texture(std::string path) 
	{
		SDL_Surface* surface = IMG_Load(path.c_str());
		w = surface->w;
		h = surface->h;
		pTexture = SDL_CreateTextureFromSurface(gRenderer, surface);
	}
	~Texture()
	{

	}
	int GetWidth() const;
	int GetHeight() const;
	SDL_Texture* GetTexture() const;
private:
	int w, h;
	SDL_Texture* pTexture = NULL;
};