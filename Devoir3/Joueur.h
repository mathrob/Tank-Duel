/*
 * Programmeur     : Mathieu Robson
 * Nom du projet   : Devoir3
 * Nom de la classe: Joueur.h
 * Date            : 2020-04-09
 * Description     : Fonctionnalite du joueur
 */

#ifndef JOUEUR_H
#define JOUEUR_H


class Joueur {
public:
	Joueur();
	int getNombreDeVies() const;
	void perteDeVie();
	bool EstIlVivant();
	void setNumeroDuJoueur(const int);
	int getNumeroDuJoueur() const;
	void setNombreAP(const int, const int);
	int getNombreAP() const;
	int** deplacement(const int, int**);
	int getDirectionJoueurPoint();
	void setPositionX(const int);
	void setPositionY(const int);
	int** getPosition(int**)const;
	int** tir(const int, int**, int*);

	~Joueur();
private:
	int positionX;
	int positionY;
	int nombreDeAP;
	int vieRestante;
	int numeroDuJoueur;
	bool enVie;
	int directionJoueurPointe;
	int JoueurPointeHaut;
	int JoueurPointeBas;
	int JoueurPointeGauche;
	int JoueurPointeDroite;
};

#endif