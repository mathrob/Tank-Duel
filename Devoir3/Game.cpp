/*
 * Programmeur     : Mathieu Robson
 * Nom du projet   : Devoir3
 * Nom de la classe: Game.cpp
 * Date            : 2020-04-09
 * Description     : Deroulement de la partie
 */

#include "Game.h"
#include "Carte.h"
#include "Joueur.h"
#include "Template.h"
#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <Windows.h>

using std::cin;
using std::cout;
using std::endl;

// Initialisation des variables
Game::Game() {
	CarteDeJeu = { 0 };
	seed = 0;
	finDePartie = true;
	recommenceLaPartie = true;
	tourAuJoueurSuivant = true;
	mouvement[MAX-1] = 'w';
	nombreDeJoueurs = 2;
	de = 0;
	numeroDuJoueurTouche = 0;
	tourJoueur = 0;
}

// Deroulement de la partie
void Game::gamePlay() {

	do {
		recommenceLaPartie = true;

		// Grandeur minimale de la console
		HWND console = GetConsoleWindow();
		RECT r;
		GetWindowRect(console, &r);
		MoveWindow(console, r.left, r.top, 1000, 520, TRUE);

		Template t;

		int ajustementPositionX = 0;
		int ajustementPositionY = 0;

		// Image d'accueil du jeu
		t.imageAccueil();

		// Choisir le nombre de joueurs ( 2 a 4 joueurs)
		t.setNombreDeJoueurs(&nombreDeJoueurs);

		// Type de seed (manuelle ou automatique)
		t.setSeed(&seed);

		// Joueur peut voir les instructions de jeu avant de debuter
		t.demandeConsultationInstructions(nombreDeJoueurs);

		// Initialisation de la carte de jeu (10 X 10) selon le seed
		Carte c;
		c.setCarteDeJeu(10, 10, seed);
		CarteDeJeu = c.getCarteDeJeu();

		// Initialisation des joueurs
		Joueur j1;
		Joueur j2;
		Joueur j3;
		Joueur j4;

		// Initialisation du joueur 1 sur la carte de jeu
		j1.setPositionX(0);
		j1.setPositionY(0);
		j1.setNumeroDuJoueur(5);
		CarteDeJeu = j1.getPosition(CarteDeJeu);

		// Initialisation du joueur 2 sur la carte de jeu
		j2.setPositionX(9);
		j2.setPositionY(9);
		j2.setNumeroDuJoueur(6);
		CarteDeJeu = j2.getPosition(CarteDeJeu);

		// Si une partie a 3 joueurs ou 4 joueurs
		if (getNombreDeJoueurs() == 3 || getNombreDeJoueurs() == 4) {
			// Initialisation du joueur 3 sur la carte de jeu
			j3.setPositionX(9);
			j3.setPositionY(0);
			j3.setNumeroDuJoueur(7);
			CarteDeJeu = j3.getPosition(CarteDeJeu);

			// Si une partie a 4 joueurs
			if (getNombreDeJoueurs() == 4) {
				// Initialisation du joueur 4 sur la carte de jeu
				j4.setPositionX(0);
				j4.setPositionY(9);
				j4.setNumeroDuJoueur(8);
				CarteDeJeu = j4.getPosition(CarteDeJeu);
			}
		}

		// Determine quel joueur debute la partie
		// Dans une partie a 3 joueurs
		if (getNombreDeJoueurs() == 3) {
			de = rand() % 3 + 1;
		}

		// Dans une partie a 4 joueurs
		else if (getNombreDeJoueurs() == 4) {
			de = rand() % 4 + 1;
		}

		// Dans une partie a 2 joueurs
		else {
			de = rand() % 2 + 1;
		}

		// Debut de la partie
		do {
			finDePartie = true;

			// Tour au joueur 1
			while (de == 1) {

				// Validation que le joueur 1 est en vie
				// sinon passe au suivant
				if (j1.EstIlVivant()) {

					// + 4 AP pour le joueur 1
					j1.setNombreAP(0, 4);

					do {
						tourAuJoueurSuivant = true;
						system("CLS");

						// Affiche les informations aux joueurs
						t.AfficheConsoleInformative(j1.getNombreAP(), j2.getNombreAP(), j3.getNombreAP(),
							j4.getNombreAP(), j1.getNombreDeVies(), j2.getNombreDeVies(), j3.getNombreDeVies(), j4.getNombreDeVies(),
							seed, de, nombreDeJoueurs);

						// Variable d'ajustement de position reinitialisee
						ajustementPositionX = 0;
						ajustementPositionY = 0;

						// Affichage de la carte de jeu
						for (int y = 0; y < 30; y += 3) {
							for (int x = 0; x < 60; x += 6) {
								// Impression des tuiles selon son numero associe
								t.affichageDesTuiles(x, y, CarteDeJeu[(y - ajustementPositionY)][(x - ajustementPositionX)],
									j1.getDirectionJoueurPoint(), j2.getDirectionJoueurPoint(), j3.getDirectionJoueurPoint(),
									j4.getDirectionJoueurPoint());

								ajustementPositionX += 5;
							}

							if (ajustementPositionX > 10) {
								ajustementPositionX = 0;
							}
							ajustementPositionY += 2;
						}

						// Demande a l'utilisateur d'entrer une action
						t.position(63, 26);
						t.couleurTexteEtBackground(6, 0);
						cout << "Entrez votre action: ";
						cin >> mouvement;

						// Deplacement sur la carte de jeu du joueur 1
						CarteDeJeu = j1.deplacement(mouvement[0], CarteDeJeu);

						// Tir d'obus du joueur 1
						CarteDeJeu = j1.tir(mouvement[0], CarteDeJeu, &numeroDuJoueurTouche);

						// Determine si un joueur adverse est touche par l'obus du joueur 1
						// Si le joueur 2 est touche
						if (getNumeroDuJoueurTouche() == j2.getNumeroDuJoueur()) {
							j2.perteDeVie();
						}

						// Si le joueur 3 est touche
						else if (getNumeroDuJoueurTouche() == j3.getNumeroDuJoueur()) {
							j3.perteDeVie();
						}

						// Si le joueur 4 est touche
						else if (getNumeroDuJoueurTouche() == j4.getNumeroDuJoueur()) {
							j4.perteDeVie();
						}

						// Remise a 0 pour prochain tour
						numeroDuJoueurTouche = 0;

						// Si le joueur veut mettre fin a son tour prematurement
						if (mouvement[0] == 'n' || mouvement[0] == 'N') {
							tourAuJoueurSuivant = false;
						}

						// Instructions de jeu
						if (mouvement[0] == '?') {
							t.aide(nombreDeJoueurs);
						}

						// Determine un vainqueur
						declarerUnVainqueur(j1.EstIlVivant(), j2.EstIlVivant(),
							j3.EstIlVivant(), j4.EstIlVivant());

						// Valide si c'est le tour au prochain joueur
						if (j1.getNombreAP() <= 0) {
							tourAuJoueurSuivant = false;
						}
					}
					while (tourAuJoueurSuivant);
				}
				de++;
			}

			// Tour au joueur 2
			while (de == 2) {

				// Validation que le joueur 1 est en vie
				// sinon passe au suivant
				if (j2.EstIlVivant()) {

					// + 4 AP pour le joueur 2
					j2.setNombreAP(0, 4);

					do {
						tourAuJoueurSuivant = true;
						system("CLS");

						// Affiche les informations aux joueurs
						t.AfficheConsoleInformative(j1.getNombreAP(), j2.getNombreAP(), j3.getNombreAP(),
							j4.getNombreAP(), j1.getNombreDeVies(), j2.getNombreDeVies(), j3.getNombreDeVies(), j4.getNombreDeVies(),
							seed, de, nombreDeJoueurs);

						// Variable d'ajustement de position reinitialisee
						ajustementPositionX = 0;
						ajustementPositionY = 0;

						// Affichage de la carte de jeu
						for (int y = 0; y < 30; y += 3) {
							for (int x = 0; x < 60; x += 6) {
								// Impression des tuiles selon son numero associe
								t.affichageDesTuiles(x, y, CarteDeJeu[(y - ajustementPositionY)][(x - ajustementPositionX)], j1.getDirectionJoueurPoint(), j2.getDirectionJoueurPoint(), j3.getDirectionJoueurPoint(), j4.getDirectionJoueurPoint());
								ajustementPositionX += 5;
							}

							if (ajustementPositionX > 10) {
								ajustementPositionX = 0;
							}
							ajustementPositionY += 2;
						}

						// Demande a l'utilisateur d'entrer une action
						t.position(63, 26);
						t.couleurTexteEtBackground(6, 0);
						cout << "Entre votre action: ";
						cin >> mouvement;

						// Deplacement sur la carte de jeu du joueur 2
						CarteDeJeu = j2.deplacement(mouvement[0], CarteDeJeu);

						// Tir d'obus du joueur 2
						CarteDeJeu = j2.tir(mouvement[0], CarteDeJeu, &numeroDuJoueurTouche);

						// Determine si un joueur adverse est touche par l'obus du joueur 2
						// Si le joueur 1 est touche
						if (getNumeroDuJoueurTouche() == j1.getNumeroDuJoueur()) {
							j1.perteDeVie();
						}

						// Si le joueur 3 est touche
						else if (getNumeroDuJoueurTouche() == j3.getNumeroDuJoueur()) {
							j3.perteDeVie();
						}

						// Si le joueur 4 est touche
						else if (getNumeroDuJoueurTouche() == j4.getNumeroDuJoueur()) {
							j4.perteDeVie();
						}

						// Remise a 0 pour prochain tour
						numeroDuJoueurTouche = 0;

						// Si le joueur veut mettre fin a son tour prematurement
						if (mouvement[0] == 'n' || mouvement[0] == 'N') {
							tourAuJoueurSuivant = false;
						}

						// Instructions de jeu
						if (mouvement[0] == '?') {
							t.aide(nombreDeJoueurs);
						}

						// Determine un vainqueur
						declarerUnVainqueur(j1.EstIlVivant(), j2.EstIlVivant(),
							j3.EstIlVivant(), j4.EstIlVivant());

						// Valide si c'est le tour au prochain joueur
						if (j2.getNombreAP() <= 0) {
							tourAuJoueurSuivant = false;
						}
					}
					while (tourAuJoueurSuivant);
				}

				// si une partie a 3 ou 4 joueurs avance le de
				if (getNombreDeJoueurs() == 3 || getNombreDeJoueurs() == 4) {
					de++;
				}

				// sinon retourne au joueur 1
				else {
					de = 1;
				}
			}

			// Partie a trois joueurs
			if (getNombreDeJoueurs() >= 3) {

				// Tour au joueur 3
				while (de == 3) {

					// Validation que le joueur 3 est en vie
					// sinon passe au suivant
					if (j3.EstIlVivant()) {

						// + 4 AP pour le joueur 3
						j3.setNombreAP(0, 4);

						do {
							tourAuJoueurSuivant = true;
							system("CLS");

							// Affiche les informations aux joueurs
							t.AfficheConsoleInformative(j1.getNombreAP(), j2.getNombreAP(), j3.getNombreAP(),
								j4.getNombreAP(), j1.getNombreDeVies(), j2.getNombreDeVies(), j3.getNombreDeVies(), j4.getNombreDeVies(),
								seed, de, nombreDeJoueurs);

							// Variable d'ajustement de position reinitialisee
							ajustementPositionX = 0;
							ajustementPositionY = 0;

							// Affichage de la carte de jeu
							for (int y = 0; y < 30; y += 3) {
								for (int x = 0; x < 60; x += 6) {
									// Impression des tuiles selon son numero associe
									t.affichageDesTuiles(x, y, CarteDeJeu[(y - ajustementPositionY)][(x - ajustementPositionX)], j1.getDirectionJoueurPoint(), j2.getDirectionJoueurPoint(), j3.getDirectionJoueurPoint(), j4.getDirectionJoueurPoint());
									ajustementPositionX += 5;
								}
								if (ajustementPositionX > 10) {
									ajustementPositionX = 0;
								}
								ajustementPositionY += 2;
							}

							// Demande a l'utilisateur d'entrer une action
							t.position(63, 26);
							t.couleurTexteEtBackground(6, 0);
							cout << "Entre votre action: ";
							cin >> mouvement;

							// Deplacement sur la carte de jeu du joueur 3
							CarteDeJeu = j3.deplacement(mouvement[0], CarteDeJeu);

							// Tir d'obus du joueur 3
							CarteDeJeu = j3.tir(mouvement[0], CarteDeJeu, &numeroDuJoueurTouche);

							// Determine si un joueur adverse est touche par l'obus du joueur 3
							// Si le joueur 1 est touche
							if (getNumeroDuJoueurTouche() == j1.getNumeroDuJoueur()) {
								j1.perteDeVie();
							}

							// Si le joueur 2 est touche
							else if (getNumeroDuJoueurTouche() == j2.getNumeroDuJoueur()) {
								j2.perteDeVie();
							}

							// Si le joueur 4 est touche
							else if (getNumeroDuJoueurTouche() == j4.getNumeroDuJoueur()) {
								j4.perteDeVie();
							}

							// Remise a 0 pour prochain tour
							numeroDuJoueurTouche = 0;

							// Si le joueur veut mettre fin a son tour prematurement
							if (mouvement[0] == 'n' || mouvement[0] == 'N') {
								tourAuJoueurSuivant = false;
							}

							// Instructions de jeu
							if (mouvement[0] == '?') {
								t.aide(nombreDeJoueurs);
							}

							// Determine un vainqueur
							declarerUnVainqueur(j1.EstIlVivant(), j2.EstIlVivant(),
								j3.EstIlVivant(), j4.EstIlVivant());

							// Valide si c'est le tour au prochain joueur
							if (j3.getNombreAP() <= 0) {
								tourAuJoueurSuivant = false;
							}
						}
						while (tourAuJoueurSuivant);
					}

					// Si une partie a 4 joueurs avance le de
					if (getNombreDeJoueurs() == 4) {
						de++;
					}

					// sinon retourne au joueur 1
					else {
						de = 1;
					}
				}

				// Partie a 4 joueurs
				if (getNombreDeJoueurs() == 4) {

					// tour au joueur 4
					while (de == 4) {

						// valide joueur 4 est en vie
						if (j4.EstIlVivant()) {

							// + 4 AP pour le joueur 4
							j4.setNombreAP(0, 4);

							do {
								tourAuJoueurSuivant = true;
								system("CLS");

								// Affiche les informations aux joueurs
								t.AfficheConsoleInformative(j1.getNombreAP(), j2.getNombreAP(), j3.getNombreAP(),
									j4.getNombreAP(), j1.getNombreDeVies(), j2.getNombreDeVies(), j3.getNombreDeVies(), j4.getNombreDeVies(),
									seed, de, nombreDeJoueurs);

								// Variable d'ajustement de position reinitialisee
								ajustementPositionX = 0;
								ajustementPositionY = 0;

								// Affichage de la carte de jeu
								for (int y = 0; y < 30; y += 3) {
									for (int x = 0; x < 60; x += 6) {
										// Impression des tuiles selon son numero associe
										t.affichageDesTuiles(x, y, CarteDeJeu[(y - ajustementPositionY)][(x - ajustementPositionX)], j1.getDirectionJoueurPoint(), j2.getDirectionJoueurPoint(), j3.getDirectionJoueurPoint(), j4.getDirectionJoueurPoint());
										ajustementPositionX += 5;
									}
									if (ajustementPositionX > 10) {
										ajustementPositionX = 0;
									}
									ajustementPositionY += 2;
								}

								// Demande a l'utilisateur d'entrer une action
								t.position(63, 26);
								t.couleurTexteEtBackground(6, 0);
								cout << "Entre votre action: ";
								cin >> mouvement;

								// Deplacement sur la carte de jeu du joueur 4
								CarteDeJeu = j4.deplacement(mouvement[0], CarteDeJeu);

								// Tir d'obus du joueur 4
								CarteDeJeu = j4.tir(mouvement[0], CarteDeJeu, &numeroDuJoueurTouche);

								// Determine si un joueur adverse est touche par l'obus du joueur 1
								// Si le joueur 1 est touche
								if (getNumeroDuJoueurTouche() == j1.getNumeroDuJoueur()) {
									j1.perteDeVie();
								}

								// Si le joueur 2 est touche
								else if (getNumeroDuJoueurTouche() == j2.getNumeroDuJoueur()) {
									j2.perteDeVie();
								}

								// Si le joueur 3 est touche
								else if (getNumeroDuJoueurTouche() == j3.getNumeroDuJoueur()) {
									j3.perteDeVie();
								}

								// Remise a 0 pour prochain tour
								numeroDuJoueurTouche = 0;

								// Si le joueur veut mettre fin a son tour prematurement
								if (mouvement[0] == 'n' || mouvement[0] == 'N') {
									tourAuJoueurSuivant = false;
								}

								// Instructions de jeu
								if (mouvement[0] == '?') {
									t.aide(nombreDeJoueurs);
								}

								// Determine un vainqueur
								declarerUnVainqueur(j1.EstIlVivant(), j2.EstIlVivant(),
									j3.EstIlVivant(), j4.EstIlVivant());

								// Valide si c'est le tour au prochain joueur
								if (j4.getNombreAP() <= 0) {
									tourAuJoueurSuivant = false;
								}
							}
							while (tourAuJoueurSuivant);
						}
						// retour au joueur 1
						de = 1;
					}
				}
			}


		}
		while (finDePartie);
		system("CLS");
	}
	while (recommenceLaPartie);
	
}

// Declaration d'un vainqueur lors d'une partie
void Game::declarerUnVainqueur(bool j1Viviant, bool j2Viviant, bool j3Viviant, bool j4Viviant) {
	Template t;

	if (nombreDeJoueurs == 2) {
		j3Viviant = false;
		j4Viviant = false;
	}

	else if (nombreDeJoueurs == 3) {
		j4Viviant = false;
	}

	// S'il reste juste le joueur 1 en vie, il gagne
	if (j1Viviant == true && j2Viviant == false && j3Viviant == false && j4Viviant == false) {
		finDePartie = false;
		tourAuJoueurSuivant = false;
		system("CLS");
		t.finDePartie('1', &recommenceLaPartie);
	}

	// S'il reste juste le joueur 2 en vie, il gagne
	else if (j2Viviant == true && j1Viviant == false && j3Viviant == false && j4Viviant == false) {
		finDePartie = false;
		tourAuJoueurSuivant = false;
		system("CLS");
		t.finDePartie('2', &recommenceLaPartie);
	}

	// S'il reste juste le joueur 3 en vie, il gagne
	else if (j3Viviant == true && j1Viviant == false && j2Viviant == false && j4Viviant == false) {
		finDePartie = false;
		tourAuJoueurSuivant = false;
		system("CLS");
		t.finDePartie('3', &recommenceLaPartie);
	}

	// S'il reste juste le joueur 4 en vie, il gagne
	else if (j4Viviant == true && j1Viviant == false && j2Viviant == false && j3Viviant == false) {
		finDePartie = false;
		tourAuJoueurSuivant = false;
		system("CLS");
		t.finDePartie('4', &recommenceLaPartie);
	}
	
	
}

// Retourne le nombre de joueurs choisi par l'utilisateur
int Game::getNombreDeJoueurs() {
	return nombreDeJoueurs;
}

// Retourne le numero associe au joueur touche par un adversaire
int Game::getNumeroDuJoueurTouche(){
	return numeroDuJoueurTouche;
}

// Destructeur de la classe Game
Game::~Game(){}