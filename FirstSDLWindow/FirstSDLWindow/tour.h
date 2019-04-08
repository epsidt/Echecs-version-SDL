#pragma once
#include "piece.h"

class tour :public piece
{
public:

	tour();

	tour(int Id, bool manger, bool Pdep, int Couleur, SDL_Rect nouvRect, int nx, int ny, const char * texturesheet, SDL_Renderer* ren);

	~tour();
};

