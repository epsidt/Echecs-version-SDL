#pragma once
#include "piece.h"

class GenerateurPiece
{
public:
	GenerateurPiece();

	static piece* generer(int Id, bool manger, bool Pdep, int Couleur, SDL_Rect nouvRect, int nx, int ny, const char * texturesheet, SDL_Renderer* ren);
	
	~GenerateurPiece();
};

