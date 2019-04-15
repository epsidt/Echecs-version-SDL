#pragma once
#include "GameObject.h"
#include <string>

using namespace std;

class SyntaxeHandler
{
public:

	SyntaxeHandler(SDL_Renderer* ren);

	void initasset();
	/*

	!! --- LES MOTS --- !!

	"blanc"
	"noir"
	"tour"
	"tourJoueur"
	*/
	GameObject* getMots(const char *leMot);
	/*
	i = la valeur dans la case
	*/
	GameObject* getChiffres(int leChiffre,int i,bool unAutre);
	// de quel chiffre ?
	int getChiffresSize(int leChiffre);
	/*donne la visibilité a un Chiffres
	visible: true = visible | false = non-visible*/
	void ChiffresVisibilite(int lechiffre,int i, bool visible);
	~SyntaxeHandler();

private:

	SDL_Rect rect;

	int n[10] = { 0,0,0,0,0,0,0,0,0,0 };
	const char * texture;
	GameObject *Mots[4];
	GameObject *Chiffres[10][10];

	SDL_Renderer *renderer;
};

