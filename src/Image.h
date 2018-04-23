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
#include "SDL/SDL.h"
#include <string>
#include <vector>
using namespace std;


#ifndef IMAGE
#define IMAGE

/**
 * @class Image
 * @brief Cette classe a pour but de charger facilement des images et de réaliser des traitements basiques dessus.
 */
class Image
{

public:
	/**
	 * Ceci est le constructeur de la classe Image qui permet de charger une image.
	 * @param path le chemin (relatif) où se trouve l'image à charger
	 */
	Image(string path);

	/**
	 * Ceci est le destructeur de la classe Image qui permet de charger une image.
	 */
	~Image();

	/**
	 * Cette méthode a pour but de recentrer l'image dans l'optique d'un prétraitement.
	 */
	void centerImage();

	/**
	 * Retourne la valeur du pixel souhaité
	 * @param x ordonnée du pixel
	 * @param y abscisse du pixel
	 */
	int obtenirPixel(int x, int y);

	/**
	 * Retourne le tableau de pixels de l'image
	 * @return tableau avec tous les pixels.
	 */
	vector<double> obtenirPixels();

	/**
	 * Cette méthode retourne la somme des pixels sur chaque ligne et colonne.
	 * @return renvois un tableau de données.
	 */
	vector<int> LigneColonne();

	/**
	 * @brief Cette méthode permet d'afficher l'image jusqu'à ce que l'utilisateur ferme la fenêtre.
	 */
	void afficher();

	/**
	 * @brief Cette méthode permet d'afficher l'image n millisecondes
	 */
	void afficher(int n);

private:
	SDL_Surface *img;
	static int SDL_Fenetre_Open;
	static int nbInstances;
	friend class Image_Test;
};


#endif
