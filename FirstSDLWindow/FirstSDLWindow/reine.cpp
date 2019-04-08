#include "reine.h"



reine::reine()
{
}

reine::reine(int Id, bool manger, bool Pdep, int Couleur, SDL_Rect nouvRect, int nx, int ny, const char * texturesheet, SDL_Renderer * ren) : piece(Id, manger, Pdep, Couleur, nouvRect, nx, ny, texturesheet, ren)
{
}


reine::~reine()
{
}
