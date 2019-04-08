#include "pion.h"
#include "echiquier.h"

pion::pion()
{
}

pion::pion(int Id,bool manger,bool Pdep,int Couleur, SDL_Rect nouvRect,int nx, int ny, const char * texturesheet, SDL_Renderer* ren): piece(Id,manger,Pdep,Couleur,nouvRect,nx,ny,texturesheet,ren)
{
}

pion::~pion()
{
}
