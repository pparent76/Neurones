/*Copyright (c) 2011 Pierre Parent
    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/
#include "ReseauNeurone.h"
#include "Neurone.h"

#ifndef RESEAUCOUCHE
#define RESEAUCOUCHE

/**
 * @class ReseauNeuroneChainees Classe heritant de réseau de neurone permettant de réaliser un réseau de neurone par couche.
 */
class ReseauNeuronesCouches : public ReseauNeurone {
public:
	ReseauNeuronesCouches();
	/**
	 * Ceci est le constructeur de la classe reseau neurone par couche.
	 * @param nbNeuronesParCouche le nombre de neurones par couche (dans ce cas le nombre de neurones par couche est fixé)
	 * @param nbCouches le nombre de couches
	 */
	ReseauNeuronesCouches(int nbNeuronesParCouche,int nbCouches);

	/**
	 * Ceci est le constructeur de la classe reseau neurone par couche.
	 * @param nbNeuronesParCouche un tableau qui contient le nombre de neurone de chaque couche (ce nombre peut varier d'une couche à l'autre).
	 * Le nombre de couches retenues est la taille du tableau.
	 */
	ReseauNeuronesCouches(vector<int> nbNeuronesParCouche);

	/**
	 * Ceci est le constructeur par recopie de la classe reseau neurone par couche.
	 */
	ReseauNeuronesCouches(const ReseauNeuronesCouches &u);

	~ReseauNeuronesCouches();

	bool chargerReseau (string path);

	bool sauvegarderReseau (string path);

	/**
	 * @brief Cette méthode permet de calculer le résultat sur la couche de sortie.
	 * @return la valeur des résultats.
	 */
	vector<double> calculerResultat (vector<double> valeurEntree);

	/**
	 * @brief Cette méthode permet de réaliser l'apprentissage complet à partir d'un jeu de données.
	 * @param entrees liste des entrées pour le jeu d'apprentissage.
	 * @param valeursAttendues les valeurs attendues en sortie pour chacunes de ses entrées.
	 * @param n la taille de l'échantillon d'apprentissage.
	 */
	void apprendre (vector<double> *entrees,vector<double> *valeursAttendues,int n);

private:
	/**
	 * Méthode utilisée pour initialiser la structure du réseau.
	 */
	void initialiserReseau(vector<int> nbNeuronesParCouche);

	/**
	 * Retourne un tableau contenant la valeur de sortie de chacun des neurones de la couche nbCouche.
	 * @param nbCouche le numéro de la couche souhaitée.
	 */
	vector<double> valeurCouche(int nbCouche);

	/**
	 * @brief Cette méthode permet de fixer la valeur de la couche d'entrée des neurones.
	 * @param valeurs Le tableau des valeurs des neurones de la première couche.
	 */
	void setEntree(vector<double> valeurs);

	/**
	 * @brief Cette méthode permet de réaliser UNE itération d'apprentissage.
	 * Il faut répéter cette itération plusieurs fois afin que l'apprentiassage se déroule correctement
	 * @param entrees liste des entrées pour le jeu d'apprentissage.
	 * @param valeursAttendues les valeurs attendues en sortie pour chacune de ses entrées.
	 * @param n la taille de l'échantillon d'apprentissage.
	 */
	void IterationApprentissage (vector<double> *entrees,vector<double> *valeursAttendues,int n);

	/**
	 * @brief Cette méthode permet de calculer les valeur qu'il faudrait avoir à la couche précédente afin d'être le plus proche possible du résultat souhaité à la couche actuelle.
	 * Le plus proche possible en tentant de minimiser l'erreur au sens des moindre carrés. Cette méthode implémente un algorithme glouton.
	 * @param valeursAttendues les valeurs attendues à la couche noCouche
	 * @param nbDonnees la taille de l'échantillon de données
	 * @param noCouche le numéro de la couche pour laquelle on attend une certaine valeur.
	 * @return retourne la valeur qu'il faudrait avoir en couche noCouche -1.
	 */
	 
	vector<double> * ValeurAttendueCouchePrec(vector<double> *valeursAttendues,int nbDonnees,int noCouche);

	double calculerErreur(vector<double> solutionProposee,vector<double> valeursAttendues,int noCouche);

	double Moyenne(vector<double> valeurs);

	double EcartType(vector<double> valeurs);

	vector<Neurone>* matriceNeurones;
	int nbCouches;

	friend class Test_ReseauNeuronesCouche;
};
#endif
