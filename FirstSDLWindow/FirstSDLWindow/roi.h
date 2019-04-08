#pragma once
#include "piece.h"
class roi :
	public piece
{
public:
	roi();

	roi(int Id, bool manger, bool Pdep, int Couleur, SDL_Rect nouvRect, int nx, int ny, const char * texturesheet, SDL_Renderer* ren);

	~roi();
};

