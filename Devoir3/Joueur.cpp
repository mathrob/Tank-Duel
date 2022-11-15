/*
 * Programmeur     : Mathieu Robson
 * Nom du projet   : Devoir3
 * Nom de la classe: Joueur.cpp
 * Date            : 2020-04-06
 * Description     : Fonctionnalite du joueur
 */

#include "Joueur.h"
#include "Game.h"
#include <iostream>

// Initialisation des variables
Joueur::Joueur() {
	enVie = true;
	vieRestante = 4;
	numeroDuJoueur = 5;
	nombreDeAP = 0;
	positionX = 0;
	positionY = 0;
	directionJoueurPointe = 5;
	JoueurPointeHaut = 5;
	JoueurPointeGauche = 6;
	JoueurPointeBas = 7;
	JoueurPointeDroite = 8;
}

// Retourne le nombre de vies du joueur
int Joueur::getNombreDeVies() const{
	return vieRestante;
}

// Retire une vie au joueur
void Joueur::perteDeVie(){
	vieRestante -= 1;
	if (vieRestante <= 0) {
		vieRestante = 0;
	}
}

// Retourne false si le joueur est mort
// Retourne True si le joueur est vivant
bool Joueur::EstIlVivant() {
	enVie = true;
	if (vieRestante == 0) {
		enVie = false;
	}
	return enVie;
}

// Initialise le numero du joueur
void Joueur::setNumeroDuJoueur(const int numDuJoueur){
	numeroDuJoueur = numDuJoueur;
}

// Retourne le numero du joueur
int Joueur::getNumeroDuJoueur() const {
	return numeroDuJoueur;
}

// Gere la perte ou le gain de AP du joueur
void Joueur::setNombreAP(const int moinsUnAP, const int plusUnAP) {
	nombreDeAP += plusUnAP;
	nombreDeAP -= moinsUnAP;

	if (nombreDeAP > 10) {
		nombreDeAP = 10;
	}
}

// Retourne le nombre de AP que le joueur possede
int Joueur::getNombreAP() const {
	return nombreDeAP;
}

// Initialise la position X du joueur sur la carte de jeu
void Joueur::setPositionX(const int px){
	positionX = px;
}

// Initialise la position Y du joueur sur la carte de jeu
void Joueur::setPositionY(const int py) {
	positionY = py;
}

// Retourne la position du joueur sur la carte de jeu
int** Joueur::getPosition(int** carte) const {
	carte[positionY][positionX] = getNumeroDuJoueur();
	
	return carte;
}

// Gere les deplacements faits par un joueur
int** Joueur::deplacement(const int mouvement, int** carte) {

	// Pivotement
	// Joueur pointe vers le bas
	if (mouvement == 's' || mouvement == 'S') {
		directionJoueurPointe = JoueurPointeBas;
		carte[positionY][positionX] = getNumeroDuJoueur();
	}

	// Joueur pointe vers le haut
	else if (mouvement == 'w' || mouvement == 'W') {
		directionJoueurPointe = JoueurPointeHaut;
		carte[positionY][positionX] = getNumeroDuJoueur();
	}

	// Joueur pointe vers la gauche
	else if (mouvement == 'a' || mouvement == 'A') {
		directionJoueurPointe = JoueurPointeGauche;
		carte[positionY][positionX] = getNumeroDuJoueur();
	}

	// Joueur pointe vers la droite
	else if (mouvement == 'd' || mouvement == 'D') {
		directionJoueurPointe = JoueurPointeDroite;
		carte[positionY][positionX] = getNumeroDuJoueur();
	}
	
	// Deplacement
	// Deplacement vers le bas
	if (mouvement == 'q' && getDirectionJoueurPoint() == JoueurPointeBas
			|| mouvement == 'Q' && getDirectionJoueurPoint() == JoueurPointeBas) {

		positionY++;

		// Restriction de mouvement
		if (positionY > 9 || carte[positionY][positionX] == 1 || carte[positionY][positionX] == 2
			|| carte[positionY][positionX] == 3 || carte[positionY][positionX] == 5
			|| carte[positionY][positionX] == 6 || carte[positionY][positionX] == 7
			|| carte[positionY][positionX] == 8) {

			positionY--;
			carte[positionY][positionX] = getNumeroDuJoueur();
		}
		// Mouvement
		else {
			// Si tuile speciale
			if (carte[positionY][positionX] == 4) {
				vieRestante += 4;
				if (vieRestante > 4) {
					vieRestante = 4;
				}
				nombreDeAP += 10;
			}

			carte[positionY - 1][positionX] = 0;
			carte[positionY][positionX] = getNumeroDuJoueur();
			// - 1 AP
			setNombreAP(1, 0);
		}
	}

	// Deplacement vers le haut
	if (mouvement == 'q' && getDirectionJoueurPoint() == 5
			|| mouvement == 'Q' && getDirectionJoueurPoint() == 5) {

		positionY--;

		// Restriction de mouvement 
		if (positionY < 0 || carte[positionY][positionX] == 1 || carte[positionY][positionX] == 2
			|| carte[positionY][positionX] == 3 || carte[positionY][positionX] == 5
			|| carte[positionY][positionX] == 6 || carte[positionY][positionX] == 7
			|| carte[positionY][positionX] == 8) {
			
			positionY++;
			carte[positionY][positionX] = getNumeroDuJoueur();
		}
		// Mouvement
		else {
			// Si tuile speciale
			if (carte[positionY][positionX] == 4) {
				vieRestante += 4;
				if (vieRestante > 4) {
					vieRestante = 4;
				}
				nombreDeAP += 10;
			}

			carte[positionY + 1][positionX] = 0;
			carte[positionY][positionX] = getNumeroDuJoueur();
			// - 1 AP
			setNombreAP(1, 0);
		}
	}

	// Deplacement vers la gauche
	if (mouvement == 'q' && getDirectionJoueurPoint() == 6
			|| mouvement == 'Q' && getDirectionJoueurPoint() == 6) {
		
		positionX--;

		// Restriction de mouvement
		if (positionX < 0 || carte[positionY][positionX] == 1 || carte[positionY][positionX] == 2
			|| carte[positionY][positionX] == 3 || carte[positionY][positionX] == 5
			|| carte[positionY][positionX] == 6 || carte[positionY][positionX] == 7
			|| carte[positionY][positionX] == 8) {
			
			positionX++;
			carte[positionY][positionX] = getNumeroDuJoueur();
		}
		// Mouvement
		else {
			// Si tuile speciale
			if (carte[positionY][positionX] == 4) {
				vieRestante += 4;
				if (vieRestante > 4) {
					vieRestante = 4;
				}
				nombreDeAP += 10;
			}

			carte[positionY][positionX + 1] = 0;
			carte[positionY][positionX] = getNumeroDuJoueur();
			// - 1 AP
			setNombreAP(1, 0);
		}
	}

	// Deplacement vers la droite
	if (mouvement == 'q' && getDirectionJoueurPoint() == 8
		|| mouvement == 'Q' && getDirectionJoueurPoint() == 8) {
		positionX++;

		// Restriction de mouvement
		if (positionX > 9 || carte[positionY][positionX] == 1 || carte[positionY][positionX] == 2
			|| carte[positionY][positionX] == 3 || carte[positionY][positionX] == 5
			|| carte[positionY][positionX] == 6 || carte[positionY][positionX] == 7
			|| carte[positionY][positionX] == 8) {

			positionX--;
			carte[positionY][positionX] = getNumeroDuJoueur();
		}
		// Mouvement
		else {
			// Si tuile speciale
			if (carte[positionY][positionX] == 4) {
				vieRestante += 4;
				if (vieRestante > 4) {
					vieRestante = 4;
				}
				nombreDeAP += 10;
			}

			carte[positionY][positionX - 1] = 0;
			carte[positionY][positionX] = getNumeroDuJoueur();
			// - 1 AP
			setNombreAP(1, 0);
		}
	}

	return carte;
}

// Retourne la direction pointee par le joueur
int Joueur::getDirectionJoueurPoint() {
	return directionJoueurPointe;
}

// Gere le systeme de tir du joueur
int** Joueur::tir(const int mouvement, int** carte, int *toucheUnAutreJoueur){

	// Tire vers le bas
	if (mouvement == 'e' && getDirectionJoueurPoint() == JoueurPointeBas
		|| mouvement == 'E' && getDirectionJoueurPoint() == JoueurPointeBas) {

		// -1 AP
		setNombreAP(1, 0);

		// Si un bloc est touche
		for (int i = (positionY + 1); i < 10; i++) {

			if (carte[i][positionX] == 1) {
				carte[i][positionX] = 0;
				break;
			}

			else if (carte[i][positionX] == 2) {
				carte[i][positionX] = 1;
				break;
			}

			else if (carte[i][positionX] == 3) {
				carte[i][positionX] = 2;
				break;
			}

			else if (carte[i][positionX] == 4) {
				carte[i][positionX] = 3;
				break;
			}

			// Si un joueur est touche
			else if (carte[i][positionX] == 5 ) {
				*toucheUnAutreJoueur = 5;
				break;
			}

			else if (carte[i][positionX] == 6) {
				*toucheUnAutreJoueur = 6;
				break;
			}

			else if (carte[i][positionX] == 7) {
				*toucheUnAutreJoueur = 7;
				break;
			}

			else if (carte[i][positionX] == 8) {
				*toucheUnAutreJoueur = 8;
				break;
			}
		}
	}

	// Tire vers le haut
	if (mouvement == 'e' && getDirectionJoueurPoint() == JoueurPointeHaut
		|| mouvement == 'E' && getDirectionJoueurPoint() == JoueurPointeHaut) {

		// -1 AP
		setNombreAP(1, 0);

		// Si un bloc est touche
		for (int i = (positionY - 1); i >= 0; i--) {

			if (carte[i][positionX] == 1) {
				carte[i][positionX] = 0;
				break;
			}

			else if (carte[i][positionX] == 2) {
				carte[i][positionX] = 1;
				break;
			}

			else if (carte[i][positionX] == 3) {
				carte[i][positionX] = 2;
				break;
			}

			else if (carte[i][positionX] == 4) {
				carte[i][positionX] = 3;
				break;
			}

			// Si un joueur est touche
			else if (carte[i][positionX] == 5) {
				*toucheUnAutreJoueur = 5;
				break;
			}

			else if (carte[i][positionX] == 6) {
				*toucheUnAutreJoueur = 6;
				break;
			}

			else if (carte[i][positionX] == 7) {
				*toucheUnAutreJoueur = 7;
				break;
			}

			else if (carte[i][positionX] == 8) {
				*toucheUnAutreJoueur = 8;
				break;
			}
		}
	}

	// Tire vers la gauche
	if (mouvement == 'e' && getDirectionJoueurPoint() == JoueurPointeGauche
		|| mouvement == 'E' && getDirectionJoueurPoint() == JoueurPointeGauche) {

		// -1 AP
		setNombreAP(1, 0);

		// Si un bloc est touche
		for (int i = (positionX - 1); i >= 0; i--) {

			if (carte[positionY][i] == 1) {
				carte[positionY][i] = 0;
				break;
			}

			else if (carte[positionY][i] == 2) {
				carte[positionY][i] = 1;
				break;
			}

			else if (carte[positionY][i] == 3) {
				carte[positionY][i] = 2;
				break;
			}

			else if (carte[positionY][i] == 4) {
				carte[positionY][i] = 3;
				break;
			}

			// Si un joueur est touche
			else if (carte[positionY][i] == 5) {
				*toucheUnAutreJoueur = 5;
				break;
			}

			else if (carte[positionY][i] == 6) {
				*toucheUnAutreJoueur = 6;
				break;
			}

			else if (carte[positionY][i] == 7) {
				*toucheUnAutreJoueur = 7;
				break;
			}

			else if (carte[positionY][i] == 8) {
				*toucheUnAutreJoueur = 8;
				break;
			}
		}
	}

	// Tire vers la droite
	if (mouvement == 'e' && getDirectionJoueurPoint() == JoueurPointeDroite
		|| mouvement == 'E' && getDirectionJoueurPoint() == JoueurPointeDroite) {
		
		// -1 AP
		setNombreAP(1, 0);

		// Si un bloc est touche
		for (int i = (positionX + 1); i < 10; i++) {

			if (carte[positionY][i] == 1) {
				carte[positionY][i] = 0;
				break;
			}

			else if (carte[positionY][i] == 2) {
				carte[positionY][i] = 1;
				break;
			}

			else if (carte[positionY][i] == 3) {
				carte[positionY][i] = 2;
				break;
			}

			else if (carte[positionY][i] == 4) {
				carte[positionY][i] = 3;
				break;
			}

			// Si un joueur est touche
			else if (carte[positionY][i] == 5) {
				*toucheUnAutreJoueur = 5;
				break;
			}

			else if (carte[positionY][i] == 6) {
				*toucheUnAutreJoueur = 6;
				break;
			}

			else if (carte[positionY][i] == 7) {
				*toucheUnAutreJoueur = 7;
				break;
			}

			else if (carte[positionY][i] == 8) {
				*toucheUnAutreJoueur = 8;
				break;
			}
		}
	}

	return carte;
}

// Destructeur de la classe Joueur
Joueur::~Joueur(){}