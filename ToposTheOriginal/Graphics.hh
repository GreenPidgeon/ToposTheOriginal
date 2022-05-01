#pragma once
//Using SDL and standard IO
#include <iostream>
#include <vector>
#include <SDL.h>
#undef main
#include <stdio.h>
#include "Cuadrao.hh"
using namespace std;

// Per poder fer imatges sense tot el rato fent arxius BMP com un mono dardero
#include <SDL_image.h>
#include "Texture.hh"
class Graphics {
public:
    Graphics();

    static void DrawSquare(int x, int y, int size, SDL_Color color);

    void DrawTabla(int x, int y);
    
    //Pre: el cuadrado "actual" (posición (x,y)) y el cuadrado "anterior" (posición (lx, ly)) no son el mismo
    static void DrawLine(int x, int y, int lx, int ly, SDL_Color color);

    static void DrawTextureRect(const Texture& texture, const SDL_Rect* destclip, const SDL_Rect* srcclip);

    //pair<Cuadrao, bool> get(int i, int j);

    bool Addline(int x, int y);

private:
    //vector<vector<pair<Cuadrao, bool>>> taula;

};