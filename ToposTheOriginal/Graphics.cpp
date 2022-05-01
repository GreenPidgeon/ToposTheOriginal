#include "Graphics.hh"
#include <iostream>
extern SDL_Renderer* gRenderer;

Graphics::Graphics() {}

void Graphics::DrawSquare(int x, int y, int size, SDL_Color color) {
    SDL_SetRenderDrawColor(gRenderer, color.r, color.g, color.b, 0xFF);
    SDL_Rect aux{ x, y, size, size };
    SDL_RenderFillRect(gRenderer, &aux);
}

void Graphics::DrawTabla(int x, int y) {
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            Graphics::DrawSquare(x + 40 * i, y + 40 * j, 40, {43, 30, 12 ,255});
            Graphics::DrawSquare(x + 40 * i + 5, y + 40 * j + 5, 30, {189, 132, 53,255});
        }
    }
}

void Graphics::DrawLine(int x, int y, int lx, int ly, SDL_Color color) {
    SDL_SetRenderDrawColor(gRenderer, color.r, color.g, color.b, 0xFF);
    int dx, dy;
    dx = lx - x;
    dy = ly - y;
    if (dx == 0) dx = 10;
    else if (dy == 0) dy = 10;
    int varx = 0, vary = 0;
    if (x < lx) varx = 10;
    if (y < ly) vary = 10;
    SDL_Rect aux{x - 5, y - 5, dx + varx, dy + vary};
    SDL_RenderFillRect(gRenderer, &aux);
}

void Graphics::DrawTextureRect(const Texture& texture, const SDL_Rect* destclip, const SDL_Rect* srcclip)
{
	SDL_RenderCopy(gRenderer, texture.GetTexture(), srcclip, destclip);
}

//pair<Cuadrao, bool> Graphics::get(int i, int j) { return taula[i][j]; }

bool Graphics::Addline(int x, int y) {
    /*if (abs(topos[topos.size() - 1]->getix() - x) + abs(topos[topos.size() - 1]->getiy() - y) <= 1) {
        Graphics::DrawLine(topos[topos.size() - 1]->x, topos[topos.size() - 1]->y, x * 40 + 5, y * 40 + 50, { 255,0,0,255 });
        return true;
    }
    */
    return false;
}