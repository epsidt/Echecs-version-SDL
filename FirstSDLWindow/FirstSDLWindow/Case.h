#pragma once
#include "GameObject.h"

class Case
{
private:
	int x;
	int y;

	bool disponible = false;

	bool PriseEnPassant = false;

	bool occuper = false;
	int couleurdeloccupant = 0; // 0 = rien | 1 = blanc | 2 = noir
	int idpiece;//type de piece

	bool echecRoi = false;
	bool sauverRoi = false;

	bool controler = false;

public:

	Case();
	SDL_Rect Rcase;

	int getx();
	int gety();

	bool getoccuper();
	void setoccuper(bool nOccuper);

	int getcouleurdeloccupant();
	void setcouleurdeloccupant(int nCouleurdeloccupant);

	bool getcontroler();
	void setcontroler(bool ncontroler);

	bool getdisponible();
	void setdisponible(bool disponibiliter);

	bool getPriseEnPassant();
	void setPriseEnPassant(bool nPriseEnPassant);

	bool getechecRoi();
	void setechecRoi(bool nechecRoi);

	bool getsauverRoi();
	void setsauverRoi(bool nsauverRoi);

	int getidpiece();
	void setidpiece(int nidpiece);
	Case(int posx, int posy, int nx, int ny);
	~Case();
};

