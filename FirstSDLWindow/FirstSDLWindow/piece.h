#pragma once
#include "GameObject.h"
#include "echiquier.h"

class piece: public GameObject
{
public:
	piece();
	piece(int Id,bool manger, bool Pdep,int Couleur,SDL_Rect nouvRect,int nx, int ny, const char * texturesheet, SDL_Renderer* ren);
	
	void setclicker(bool S);
	bool getClicker();

	void setrposI(SDL_Rect *nouvRect); // set le rectangle de la position inital sur le tableau

	void setposI(); // position inital sur le tableau
	void setpos(); // position dans le tableau

	SDL_Rect * getrI(); // renvois le rectengle initial

	void setid(int nid);
	int getid();

	int getcouleur();

	void setmanger(bool nManger);
	bool getmanger();

	int getx();// position x sur le tableau
	int gety();// position y sur le tableau
	void setx(int nx);// position x sur le tableau
	void sety(int ny);// position y sur le tableau

	int getxi();// position initiale x sur le tableau
	int getyi();// position initiale y sur le tableau
	void setxi(int nxi);// position initiale x sur le tableau
	void setyi(int nyi);// position initiale y sur le tableau

	void setpdep(bool i);
	bool getpdep();

	void setdepIncorrect(bool i);
	bool getdepIncorrect();

	void dispodeplace(echiquier *Echiquier);

	void haut(echiquier *Echiquier); // la Direction
	void bas(echiquier *Echiquier); // la Direction
	void gauche(echiquier *Echiquier); // la Direction
	void droite(echiquier *Echiquier); // la Direction

	void hautdroite(echiquier *Echiquier); // la Direction
	void basgauche(echiquier *Echiquier); // la Direction
	void hautgauche(echiquier *Echiquier); // la Direction
	void basdroite(echiquier *Echiquier); // la Direction

	bool deplacement(echiquier *Echiquier);

	~piece();

protected:
	int dx = 1; // a partir de quel x
	int dy = 1; // a partir de quel y

	int ixdep = 0; // jusqu'à combien en x?
	int iydep = 0; // jusqu'à combien en y?

	bool pdep;
	bool depIncorrect = false;

	int id;

	bool manger;

	int couleur; // 0 = rien 1 = blanc & 2 = noir

	bool clicker;

	int x; // position de la piece sur le tableau
	int y; // position de la piece sur le tableau

	int xi; // x initial
	int yi; // y initial

	SDL_Rect *rI;
};
