#pragma once
#include "GameObject.h"

class Case
{
private:
	int x;
	int y;
	bool disponible = false;

	bool occuper;
	int couleurdeloccupant; // true = blanc / false = noir ;-)

public:

	Case();
	SDL_Rect Rcase;

	int getx();
	int gety();

	bool getoccuper();
	int getcouleurdeloccupant();

	void setoccuper(bool nOccuper);
	void setcouleurdeloccupant(int nCouleurdeloccupant);

	bool getdisponible();
	void setdisponible(bool disponibiliter);

	Case(int posx, int posy, int nx, int ny);
	~Case();
};

