#include "Case.h"

Case::Case()
{
}

Case::Case(int posx, int posy, int nx, int ny)
{
	// taille des cases
	Rcase.h = 70;
	Rcase.w = 70;
	// positions relatives a la fenetre
	Rcase.x = posx;
	Rcase.y = posy;
	// position dans le tableau de l'echiquier (position qui ne change jamais pour une case)
	x = nx;
	y = ny;
}

int Case::getx()
{
	return x;
}
int Case::gety()
{
	return y;
}

bool Case::getoccuper()
{
	return occuper;
}

int Case::getcouleurdeloccupant()
{
	return couleurdeloccupant;
}

void Case::setoccuper(bool nOccuper)
{
	
	occuper = nOccuper;
}

void Case::setcouleurdeloccupant(int nCouleurdeloccupant)
{
	couleurdeloccupant = nCouleurdeloccupant;
}

bool Case::getcontroler()
{
	return controler;
}

void Case::setcontroler(bool ncontroler)
{
	controler = ncontroler;
}

bool Case::getdisponible()
{
	return disponible;
}

void Case::setdisponible(bool disponibiliter)
{
	disponible = disponibiliter;
}

bool Case::getPriseEnPassant()
{
	return PriseEnPassant;
}

void Case::setPriseEnPassant(bool nPriseEnPassant)
{
	PriseEnPassant = nPriseEnPassant;
}

bool Case::getechecRoi()
{
	return echecRoi;
}

void Case::setechecRoi(bool nechecRoi)
{
	echecRoi = nechecRoi;
}

bool Case::getsauverRoi()
{
	return sauverRoi;
}

void Case::setsauverRoi(bool nsauverRoi)
{
	sauverRoi = nsauverRoi;
}

int Case::getidpiece()
{
	return idpiece;
}

void Case::setidpiece(int nidpiece)
{
	idpiece = nidpiece;
}



Case::~Case()
{
}
