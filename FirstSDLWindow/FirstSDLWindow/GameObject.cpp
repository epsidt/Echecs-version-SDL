#include "GameObject.h"
#include "TextureManager.h"


GameObject::GameObject()
{
}

GameObject::GameObject(const char * texturesheet, SDL_Renderer * ren)
{
	renderer = ren;
	objTexture = TextureManager::loadTexture(texturesheet, ren);
}

GameObject::~GameObject()
{
}

void GameObject::Update()
{
}

void GameObject::Render()
{
	SDL_RenderCopy(renderer, objTexture, NULL, &posR);
}

void GameObject::Position(int x, int y)
{
	posR.x = x;
	posR.y = y;
}

void GameObject::Taille(int nW, int nH)
{
	posR.w = nW;
	posR.h = nH;
}

bool GameObject::comparerPosition(SDL_Rect *r1, SDL_Rect *r2,int dif)
{
	if (r1->x > r2->x - dif &&
		r1->x < r2->x + dif &&
		r1->y > r2->y - dif &&
		r1->y < r2->y + dif)
	{
		return true;
	}
	else 
	{
		return false;
	}
	
}

SDL_Texture * GameObject::getTexture()
{
	return objTexture;
}

SDL_Rect GameObject::getPos()
{
	return posR;
}



