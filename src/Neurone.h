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
#include "FonctionTransfert.h"
#include <cstdio>
#include <vector>
#include <fstream>

using namespace std;

#ifndef NEURONE
#define NEURONE

/**
 * @class Neurone cette classe représente un neurone.
 */
class Neurone {
protected:
	int identifiant;
	double valeurTransfert;
	double valeurErreur;
	vector<double> poidsSynaptiques;
	FonctionTransfert fonctionTransfert;

public:
	/**
	 * @brief Ceci est le créateur d'un neurone.
	 * @param identifiant le numéro d'identification du neurone.
	 * @param nbAntecedents le nombre d'antecedents qu'aura le neurone (c'est à dire le nombre de coefficient synaptic qu'il aura)
	 **/
	Neurone (int identifiant,int nbAntecedents);

	Neurone (const Neurone &n);

	/**
	 * @brief Cette méthode permet de lire un neurone dans un fichier.
	 * @param sauvegarde le fichier dans lequel il faut lire le neurone.
	 **/
	virtual void chargerNeurone (ifstream * sauvegarde);

	/**
	 * @brief Cette méthode permet de sauvegarder un neurone dans un fichier.
	 * @param sauvegarde le fichier dans lequel il faut écrire le neurone.
	 */
	virtual void sauvegarderNeurone (ofstream * sauvegarde);

	/**
	 *@brief Calcule la valeur de transfert à partir des entrée synaptiques qui lui sont données.
	 *@param entreeSynaptique donne les valeurs aux entrées du neurones.
	 **/
	virtual void calculeValeurTransfert(vector<double> entreeSynaptique);

	/**
	 * @brief Cette méthode retourne la valeur de sortie du neurone après passage dans la fonction de transfert.
	 * @return la valeur de sortie.
	 */
	virtual double getValeurSortie();

	/**
	 * @brief Cette méthode retourne la valeur de l'identifiant du neurone.
	 * @return l'identifiant du neurone.
	 */
	virtual int getIdentifiant();

	/**
	 * @brief Permet d'assigner la valeur d'entrée du neurone (utile quand le neurone est de la première couche).
	 * @param v la valeur souhaitée.
	 */
	virtual void setValeurEntree(double v);

	/**
	 * @brief Permet d'assigner la valeur des poids synaptiques du neurone (pour la phase d'apprentissage).
	 * @param poids les valeurs souhaitées.
	 */
	virtual void setPoidsSynaptic(vector<double> poids);

	/**
	 * @brief Permet de récupérer la valeur des poids synaptiques du neurone (pour la phase d'apprentissage).
	 * @return la valeur des poids.
	 */
	virtual vector<double> getPoidsSynaptic();

	/**
	 *
	 */
	virtual double getValeurAvantTrasphert();

	friend class Test_Neurone;
	friend class Test_ReseauNeuronesCouche;
};

#endif
