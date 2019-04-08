#include "jeu.h"

jeu *jeux = nullptr;

int main(int argc, char* argv[])
{

	jeux = new jeu();
	jeux->init("Jeu d'Echecs", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1280, 800, false);
	
	while (jeux->running()) 
	{
		jeux->handleEvents();
		jeux->update();
		jeux->render();

	}
	jeux->clean();

	return 0;
}