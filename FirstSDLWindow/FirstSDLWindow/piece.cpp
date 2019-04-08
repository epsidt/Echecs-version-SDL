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

//  methode get/set des position sur le tableau
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

//  methode get/set des position inital sur le tableau
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

piece::~piece()
{
}

// -----------------LES DEPLACEMENTs !!!----------------------
void piece::dispodeplace(echiquier *Echiquier)
{
	cout << "pdep = " << iydep << endl;
	cout << "couleur = " << couleur << endl;

	if (getid() == 0) // Pion
	{
		dx = 1;
		dy = 1;

		if (couleur == 1) // Deplacement en fonction de la couleur
		{
			if (pdep) // premier deplacement ou non
			{
				iydep = 2; // indice de deplacement en y en fonction de la piece et de la couleur
			}
			else if (!pdep)
			{
				iydep = 1;
			}
			bas(Echiquier);
		}
		if (couleur == 2) // Deplacement en fonction de la couleur
		{
			if (pdep)
			{
				iydep = 2;
			}
			else if (!pdep)
			{
				iydep = 1;
			}
			haut(Echiquier);
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
	//================= VERS LA DROITE =======================
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
		ixdep = 1;
		iydep = 2;

		dx = 1;
		dy = 2;
		basdroite(Echiquier);
		//------ droitebas ------
		ixdep = 2;
		iydep = 1;

		dx = 2;
		dy = 1;
		basdroite(Echiquier);

	//================= VERS LA GAUCHE =======================
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
		basgauche(Echiquier);
		hautgauche(Echiquier);
		basdroite(Echiquier);
	}
	if (getid() == 4) // roi
	{
		dx = 1;
		dy = 1;
		ixdep = 1;
		iydep = 1;

		haut(Echiquier);
		bas(Echiquier);
		gauche(Echiquier);
		droite(Echiquier);
	}
	if (getid() == 5) // reine
	{
		dx = 1;
		dy = 1;
		ixdep = 8;
		iydep = 8;

		haut(Echiquier);
		bas(Echiquier);
		gauche(Echiquier);
		droite(Echiquier);

		hautdroite(Echiquier);
		basgauche(Echiquier);
		hautgauche(Echiquier);
		basdroite(Echiquier);
	}
}

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
			Echiquier->GetCases(xi, yi - dy)->setdisponible(true);
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
			Echiquier->GetCases(xi, yi + dy)->setdisponible(true);
		}
		if (Echiquier->GetCases(xi, yi + dy)->getoccuper() == true)
		{
			dy += 8;
		}
	}
}
void piece::gauche(echiquier *Echiquier)
{
	//------------------------ gauche ----------------------------
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
void piece::droite(echiquier *Echiquier)
{
	//------------------------- droite -----------------------------
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

void piece::hautdroite(echiquier *Echiquier)
{
	//------------------------- hautdroite ------------------------------
	for (dx; dx <= ixdep && dx <= xi; dx++)
	{
		for (dy; dy <= iydep && dy <= yi; dy++)
		{
			if (Echiquier->GetCases(xi - dx, yi - dy)->getoccuper() != true)
			{
				Echiquier->GetCases(xi - dx, yi - dy)->setdisponible(true);
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
		}
	}
}
void piece::basgauche(echiquier *Echiquier)
{
	//------------------------- basgauche -------------------------------
	for (dx; dx <= ixdep && dx <= 7 - xi; dx++)
	{
		for (dy; dy <= iydep && dy <= 7 - yi; dy++)
		{
			if (Echiquier->GetCases(xi + dx, yi + dy)->getoccuper() != true)
			{
				Echiquier->GetCases(xi + dx, yi + dy)->setdisponible(true);
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
		}
	}
}
void piece::hautgauche(echiquier *Echiquier)
{
	//------------------------ hautgauche ----------------------------
	for (dy; dy <= iydep && dy <= yi; dy++)
	{
		for (dx; dx <= ixdep && dx <= 8 - xi; dx++)
		{
			if (Echiquier->GetCases(xi + dx, yi - dy)->getoccuper() != true)
			{
				Echiquier->GetCases(xi + dx, yi - dy)->setdisponible(true);
			}
			else if (Echiquier->GetCases(xi + dx, yi - dy)->getcouleurdeloccupant() != couleur)
			{
				Echiquier->GetCases(xi + dx, yi - dy)->setdisponible(true);
			}
		}
	}
}
void piece::basdroite(echiquier *Echiquier)
{
	//------------------------- basdroite -----------------------------
	for (dy; dy <= iydep && dy <= 8 - yi; dy++)
	{
		for (dx; dx <= ixdep && dx <= 8 - (8 - xi); dx++)
		{
			if (Echiquier->GetCases(xi - dx, yi + dy)->getoccuper() != true)
			{
				Echiquier->GetCases(xi - dx, yi + dy)->setdisponible(true);
			}
			else if (Echiquier->GetCases(xi - dx, yi + dy)->getcouleurdeloccupant() != couleur)
			{
				Echiquier->GetCases(xi - dx, yi + dy)->setdisponible(true);
			}
		}
	}
}

bool piece::deplacement(echiquier *Echiquier)
{
	// si la case ou se trouve le pion est disponible alors ... deplacement accordé
	if (posR.y < 650 && posR.y > 90 &&
		posR.x < 910 && posR.x > 350)
	{
		if (Echiquier->GetCases(x, y)->getdisponible())
		{
			cout << "Dans deplacement " << Echiquier->GetCases(x, y)->getdisponible() << " x/y :";
			cout << x << " " << y << endl;
			return true;
		}
		else
		{
			return false;
		}
	}
	return false;
}