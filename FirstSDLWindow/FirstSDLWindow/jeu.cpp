#include "jeu.h"

int iA = 0;
int iB = 32;

jeu::jeu()
{
}

jeu::~jeu()
{
}

void jeu::init(const char * titre, int xpos, int ypos, int largeur, int hauteur, bool fullscreen)
{
	//initialisation fenetre
	int flags = 0;
	if (fullscreen)
	{
		flags = SDL_WINDOW_FULLSCREEN;
	}
	if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
	{
		cout << "Sous systems initialis\202!..." << endl;

		window = SDL_CreateWindow(titre, xpos, ypos, largeur, hauteur, flags);
		if (window)
		{
			cout << "Fenetre cr\202\202e !" << endl;
		}
		renderer = SDL_CreateRenderer(window, -1, 0);
		if (renderer)
		{
			SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
			cout << "Render cr\202\202e !" << endl;
		}
		isRunning = true;
	}
	else {
		isRunning = false;
	}
	//initialisation Echiquier
	Echiquier = new echiquier("texture/Echiquier.png", renderer);
	Echiquier->Position(300, 58);
	Echiquier->Taille(700, 690);
	//initialisation case
	int posx; // pos = positions relative a la fenetre
	int posy = 55; // pos = positions relative a la fenetre

	for (int y = 0; y < 8; y++) // x/y = position dans le tableau de lechiquier
	{
		posx = 315;
		posy += 70;

		for (int x = 0; x < 8; x++) // x/y = position dans le tableau de lechiquier
		{
			posx += 70;
			Echiquier->ajouterCases(posx, posy, x, y);
			Echiquier->GetCases(x, y)->setoccuper(false);
			Echiquier->GetCases(x, y)->setcouleurdeloccupant(0);
		}
	}
	/*
	//initialisation pion
	const char * texture;
	for (int c=0; c < 2; c++) // c = couleur de la piece
	{
		for (int i = 0; i < 8; i++)
		{
			texture = "texture/pionB.png";
			if (c == 0) {
				lesPions[i] = pion(1,false, true, 1, Echiquier->GetCases(i,1)->Rcase, Echiquier->GetCases(i, 1)->getx(), Echiquier->GetCases(i, 1)->gety(), texture, renderer);
				lesPions[i].setposI(); // remplace la position initial sur le tableau
				Echiquier->GetCases(i, 1)->setoccuper(true);
				Echiquier->GetCases(i, 1)->setcouleurdeloccupant(lesPions[i].getcouleur());
			}
			if (c == 1) {
				texture = "texture/pionN.png";
				lesPions[8+i] = pion(1,false, true, 2, Echiquier->GetCases(i,6)->Rcase, Echiquier->GetCases(i, 6)->getx(), Echiquier->GetCases(i, 6)->gety(), texture, renderer);
				lesPions[8+i].setposI(); // remplace la position initial sur le tableau
				Echiquier->GetCases(i, 6)->setoccuper(true);
				Echiquier->GetCases(i, 6)->setcouleurdeloccupant(lesPions[8 + i].getcouleur());
			}

		}
	}
	*/
	//initialisation des autres pieces

	const char * texture = NULL;
	int id = 0;
	int typePiece = 0;
	int px = 0;
	int mx = 0;
	int ix = 0;

	int y = 0;
	cout << "test initialisation  des piece : \n";
	for (int c = 0; c < 2; c++) // la couleur
	{
		for (int i = 0; i < 6; i++) // les pions
		{
			// Paramettre en fonction de la piece 
			switch (i)
			{
			case 0: // pion
				if (c == 0) // les pions
				{
					texture = "texture/pionB.png";
					px = 0;
					typePiece = 0;
					mx = 8;
					ix = 1;
					y = 1;
				}
				if (c == 1)
				{
					texture = "texture/pionN.png";
					px = 0;
					typePiece = 0;
					mx = 8;
					ix = 1;
					y = 6;
				}
				break;
			case 1: // tour
				if (c == 0) // les tours
				{
					texture = "texture/tourB.png";
					px = 0;
					typePiece = 1;
					px = 0;
					mx = 8;
					ix = 7;
					y = 0;
				}
				if (c == 1)
				{
					texture = "texture/tourN.png";
					px = 0;
					typePiece = 1;
					mx = 8;
					ix = 7;
					y = 7;
				}
				break;
			case 2: // cavalier
				if (c == 0) // les cavaliers
				{
					texture = "texture/cavalierB.png";
					px = 1;
					typePiece = 2;
					mx = 7;
					ix = 5;
					y = 0;
				}
				if (c == 1)
				{
					texture = "texture/cavalierN.png";
					px = 1;
					typePiece = 2;
					mx = 7;
					ix = 5;
					y = 7;
				}
				break;
			case 3:  // fou
				if (c == 0) // les fous
				{
					texture = "texture/fouB.png";
					px = 2;
					typePiece = 3;
					mx = 6;
					ix = 3;
					y = 0;
				}
				if (c == 1)
				{
					texture = "texture/fouN.png";
					px = 2;
					typePiece = 3;
					mx = 6;
					ix = 3;
					y = 7;
				}
				break;
			case 4: // roi
				if (c == 0) // les rois
				{
					texture = "texture/roiB.png";
					px = 3;
					typePiece = 4;
					mx = 5;
					ix = 2;
					y = 0;
				}
				if (c == 1)
				{
					texture = "texture/roiN.png";
					px = 3;
					typePiece = 4;
					mx = 5;
					ix = 2;
					y = 7;
				}
				break;
			case 5:
				if (c == 0) // les reines
				{
					texture = "texture/reineB.png";
					px = 4;
					typePiece = 5;
					mx = 6;
					ix = 2;
					y = 0;
				}
				if (c == 1)
				{
					texture = "texture/reineN.png";
					px = 4;
					typePiece = 5;
					mx = 6;
					ix = 2;
					y = 7;
				}
				break;
			}
			for (int x = px; x < mx; x += ix)
			{
				cout << "\n |id :" << i << " |couleur :" << c + 1 << " |type piece :" << typePiece << "\n |texture : "<< texture <<" |x :" << x << " |y :" << y << endl;
				lesPieces[id] = GenerateurPiece::generer(i, false, 1, c + 1, Echiquier->GetCases(x, y)->Rcase, Echiquier->GetCases(x, y)->getx(), Echiquier->GetCases(x, y)->gety(), texture, renderer);
				lesPieces[id]->setposI(); // remplace la position initial sur le tableau
				// les cases sur les quelles les pions on été initialiser sont mise a occuper
				Echiquier->GetCases(x, y)->setoccuper(true);
				Echiquier->GetCases(x, y)->setcouleurdeloccupant(lesPieces[id]->getcouleur());
				id++;
			}
		}
	}
}
int pi=32; // piece indice
bool once= true;

void jeu::handleEvents()
{
	SDL_Event event;
	SDL_PollEvent(&event);
	
	if (event.type == SDL_QUIT)
	{
		isRunning = 0;
	}
	else if (isRunning)
	{
		for (int i = iA; i != pi && i < iB; i++)
		{
			if (event.button.button == SDL_BUTTON_LEFT) // piece selecioné
			{
				if (lesPieces[i]->getmanger() != true)
				{
					if (event.button.x > lesPieces[i]->getPos().x - 10 && event.button.x < lesPieces[i]->getPos().x + 40 && event.button.y > lesPieces[i]->getPos().y && event.button.y < lesPieces[i]->getPos().y + 70)
					{
						if (once)
						{
							cout << "position initial : xi " << lesPieces[i]->getxi() << " yi " << lesPieces[i]->getyi() << endl;
							lesPieces[i]->dispodeplace(Echiquier); // rend les case disponible au deplacement
							for (int cy = 0; cy < 8; cy++)
							{
								for (int cx = 0; cx < 8; cx++)
								{
									if (Echiquier->GetCases(cx, cy)->getdisponible())
									{
										cout << "test pointverst : x" << cx << " y" << cy << endl;
										Pointverts.push_back(new GameObject("texture/disponible.png", renderer));
										Pointverts.back()->Position(Echiquier->GetCases(cx, cy)->Rcase.x, Echiquier->GetCases(cx, cy)->Rcase.y);
										Pointverts.back()->Taille(35, 60);
									}
								}
							}
						}
						lesPieces[i]->Position(event.button.x - 19, event.button.y - 31);
						iA = i;
						iB = i + 1;
						once = false;
						if (event.type == SDL_MOUSEBUTTONUP) // pièce relacher
						{
							once = true;
							for (int y = 0; y < 8; y++)
							{
								for (int x = 0; x < 8; x++)
								{
									if (GameObject::comparerPosition(&lesPieces[i]->getPos(), &Echiquier->GetCases(x, y)->Rcase, 36)) // force la position dans une case
									{
										lesPieces[i]->setx(x); // met les nouvel position du pion dans le tableau
										lesPieces[i]->sety(y);

										lesPieces[i]->Position(Echiquier->GetCases(x, y)->Rcase.x, Echiquier->GetCases(x, y)->Rcase.y); // position de test ou le pion a été poser
										cout << "position en test " << lesPieces[i]->getx() << lesPieces[i]->gety() << endl;
									}
								}
							}

							if (lesPieces[i]->deplacement(Echiquier)) // vérification deplacement valide ( case en x et y disponible)
							{
								Echiquier->GetCases(lesPieces[i]->getx(), lesPieces[i]->gety())->setoccuper(true);
								Echiquier->GetCases(lesPieces[i]->getx(), lesPieces[i]->gety())->setcouleurdeloccupant(lesPieces[i]->getcouleur());

								for (int ip = 0; ip < 32; ip++)
								{
									if (lesPieces[i]->getx() == lesPieces[ip]->getx() && lesPieces[i]->gety() == lesPieces[ip]->gety()) // test si il y a un pion sur notre case
									{
										cout << "x " << lesPieces[i]->getx() << " et y " << lesPieces[i]->gety() << " du premier pion, x " << lesPieces[ip]->getx() << " et y " << lesPieces[ip]->gety() << " du deuxieme pion" << endl;
										if (lesPieces[ip]->getcouleur() != lesPieces[i]->getcouleur()) // et si le pion est d'une autre couleur
										{
											lesPieces[ip]->setmanger(true);
											lesPieces[ip]->Position(0, 23*ip);
											cout << "sayonara pion" << lesPieces[ip]->getid() << lesPieces[ip]->getcouleur() << endl;
										}
									}
								}
								Echiquier->GetCases(lesPieces[i]->getxi(), lesPieces[i]->getyi())->setoccuper(false);
								Echiquier->GetCases(lesPieces[i]->getxi(), lesPieces[i]->getyi())->setcouleurdeloccupant(0);
								lesPieces[i]->setposI(); // remplace la position initial sur le tableau

								if (lesPieces[i]->getdepIncorrect() != true) // verifie si le deplacement est correct
								{
									lesPieces[i]->setpdep(false); // retire le premier deplacement au pion 
								}

								lesPieces[i]->setdepIncorrect(false); // le deplace ment est correct

							}
							else// n'execute pas cela si le deplacement est valide
							{
								lesPieces[i]->setdepIncorrect(true);
							}

							if (lesPieces[i]->getdepIncorrect()) // si le deplacement est incorrect replace le pion sur sa position inital
							{
								lesPieces[i]->Position(Echiquier->GetCases(lesPieces[i]->getxi(), lesPieces[i]->getyi())->Rcase.x, Echiquier->GetCases(lesPieces[i]->getxi(), lesPieces[i]->getyi())->Rcase.y);
								Echiquier->GetCases(lesPieces[i]->getx(), lesPieces[i]->gety())->setoccuper(false);
								Echiquier->GetCases(lesPieces[i]->getx(), lesPieces[i]->gety())->setcouleurdeloccupant(0);
								lesPieces[i]->setpos();
							}


							for (int y2 = 0; y2 < 8; y2++)
							{
								for (int x2 = 0; x2 < 8; x2++)
								{
									Echiquier->GetCases(x2, y2)->setdisponible(false);
									
								}
							}
							Pointverts.clear();
						}
					}
					else
					{
						pi = i;
						iA = 0;
						iB = 32;
					}
				}
			}
			else
			{
				pi = 32;
			}
		}
	}
}

void jeu::update()
{
	Echiquier->Update();
	for (int i = 0; i < 32; i++)
	{
		lesPieces[i]->Update();
	}
}

void jeu::render()
{
	SDL_RenderClear(renderer);
	Echiquier->Render();

	for (int i = 0; i < Pointverts.size(); i++)
	{
		Pointverts.at(i)->Render();
	}

	for (int i = 0; i < 32; i++)
	{
		lesPieces[i]->Render();

	}
	
	SDL_RenderPresent(renderer);
}

void jeu::clean()
{
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
	cout << "Game cleaned" << endl;
}

bool jeu::running()
{
	return isRunning;
}
