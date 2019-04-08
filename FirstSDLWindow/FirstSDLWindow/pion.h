#pragma once
#include "piece.h"

class pion: public piece
{
public:
	pion();

	pion(int Id, bool manger, bool Pdep, int Couleur, SDL_Rect nouvRect,int nx, int ny, const char * texturesheet, SDL_Renderer* ren);

	~pion();
};

