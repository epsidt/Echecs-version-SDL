#pragma once
#include "GameObject.h"
#include "Case.h"
#include <vector>

class echiquier : public GameObject
{
private:
	Case* Tableau[8][8];
public:
	echiquier();
	
	echiquier(const char * texturesheet, SDL_Renderer * ren);
	Case* GetCases(int x, int y);
	void ajouterCases(int posx,int posy,int nx, int ny );
	~echiquier();
};

