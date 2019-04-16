#pragma once
#include "GameObject.h"
#include <string>

using namespace std;

class SyntaxeHandler
{
public:

	SyntaxeHandler(SDL_Renderer* ren);

	void initasset();
	void initchiffres();
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
	/*donne la visibilité a un Chiffre
	visible: true = visible | false = non-visible*/
	void ChiffresVisibilite(int lechiffre,int i, bool visible);
	/*donne la visibilité a un mot
	visible: true = visible | false = non-visible
	
	!! --- LES MOTS --- !!

	"blanc"
	"noir"
	"tour"
	"tourJoueur"*/
	void MotsVisibilite(const char *lemot,bool visibile);
	GameObject* getChiffresjoueur(int leChiffre);
	void ChiffresjoueurVisibilite(int lechiffre, bool visible);

	~SyntaxeHandler();

private:

	SDL_Rect rect;

	int n[10] = { 0,0,0,0,0,0,0,0,0,0 };
	const char * texture;
	GameObject *Mots[4];
	GameObject *Chiffres[10][10];
	GameObject *Chiffresjoueur[2];

	SDL_Renderer *renderer;
};

