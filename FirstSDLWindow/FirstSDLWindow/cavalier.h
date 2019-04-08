#pragma once
#include "piece.h"
class cavalier :
	public piece
{
public:
	cavalier();

	cavalier(int Id, bool manger, bool Pdep, int Couleur, SDL_Rect nouvRect, int nx, int ny, const char * texturesheet, SDL_Renderer* ren);

	~cavalier();
};

