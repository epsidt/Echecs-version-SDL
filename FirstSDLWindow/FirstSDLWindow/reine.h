#pragma once
#include "piece.h"
class reine :
	public piece
{
public:
	reine();

	reine(int Id, bool manger, bool Pdep, int Couleur, SDL_Rect nouvRect, int nx, int ny, const char * texturesheet, SDL_Renderer* ren);

	~reine();
};

