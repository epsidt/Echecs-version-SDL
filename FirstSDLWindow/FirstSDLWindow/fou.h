#pragma once
#include "piece.h"
class fou :
	public piece
{
public:
	fou();

	fou(int Id, bool manger, bool Pdep, int Couleur, SDL_Rect nouvRect, int nx, int ny, const char * texturesheet, SDL_Renderer* ren);
	
	~fou();
};

