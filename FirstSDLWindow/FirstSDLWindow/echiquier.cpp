#include "echiquier.h"

echiquier::echiquier()
{
}

echiquier::echiquier(const char * texturesheet, SDL_Renderer * ren) : GameObject(texturesheet, ren)
{
	
}

Case* echiquier::GetCases(int x,int y)
{
	return Tableau[x][y];
}

void echiquier::ajouterCases(int posx, int posy,int nx, int ny)
{
	Tableau[nx][ny] = new Case(posx,posy,nx,ny);
}


echiquier::~echiquier()
{
}