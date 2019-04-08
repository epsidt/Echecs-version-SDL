#include "tour.h"



tour::tour()
{
}

tour::tour(int Id, bool manger, bool Pdep,int Couleur, SDL_Rect nouvRect, int nx, int ny, const char * texturesheet, SDL_Renderer * ren) : piece(Id, manger, Pdep, Couleur, nouvRect, nx, ny, texturesheet, ren)
{
}

tour::~tour()
{
}
