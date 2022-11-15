/*
 * Programmeur     : Mathieu Robson
 * Nom du projet   : Devoir3
 * Nom de la classe: Carte.h
 * Date            : 2020-04-09
 * Description     : Initialisation de la carte de jeu
 */

#ifndef CARTE_H
#define CARTE_H

class Carte {
public:
	Carte();
	void setCarteDeJeu(const int, const int, const long);
	int** getCarteDeJeu() const;
	~Carte();
private:
	int** carte;
	int sizeX;
	int sizeY;
};

#endif