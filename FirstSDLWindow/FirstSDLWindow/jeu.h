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

	//roque 
	void roque(int i);
	void verificationRoque(int i);
	bool running();
	//forcer la position dans une case
	void ForcerPosition(int i);
	//pointvert
	void AfficherPointvert(int i);
	//Compteur de tour
	void CompteurDeTour();
	//Prise en passant
	void MepPriseEnPassant(int i);
	void PriseEnPassant(int i, int ip);
	//Cannibalisme de piece
	void Cannibalisme(int i);
	void MangerPiece(int i, int ip);
	//Echec roi
	void DetectionEchecRoi(int i2);
	void setPieceProtectionRoi(int i2);
	void setPieceMenacente(int i2);

	int getnbProtecRoiB();
	void setnbProtecRoiB(int newnbProtecRoiB);

	int getnbProtecRoiN();
	void setnbProtecRoiN(int newnbProtecRoiN);

private:
	int nbProtecRoiB = 0; // nombre de pièce qui protège le rois
	int nbProtecRoiN = 0; // nombre de pièce qui protège le rois

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

