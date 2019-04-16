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

	//set la position inital par rapport a la réel position du pion sur le tableau
	void setposI(); 
	//set la position réel par rapport a la position inital du pion sur le tableau
	void setpos();

	SDL_Rect * getrI(); // renvois le rectengle initial

	void setid(int nid);
	int getid();
	// 0 = rien | 1 = blanc | 2 = noir
	int getcouleur();

	void setmanger(bool nManger);
	bool getmanger();

	// position x sur le tableau
	int getx();
	// position y sur le tableau
	int gety();
	// position x sur le tableau
	void setx(int nx);
	// position y sur le tableau
	void sety(int ny);

	// position initiale x sur le tableau
	int getxi();
	// position initiale y sur le tableau
	int getyi();
	// position initiale x sur le tableau
	void setxi(int nxi);
	// position initiale y sur le tableau
	void setyi(int nyi);

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

	void setposPPy(bool null);
	int getposPPy();

	void setposPPx(bool null);
	int getposPPx();

	void setConditiondep(int ndx, int ndy, int nixdep, int niydep);

	~piece();

protected:
	int dx = 1; // a partir de quel x
	int dy = 1; // a partir de quel y

	int ixdep = 0; // jusqu'à combien en x?
	int iydep = 0; // jusqu'à combien en y?

	bool pdep = 1; // premier deplacement (bool)
	bool depIncorrect = false;

	int id;

	bool manger;

	int couleur; // 0 = rien | 1 = blanc | 2 = noir

	bool clicker;

	int x; // position de la piece sur le tableau
	int y; // position de la piece sur le tableau

	int xi; // x initial
	int yi; // y initial

	int posPPy; // position y de la prise en passant
	int posPPx; // position y de la prise en passant

	SDL_Rect *rI;
};
