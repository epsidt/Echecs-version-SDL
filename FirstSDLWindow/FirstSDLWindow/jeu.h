#pragma once
#include <Windows.h>
#include <SDL.h>
#include <iostream>
#include <SDL_image.h>
#include <vector>

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

	bool running();

private:
	echiquier *Echiquier;

	vector<GameObject*> Pointverts;

	piece* lesPieces[32];

	bool isRunning;
	SDL_Window *window;
	SDL_Renderer *renderer;
};

