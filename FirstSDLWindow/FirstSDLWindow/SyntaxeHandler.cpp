#include "SyntaxeHandler.h"



SyntaxeHandler::SyntaxeHandler(SDL_Renderer* ren)
{
	renderer = ren;
}

void SyntaxeHandler::initasset()
{
	for (int i = 0; i < 10; i++)
	{
		switch (i)
		{
		case 0:
			texture = "texture/Syntaxe/S0.png";
			break;
		case 1:
			texture = "texture/Syntaxe/S1.png";
			break;
		case 2:
			texture = "texture/Syntaxe/S2.png";
			break;
		case 3:
			texture = "texture/Syntaxe/S3.png";
			break;
		case 4:
			texture = "texture/Syntaxe/S4.png";
			break;
		case 5:
			texture = "texture/Syntaxe/S5.png";
			break;
		case 6:
			texture = "texture/Syntaxe/S6.png";
			break;
		case 7:
			texture = "texture/Syntaxe/S7.png";
			break;
		case 8:
			texture = "texture/Syntaxe/S8.png";
			break;
		case 9:
			texture = "texture/Syntaxe/S9.png";
			break;
		default:
			break;
		}
		Chiffres[i][n[i]] = new GameObject(texture, renderer);
		Chiffres[i][n[i]]->Taille(rect.w, rect.h);
	}
	
	for (int i = 0; i < 4; i++)
	{
		switch (i)
		{
		case 0:
			texture = "texture/Syntaxe/SBlanc.png";
			rect.w = 128;
			rect.h = 44;
			break;
		case 1:
			texture = "texture/Syntaxe/SNoir.png";
			rect.w = 96;
			rect.h = 53;
			break;
		case 2:
			texture = "texture/Syntaxe/Stour.png";
			rect.w = 75;
			rect.h = 45;
			break;
		case 3:
			texture = "texture/Syntaxe/STourDeJoueur.png";
			rect.w = 300;
			rect.h = 60;
			break;
		default:
			break;
		}
		Mots[i] = new GameObject(texture, renderer);
		Mots[i]->Taille(rect.w, rect.h);
	}
	
}


GameObject * SyntaxeHandler::getMots(const char* leMot)
{
	if (leMot == "blanc")
	{
		return Mots[0];
	}
	else if (leMot == "noir")
	{
		return Mots[1];
	}
	else if (leMot == "tour")
	{
		return Mots[2];
	}
	else if (leMot == "tourJoueur")
	{
		return Mots[3];
	}
	return Mots[1];
}

GameObject * SyntaxeHandler::getChiffres(int leChiffre,int i,bool unAutre)
{
	if (!unAutre)
	{
		return Chiffres[leChiffre][i];
	}
	else
	{
		switch (leChiffre)
		{
		case 0:
			texture = "texture/Syntaxe/S0.png";
			break;
		case 1:
			texture = "texture/Syntaxe/S1.png";
			break;
		case 2:
			texture = "texture/Syntaxe/S2.png";
			break;
		case 3:
			texture = "texture/Syntaxe/S3.png";
			break;
		case 4:
			texture = "texture/Syntaxe/S4.png";
			break;
		case 5:
			texture = "texture/Syntaxe/S5.png";
			break;
		case 6:
			texture = "texture/Syntaxe/S6.png";
			break;
		case 7:
			texture = "texture/Syntaxe/S7.png";
			break;
		case 8:
			texture = "texture/Syntaxe/S8.png";
			break;
		case 9:
			texture = "texture/Syntaxe/S9.png";
			break;
		default:
			break;

		}

		Chiffres[leChiffre][n[leChiffre]=i] = new GameObject(texture, renderer);
		Chiffres[leChiffre][n[leChiffre]]->Taille(rect.w, rect.h);
		return Chiffres[leChiffre][n[leChiffre]];
	}

}

int SyntaxeHandler::getChiffresSize(int leChiffre)
{
	return n[leChiffre];
}


void SyntaxeHandler::ChiffresVisibilite(int lechiffre,int i,bool visible)
{
	if (visible)
	{
		rect.h = 33;
		switch (lechiffre)
		{
		case 0:
			rect.w = 25;
			break;
		case 1:
			rect.w = 15;
			break;
		case 2:
			rect.w = 25;
			break;
		case 3:
			rect.w = 27;
			break;
		case 4:
			rect.w = 24;
			break;
		case 5:
			rect.w = 31;
			break;
		case 6:
			rect.w = 24;
			break;
		case 7:
			rect.w = 33;
			break;
		case 8:
			rect.w = 27;
			break;
		case 9:
			rect.w = 24;
			break;
		default:
			break;
		}
		Chiffres[lechiffre][i]->Taille(rect.w, rect.h);
	}
	else
	{
		rect.h = 0;
		switch (lechiffre)
		{
		case 0:
			rect.w = 0;
			break;
		case 1:
			rect.w = 0;
			break;
		case 2:
			rect.w = 0;
			break;
		case 3:
			rect.w = 0;
			break;
		case 4:
			rect.w = 0;
			break;
		case 5:
			rect.w = 0;
			break;
		case 6:
			rect.w = 0;
			break;
		case 7:
			rect.w = 0;
			break;
		case 8:
			rect.w = 0;
			break;
		case 9:
			rect.w = 0;
			break;
		default:
			break;
		}
		Chiffres[lechiffre][i]->Taille(rect.w, rect.h);
	}
	
}

SyntaxeHandler::~SyntaxeHandler()
{
}
