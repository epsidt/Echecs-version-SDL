#include "jeu.h"
#include "TextureManager.h"

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
	//initialisation du background
	background = new GameObject("texture/background.png", renderer);
	background->Position(0, 0);
	background->Taille(1280, 800);
	//------ initialisation des composant de syntaxe ------

	Syntaxe = new SyntaxeHandler(renderer);

	Syntaxe->initasset();

	Syntaxe->getMots("tourJoueur")->Position(850, 57);
	Syntaxe->getMots("noir")->Position(375, 70);
	Syntaxe->getMots("tour")->Position(365, 695);

	Syntaxe->getChiffres(0, 1, true)->Position(Syntaxe->getMots("tour")->getPos().x + 80, Syntaxe->getMots("tour")->getPos().y + 8);
	Syntaxe->ChiffresVisibilite(0, 1, false);

	Syntaxe->getChiffres(0, 2, true)->Position(Syntaxe->getMots("tour")->getPos().x + 80, Syntaxe->getMots("tour")->getPos().y + 8);
	Syntaxe->ChiffresVisibilite(0, 2, false);
	
	Syntaxe->getChiffres(1,1,true)->Position(Syntaxe->getMots("tourJoueur")->getPos().x + 305, Syntaxe->getMots("tourJoueur")->getPos().y + 14);
	Syntaxe->ChiffresVisibilite(1,1, true);

	Syntaxe->getChiffres(1,0,false)->Position(Syntaxe->getMots("tour")->getPos().x + 80, Syntaxe->getMots("tour")->getPos().y + 8);
	Syntaxe->ChiffresVisibilite(1,0, true);

	//-----------------------------------------------------

	//initialisation de l'Echiquier
	Echiquier = new echiquier("texture/Echiquier.png", renderer);
	Echiquier->Position(80, 57);
	Echiquier->Taille(700, 695);
	//initialisation de case
	int posx; // pos = positions relative a la fenetre
	int posy = 55; // pos = positions relative a la fenetre

	for (int y = 0; y < 8; y++) // x/y = position dans le tableau de lechiquier
	{
		posx = 95;
		posy += 70;

		for (int x = 0; x < 8; x++) // x/y = position dans le tableau de lechiquier
		{
			posx += 70;
			Echiquier->ajouterCases(posx, posy, x, y);
			Echiquier->GetCases(x, y)->setoccuper(false);
			Echiquier->GetCases(x, y)->setcouleurdeloccupant(0);
		}
	}
	
	//initialisation des pieces

	const char * texture = NULL;
	int id = 0;
	int typePiece = 0;
	int px = 0;
	int mx = 0;
	int ix = 0;

	int y = 0;
	cout << "Test initialisation  des piece : \n______________________________________\n";
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
bool once= true; // pour effectuer des taches une seul fois dans la boucle handlevent

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
						if (lesPieces[i]->getcouleur() - 1 == (jtour % 2))
						{
							if (once)
							{
								//------------------------------------ Rendre une case disponible ---------------------------------------
								lesPieces[i]->setposI();
								
								cout << "\n!!--- Dernier pion it:" << iTDPiece;
								cout << "\nPiece :"<<"it="<<i<<" id=" << lesPieces[i]->getid() << " couleur=" << lesPieces[i]->getcouleur() << endl;
								cout << "position initial : xi=" << lesPieces[i]->getxi() << " yi=" << lesPieces[i]->getyi() << endl;
								lesPieces[i]->dispodeplace(Echiquier); // rend les case disponible au deplacement
								//-------------------------------------------------------------------------------------------------------

								for (int cy = 0; cy < 8; cy++)
								{
									for (int cx = 0; cx < 8; cx++)
									{
										if (Echiquier->GetCases(cx, cy)->getdisponible())
										{
											Pointverts.push_back(new GameObject("texture/disponible.png", renderer));
											Pointverts.back()->Position(Echiquier->GetCases(cx, cy)->Rcase.x, Echiquier->GetCases(cx, cy)->Rcase.y);
											Pointverts.back()->Taille(40, 70);
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
								//--------------- Force la position de la piece dans une case -------------
								for (int y = 0; y < 8; y++)
								{
									for (int x = 0; x < 8; x++)
									{
										if (GameObject::comparerPosition(&lesPieces[i]->getPos(), &Echiquier->GetCases(x, y)->Rcase, 36)) // force la position dans une case
										{
											lesPieces[i]->setx(x); // met les nouvel position du pion dans le tableau
											lesPieces[i]->sety(y);

											lesPieces[i]->Position(Echiquier->GetCases(x, y)->Rcase.x, Echiquier->GetCases(x, y)->Rcase.y); // position de test ou le pion a été poser
											cout << "position : x=" << lesPieces[i]->getx() <<" y="<< lesPieces[i]->gety() << endl;
										}
									}
								}
								//-------------------------------------------------------------------------
								
								if (lesPieces[i]->deplacement(Echiquier)) // vérification deplacement valide ( case en x et y disponible)
								{
									jtour++;
									//------------ les tours de jeux --------------
									if (jtour < 10)
									{
										Syntaxe->ChiffresVisibilite(jtour - 1, 0, false);
										Syntaxe->getChiffres(jtour,0, false)->Position(Syntaxe->getMots("tour")->getPos().x + 80, Syntaxe->getMots("tour")->getPos().y + 8);
										Syntaxe->ChiffresVisibilite(jtour, 0, true);
									}
									else if (jtour >= 10)
									{
										if (jtour % 100 == 0)
										{
											Syntaxe->ChiffresVisibilite(9, 0, false);
											Syntaxe->ChiffresVisibilite(9, 1, false);

											Syntaxe->ChiffresVisibilite(jtour / 100 - 1, Syntaxe->getChiffresSize(jtour / 100 - 1), false);
											Syntaxe->getChiffres(jtour / 100, Syntaxe->getChiffresSize(jtour / 100) + 1, true)->Position(Syntaxe->getMots("tour")->getPos().x + 80, Syntaxe->getMots("tour")->getPos().y + 8);
											Syntaxe->ChiffresVisibilite(jtour / 100, Syntaxe->getChiffresSize(jtour / 100), true);
										}
										if (jtour % 10 == 0)
										{
											Syntaxe->ChiffresVisibilite(9, 0, false);
											Syntaxe->ChiffresVisibilite((jtour -1 % 100) / 10, Syntaxe->getChiffresSize((jtour-1 % 100) / 10), false);
											if (jtour < 100)
											{
												Syntaxe->getChiffres((jtour % 100) / 10, Syntaxe->getChiffresSize((jtour % 100) / 10) + 1, true)->Position(Syntaxe->getChiffres(jtour / 100, Syntaxe->getChiffresSize(jtour / 100), false)->getPos().x + Syntaxe->getChiffres(jtour / 100, Syntaxe->getChiffresSize(jtour / 100), false)->getPos().w, Syntaxe->getMots("tour")->getPos().y + 8);
												Syntaxe->ChiffresVisibilite((jtour % 100) / 10, Syntaxe->getChiffresSize((jtour % 100) / 10), true);
											}
											else
											{
												Syntaxe->getChiffres((jtour % 100) / 10, Syntaxe->getChiffresSize((jtour % 100) / 10) - 1, false)->Position(Syntaxe->getChiffres(jtour / 100, Syntaxe->getChiffresSize(jtour / 100), false)->getPos().x + Syntaxe->getChiffres(jtour / 100, Syntaxe->getChiffresSize(jtour / 100), false)->getPos().w, Syntaxe->getMots("tour")->getPos().y + 8);
												Syntaxe->ChiffresVisibilite((jtour % 100) / 10, Syntaxe->getChiffresSize((jtour % 100) / 10)-1, true);
											}
											
										}

										Syntaxe->ChiffresVisibilite((jtour - 1) % 10, 0, false);
										Syntaxe->getChiffres(jtour % 10, 0, false)->Position(Syntaxe->getChiffres((jtour % 100) / 10, Syntaxe->getChiffresSize((jtour % 100) / 10), false)->getPos().x + Syntaxe->getChiffres((jtour % 100) / 10, Syntaxe->getChiffresSize((jtour % 100) / 10), false)->getPos().w, Syntaxe->getMots("tour")->getPos().y + 8);
										Syntaxe->ChiffresVisibilite(jtour % 10, 0, true);
									}
									//--------------------------------------------

									//--------- PRISE EN PASSANT (mise en place) -----------
									
									if (lesPieces[i]->getid() == 0)
									{
										if (!lesPieces[iTDPiece]->getmanger()) // la case de la position est mise a null si le pion a été manger
										{
											Echiquier->GetCases(lesPieces[iTDPiece]->getposPPx(), lesPieces[iTDPiece]->getposPPy())->setoccuper(false);
											Echiquier->GetCases(lesPieces[iTDPiece]->getposPPx(), lesPieces[iTDPiece]->getposPPy())->setcouleurdeloccupant(0);
										}
										if (!lesPieces[i]->getpdep())
										{
											Echiquier->GetCases(lesPieces[i]->getposPPx(), lesPieces[i]->getposPPy())->setcouleurdeloccupant(0);
										}
										if (lesPieces[i]->getpdep())
										{
											
											lesPieces[i]->setposPPy(false);
											lesPieces[i]->setposPPx(false);

											cout << "posPPy =" << lesPieces[i]->getposPPy() << "posPPx =" << lesPieces[i]->getposPPx() << endl;
											Echiquier->GetCases(lesPieces[i]->getposPPx(), lesPieces[i]->getposPPy())->setcouleurdeloccupant(lesPieces[i]->getcouleur()); // la case en X/Y ACTUELLE est mise a la couleur du pion qui l'occupe
											
											iTDPiece = i;
										}
									}
									//------------------------------------------------------

									//les paramètre des pièces sur l'ancienne position est suprrimer
									Echiquier->GetCases(lesPieces[i]->getxi(), lesPieces[i]->getyi())->setoccuper(false); // la case en X/Y INITIALE est mise a NONoccuper
									Echiquier->GetCases(lesPieces[i]->getxi(), lesPieces[i]->getyi())->setcouleurdeloccupant(0); // la case en X/Y INITIALE est sans couleur
									//les paramètre des pièces sur la nouvelle position son misent a jour
									Echiquier->GetCases(lesPieces[i]->getx(), lesPieces[i]->gety())->setoccuper(true); // la case en X/Y ACTUELLE est mise a occuper
									Echiquier->GetCases(lesPieces[i]->getx(), lesPieces[i]->gety())->setcouleurdeloccupant(lesPieces[i]->getcouleur()); // la case en X/Y ACTUELLE est mise a la couleur du pion qui l'occupe

									lesPieces[i]->setposI(); // remplace la position initial sur le tableau

									//======================================= LE CANIBALISME DE PIECE ==============================================
									for (int ip = 0; ip < 32; ip++)
									{
										//----------------------------------- Manger une piece ------------------------------------
										if (lesPieces[i]->getx() == lesPieces[ip]->getx() && lesPieces[i]->gety() == lesPieces[ip]->gety()) // test s'il y a un pion sur nôtre case
										{
											 if (lesPieces[ip]->getcouleur() != lesPieces[i]->getcouleur()) // Mange le pion s'il est d'une autre couleur
											{
												lesPieces[ip]->setmanger(true);
												lesPieces[ip]->Position(20,23+23 * ip);
												
												cout << "manger pion" << lesPieces[ip]->getid() << lesPieces[ip]->getcouleur() << endl;
											}
										}
										//------------------------------------------------------------------------------------------

										//----------------------------------- Prise en passant -------------------------------------
										if (lesPieces[i]->getid() == 0) // si c'est un pion
										{
											if (lesPieces[i]->getx() == lesPieces[ip]->getposPPx() && lesPieces[i]->gety() == lesPieces[ip]->getposPPy()) // et si il se trouve a la position de la prise en passant d'un autre pion
											{
												Echiquier->GetCases(lesPieces[iTDPiece]->getposPPx(), lesPieces[iTDPiece]->getposPPy())->setoccuper(true);
												Echiquier->GetCases(lesPieces[iTDPiece]->getposPPx(), lesPieces[iTDPiece]->getposPPy())->setcouleurdeloccupant(lesPieces[i]->getcouleur());
												Echiquier->GetCases(lesPieces[ip]->getposPPx(), lesPieces[ip]->getposPPy())->setoccuper(true);
												Echiquier->GetCases(lesPieces[ip]->getposPPx(), lesPieces[ip]->getposPPy())->setcouleurdeloccupant(lesPieces[i]->getcouleur());

												lesPieces[ip]->setmanger(true);
												lesPieces[ip]->Position(20, 23 + 23 * ip);
												cout << "\n prise en passant pion : \n ip=" << ip << " couleur=" << lesPieces[ip]->getcouleur() << "\n x=" << lesPieces[ip]->getx() << " y=" << lesPieces[ip]->gety() << endl;
											}
										}
										//------------------------------------------------------------------------------------------
									}
									//==============================================================================================================
									if (!lesPieces[i]->getdepIncorrect()) // verifie si le deplacement est correct
									{
										lesPieces[i]->setpdep(0); // retire le premier deplacement au pion 
									}

									lesPieces[i]->setdepIncorrect(false); // le deplace ment est correct
								}
								else // n'execute pas cela si le deplacement est valide
								{
									lesPieces[i]->setdepIncorrect(true);
								}

								if (lesPieces[i]->getdepIncorrect()) // si le deplacement est incorrect replace le pion sur sa position inital
								{
									lesPieces[i]->Position(Echiquier->GetCases(lesPieces[i]->getxi(), lesPieces[i]->getyi())->Rcase.x, Echiquier->GetCases(lesPieces[i]->getxi(), lesPieces[i]->getyi())->Rcase.y);

									lesPieces[i]->setpos();
									lesPieces[i]->setdepIncorrect(false);
								}


								for (int y2 = 0; y2 < 8; y2++)
								{
									for (int x2 = 0; x2 < 8; x2++)
									{
										Echiquier->GetCases(x2, y2)->setdisponible(false);

									}
								}
								Pointverts.clear();
								Syntaxe->getMots("tourJoueur")->Taille(300, 60);
								cout << "Tour de jeu : x=" << Syntaxe->getMots("tourJoueur")->getPos().x << " y=" << Syntaxe->getMots("tourJoueur")->getPos().y << " w=" << Syntaxe->getMots("tourJoueur")->getPos().w << " h=" << Syntaxe->getMots("tourJoueur")->getPos().h << endl;
							}
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

	background->Render();
	Echiquier->Render();

	Syntaxe->getMots("tourJoueur")->Render();

	for (int i = 0; i < 10; i++)
	{
		for (int i2 = 0; i2 <= Syntaxe->getChiffresSize(i); i2++)
		{
			Syntaxe->getChiffres(i,i2,false)->Render();
		}
	}
	
	Syntaxe->getMots("tour")->Render();
	Syntaxe->getMots("Noir")->Render();

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
