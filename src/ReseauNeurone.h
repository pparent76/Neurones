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
#include <vector>
#include <string>
#include "Neurone.h"

using namespace std;

#ifndef RESEAU
#define RESEAU

/**
 * @class ReseauNeurone classe abstraite représentant un réseau de neurones.
 */
class ReseauNeurone {

protected:
	vector<Neurone> Neurones;

public:
	/**
	 * @brief Cette méthode permet de charger un réseau lu dans un fichier.
	 * @param path une chaine de caractère décrivant le nom du fichier dans lequel est stocké le réseau.
	 * @return Si oui ou non le chargement s'est bien déroulé.
	 */
	virtual bool chargerReseau (string path) = 0;

	/**
	 * @brief Cette méthode permet de sauvegarder un réseau dans un fichier.
	 * @param path une chaine de caractère décrivant le nom du fichier dans lequel on stocke le réseau.
	 * @return Si oui ou non la sauvegarde s'est bien déroulée.
	 */
	virtual bool sauvegarderReseau (string path) = 0;

	/**
	 * @brief Cette méthode permet de réaliser une étape d'apprentissage.
	 * @param entrees liste des entrées pour le jeu d'apprentiassage.
	 * @param valeursAttendues les valeurs attendues en sortie pour chacune de ses entrées.
	 * @param n la taille de l'échantillon d'apprentissage.
	 */
	void apprendre (vector<double> *entrees,vector<double> *valeursAttendues,int n);

	/**
	 * @brief Cette méthode permet de calculer le résultat sur la couche de sortie.
	 * @return la valeur des résultats.
	 */
	vector<double> calculerResultat (vector<double> valeurEntree);

};

#endif
