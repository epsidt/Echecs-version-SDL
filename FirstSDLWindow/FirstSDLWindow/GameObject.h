#pragma once
#include <SDL.h>
#include <iostream>
#include <SDL_image.h>
#include <vector>

class GameObject
{
public:
	GameObject();
	GameObject(const char * texturesheet, SDL_Renderer* ren);
	~GameObject();

	void Update();
	void Render();

	void Position(int x, int y);
	void Taille(int nW, int nH);
	static bool comparerPosition(SDL_Rect *r1, SDL_Rect *r2,int dif);

	SDL_Texture *getTexture();
	SDL_Rect getPos();


protected:

	SDL_Texture* objTexture;
	SDL_Rect srcR, posR;
	SDL_Renderer* renderer;
};

