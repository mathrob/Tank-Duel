/*
 * Programmeur     : Mathieu Robson
 * Nom du projet   : Devoir3
 * Nom de la classe: Carte.cpp
 * Date            : 2020-04-09
 * Description     : Initialisation de la carte de jeu
 */

#include "Carte.h"
#include <algorithm>

// Initialisation des variables
Carte::Carte() {
	sizeX = 0;
	sizeY = 0;

	carte = new int* [sizeY];

	for (int y = 0; y < sizeY; y++) {
		carte[y] = new int[sizeX];

		for (int x = 0; x < sizeX; x++) {
			carte[y][x] = 0;
		}
	}
}

// Initialise la carte de jeu
void Carte::setCarteDeJeu(const int szx,const int szy,const long seed) {
	sizeX = szx;
	sizeY = szy;
	srand(seed);

	carte = new int* [sizeY];

	// Creation de la carte de jeu vide "0"
	for (int y = 0; y < sizeY; y++) {
		carte[y] = new int[sizeX];

		for (int x = 0; x < sizeX; x++) {
			carte[y][x] = 0;
		}
	}

	// Initialisation de blocs aleatoirement selon le seed
	for (int i = 0; i < sizeY; i++) {
		for (int j = 0; j < sizeX; j++) {
		
			int	dice = rand() % 100 + 1;
			int random;
			
			if (dice > 1 && dice < 20) {
				random = 1;
			}

			else if (dice > 20 && dice < 40) {
				random = 3;
			}

			else {
				random = 0;
			}

			carte[i][j] = random;
		}
	}

	// bloc special
	int xAleatoire = rand() % 4 + 3;
	int yAleatoir = rand() % 4 + 3;
	carte[yAleatoir][xAleatoire] = 4;
}

// Retourne la carte de jeu
int** Carte::getCarteDeJeu() const{
	return carte;
}

// Destructeur de la classe Carte et le tableau carte
Carte::~Carte() {
	for (int y = 0; y < sizeY; y++) {
		delete[] carte[y];
	}
	delete[] carte;
	carte = 0;
}