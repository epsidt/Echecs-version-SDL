#include "piece.h"
#include "GameObject.h"
#include "TextureManager.h"

piece::piece()
{
}

piece::piece(int Id, bool manger, bool Pdep, int Couleur, SDL_Rect nouvRect, int nx, int ny, const char * texturesheet, SDL_Renderer* ren) : GameObject(texturesheet, ren)
{
	id = Id;
	couleur = Couleur;

	Position(nouvRect.x,nouvRect.y);
	Taille(40, 70);

	rI = &nouvRect;

	x = nx;
	y = ny;

	xi = nx;
	yi = ny;

	clicker = false;

	pdep = Pdep;
	
}

void piece::setclicker(bool S)
{
	clicker = S;
}

bool piece::getClicker()
{
	return clicker;
}

void piece::setrposI(SDL_Rect *nouvRect)
{
	rI->x = nouvRect->x;
	rI->y = nouvRect->y;
}

void piece::setposI()
{
	xi = x;
	yi = y;
}

void piece::setpos()
{
	x = xi;
	y = yi;
}

SDL_Rect* piece::getrI()
{
	return rI;
}

int piece::getid()
{
	return id;
}

void piece::setid(int nid)
{
	id = nid;
}

int piece::getcouleur()
{
	return couleur;
}

void piece::setmanger(bool nManger)
{
	manger = nManger;
}

bool piece::getmanger()
{
	return manger;
}

//-- methode get/set des position sur le tableau --
int piece::getx()
{
	return x;
}
int piece::gety()
{
	return y;
}
void piece::setx(int nx)
{
	x = nx;
}
void piece::sety(int ny)
{
	y = ny;
}
//-------------------------------------------------

//-- methode get/set des position inital sur le tableau --
int piece::getxi()
{
	return xi;
}
int piece::getyi()
{
	return yi;
}
void piece::setxi(int nxi)
{
	xi = nxi;
}
void piece::setyi(int nyi)
{
	yi = nyi;
}
//---------------------------------------------------------

void piece::setdepIncorrect(bool i)
{
	depIncorrect = i;
}

bool piece::getdepIncorrect()
{
	return depIncorrect;
}

void piece::setpdep(bool i)
{
	pdep = i;
}

bool piece::getpdep()
{
	return pdep;
}

// =====================LES DEPLACEMENTs !!!==========================
// ------------ Parametre des deplacement ---------------
void piece::dispodeplace(echiquier *Echiquier)
{
	if (getid() == 0) // Pion
	{
		dx = 1;
		dy = 1;
		ixdep = 1;

		if (couleur == 1) // Deplacement en fonction de la couleur
		{
			if (pdep == 1) // premier deplacement ou non
			{
				iydep = 2; // indice de deplacement en y en fonction de la piece et de la couleur

				bas(Echiquier);

				dx = 1;
				dy = 1;
				basgauche(Echiquier);

				dx = 1;
				dy = 1;
				basdroite(Echiquier);
			}
			else if (pdep == 0)
			{
				iydep = 1;

				bas(Echiquier);

				dx = 1;
				dy = 1;
				basgauche(Echiquier);

				dx = 1;
				dy = 1;
				basdroite(Echiquier);
			}
		}
		if (couleur == 2) // Deplacement en fonction de la couleur
		{
			if (pdep == 1)
			{
				iydep = 2;

				haut(Echiquier);

				dx = 1;
				dy = 1;
				hautgauche(Echiquier);

				dx = 1;
				dy = 1;
				hautdroite(Echiquier);
			}
			else if (pdep == 0)
			{
				iydep = 1;

				haut(Echiquier);

				dx = 1;
				dy = 1;
				hautgauche(Echiquier);

				dx = 1;
				dy = 1;
				hautdroite(Echiquier);
			}
		}
	}
	if (getid() == 1) // tour
	{
		dx = 1;
		dy = 1;
		ixdep = 8;
		iydep = 8;
		haut(Echiquier);
		dx = 1;
		dy = 1;
		ixdep = 8;
		iydep = 8;
		bas(Echiquier);
		dx = 1;
		dy = 1;
		ixdep = 8;
		iydep = 8;
		gauche(Echiquier);
		dx = 1;
		dy = 1;
		ixdep = 8;
		iydep = 8;
		droite(Echiquier);
	}
	if (getid() == 2)// cavalier
	{
	//========= VERS LA DROITE ===========
		//------ hautdroite ------
		ixdep = 1;
		iydep = 2;
		
		dx = 1;
		dy = 2;
		hautdroite(Echiquier);
		//------ droitehaut ------
		ixdep = 2;
		iydep = 1;

		dx = 2;
		dy = 1;
		hautdroite(Echiquier);
		//------ basdroite ------
		ixdep = 2;
		iydep = 1;

		dx = 2;
		dy = 1;
		basdroite(Echiquier);
		//------ droitebas ------
		ixdep = 1;
		iydep = 2;

		dx = 1;
		dy = 2;
		basdroite(Echiquier);

	//========== VERS LA GAUCHE ===========
		//------ hautgauche ------
		ixdep = 1;

		iydep = 2;

		dx = 1;
		dy = 2;
		hautgauche(Echiquier);
		//------ gauchehaut ------
		ixdep = 2;
		iydep = 1;

		dx = 2;
		dy = 1;
		hautgauche(Echiquier);
		//------ basgauche ------
		ixdep = 1;
		iydep = 2;

		dx = 1;
		dy = 2;
		basgauche(Echiquier);
		//------ gauchebas ------
		ixdep = 2;
		iydep = 1;

		dx = 2;
		dy = 1;
		basgauche(Echiquier);
	}
	if (getid() == 3) // fou
	{
		dx = 1;
		dy = 1;
		ixdep = 8;
		iydep = 8;
		hautdroite(Echiquier);

		dx = 1;
		dy = 1;
		ixdep = 8;
		iydep = 8;
		basgauche(Echiquier);

		dx = 1;
		dy = 1;
		ixdep = 8;
		iydep = 8;
		hautgauche(Echiquier);

		dx = 1;
		dy = 1;
		ixdep = 8;
		iydep = 8;
		basdroite(Echiquier);
	}
	if (getid() == 4) // roi
	{
		dx = 1;
		dy = 1;
		ixdep = 1;
		iydep = 1;

		haut(Echiquier);

		dx = 1;
		dy = 1;
		ixdep = 1;
		iydep = 1;
		bas(Echiquier);

		dx = 1;
		dy = 1;
		ixdep = 1;
		iydep = 1;
		gauche(Echiquier);

		dx = 1;
		dy = 1;
		ixdep = 1;
		iydep = 1;
		droite(Echiquier);

		dx = 1;
		dy = 1;
		ixdep = 1;
		iydep = 1;
		hautdroite(Echiquier);

		dx = 1;
		dy = 1;
		ixdep = 1;
		iydep = 1;
		basgauche(Echiquier);

		dx = 1;
		dy = 1;
		ixdep = 1;
		iydep = 1;
		hautgauche(Echiquier);

		dx = 1;
		dy = 1;
		ixdep = 1;
		iydep = 1;
		basdroite(Echiquier);

	}
	if (getid() == 5) // reine
	{
		dx = 1;
		dy = 1;
		ixdep = 8;
		iydep = 8;

		haut(Echiquier);

		dx = 1;
		dy = 1;
		ixdep = 8;
		iydep = 8;
		bas(Echiquier);

		dx = 1;
		dy = 1;
		ixdep = 8;
		iydep = 8;
		gauche(Echiquier);

		dx = 1;
		dy = 1;
		ixdep = 8;
		iydep = 8;
		droite(Echiquier);

		dx = 1;
		dy = 1;
		ixdep = 8;
		iydep = 8;
		hautdroite(Echiquier);

		dx = 1;
		dy = 1;
		ixdep = 8;
		iydep = 8;
		basgauche(Echiquier);

		dx = 1;
		dy = 1;
		ixdep = 8;
		iydep = 8;
		hautgauche(Echiquier);

		dx = 1;
		dy = 1;
		ixdep = 8;
		iydep = 8;
		basdroite(Echiquier);
	}
}
// ------------------------------------------------------

// ------------ Joystick cardinal -----------------
void piece::haut(echiquier *Echiquier)
{
	//------------------------- haut ------------------------------
	for (dy; dy <= iydep && dy <= yi; dy++)
	{
		if (Echiquier->GetCases(xi, yi - dy)->getoccuper() != true)
		{
			Echiquier->GetCases(xi, yi - dy)->setdisponible(true);
		}
		else if (Echiquier->GetCases(xi, yi - dy)->getcouleurdeloccupant() != couleur)
		{
			if (getid() != 0)
			{
				Echiquier->GetCases(xi, yi - dy)->setdisponible(true);
			}
		}
		if (Echiquier->GetCases(xi, yi - dy)->getoccuper() == true)
		{
			dy += 8;
		}
	}
}
void piece::bas(echiquier *Echiquier)
{
	//------------------------- bas -------------------------------
	for (dy; dy <= iydep && dy <= 7 - yi; dy++)
	{
		if (Echiquier->GetCases(xi, yi + dy)->getoccuper() != true)
		{
			Echiquier->GetCases(xi, yi + dy)->setdisponible(true);
			
		}
		else if (Echiquier->GetCases(xi, yi + dy)->getcouleurdeloccupant() != couleur)
		{
			if (getid() != 0)
			{
				Echiquier->GetCases(xi, yi + dy)->setdisponible(true);
			}
			
		}
		if (Echiquier->GetCases(xi, yi + dy)->getoccuper() == true)
		{
			dy += 8;
		}
	}
}
void piece::gauche(echiquier *Echiquier)
{
	//------------------------- gauche -----------------------------
	for (dx; dx <= ixdep && dx <= xi; dx++)
	{
		if (Echiquier->GetCases(xi - dx, yi)->getoccuper() != true)
		{
			Echiquier->GetCases(xi - dx, yi)->setdisponible(true);
		}
		else if (Echiquier->GetCases(xi - dx, yi)->getcouleurdeloccupant() != couleur)
		{
			Echiquier->GetCases(xi - dx, yi)->setdisponible(true);
		}
		if (Echiquier->GetCases(xi - dx, yi)->getoccuper() == true)
		{
			dx += 8;
		}
	}
}
void piece::droite(echiquier *Echiquier)
{
	
	//------------------------ droite ----------------------------
	for (dx; dx <= ixdep && dx <= 7 - xi; dx++)
	{
		if (Echiquier->GetCases(xi + dx, yi)->getoccuper() != true)
		{
			Echiquier->GetCases(xi + dx, yi)->setdisponible(true);
		}
		else if (Echiquier->GetCases(xi + dx, yi)->getcouleurdeloccupant() != couleur)
		{
			Echiquier->GetCases(xi + dx, yi)->setdisponible(true);
		}
		if (Echiquier->GetCases(xi + dx, yi)->getoccuper() == true)
		{
			dx += 8;
		}
	}
}

void piece::hautdroite(echiquier *Echiquier)
{
	//------------------------- hautdroite ------------------------------
	for (dx; dx <= ixdep && dx <= 7 - xi; dx++)
	{
		if (dy <= iydep && dy <= yi)
		{
			if (!Echiquier->GetCases(xi + dx, yi - dy)->getoccuper()) // si la case n'est pas occuper
			{
				if (getid() == 0)
				{
					if (Echiquier->GetCases(xi + dx, yi - dy)->getcouleurdeloccupant() != couleur && Echiquier->GetCases(xi + dx, yi - dy)->getcouleurdeloccupant() != 0) // si la couleur de l'occupant n'est pas la même que celle de la piece
					{
						Echiquier->GetCases(xi + dx, yi - dy)->setdisponible(true);
					}
				}
				else
				{
					Echiquier->GetCases(xi + dx, yi - dy)->setdisponible(true);
				}
			}
			else if (Echiquier->GetCases(xi + dx, yi - dy)->getcouleurdeloccupant() != couleur) // si la couleur de l'occupant n'est pas la même que celle de la piece
			{
				Echiquier->GetCases(xi + dx, yi - dy)->setdisponible(true);
			}
			if (Echiquier->GetCases(xi + dx, yi - dy)->getoccuper() == true)
			{
				dx += 8;
				dy += 8;
			}
			dy++;
		}
	}
}
void piece::basgauche(echiquier *Echiquier)
{
	//------------------------- basgauche -------------------------------
	for (dx; dx <= ixdep && dx <= xi; dx++)
	{
		if (dy <= iydep && dy <= 7 - yi)
		{
			if (Echiquier->GetCases(xi - dx, yi + dy)->getoccuper() != true)
			{
				if (getid()	== 0)
				{
					if (Echiquier->GetCases(xi - dx, yi + dy)->getcouleurdeloccupant() != couleur && Echiquier->GetCases(xi - dx, yi + dy)->getcouleurdeloccupant() != 0 )
					{
						Echiquier->GetCases(xi - dx, yi + dy)->setdisponible(true);
					}
					
				}
				else
				{
					Echiquier->GetCases(xi - dx, yi + dy)->setdisponible(true);
				}
			}
			else if (Echiquier->GetCases(xi - dx, yi + dy)->getcouleurdeloccupant() != couleur)
			{
				Echiquier->GetCases(xi - dx, yi + dy)->setdisponible(true);
			}
			if (Echiquier->GetCases(xi - dx, yi + dy)->getoccuper() == true)
			{
				dx += 8;
				dy += 8;
			}
			dy++;
		}
	}
}
void piece::hautgauche(echiquier *Echiquier)
{
	//------------------------ hautgauche ----------------------------
	for (dx; dx <= ixdep && dx <= xi; dx++)
	{
		if (dy <= iydep && dy <= yi)
		{
			if (Echiquier->GetCases(xi - dx, yi - dy)->getoccuper() != true)
			{
				if (getid() == 0)
				{
					if (Echiquier->GetCases(xi - dx, yi - dy)->getcouleurdeloccupant() != couleur && Echiquier->GetCases(xi - dx, yi - dy)->getcouleurdeloccupant() != 0)
					{
						Echiquier->GetCases(xi - dx, yi - dy)->setdisponible(true);
					}
				}
				else
				{
					Echiquier->GetCases(xi - dx, yi - dy)->setdisponible(true);
				}
			}
			else if (Echiquier->GetCases(xi - dx, yi - dy)->getcouleurdeloccupant() != couleur)
			{
				Echiquier->GetCases(xi - dx, yi - dy)->setdisponible(true);
			}
			if (Echiquier->GetCases(xi - dx, yi - dy)->getoccuper() == true)
			{
				dx += 8;
				dy += 8;
			}
			dy++;
		}
	}
}
void piece::basdroite(echiquier *Echiquier)
{
	//------------------------- basdroite -----------------------------
	for (dx; dx <= ixdep && dx <= 7 - xi; dx++)
	{
		if (dy <= iydep && dy <= 7 - yi)
		{
			if (Echiquier->GetCases(xi + dx, yi + dy)->getoccuper() != true)
			{
				if (getid() == 0)
				{
					if (Echiquier->GetCases(xi + dx, yi + dy)->getcouleurdeloccupant() != couleur && Echiquier->GetCases(xi + dx, yi + dy)->getcouleurdeloccupant() != 0)
					{
						Echiquier->GetCases(xi + dx, yi + dy)->setdisponible(true);
					}
				}
				else
				{
					Echiquier->GetCases(xi + dx, yi + dy)->setdisponible(true);
				}
			}
			else if (Echiquier->GetCases(xi + dx, yi + dy)->getcouleurdeloccupant() != couleur)
			{
				Echiquier->GetCases(xi + dx, yi + dy)->setdisponible(true);
			}
			if (Echiquier->GetCases(xi + dx, yi + dy)->getoccuper() == true)
			{
				dx += 8;
				dy += 8;
			}
			dy++;
		}
	}
}
//-------------------------------------------------

//------------ deplacement autorisée ------------------
bool piece::deplacement(echiquier *Echiquier)
{
	// si la case ou se trouve le pion est disponible alors ... deplacement accordé
	if (posR.y < 650 && posR.y > 90 &&
		posR.x < 670 && posR.x > 70)
	{
		if (Echiquier->GetCases(x, y)->getdisponible())
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	return false;
}
//-----------------------------------------------------

//---------- prise en passant ------------
void piece::setposPPy(bool null)
{
	if (!null)
	{
		if (couleur == 1) // si couleur = blanche
		{
			posPPy = y - 1;
		}
		if (couleur == 2) // si couluer = noire
		{
			posPPy = y + 1;
		}
	}
	else
	{
		posPPy = NULL;
	}
}
int piece::getposPPy()
{
	return posPPy;
}

void piece::setposPPx(bool null)
{
	if (!null)
	{
		posPPx = x;
		posPPx = x;
	}
	else
	{
		posPPx = NULL;
	}
}

int piece::getposPPx()
{
	return posPPx;
}
//---------------------------------------
//==================================================================

piece::~piece()
{
}