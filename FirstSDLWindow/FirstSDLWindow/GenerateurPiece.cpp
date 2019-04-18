#include "GenerateurPiece.h"

#include "pion.h"
#include "tour.h"
#include "cavalier.h"
#include "fou.h"
#include "roi.h"
#include "reine.h"


GenerateurPiece::GenerateurPiece()
{
}

piece* GenerateurPiece::generer(int Id, bool manger, bool Pdep, int Couleur, SDL_Rect nouvRect, int nx, int ny, const char * texturesheet, SDL_Renderer* ren)
{
	switch (Id)
	{
	case 0: // pion
		return new pion(Id, manger, Pdep, Couleur, nouvRect, nx, ny, texturesheet, ren);
		break;

	case 1: // tour
		return new tour(Id, manger, Pdep, Couleur, nouvRect, nx, ny, texturesheet, ren);
		break;

	case 2: // cavalier
		return new cavalier(Id, manger, Pdep, Couleur, nouvRect, nx, ny, texturesheet, ren);
		break;

	case 3:  // fou
		return new fou(Id, manger, Pdep, Couleur, nouvRect, nx, ny, texturesheet, ren);
		break;

	case 4: // roi
		return new roi(Id, manger, Pdep, Couleur, nouvRect, nx, ny, texturesheet, ren);
		break;

	case 5: // reine
		return new reine(Id, manger, Pdep, Couleur, nouvRect, nx, ny, texturesheet, ren);
		break;
	}
	return NULL;
}


GenerateurPiece::~GenerateurPiece()
{
}
