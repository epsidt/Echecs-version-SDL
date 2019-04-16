#pragma once
#include <SDL.h>
#include <iostream>
#include <SDL_image.h>
#include <vector>
#include "SyntaxeHandler.h"

#include "GenerateurPiece.h"

#include "pion.h"
#include "tour.h"
#include "cavalier.h"
#include "fou.h"
#include "roi.h"
#include "reine.h"

#include "echiquier.h"

using namespace std;

class jeu
{
public:
	jeu();
	~jeu();

	void init(const char* titre, int xpos, int ypos,int largeur, int hauteur, bool fullscreen);

	void handleEvents();
	void update();
	void render();
	void clean();

	// roque
	void roque();

	bool running();

private:
	bool GrandRoque = false;
	bool PetitRoque = false;

	int jtour = 1; // tour de jeu

	echiquier *Echiquier;

	int iTDPiece = NULL; // id dans le tableau des pièces de la dernier pièce

	GameObject* background;
	SyntaxeHandler* Syntaxe;

	vector<GameObject*> Pointverts;

	piece* lesPieces[32];

	bool isRunning;
	SDL_Window *window;
	SDL_Renderer *renderer;
};

