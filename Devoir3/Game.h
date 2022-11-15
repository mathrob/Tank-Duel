/*
 * Programmeur     : Mathieu Robson
 * Nom du projet   : Devoir3
 * Nom de la classe: Game.h
 * Date            : 2020-04-09
 * Description     : Deroulement de la partie
 */

#ifndef GAME_H
#define GAME_H

const int MAX = 255;

class Game {
public:
	Game();
	int getNombreDeJoueurs();
	void gamePlay();
	void declarerUnVainqueur(bool, bool, bool, bool);
	int getNumeroDuJoueurTouche();
	~Game();
private:
	int** CarteDeJeu;
	unsigned long seed;
	bool finDePartie;
	bool recommenceLaPartie;
	bool tourAuJoueurSuivant;
	char mouvement[MAX];
	int nombreDeJoueurs;
	int de;
	int numeroDuJoueurTouche;
	int tourJoueur;
};

#endif