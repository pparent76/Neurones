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
#include "Image.h"
#include "ReseauNeuronesCouches.h"

/**
 * @class IHM
 * @brief Cette classe a pour but de charger l'interface en mode console
 */
class IHM {
private:
	/**
	 * ceci correspond a la mode automatique du menu, tout les parametre sont predefini
	 */
	void calcul();

	/**
	 * Ceci est un fonction qui calcule le nombre de fichier dans un répertoire.
	 * @param pathRepertoire l'adresse du répertoire.
	 */
	int listFile(string pathRepertoire);

	/**
	 * Pierre?
	 */
	string str(int number);

	/**
	 * Ceci permet de lancer l'apprentissage depuis le menu.
	 * @param pathImage l'adresse du répertoire des images.
	 * @param pathReseau l'adresse du fichier stockant le réseau.
	 */
	void apprendreIhm(string pathImage, string pathReseau);

	/**
	 * Ceci permet de lancer la reconnaissance depuis le menu
	 * @param pathImage l'adresse du répertoire des images.
	 * @param pathReseau l'adresse du fichier stockant le réseau.
	 */
	void reconnaitreIhm(string pathImage, string pathReseau);

public:
	/**
	 * Ceci est le constructeur par defaut de la classe IHM.
	 */
	IHM();

	/**
	 * Ceci est le destructeur par defaut.
	 */
	~IHM();

	/**
	 * Lance le menu principal de l'interface.
	 */
	void menu();
};

