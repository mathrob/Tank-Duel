/*
 * Programmeur     : Mathieu Robson
 * Nom du projet   : Devoir3
 * Nom de la classe: Template.h
 * Date            : 2020-04-09
 * Description     : Affichage graphique du jeu
 */

#ifndef TEMPLATE_H
#define TEMPLATE_H

class Template {
public:
	Template();
	void imageAccueil();
	void setNombreDeJoueurs(int*);
	void setSeed(unsigned long*);
	void AfficheConsoleInformative(int, int, int, int, int, int, int, int, long, int, int);
	void affichageDesTuiles(int, int, int,int,int,int,int);
	void position(short, short);
	void couleurTexteEtBackground(int, int);
	void demandeConsultationInstructions(int);
	void aide(int);
	void barreDeVie(int,int,int,char,int);
	void finDePartie(char, bool*);
	~Template();
private:
	int Y;
	int X;
	int couleurJoueur1;
	int couleurJoueur2;
	int couleurJoueur3;
	int couleurJoueur4;
	int couleurBloc1;
	int couleurBloc2;
	int couleurBloc3;
	int couleurBloc4;
	int couleurCentreBloc123;
};

#endif