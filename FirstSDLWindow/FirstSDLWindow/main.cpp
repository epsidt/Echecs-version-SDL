#include "jeu.h"

jeu *jeux = nullptr;

int main(int argc, char* argv[])
{
	

	jeux = new jeu();
	jeux->init("Jeu d'Echecs", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1280, 800, false);
	SDL_Surface* cursorSurface = IMG_Load("texture/cursor.png");
	SDL_Cursor* cursor = SDL_CreateColorCursor(cursorSurface, 0, 0);
	SDL_SetCursor(cursor);

	while (jeux->running()) 
	{
		jeux->handleEvents();
		jeux->update();
		jeux->render();

	}
	jeux->clean();

	return 0;
}