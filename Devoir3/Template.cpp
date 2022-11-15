/*
 * Programmeur     : Mathieu Robson
 * Nom du projet   : Devoir3
 * Nom de la classe: Template.cpp
 * Date            : 2020-04-09
 * Description     : Affichage graphique du jeu
 */

#include "Template.h"
#include "Game.h"
#include <iostream>
#include <Windows.h>
#include <time.h>

// Initialisation des variables
Template::Template(){
    Y = 0;
    X = 0;
	couleurJoueur1 = 5; // Mauve
	couleurJoueur2 = 10; // vert fluo
	couleurJoueur3 = 12; // rouge clair
	couleurJoueur4 = 1; // bleu fonce
	couleurBloc1 = 84265; // bleu quadrille
	couleurBloc2 = 84260; // rouge quadrille
	couleurBloc3 = 84264; // gris quadrille
	couleurBloc4 = 13;
	couleurCentreBloc123 = 15; // blanc
}

// Affiche l'image d'accueil du jeu
void Template::imageAccueil() {

	// Lettre T
	// Barre du haut
	for (short y = 7; y < 8; y++) {
		for (short x = 43; x < 51; x++) {
			position(x, y);
			couleurTexteEtBackground(0, 1);
			std::cout << " ";
		}
	}
	
	// Barre du milieu
	for (short y = 7; y < 12; y++) {
		for (short x = 46; x < 47; x++) {
			position(x, y);
			couleurTexteEtBackground(0, 1);
			std::cout << "  ";
		}
	}

	// Lettre A
	// Barre de gauche
	for (short y = 7; y < 12; y++) {
		for (short x = 52; x < 53; x++) {
			position(x, y);
			couleurTexteEtBackground(0, 1);
			std::cout << "  ";
		}
	}

	// Barre du haut
	for (short y = 7; y < 8; y++) {
		for (short x = 52; x < 60; x++) {
			position(x, y);
			couleurTexteEtBackground(0, 1);
			std::cout << " ";
		}
	}

	// Barre du centre
	for (short y = 9; y < 10; y++) {
		for (short x = 52; x < 60; x++) {
			position(x, y);
			couleurTexteEtBackground(0, 1);
			std::cout << " ";
		}
	}

	// Barre de droite
	for (short y = 7; y < 12; y++) {
		for (short x = 58; x < 59; x++) {
			position(x, y);
			couleurTexteEtBackground(0, 1);
			std::cout << "  ";
		}
	}

	// Lettre N
	// Barre de gauche
	for (short y = 7; y < 12; y++) {
		for (short x = 61; x < 62; x++) {
			position(x, y);
			couleurTexteEtBackground(0, 1);
			std::cout << "  ";
		}
	}

	// Barre du haut
	for (short y = 7; y < 8; y++) {
		for (short x = 61; x < 69; x++) {
			position(x, y);
			couleurTexteEtBackground(0, 1);
			std::cout << " ";
		}
	}

	// Barre de droite
	for (short y = 7; y < 12; y++) {
		for (short x = 67; x < 68; x++) {
			position(x, y);
			couleurTexteEtBackground(0, 4);
			std::cout << "  ";
		}
	}

	// Lettre K
	// Barre de gauche
	for (short y = 7; y < 12; y++) {
		for (short x = 70; x < 71; x++) {
			position(x, y);
			couleurTexteEtBackground(0, 4);
			std::cout << "  ";
		}
	}

	// Barre diagonale du haut (partie 1)
	for (short y = 7; y < 8; y++) {
		for (short x = 76; x < 77; x++) {
			position(x, y);
			couleurTexteEtBackground(0, 4);
			std::cout << "  ";
		}
	}

	// Barre diagonale du haut (partie 2)
	for (short y = 8; y < 9; y++) {
		for (short x = 74; x < 75; x++) {
			position(x, y);
			couleurTexteEtBackground(0, 4);
			std::cout << "  ";
		}
	}

	// Barre diagonale partie du centre
	for (short y = 9; y < 10; y++) {
		for (short x = 72; x < 73; x++) {
			position(x, y);
			couleurTexteEtBackground(0, 4);
			std::cout << "  ";
		}
	}

	// Barre diagonale du bas (partie 1)
	for (short y = 10; y < 11; y++) {
		for (short x = 74; x < 75; x++) {
			position(x, y);
			couleurTexteEtBackground(0, 4);
			std::cout << "  ";
		}
	}

	// Barre diagonale du bas (partie 2)
	for (short y = 11; y < 12; y++) {
		for (short x = 76; x < 77; x++) {
			position(x, y);
			couleurTexteEtBackground(0, 4);
			std::cout << "  ";
		}
	}

	// Lettre D
	// Barre de gauche
	for (short y = 13; y < 18; y++) {
		for (short x = 43; x < 44; x++) {
			position(x, y);
			couleurTexteEtBackground(0, 1);
			std::cout << "  ";
		}
	}

	// Barre du haut
	for (short y = 13; y < 14; y++) {
		for (short x = 43; x < 50; x++) {
			position(x, y);
			couleurTexteEtBackground(0, 1);
			std::cout << " ";
		}
	}

	// Barre du bas
	for (short y = 17; y < 18; y++) {
		for (short x = 43; x < 50; x++) {
			position(x, y);
			couleurTexteEtBackground(0, 1);
			std::cout << " ";
		}
	}

	// Barre de droite
	for (short y = 14; y < 17; y++) {
		for (short x = 49; x < 50; x++) {
			position(x, y);
			couleurTexteEtBackground(0, 1);
			std::cout << "  ";
		}
	}

	// Lettre U
	// Barre de gauche
	for (short y = 13; y < 18; y++) {
		for (short x = 52; x < 53; x++) {
			position(x, y);
			couleurTexteEtBackground(0, 1);
			std::cout << "  ";
		}
	}

	// Barre de droite
	for (short y = 13; y < 18; y++) {
		for (short x = 58; x < 59; x++) {
			position(x, y);
			couleurTexteEtBackground(0, 4);
			std::cout << "  ";
		}
	}

	// Barre du bas
	for (short y = 17; y < 18; y++) {
		for (short x = 54; x < 59; x++) {
			position(x, y);
			couleurTexteEtBackground(0, 4);
			std::cout << "  ";
		}
	}

	// Lettre E
	// Barre de gauche
	for (short y = 13; y < 18; y++) {
		for (short x = 61; x < 62; x++) {
			position(x, y);
			couleurTexteEtBackground(0, 4);
			std::cout << "  ";
		}
	}

	// Barre du haut
	for (short y = 13; y < 14; y++) {
		for (short x = 61; x < 69; x++) {
			position(x, y);
			couleurTexteEtBackground(0, 4);
			std::cout << " ";
		}
	}

	// Barre du centre
	for (short y = 15; y < 16; y++) {
		for (short x = 61; x < 69; x++) {
			position(x, y);
			couleurTexteEtBackground(0, 4);
			std::cout << " ";
		}
	}

	// Barre du bas
	for (short y = 17; y < 18; y++) {
		for (short x = 61; x < 69; x++) {
			position(x, y);
			couleurTexteEtBackground(0, 4);
			std::cout << " ";
		}
	}

	// Lettre L
	// Barre de gauche
	for (short y = 13; y < 18; y++) {
		for (short x = 70; x < 71; x++) {
			position(x, y);
			couleurTexteEtBackground(0, 4);
			std::cout << "  ";
		}
	}

	// Barre du bas
	for (short y = 17; y < 18; y++) {
		for (short x = 70; x < 78; x++) {
			position(x, y);
			couleurTexteEtBackground(0, 4);
			std::cout << " ";
		}
	}

	// Affichage "PRODUIT PAR MATHIEU ROBSON"
	for (short y = 19; y < 20; y++) {
		for (short x = 48; x < 49; x++) {
			position(x, y);
			couleurTexteEtBackground(6, 0);
			std::cout << "PRODUIT PAR MATHIEU ROBSON";
		}
	}

	position(43, 21);
	system("pause");
}

// Initialise le nombre de joueurs dans la partie selon l'utilisateur
void Template::setNombreDeJoueurs(int* nombreDeJoueursDansLaPartie) {
	do {
		system("CLS");

		// Encadre bleu
		// Cote gauche
		for (short y = 10; y < 20; y++) {
			for (short x = 42; x < 43; x++) {
				position(x, y);
				couleurTexteEtBackground(0, 1);
				std::cout << " ";
			}
		}

		// Cote droit
		for (short y = 10; y < 20; y++) {
			for (short x = 78; x < 79; x++) {
				position(x, y);
				couleurTexteEtBackground(0, 1);
				std::cout << " ";
			}
		}

		// Cote du haut
		for (short y = 10; y < 11; y++) {
			for (short x = 42; x < 78; x++) {
				position(x, y);
				couleurTexteEtBackground(0, 1);
				std::cout << " ";
			}
		}

		// Cote du bas
		for (short y = 19; y < 20; y++) {
			for (short x = 42; x < 78; x++) {
				position(x, y);
				couleurTexteEtBackground(0, 1);
				std::cout << " ";
			}
		}

		position(44, 12);
		couleurTexteEtBackground(6, 0);
		std::cout << "Nombre de joueurs dans la partie: \n";
		position(44, 13);
		std::cout << " #2 = 2 joueurs\n";
		position(44, 14);
		std::cout << " #3 = 3 joueurs\n";
		position(44, 15);
		std::cout << " #4 = 4 joueurs\n";
		position(44, 17);

		if (*nombreDeJoueursDansLaPartie < 2) {
			position(43, 16);
			couleurTexteEtBackground(4, 0);
			std::cout << "DSL! Vous devez vous faire des amis";
		}

		else if (*nombreDeJoueursDansLaPartie > 4) {
			position(44, 16);
			couleurTexteEtBackground(4, 0);
			std::cout << "Euh, Tu exageres la!!";
		}

		position(44, 17);
		couleurTexteEtBackground(6, 0);
		std::cout << "Entrez votre Choix: ";
		std::cin >> *nombreDeJoueursDansLaPartie;

	} while (!(*nombreDeJoueursDansLaPartie == 2 || *nombreDeJoueursDansLaPartie == 3
		|| *nombreDeJoueursDansLaPartie == 4));
	
	system("CLS");
}

// Initialise le seed (automatique ou manuelle) selon l'utilisateur
void Template::setSeed(unsigned long *seed) {
	int sc = 1;

	do {
		system("CLS");

		// Encadre bleu 
		// Barre de gauche
		for (short y = 10; y < 19; y++) {
			for (short x = 42; x < 43; x++) {
				position(x, y);
				couleurTexteEtBackground(0, 1);
				std::cout << " ";
			}
		}

		// Barre de droite
		for (short y = 10; y < 19; y++) {
			for (short x = 77; x < 78; x++) {
				position(x, y);
				couleurTexteEtBackground(0, 1);
				std::cout << " ";
			}
		}

		// Barre du haut
		for (short y = 10; y < 11; y++) {
			for (short x = 42; x < 77; x++) {
				position(x, y);
				couleurTexteEtBackground(0, 1);
				std::cout << " ";
			}
		}

		// Barre du bas
		for (short y = 18; y < 19; y++) {
			for (short x = 42; x < 77; x++) {
				position(x, y);
				couleurTexteEtBackground(0, 1);
				std::cout << " ";
			}
		}

		position(44, 12);
		couleurTexteEtBackground(6, 0);
		std::cout << "Type de seed : \n";
		position(44, 13);
		std::cout << " #1 automatique\n";
		position(44, 14);
		std::cout << " #2 personnalise\n";

		if (sc < 1 || sc > 2) {
			couleurTexteEtBackground(4, 0);
			position(44, 15);
			std::cout << "Erreur: " << sc << " n'est pas une option";
		}

		couleurTexteEtBackground(6, 0);
		position(44, 16);
		std::cout << "Entrez votre Choix: ";
		std::cin >> sc;

	} while (!(sc == 1 || sc == 2));
	
	if (sc == 1) {
		srand(time(0));
		*seed = rand();
	}

	else {
		// Encadre bleu pour l'entree du seed
		// Barre de gauche
		for (short y = 19; y < 23; y++) {
			for (short x = 42; x < 43; x++) {
				position(x, y);
				couleurTexteEtBackground(0, 1);
				std::cout << " ";
			}
		}

		// Barre de droite
		for (short y = 19; y < 23; y++) {
			for (short x = 77; x < 78; x++) {
				position(x, y);
				couleurTexteEtBackground(0, 1);
				std::cout << " ";
			}
		}

		// Barre du bas
		for (short y = 22; y < 23; y++) {
			for (short x = 42; x < 77; x++) {
				position(x, y);
				couleurTexteEtBackground(0, 1);
				std::cout << " ";
			}
		}

		position(44, 20);
		couleurTexteEtBackground(6, 0);
		std::cout << "Entrez votre seed: ";
		std::cin >> *seed;
	}

	system("CLS");
}

// Affiche a l'utilisateur s'il veut consulter les instructions de jeu
void Template::demandeConsultationInstructions(int nombreDeJoueurs) {
	const int MAX = 255;
	char instructions[MAX] = { 'O' };

	do {
		// Encadre bleu
		// Barre du haut
		for (short y = 10; y < 11; y++) {
			for (short x = 38; x < 83; x++) {
				position(x, y);
				couleurTexteEtBackground(0, 1);
				std::cout << " ";
			}
		}

		// Barre du bas
		for (short y = 18; y < 19; y++) {
			for (short x = 38; x < 83; x++) {
				position(x, y);
				couleurTexteEtBackground(0, 1);
				std::cout << " ";
			}
		}

		// Barre de gauche
		for (short y = 10; y < 19; y++) {
			for (short x = 38; x < 39; x++) {
				position(x, y);
				couleurTexteEtBackground(0, 1);
				std::cout << " ";
			}
		}

		// Barre de droite
		for (short y = 10; y < 19; y++) {
			for (short x = 83; x < 84; x++) {
				position(x, y);
				couleurTexteEtBackground(0, 1);
				std::cout << " ";
			}
		}

		position(40, 12);
		couleurTexteEtBackground(6, 0);
		std::cout << "Desirez-vous voir les instructions de jeu?";
		position(43, 13);
		std::cout << "O = Oui";
		position(43, 14);
		std::cout << "N = Non";

		if (!(instructions[0] == 'o' || instructions[0] == 'O'
			|| instructions[0] == 'n' || instructions[0] == 'N')) {
			position(40, 15);
			couleurTexteEtBackground(4, 0);
			std::cout << "Erreur: " << instructions[0] << " n'est pas une option";
		}

		position(40, 16);
		couleurTexteEtBackground(6, 0);
		std::cout << "Entrez votre Choix: ";
		std::cin >> instructions;

	}
	while (!(instructions[0] == 'o' || instructions[0] == 'O'
		|| instructions[0] == 'n' || instructions[0] == 'N'));

	if (instructions[0] == 'o' || instructions[0] == 'O') {
		aide(nombreDeJoueurs);
	}
}

// Affiche les instructions de jeu
void Template::aide(int nombreDeJoueurs) {
	system("CLS");

	// Section informative sur l'objectif du jeu
	position(1, 1);
	couleurTexteEtBackground(4, 0);
	std::cout << "But du jeu:";
	couleurTexteEtBackground(6, 0);
	std::cout << "\n Detruire vos adversaires, le dernier survivant sera declare vainqueur de Tank Duel!";

	// Section informative sur les blocs
	position(1, 4);
	couleurTexteEtBackground(4, 0);
	std::cout << "Instructions a propos des blocs:";

	// Bloc de solidite 1
	// Contour de la tuile
	for (short y = 6; y < 9; y++) {
		for (short x = 1; x < 7; x++) {
			position(x, y);
			couleurTexteEtBackground(0, couleurBloc1);
			std::cout << " ";
		}
	}

	position(3, 7);
	couleurTexteEtBackground(0, couleurCentreBloc123);
	std::cout << " 1";

	// Bloc de solidite 2
	// Contour de la tuile
	for (short y = 6; y < 9; y++) {
		for (short x = 8; x < 14; x++) {
			position(x, y);
			couleurTexteEtBackground(0, couleurBloc2);
			std::cout << " ";
		}
	}

	position(10, 7);
	couleurTexteEtBackground(0, couleurCentreBloc123);
	std::cout << " 2";

	// Bloc de solidite 3
	// Contour de la tuile
	for (short y = 6; y < 9; y++) {
		for (short x = 15; x < 21; x++) {
			position(x, y);
			couleurTexteEtBackground(0, couleurBloc3);
			std::cout << " ";
		}
	}

	position(17, 7);
	couleurTexteEtBackground(0, couleurCentreBloc123);
	std::cout << " 3";

	position(1, 10);
	couleurTexteEtBackground(6, 0);
	std::cout << "Nous retrouvons sur la carte de jeu trois solidites de bloc differentes" <<
		"\n soit 1, 2 et 3. Cela represente le nombre d'obus nessessaire pour les detruire.";

	// Bloc special
	// Contour de la tuile
	for (short y = 13; y < 16; y++) {
		for (short x = 1; x < 7; x++) {
			position(x, y);
			couleurTexteEtBackground(0, couleurBloc4);
			std::cout << " ";
		}
	}

	position(1, 17);
	couleurTexteEtBackground(6, 0);
	std::cout << "Il s'agit d'un bloc special qui remplit les vies et le nombre d'actions" <<
		"\n du joueur qui le touche. Ce bloc peut etre detruit s'il est touche par un obus.";

	position(1, 28);
	couleurTexteEtBackground(4, 0);
	system("PAUSE");
	system("CLS");

	// Section informative des joueurs
	position(1, 0);
	couleurTexteEtBackground(4, 0);
	std::cout << "Instructions a propos des joueurs: " <<
		"\n\n Apparence des joueurs: ";

	//Joueur 1
	for (short y = 4; y < 5; y++) {
		for (short x = 1; x < 3; x++) {
			position(x, y);
			couleurTexteEtBackground(0, couleurJoueur1);
			std::cout << " ";
		}
	}

	position(4, 4);
	couleurTexteEtBackground(6, 0);
	std::cout << "= Joueur 1";

	// Joueur 2
	for (short y = 4; y < 5; y++) {
		for (short x = 15; x < 17; x++) {
			position(x, y);
			couleurTexteEtBackground(0, couleurJoueur2);
			std::cout << " ";
		}
	}

	position(18, 4);
	couleurTexteEtBackground(6, 0);
	std::cout << "= Joueur 2";

	if (nombreDeJoueurs == 3 || nombreDeJoueurs == 4) {
		// Joueur 3
		for (short y = 4; y < 5; y++) {
			for (short x = 29; x < 31; x++) {
				position(x, y);
				couleurTexteEtBackground(0, couleurJoueur3);
				std::cout << " ";
			}
		}

		position(32, 4);
		couleurTexteEtBackground(6, 0);
		std::cout << "= Joueur 3";

		if (nombreDeJoueurs == 4) {
			// Joueur 4
			for (short y = 4; y < 5; y++) {
				for (short x = 43; x < 45; x++) {
					position(x, y);
					couleurTexteEtBackground(0, couleurJoueur4);
					std::cout << " ";
				}
			}

			position(46, 4);
			couleurTexteEtBackground(6, 0);
			std::cout << "= Joueur 4";
		}
	}

	// Section informative sur l'orientation des joueurs
	position(1, 6);
	couleurTexteEtBackground(4, 0);
	std::cout << "Orientation des joueurs:";

	position(1, 8);
	couleurTexteEtBackground(6, 0);
	std::cout << "Il ne coute pas d'action (AP) pour orienter le joueur.";

	position(1, 10);
	couleurTexteEtBackground(0, couleurJoueur2);
	std::cout << " >";

	position(3, 10);
	couleurTexteEtBackground(6, 0);
	std::cout << " = Appuyer -> D + Enter afin d'orienter le joueur vers la droite";

	position(1, 12);
	couleurTexteEtBackground(0, couleurJoueur2);
	std::cout << "< ";

	position(3, 12);
	couleurTexteEtBackground(6, 0);
	std::cout << " = Appuyer -> A + Enter afin d'orienter le joueur vers la gauche";

	position(1, 14);
	couleurTexteEtBackground(0, couleurJoueur2);
	std::cout << "/\\";

	position(3, 14);
	couleurTexteEtBackground(6, 0);
	std::cout << " = Appuyer -> W + Enter afin d'orienter le joueur vers le haut";

	position(1, 16);
	couleurTexteEtBackground(0, couleurJoueur2);
	std::cout << "\\/";

	position(3, 16);
	couleurTexteEtBackground(6, 0);
	std::cout << " = Appuyer -> S + Enter afin d'orienter le joueur vers le bas";

	// Section informative sur les vies
	position(1, 18);
	couleurTexteEtBackground(4, 0);
	std::cout << "Vie:";
	couleurTexteEtBackground(6, 0);
	std::cout << "\n Les joueurs debutent la partie avec 4 vies." <<
		"\n Lorsque touche par un obus adverse, le joueur perd une vie.";

	// Section informative sur les AP
	position(1, 22);
	couleurTexteEtBackground(4, 0);
	std::cout << "Points d'action (AP):";
	couleurTexteEtBackground(6, 0);
	std::cout << "\n Les AP representent le nombre d'actions possibles dont un joueur dispose pour son tour." <<
		"\n A tous les debuts de ronde, le joueur actif recoit 4 AP." <<
		"\n Il est possible d'accumuler un maximum de 10 AP." <<
		"\n Les AP peuvent servir a se deplacer ou a tirer des obus.";

	couleurTexteEtBackground(4, 0);
	position(1, 29);
	system("PAUSE");
	system("CLS");

	// Section informative sur l'option de mettre fin a son tour
	position(1, 1);
	couleurTexteEtBackground(4, 0);
	std::cout << "Mettre fin a son tour:";
	couleurTexteEtBackground(6, 0);
	std::cout << "\n Un joueur actif peut mettre fin a sont tour prematurement et" <<
		"\n accumuler ses AP restants en appuyant sur N + Enter." <<
		"\n Le tour du joueur actif prendra fin immediatement.";

	// Section informative sur les deplacements
	position(1, 6);
	couleurTexteEtBackground(4, 0);
	std::cout << "Deplacement:";
	couleurTexteEtBackground(6, 0);
	std::cout << "\n Pour se deplacer, appuyer sur Q + Enter." <<
		"\n Le joueur se deplacera dans la direction qu'il pointe.";

	// Section informative sur les tirs d'obus
	position(1, 10);
	couleurTexteEtBackground(4, 0);
	std::cout << "Tir d'obus:";
	couleurTexteEtBackground(6, 0);
	std::cout << "\n Pour tirer, appuyer sur E + Enter." <<
		"\n Le joueur tirera dans la direction qu'il pointe.";

	couleurTexteEtBackground(4, 0);
	position(1, 28);
	system("pause");
}

// Positionnement du curseur dans la console
void Template::position(short x, short y) {
    COORD position = { x , y };
    HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(console, position);
}

// Initialise la couleur du texte et du backgound de la console
void Template::couleurTexteEtBackground(int couleurTexte, int couleurBackground) {
    HANDLE H = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(H, couleurBackground * 16 + couleurTexte);
}

// Affiche les tuiles dans la console selon le numero associe
void Template::affichageDesTuiles(int X, int Y, int numeroDuBloc, int directionPointeJoueur1,
		int directionPointeJoueur2, int directionPointeJoueur3, int directionPointeJoueur4) {

    int backgroundContour = 0;
    int backgroundCentre = 0;
    int couleurTexte = 0;
	int direction = 0;

	// Espace vide sur la carte de jeu
    if (numeroDuBloc == 0) {
        backgroundContour = 0;
        backgroundCentre = 0;
    }

	// Bloc de solidite 1
    else if (numeroDuBloc == 1) {
        backgroundContour = couleurBloc1;
        backgroundCentre = couleurCentreBloc123;
    }

	// Bloc de solidite 2
    else if (numeroDuBloc == 2) {
        backgroundContour = couleurBloc2;
        backgroundCentre = couleurCentreBloc123;
    }

	// Bloc de solidite 3
    else if (numeroDuBloc == 3) {
        backgroundContour = couleurBloc3;
        backgroundCentre = couleurCentreBloc123;
    }

	// Bloc special
	else if (numeroDuBloc == 4) {
		backgroundContour = couleurBloc4;
		backgroundCentre = 13;
		couleurTexte = 13;
	}

	// Bloc du Joueur 1
	else if (numeroDuBloc == 5) {
		backgroundContour = 0;
		backgroundCentre = couleurJoueur1;
		direction = directionPointeJoueur1;
	}

	// Bloc du Joueur 2
	else if (numeroDuBloc == 6) {
		backgroundContour = 0;
		backgroundCentre = couleurJoueur2;
		direction = directionPointeJoueur2;
	}

	// Bloc du Joueur 3
	else if (numeroDuBloc == 7) {
		backgroundContour = 0;
		backgroundCentre = couleurJoueur3;
		direction = directionPointeJoueur3;
	}

	// Bloc du Joueur 4
	else if (numeroDuBloc == 8) {
		backgroundContour = 0;
		backgroundCentre = couleurJoueur4;
		direction = directionPointeJoueur4;
	}

	// Contour de la tuile
    for (short y = (0 + Y); y < (3 + Y); y++) {
        for (short x = (0 + X); x < (6 + X); x++) {
            position(x, y);
            couleurTexteEtBackground(couleurTexte, backgroundContour);
            std::cout << " ";
        }
    }

	// Centre gauche de la tuile + direction du joueur
    for (short y = (1 + Y); y < (2 + Y); y++) {
        for (short x = (2 + X); x < (3 + X); x++) {
            position(x, y);
            couleurTexteEtBackground(couleurTexte, backgroundCentre);
			if (direction == 5) {
				std::cout << "/";
			}

			else if (direction == 6) {
				std::cout << "<";
			}

			else if (direction == 7) {
				std::cout << "\\";
			}

			else {
				std::cout << " ";
			}
        }
    }

	// Centre droit + chiffre de la tuile ou direction du joueur 
    for (short y = (1 + Y); y < (2 + Y); y++) {
        for (short x = (3 + X); x < (4 + X); x++) {
            position(x, y);
            couleurTexteEtBackground(couleurTexte, backgroundCentre);
			if (direction == 5) {
				std::cout << "\\";
			}

			else if (direction == 6) {
				std::cout << " ";
			}

			else if (direction == 7) {
				std::cout << "/";
			}

			else if (direction == 8) {
				std::cout << ">";
			}

			else {
				std::cout << numeroDuBloc;
			}
        }
    }
}

// Affiche la barre de vie d'un joueur
void Template::barreDeVie(int vie, int y, int AP, char numeroDeJoueur, int couleurJ){

	// Joueur + numeroDeJoueur :
	position(65, y);
	couleurTexteEtBackground(6, 0);
	std::cout << "Joueur " << numeroDeJoueur << ":";

	// Couleur du joueur
	position(62, y);
	couleurTexteEtBackground(0, couleurJ);
	std::cout << "  ";

	// AP:
	position(109, y);
	couleurTexteEtBackground(6, 0);
	std::cout << "AP: " << AP << "/10";

	// Barre de vie (Pleine)
	if (vie == 4) {
		position(74, y);
		couleurTexteEtBackground(0, 2);
		std::cout << "                                ";

	}

	// Barre de vie (moins une vie)
	else if (vie == 3) {
		position(74, y);
		couleurTexteEtBackground(0, 2);
		std::cout << "                        ";
		position(98, y);
		couleurTexteEtBackground(0, 12);
		std::cout << "        ";
	}

	// Barre de vie (moins deux vies)
	else if (vie == 2) {
		position(74, y); 
		couleurTexteEtBackground(0, 2);
		std::cout << "                ";
		position(90, y);
		couleurTexteEtBackground(0, 12);
		std::cout << "                ";
	}

	// Barre de vie (moins trois vies)
	else if (vie == 1) {
		position(74, y);
		couleurTexteEtBackground(0, 2);
		std::cout << "        ";
		position(82, y);
		couleurTexteEtBackground(0, 12);
		std::cout << "                        ";
	}

	// Barre de vie (joueur mort)
	else if (vie == 0) {
		position(74, y);
		couleurTexteEtBackground(0, 12);
		std::cout << "    MORT AU CHAMP D'HONNEUR!    ";
	}
}

// Affiche le tableau informatif de droite dans la console
void Template::AfficheConsoleInformative(int APJ1, int APJ2, int APJ3, int APJ4,
	int vieJ1, int vieJ2, int vieJ3, int vieJ4, long seed, int de, int nombreDeJoueurs) {

	int couleurDuJoueur = 0;
	int couleurTexte = 0;
	char numeroDeJoueur = 0;

	// Affichage du menu de droite dans la partie
	// Barre de gauche
	for (short y = 0; y < 30; y++) {
		for (short x = 60; x < 61; x++) {
			position(x, y);
			couleurTexteEtBackground(0, 3);
			std::cout << "  ";
		}
	}

	// Barre de droite
	for (short y = 0; y < 30; y++) {
		for (short x = 118; x < 119; x++) {
			position(x, y);
			couleurTexteEtBackground(0, 3);
			std::cout << "  ";
		}
	}

	// Barre du haut
	for (short y = 0; y < 1; y++) {
		for (short x = 60; x < 120; x++) {
			position(x, y);
			couleurTexteEtBackground(0, 3);
			std::cout << " ";
		}
	}

	// Barre du bas
	for (short y = 29; y < 30; y++) {
		for (short x = 60; x < 120; x++) {
			position(x, y);
			couleurTexteEtBackground(0, 3);
			std::cout << " ";
		}
	}

	// Barre du bas (info du joueur 1)
	for (short y = 4; y < 5; y++) {
		for (short x = 60; x < 120; x++) {
			position(x, y);
			couleurTexteEtBackground(0, 3);
			std::cout << " ";
		}
	}

	// Barre du bas (info du joueur 2)
	for (short y = 8; y < 9; y++) {
		for (short x = 60; x < 120; x++) {
			position(x, y);
			couleurTexteEtBackground(0, 3);
			std::cout << " ";
		}
	}

	// Barre du bas (info du joueur 3)
	for (short y = 12; y < 13; y++) {
		for (short x = 60; x < 120; x++) {
			position(x, y);
			couleurTexteEtBackground(0, 3);
			std::cout << " ";
		}
	}

	// Barre du bas (info du joueur 4)
	for (short y = 16; y < 17; y++) {
		for (short x = 60; x < 120; x++) {
			position(x, y);
			couleurTexteEtBackground(0, 3);
			std::cout << " ";
		}
	}

	// Barre de separation vie / AP
	for (short y = 0; y < 17; y++) {
		for (short x = 107; x < 108; x++) {
			position(x, y);
			couleurTexteEtBackground(0, 3);
			std::cout << " ";
		}
	}

	// Tour du joueur 1
	if (de == 1) {
		couleurDuJoueur = couleurJoueur1;
		numeroDeJoueur = '1';
		couleurTexte = 15;
	}

	// Tour du joueur 2
	else if (de == 2) {
		couleurDuJoueur = couleurJoueur2;
		numeroDeJoueur = '2';
		couleurTexte = 15;
	}

	// Tour du joueur 3
	else if (de == 3) {
		couleurDuJoueur = couleurJoueur3;
		numeroDeJoueur = '3';
		couleurTexte = 15;
	}

	// Tour du joueur 4
	else if (de == 4) {
		couleurDuJoueur = couleurJoueur4;
		numeroDeJoueur = '4';
		couleurTexte = 15;
	}

	// Affiche a qui le tour
	for (short y = 21; y < 24; y++) {
		for (short x = 96; x < 116; x++) {
			position(x, y);
			couleurTexteEtBackground(0, couleurDuJoueur);
			std::cout << " ";
		}
	}

	position(98, 22);
	couleurTexteEtBackground(couleurTexte, couleurDuJoueur);
	std::cout << "Tour au joueur " << numeroDeJoueur;
	
	// Affichage des touches
	// Pointe vers le haut
	position(63, 18);
	couleurTexteEtBackground(6, 0);
	std::cout << "W: Tourner vers le haut";

	// Pointe vers la gauche
	position(63, 19);
	couleurTexteEtBackground(6, 0);
	std::cout << "A: Tourner vers la gauche";

	// Pointe vers la droite
	position(63, 20);
	couleurTexteEtBackground(6, 0);
	std::cout << "D: Tourner vers la droite";

	// Pointe vers le bas
	position(63, 21);
	couleurTexteEtBackground(6, 0);
	std::cout << "S: Tourner vers le bas";

	// Deplacement du joueur
	position(63, 22);
	couleurTexteEtBackground(6, 0);
	std::cout << "Q: Avance d'une tuile";

	// Tirer
	position(63, 23);
	couleurTexteEtBackground(6, 0);
	std::cout << "E: Tirer un obus";

	// Mettre fin a son tour
	position(63, 24);
	couleurTexteEtBackground(6, 0);
	std::cout << "N: Mettre fin a son tour";

	// Barre de vie du joueur 1
	barreDeVie(vieJ1, 2, APJ1, '1', couleurJoueur1);

	// Barre de vie du joueur 2
	barreDeVie(vieJ2, 6, APJ2, '2', couleurJoueur2);

	// Si joueur 3 ne joue pas
	position(65, 10);
	couleurTexteEtBackground(6, 0);
	std::cout << "Joueur 3:       HORS SERVICE";

	// Si joueur 4 ne joue pas
	position(65, 14);
	couleurTexteEtBackground(6, 0);
	std::cout << "Joueur 4:       HORS SERVICE";

	if (nombreDeJoueurs == 3 || nombreDeJoueurs == 4) {
		// Barre de vie du joueur 3
		barreDeVie(vieJ3, 10, APJ3, '3', couleurJoueur3);

		if (nombreDeJoueurs == 4) {
			// Barre de vie du joueur 4
			barreDeVie(vieJ4, 14, APJ4, '4', couleurJoueur4);
		}
	}

	// Affichage du seed
	position(63, 28);
	couleurTexteEtBackground(6, 0);
	std::cout << "Seed # " << seed;

	// Aide
	position(102, 28);
	couleurTexteEtBackground(6, 0);
	std::cout << "?: Instructions";
}

// Affiche le gagnant et demande si l'utilisateur veut rejouer
void Template::finDePartie(char numeroDuJoueurGagnant, bool *rejouer){
	int couleurJ = 0;
	
	// Couleur du gagnant pour afficher sur le trophee
	// Couleur du joueur 1
	if (numeroDuJoueurGagnant == '1') {
		couleurJ = couleurJoueur1;
	}

	// Couleur du joueur 2
	else if (numeroDuJoueurGagnant == '2') {
		couleurJ = couleurJoueur2;
	}

	// Couleur du joueur 3
	else if (numeroDuJoueurGagnant == '3') {
		couleurJ = couleurJoueur3;
	}

	// Couleur du joueur 4
	else if (numeroDuJoueurGagnant == '4') {
		couleurJ = couleurJoueur4;
	}

	// Trophee
	// Centre du trophee
	for (short y = 9; y < 11; y++) {
		for (short x = 52; x < 69; x++) {
			position(x, y);
			couleurTexteEtBackground(0, 6);
			std::cout << " ";
		}
	}

	for (short y = 11; y < 13; y++) {
		for (short x = 50; x < 71; x++) {
			position(x, y);
			couleurTexteEtBackground(0, 6);
			std::cout << " ";
		}
	}

	for (short y = 13; y < 15; y++) {
		for (short x = 52; x < 69; x++) {
			position(x, y);
			couleurTexteEtBackground(0, 6);
			std::cout << " ";
		}
	}

	for (short y = 15; y < 17; y++) {
		for (short x = 54; x < 67; x++) {
			position(x, y);
			couleurTexteEtBackground(0, 6);
			std::cout << " ";
		}
	}

	for (short y = 17; y < 19; y++) {
		for (short x = 56; x < 65; x++) {
			position(x, y);
			couleurTexteEtBackground(0, 6);
			std::cout << " ";
		}
	}

	for (short y = 19; y < 20; y++) {
		for (short x = 54; x < 67; x++) {
			position(x, y);
			couleurTexteEtBackground(0, 6);
			std::cout << " ";
		}
	}

	// Poignee de gauche
	position(46, 10);
	couleurTexteEtBackground(0, 6);
	std::cout << "    ";

	for (short y = 11; y < 13; y++) {
		for (short x = 44; x < 46; x++) {
			position(x, y);
			couleurTexteEtBackground(0, 6);
			std::cout << " ";
		}
	}

	for (short y = 13; y < 15; y++) {
		for (short x = 46; x < 48; x++) {
			position(x, y);
			couleurTexteEtBackground(0, 6);
			std::cout << " ";
		}
	}

	position(48, 15);
	couleurTexteEtBackground(0, 6);
	std::cout << "    ";

	// Poignee de droite
	position(71, 10);
	couleurTexteEtBackground(0, 6);
	std::cout << "    ";

	for (short y = 11; y < 13; y++) {
		for (short x = 75; x < 77; x++) {
			position(x, y);
			couleurTexteEtBackground(0, 6);
			std::cout << " ";
		}
	}

	for (short y = 13; y < 15; y++) {
		for (short x = 73; x < 75; x++) {
			position(x, y);
			couleurTexteEtBackground(0, 6);
			std::cout << " ";
		}
	}

	position(69, 15);
	couleurTexteEtBackground(0, 6);
	std::cout << "    ";

	// Affichage du chiffre 1, selon la couleur du joueur, sur le trophee
	position(59, 11);
	couleurTexteEtBackground(0, couleurJ);
	std::cout << "  ";

	position(60, 12);
	couleurTexteEtBackground(0, couleurJ);
	std::cout << " ";

	position(60, 13);
	couleurTexteEtBackground(0, couleurJ);
	std::cout << " ";

	position(60, 14);
	couleurTexteEtBackground(0, couleurJ);
	std::cout << " ";

	position(59, 15);
	couleurTexteEtBackground(0, couleurJ);
	std::cout << "   ";

	// Joueur x est gagnant
	position(52, 21);
	couleurTexteEtBackground(6, 0);
	std::cout << "Bravo au joueur " << numeroDuJoueurGagnant;
	position(44, 22);
	std::cout << "Le grand vainqueur de Tank duel!!";

	char reponseRejouer;

	position(44,25);
	couleurTexteEtBackground(6, 0);
	std::cout << "Voulez-vous rejouer? O = oui / N = non  ";
	std::cin >> reponseRejouer;

	if (reponseRejouer == 'o' || reponseRejouer == 'O') {
		*rejouer = true;
	}

	else {
		*rejouer = false;
	}
}

// Destructeur de la classe Template
Template::~Template(){}
