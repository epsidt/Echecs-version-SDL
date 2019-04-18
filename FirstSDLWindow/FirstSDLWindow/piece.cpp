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
void piece::AutorisationDeplacement(echiquier *Echiquier, bool controle, bool ic)
{
	if (getid() == 0) // Pion
	{
		dx = 1;
		dy = 1;
		ixdep = 1;

		if (couleur == 2) // Deplacement en fonction de la couleur
		{
			if (pdep == 1) // premier deplacement ou non
			{
				iydep = 2; // indice de deplacement en y en fonction de la piece et de la couleur

				bas(Echiquier, controle, ic);

				dx = 1;
				dy = 1;
				basgauche(Echiquier, controle, ic);

				dx = 1;
				dy = 1;
				basdroite(Echiquier, controle, ic);
			}
			else if (pdep == 0)
			{
				iydep = 1;

				bas(Echiquier, controle, ic);

				dx = 1;
				dy = 1;
				basgauche(Echiquier, controle, ic);

				dx = 1;
				dy = 1;
				basdroite(Echiquier, controle, ic);
			}
		}
		if (couleur == 1) // Deplacement en fonction de la couleur
		{
			if (pdep == 1)
			{
				iydep = 2;

				haut(Echiquier, controle, ic);

				dx = 1;
				dy = 1;
				hautgauche(Echiquier, controle, ic);

				dx = 1;
				dy = 1;
				hautdroite(Echiquier, controle, ic);
			}
			else if (pdep == 0)
			{
				iydep = 1;

				haut(Echiquier, controle, ic);

				dx = 1;
				dy = 1;
				hautgauche(Echiquier, controle, ic);

				dx = 1;
				dy = 1;
				hautdroite(Echiquier, controle, ic);
			}
		}
	}
	if (getid() == 1) // tour
	{
		dx = 1;
		dy = 1;
		ixdep = 8;
		iydep = 8;
		haut(Echiquier, controle, ic);
		dx = 1;
		dy = 1;
		ixdep = 8;
		iydep = 8;
		bas(Echiquier, controle, ic);
		dx = 1;
		dy = 1;
		ixdep = 8;
		iydep = 8;
		gauche(Echiquier, controle, ic);
		dx = 1;
		dy = 1;
		ixdep = 8;
		iydep = 8;
		droite(Echiquier, controle, ic);
	}
	if (getid() == 2)// cavalier
	{
	//========= VERS LA DROITE ===========
		//------ hautdroite ------
		ixdep = 1;
		iydep = 2;
		
		dx = 1;
		dy = 2;
		hautdroite(Echiquier, controle, ic);
		//------ droitehaut ------
		ixdep = 2;
		iydep = 1;

		dx = 2;
		dy = 1;
		hautdroite(Echiquier, controle, ic);
		//------ basdroite ------
		ixdep = 2;
		iydep = 1;

		dx = 2;
		dy = 1;
		basdroite(Echiquier, controle, ic);
		//------ droitebas ------
		ixdep = 1;
		iydep = 2;

		dx = 1;
		dy = 2;
		basdroite(Echiquier, controle, ic);

	//========== VERS LA GAUCHE ===========
		//------ hautgauche ------
		ixdep = 1;

		iydep = 2;

		dx = 1;
		dy = 2;
		hautgauche(Echiquier, controle, ic);
		//------ gauchehaut ------
		ixdep = 2;
		iydep = 1;

		dx = 2;
		dy = 1;
		hautgauche(Echiquier, controle, ic);
		//------ basgauche ------
		ixdep = 1;
		iydep = 2;

		dx = 1;
		dy = 2;
		basgauche(Echiquier, controle, ic);
		//------ gauchebas ------
		ixdep = 2;
		iydep = 1;

		dx = 2;
		dy = 1;
		basgauche(Echiquier, controle, ic);
	}
	if (getid() == 3) // fou
	{
		dx = 1;
		dy = 1;
		ixdep = 8;
		iydep = 8;
		hautdroite(Echiquier, controle, ic);

		dx = 1;
		dy = 1;
		ixdep = 8;
		iydep = 8;
		basgauche(Echiquier, controle, ic);

		dx = 1;
		dy = 1;
		ixdep = 8;
		iydep = 8;
		hautgauche(Echiquier, controle, ic);

		dx = 1;
		dy = 1;
		ixdep = 8;
		iydep = 8;
		basdroite(Echiquier, controle, ic);
	}
	if (getid() == 4) // roi
	{
		dx = 1;
		dy = 1;
		ixdep = 1;
		iydep = 1;

		haut(Echiquier, controle, ic);

		dx = 1;
		dy = 1;
		ixdep = 1;
		iydep = 1;
		bas(Echiquier, controle, ic);

		dx = 1;
		dy = 1;
		ixdep = 1;
		iydep = 1;
		gauche(Echiquier, controle, ic);

		dx = 1;
		dy = 1;
		ixdep = 1;
		iydep = 1;
		droite(Echiquier, controle, ic);

		dx = 1;
		dy = 1;
		ixdep = 1;
		iydep = 1;
		hautdroite(Echiquier, controle, ic);

		dx = 1;
		dy = 1;
		ixdep = 1;
		iydep = 1;
		basgauche(Echiquier, controle, ic);

		dx = 1;
		dy = 1;
		ixdep = 1;
		iydep = 1;
		hautgauche(Echiquier, controle, ic);

		dx = 1;
		dy = 1;
		ixdep = 1;
		iydep = 1;
		basdroite(Echiquier, controle, ic);
	}
	if (getid() == 5) // reine
	{
		dx = 1;
		dy = 1;
		ixdep = 8;
		iydep = 8;

		haut(Echiquier, controle, ic);

		dx = 1;
		dy = 1;
		ixdep = 8;
		iydep = 8;
		bas(Echiquier, controle, ic);

		dx = 1;
		dy = 1;
		ixdep = 8;
		iydep = 8;
		gauche(Echiquier, controle, ic);

		dx = 1;
		dy = 1;
		ixdep = 8;
		iydep = 8;
		droite(Echiquier, controle, ic);

		dx = 1;
		dy = 1;
		ixdep = 8;
		iydep = 8;
		hautdroite(Echiquier, controle, ic);

		dx = 1;
		dy = 1;
		ixdep = 8;
		iydep = 8;
		basgauche(Echiquier, controle, ic);

		dx = 1;
		dy = 1;
		ixdep = 8;
		iydep = 8;
		hautgauche(Echiquier, controle, ic);

		dx = 1;
		dy = 1;
		ixdep = 8;
		iydep = 8;
		basdroite(Echiquier, controle, ic);
	}
}
// ------------------------------------------------------

// ------------ Joystick cardinal -----------------
void piece::haut(echiquier *Echiquier,bool controle, bool ic)
{
	//------------------------- haut ------------------------------
	for (dy; dy <= iydep && dy <= yi; dy++)
	{
		if (Echiquier->GetCases(xi, yi - dy)->getoccuper() != true)
		{
			if (controle)
			{
				if (getid() != 0)
				{
					Echiquier->GetCases(xi, yi - dy)->setcontroler(ic);
				}
				if (ic)
				{
					Echiquier->GetCases(xi, yi - dy)->setcouleurdeloccupant(couleur);
				}
				else
				{
					Echiquier->GetCases(xi, yi - dy)->setcouleurdeloccupant(0);
				}

			}
			else
			{
				if (!controle)
				{
					if (getid() != 4)
						// si la piece n'est pas un roi OU si la case controlé l'est par une piece de la même couleur
					{
						Echiquier->GetCases(xi, yi - dy)->setdisponible(true);
					}
					else if (Echiquier->GetCases(xi, yi - dy)->getcontroler() && Echiquier->GetCases(xi, yi - dy)->getcouleurdeloccupant() == couleur)
					{
						Echiquier->GetCases(xi, yi - dy)->setdisponible(true);
					}
					else if (!Echiquier->GetCases(xi, yi - dy)->getcontroler())
					{
						Echiquier->GetCases(xi, yi - dy)->setdisponible(true);
					}
				}
			}
		}
		else if (Echiquier->GetCases(xi, yi - dy)->getcouleurdeloccupant() != couleur && !controle)
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
void piece::bas(echiquier *Echiquier, bool controle, bool ic)
{
	//------------------------- bas -------------------------------
	for (dy; dy <= iydep && dy <= 7 - yi; dy++)
	{
		if (Echiquier->GetCases(xi, yi + dy)->getoccuper() != true)
		{
			if (controle)
			{
				if (getid() != 0)
				{
					Echiquier->GetCases(xi, yi + dy)->setcontroler(ic);
				}
				if (ic)
				{
					Echiquier->GetCases(xi, yi + dy)->setcouleurdeloccupant(couleur);
				}
				else
				{
					Echiquier->GetCases(xi, yi + dy)->setcouleurdeloccupant(0);
				}
			}
			else
			{
				if (!controle)
				{
					if (getid() != 4 || (Echiquier->GetCases(xi, yi + dy)->getcontroler() && Echiquier->GetCases(xi, yi + dy)->getcouleurdeloccupant() == couleur))
						// si la piece n'est pas un roi OU si la case controlé l'est par une piece de la même couleur
					{
						Echiquier->GetCases(xi, yi + dy)->setdisponible(true);
					}
					else if(!Echiquier->GetCases(xi, yi + dy)->getcontroler())
					{
						Echiquier->GetCases(xi, yi + dy)->setdisponible(true);
					}
				}
			}
		}
		else if (Echiquier->GetCases(xi, yi + dy)->getcouleurdeloccupant() != couleur && !controle)
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
void piece::gauche(echiquier *Echiquier, bool controle, bool ic)
{
	//------------------------- gauche -----------------------------
	for (dx; dx <= ixdep && dx <= xi; dx++)
	{
		if (Echiquier->GetCases(xi - dx, yi)->getoccuper() != true)
		{
			if (controle)
			{
				Echiquier->GetCases(xi - dx, yi)->setcontroler(ic);
				if (ic)
				{
					Echiquier->GetCases(xi - dx, yi)->setcouleurdeloccupant(couleur);
				}
				else
				{
					Echiquier->GetCases(xi - dx, yi)->setcouleurdeloccupant(0);
				}
				
			}
			else
			{
				if (!controle)
				{
					if (getid() != 4 || Echiquier->GetCases(xi - dx, yi)->getcontroler() && Echiquier->GetCases(xi - dx, yi)->getcouleurdeloccupant() == couleur)
					{// si la piece n'est pas un roi OU si la case controlé l'est par une piece de la même couleur
						Echiquier->GetCases(xi - dx, yi)->setdisponible(true);
					}
					else if (!Echiquier->GetCases(xi - dx, yi)->getcontroler())
					{
						Echiquier->GetCases(xi - dx, yi)->setdisponible(true);
					}
				}
			}
		}
		else if (Echiquier->GetCases(xi - dx, yi)->getcouleurdeloccupant() != couleur && !controle)
		{
			Echiquier->GetCases(xi - dx, yi)->setdisponible(true);
		}
		if (Echiquier->GetCases(xi - dx, yi)->getoccuper() == true)
		{
			dx += 8;
		}
	}
}
void piece::droite(echiquier *Echiquier, bool controle, bool ic)
{
	
	//------------------------ droite ----------------------------
	for (dx; dx <= ixdep && dx <= 7 - xi; dx++)
	{
		if (Echiquier->GetCases(xi + dx, yi)->getoccuper() != true)
		{
			if (controle)
			{
				Echiquier->GetCases(xi + dx, yi)->setcontroler(ic);
				if (ic)
				{
					Echiquier->GetCases(xi + dx, yi)->setcouleurdeloccupant(couleur);
				}
				else
				{
					Echiquier->GetCases(xi + dx, yi)->setcouleurdeloccupant(0);
				}
				
			}
			else
			{
				if (!controle)
				{
					if (getid() != 4 || (Echiquier->GetCases(xi + dx, yi)->getcontroler() && Echiquier->GetCases(xi + dx, yi)->getcouleurdeloccupant() == couleur))
						// si la piece n'est pas un roi OU si la case controlé l'est par une piece de la même couleur
					{

						Echiquier->GetCases(xi + dx, yi)->setdisponible(true);
					}
					else if (!Echiquier->GetCases(xi + dx, yi)->getcontroler())
					{
						Echiquier->GetCases(xi + dx, yi)->setdisponible(true);
					}
				}
			}
		}
		else if (Echiquier->GetCases(xi + dx, yi)->getcouleurdeloccupant() != couleur && !controle)
		{
			if (!controle)
			{
				Echiquier->GetCases(xi + dx, yi)->setdisponible(true);
			}
		}
		if (Echiquier->GetCases(xi + dx, yi)->getoccuper() == true)
		{
			dx += 8;
		}
	}
}

void piece::hautdroite(echiquier *Echiquier, bool controle, bool ic)
{
	//------------------------- hautdroite ------------------------------
	for (dx; dx <= ixdep && dx <= 7 - xi; dx++)
	{
		if (dy <= iydep && dy <= yi)
		{
			if (!Echiquier->GetCases(xi + dx, yi - dy)->getoccuper()) // si la case n'est pas occuper
			{
				if (controle)
				{
					Echiquier->GetCases(xi + dx, yi - dy)->setcontroler(ic);
					if (ic)
					{
						Echiquier->GetCases(xi + dx, yi - dy)->setcouleurdeloccupant(couleur);
					}
					else
					{
						Echiquier->GetCases(xi + dx, yi - dy)->setcouleurdeloccupant(0);
					}
					
				}
				else
				{
					if (getid() == 0)
					{
						if (Echiquier->GetCases(xi + dx, yi - dy)->getPriseEnPassant() && Echiquier->GetCases(xi + dx, yi - dy)->getcouleurdeloccupant() != couleur) // si la case est en Prise en passant
						{
							Echiquier->GetCases(xi + dx, yi - dy)->setdisponible(true);
						}
					}
					else
					{
						if (!controle)
						{
							if (getid() != 4 || (Echiquier->GetCases(xi + dx, yi - dy)->getcontroler() && Echiquier->GetCases(xi + dx, yi - dy)->getcouleurdeloccupant() == couleur))
								// si la piece n'est pas un roi OU si la case controlé l'est par une piece de la même couleur
							{

								Echiquier->GetCases(xi + dx, yi - dy)->setdisponible(true);
							}
							else if (!Echiquier->GetCases(xi + dx, yi - dy)->getcontroler())
							{
								Echiquier->GetCases(xi + dx, yi - dy)->setdisponible(true);
							}
							
						}
					}
				}
			}
			else if (Echiquier->GetCases(xi + dx, yi - dy)->getcouleurdeloccupant() != couleur && !controle) // si la couleur de l'occupant n'est pas la même que celle de la piece
			{
				if (!controle)
				{
					Echiquier->GetCases(xi + dx, yi - dy)->setdisponible(true);
				}
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
void piece::basgauche(echiquier *Echiquier, bool controle, bool ic)
{
	//------------------------- basgauche -------------------------------
	for (dx; dx <= ixdep && dx <= xi; dx++)
	{
		if (dy <= iydep && dy <= 7 - yi)
		{
			if (Echiquier->GetCases(xi - dx, yi + dy)->getoccuper() != true)
			{
				if (controle)
				{
					Echiquier->GetCases(xi - dx, yi + dy)->setcontroler(ic);
					if (ic)
					{
						Echiquier->GetCases(xi - dx, yi + dy)->setcouleurdeloccupant(couleur);
					}
					else
					{
						Echiquier->GetCases(xi - dx, yi + dy)->setcouleurdeloccupant(0);
					}
					
				}
				else
				{
					if (getid() == 0)
					{
						if (Echiquier->GetCases(xi - dx, yi + dy)->getPriseEnPassant() && Echiquier->GetCases(xi - dx, yi + dy)->getcouleurdeloccupant() != couleur)
						{
							Echiquier->GetCases(xi - dx, yi + dy)->setdisponible(true);
						}

					}
					else
					{
						if (!controle)
						{
							if (getid() != 4 || (Echiquier->GetCases(xi - dx, yi + dy)->getcontroler() && Echiquier->GetCases(xi - dx, yi + dy)->getcouleurdeloccupant() == couleur))
								// si la piece n'est pas un roi OU si la case controlé l'est par une piece de la même couleur
							{

								Echiquier->GetCases(xi - dx, yi + dy)->setdisponible(true);
							}
							else if (!Echiquier->GetCases(xi - dx, yi + dy)->getcontroler())
							{
								Echiquier->GetCases(xi - dx, yi + dy)->setdisponible(true);
							}
						}
					}
				}
			}
			else if (Echiquier->GetCases(xi - dx, yi + dy)->getcouleurdeloccupant() != couleur && !controle)
			{
				if (!controle)
				{
					Echiquier->GetCases(xi - dx, yi + dy)->setdisponible(true);
				}
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
void piece::hautgauche(echiquier *Echiquier, bool controle, bool ic)
{
	//------------------------ hautgauche ----------------------------
	for (dx; dx <= ixdep && dx <= xi; dx++)
	{
		if (dy <= iydep && dy <= yi)
		{
			if (Echiquier->GetCases(xi - dx, yi - dy)->getoccuper() != true)
			{
				if (controle)
				{
					Echiquier->GetCases(xi - dx, yi - dy)->setcontroler(ic);
					if (ic)
					{
						Echiquier->GetCases(xi - dx, yi - dy)->setcouleurdeloccupant(couleur);
					}
					else
					{
						Echiquier->GetCases(xi - dx, yi - dy)->setcouleurdeloccupant(0);
					}
					
				}
				else
				{
					if (getid() == 0)
					{
						if (Echiquier->GetCases(xi - dx, yi - dy)->getPriseEnPassant() && Echiquier->GetCases(xi - dx, yi - dy)->getcouleurdeloccupant() != couleur)
						{
							if (!controle)
							{
								Echiquier->GetCases(xi - dx, yi - dy)->setdisponible(true);
							}
						}
					}
					else
					{
						if (!controle)
						{
							if (getid() != 4 || (Echiquier->GetCases(xi - dx, yi - dy)->getcontroler() && Echiquier->GetCases(xi - dx, yi - dy)->getcouleurdeloccupant() == couleur))
								// si la piece n'est pas un roi OU si la case controlé l'est par une piece de la même couleur
							{
								Echiquier->GetCases(xi - dx, yi - dy)->setdisponible(true);
							}
							else if (!Echiquier->GetCases(xi - dx, yi - dy)->getcontroler())
							{
								Echiquier->GetCases(xi - dx, yi - dy)->setdisponible(true);
							}
						}
					}
				}
			}
			else if (Echiquier->GetCases(xi - dx, yi - dy)->getcouleurdeloccupant() != couleur && !controle)
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
void piece::basdroite(echiquier *Echiquier, bool controle, bool ic)
{
	//------------------------- basdroite -----------------------------
	for (dx; dx <= ixdep && dx <= 7 - xi; dx++)
	{
		if (dy <= iydep && dy <= 7 - yi)
		{
			if (Echiquier->GetCases(xi + dx, yi + dy)->getoccuper() != true)
			{
				if (controle)
				{
					Echiquier->GetCases(xi + dx, yi + dy)->setcontroler(ic);
					if (ic)
					{
						Echiquier->GetCases(xi + dx, yi + dy)->setcouleurdeloccupant(couleur);
					}
					else
					{
						Echiquier->GetCases(xi + dx, yi + dy)->setcouleurdeloccupant(0);
					}
					
				}
				else
				{
					if (getid() == 0)
					{
						if (Echiquier->GetCases(xi + dx, yi + dy)->getPriseEnPassant() && Echiquier->GetCases(xi + dx, yi + dy)->getcouleurdeloccupant() != couleur)
						{
							if (!controle)
							{
								Echiquier->GetCases(xi + dx, yi + dy)->setdisponible(true);
							}
						}
					}
					else
					{
						if (getid() != 4 || (Echiquier->GetCases(xi + dx, yi +dy)->getcontroler() && Echiquier->GetCases(xi + dx, yi + dy)->getcouleurdeloccupant() == couleur)) 
							// si la piece n'est pas un roi OU si la case controlé l'est par une piece de la même couleur
						{
							Echiquier->GetCases(xi + dx, yi + dy)->setdisponible(true); // la case est rendu disponible
						}
						else if (!Echiquier->GetCases(xi + dx, yi + dy)->getcontroler())
						{
							Echiquier->GetCases(xi + dx, yi + dy)->setdisponible(true);
						}
					}
				}
			}
			else if (Echiquier->GetCases(xi + dx, yi + dy)->getcouleurdeloccupant() != couleur && !controle)
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

void piece::EchecRoi(echiquier * Echiquier)
{
	bool Ped = false;// piece enemi detecter
	//------------------------- haut ------------------------------
	for (dy = 1; dy <= yi; dy++)
	{
		if (Echiquier->GetCases(xi, yi - dy)->getoccuper() == true)
		{
			if (Echiquier->GetCases(xi, yi - dy)->getcouleurdeloccupant() != couleur)
			{
				if (Echiquier->GetCases(xi, yi - dy)->getidpiece() == 1 || Echiquier->GetCases(xi, yi - dy)->getidpiece() == 5)
				{
					Ped = true;
				}
				else
				{
					Ped = false;
					dy = 8;
				}
			}
		}
		
	}
	if (Ped == true)
	{
		for (dy = 1; dy <= yi; dy++)
		{
			if (Echiquier->GetCases(xi, yi - dy)->getoccuper() == true && Echiquier->GetCases(xi , yi - dy)->getcouleurdeloccupant() != couleur)
			{
				
				Echiquier->GetCases(xi, yi - dy)->setsauverRoi(true);
				dy = 8;
			}
			else
			{
				Echiquier->GetCases(xi, yi - dy)->setechecRoi(true);
			}
		}
		Ped = false;
	}
	//------------------------- bas -------------------------------
	for (dy = 1; dy <= 7 - yi; dy++)
	{
		if (Echiquier->GetCases(xi, yi + dy)->getoccuper() == true)
		{
			if (Echiquier->GetCases(xi, yi + dy)->getcouleurdeloccupant() != couleur)
			{
				if (Echiquier->GetCases(xi, yi + dy)->getidpiece() == 1 || Echiquier->GetCases(xi, yi + dy)->getidpiece() == 5)
				{
					Ped = true;
				}
				else
				{
					Ped = false;
					dy = 8;
				}
			}
		}
	}
	if (Ped == true)
	{
		for (dy = 1; dy <= yi; dy++)
		{
			if (Echiquier->GetCases(xi, yi + dy)->getoccuper() == true && Echiquier->GetCases(xi, yi + dy)->getcouleurdeloccupant() != couleur)
			{
				
				Echiquier->GetCases(xi, yi + dy)->setsauverRoi(true);
				dy = 8;
			}
			else
			{
				Echiquier->GetCases(xi, yi + dy)->setechecRoi(true);
			}
		}
		Ped = false;
	}
	//------------------------- gauche -----------------------------
	for (dx = 1; dx <= xi; dx++)
	{
		if (Echiquier->GetCases(xi - dx, yi)->getoccuper() == true)
		{
			if (Echiquier->GetCases(xi - dx, yi)->getcouleurdeloccupant() != couleur)
			{
				if (Echiquier->GetCases(xi - dx, yi)->getidpiece() == 1 || Echiquier->GetCases(xi - dx, yi)->getidpiece() == 5)
				{
					Ped = true;
				}
				else
				{
					Ped = false;
					dx = 8;
				}
			}
		}
	}
	if (Ped == true)
	{
		for (dx = 1; dx <= xi; dx++)
		{
			if (Echiquier->GetCases(xi - dx, yi)->getoccuper() == true && Echiquier->GetCases(xi - dx, yi)->getcouleurdeloccupant() != couleur)
			{
				
				Echiquier->GetCases(xi - dx, yi)->setsauverRoi(true);
				dx = 8;
			}
			else
			{
				Echiquier->GetCases(xi - dx, yi)->setechecRoi(true);
			}
		}
		Ped = false;
	}
	//------------------------ droite ----------------------------
	for (dx = 1; dx <= 7 - xi; dx++)
	{
		if (Echiquier->GetCases(xi + dx, yi)->getoccuper() == true )
		{
			if (Echiquier->GetCases(xi + dx, yi)->getcouleurdeloccupant() != couleur)
			{
				if (Echiquier->GetCases(xi + dx, yi)->getidpiece() == 1 || Echiquier->GetCases(xi + dx, yi)->getidpiece() == 5)
				{
					Ped = true;
				}
				else
				{
					Ped = false;
					dx = 8;
				}
			}
		}
	}
	if (Ped == true)
	{
		for (dx = 1; dx <= 7 - xi; dx++)
		{
			if (Echiquier->GetCases(xi + dx, yi)->getoccuper() == true && Echiquier->GetCases(xi + dx, yi)->getcouleurdeloccupant() != couleur)
			{
				Echiquier->GetCases(xi + dx, yi)->setsauverRoi(true);
				dx = 8;
			}
			else
			{
				Echiquier->GetCases(xi + dx, yi)->setechecRoi(true);
			}
		}
		Ped = false;
	}
	//------------------------- hautdroite ------------------------------
	dy = 1;
	for (dx = 1;dx <= 7 - xi; dx++)
	{
		if (dy <= yi)
		{
			if (Echiquier->GetCases(xi + dx, yi - dy)->getoccuper() == true )
			{
				if (Echiquier->GetCases(xi + dx, yi - dy)->getcouleurdeloccupant() != couleur)
				{
					if (Echiquier->GetCases(xi + dx, yi - dy)->getidpiece() == 3 || Echiquier->GetCases(xi + dx, yi - dy)->getidpiece() == 5)
					{
						Ped = true;
					}
					else
					{
						Ped = false;
						dy = 8;
						dx = 8;
					}
				}
			}
			dy++;
		}
	}
	dy = 1;
	if (Ped == true)
	{
		for (dx = 1; dx <= 7 - xi; dx++)
		{
			if (dy <= yi)
			{
				if (Echiquier->GetCases(xi + dx, yi - dy)->getoccuper() == true && Echiquier->GetCases(xi + dx, yi - dy)->getcouleurdeloccupant() != couleur)
				{
					Echiquier->GetCases(xi + dx, yi - dy)->setsauverRoi(true);
					dy = 8;
					dx = 8;
				}
				else
				{
					Echiquier->GetCases(xi + dx, yi - dy)->setechecRoi(true);
				}
				dy++;
			}
		}
		Ped = false;
	}
	//------------------------- basgauche -------------------------------
	dy = 1;
	for (dx = 1;dx <= xi; dx++)
	{
		if (dy <= 7 - yi)
		{
			if (Echiquier->GetCases(xi - dx, yi + dy)->getoccuper() == true )
			{
				if (Echiquier->GetCases(xi - dx, yi + dy)->getcouleurdeloccupant() != couleur)
				{
					if (Echiquier->GetCases(xi - dx, yi + dy)->getidpiece() == 3 || Echiquier->GetCases(xi - dx, yi + dy)->getidpiece() == 5)
					{
						Ped = true;
					}
					else
					{
						Ped = false;
						dy = 8;
						dx = 8;
					}
				}
			}
			dy++;
		}
	}
	dy = 1;
	if (Ped == true)
	{
		for (dx = 1; dx <= xi; dx++)
		{
			if (dy <= 7 - yi)
			{
				if (Echiquier->GetCases(xi - dx, yi + dy)->getoccuper() == true && Echiquier->GetCases(xi - dx, yi + dy)->getcouleurdeloccupant() != couleur)
				{
					Echiquier->GetCases(xi - dx, yi + dy)->setsauverRoi(true);
					dy = 8;
					dx = 8;
				}
				else
				{
					Echiquier->GetCases(xi - dx, yi + dy)->setechecRoi(true);
				}
				dy++;
			}
		}
		Ped = false;
	}
	//------------------------ hautgauche ----------------------------
	dy = 1;
	for (dx = 1; dx <= xi; dx++)
	{
		if (dy <= yi)
		{
			if (Echiquier->GetCases(xi - dx, yi - dy)->getoccuper() == true )
			{
				if (Echiquier->GetCases(xi - dx, yi - dy)->getcouleurdeloccupant() != couleur)
				{
					if (Echiquier->GetCases(xi - dx, yi - dy)->getidpiece() == 3 || Echiquier->GetCases(xi - dx, yi - dy)->getidpiece() == 5)
					{
						Ped = true;
					}
					else
					{
						Ped = false;
						dy = 8;
						dx = 8;
					}
				}
			}
			dy++;
		}
	}
	dy = 1;
	if (Ped == true)
	{
		for (dx = 1; dx <= xi; dx++)
		{
			if (dy <= yi)
			{
				if (Echiquier->GetCases(xi - dx, yi - dy)->getoccuper() == true && Echiquier->GetCases(xi - dx, yi - dy)->getcouleurdeloccupant() != couleur)
				{
					Echiquier->GetCases(xi - dx, yi - dy)->setsauverRoi(true);
					dy = 8;
					dx = 8;
				}
				else
				{
					Echiquier->GetCases(xi - dx, yi - dy)->setechecRoi(true);
				}
				dy++;
			}
		}
		Ped = false;
	}
	//------------------------- basdroite -----------------------------
	dy = 1;
	for (dx = 1;dx <= 7 - xi; dx++)
	{
		if (dy <= 7 - yi)
		{
			if (Echiquier->GetCases(xi + dx, yi + dy)->getoccuper() == true )
			{
				if (Echiquier->GetCases(xi + dx, yi + dy)->getcouleurdeloccupant() != couleur)
				{
					if (Echiquier->GetCases(xi + dx, yi + dy)->getidpiece() == 3 || Echiquier->GetCases(xi + dx, yi + dy)->getidpiece() == 5)
					{
						Ped = true;
					}
					else
					{
						Ped = false;
						dy = 8;
						dx = 8;
					}
				}
			}
			dy++;
		}
	}
	dy = 1;
	if (Ped == true)
	{
		for (dx = 1; dx <= 7 - xi; dx++)
		{
			if (dy <= 7 - yi)
			{
				if (Echiquier->GetCases(xi + dx, yi + dy)->getoccuper() == true && Echiquier->GetCases(xi + dx, yi + dy)->getcouleurdeloccupant() != couleur)
				{
					Echiquier->GetCases(xi + dx, yi + dy)->setsauverRoi(true);
					dy = 8;
					dx = 8;
				}
				else
				{
					Echiquier->GetCases(xi + dx, yi + dy)->setechecRoi(true);
				}
				dy++;
			}
		}
		Ped = false;
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
			posPPy = y + 1;
		}
		if (couleur == 2) // si couluer = noire
		{
			posPPy = y - 1;
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
void piece::setConditiondep(int ndx, int ndy, int nixdep, int niydep)
{
	dx = ndx;
	dy = ndy;
	ixdep = nixdep;
	iydep = niydep;
}
bool piece::getPieceProtectrice()
{
	return PieceProtectrice;
}
void piece::setPieceProtectrice(bool i)
{
	PieceProtectrice = i;
}
bool piece::getpieceMenacente()
{
	return PieceMenacente;
}
//---------------------------------------
//==================================================================

	void piece::setpieceMenacente(bool npieceMenacente)
	{
		PieceMenacente = npieceMenacente;
	}

	piece::~piece()
{
}