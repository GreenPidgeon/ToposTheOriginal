#include "Texture.hh"

int Texture::GetWidth() const
{
    return w;
}

int Texture::GetHeight() const
{
    return h;
}

SDL_Texture* Texture::GetTexture() const
{
    return pTexture;
}
