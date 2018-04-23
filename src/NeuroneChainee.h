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
#include "Neurone.h"
#include "ReseauNeuronesChainees.h"

#ifndef NEURONECHAINE
#define NEURONECHAINE
/**
 * @class NeuroneChainee Cette classe hérite de la classe neurone et permet de de réaliser des
 * réseaux de neurones en graphe
 */
class NeuroneChainee : public Neurone {

private:
	int nombreSucceseurs;
	Neurone* antecedents;
	Neurone* successeurs;

	bool estCalcule;
	bool estEstime;

public:
  /**
   * @brief Cette méthode permet de calculer la valeur du neurone en faisant des appels récurcifs.
   * La méthode calcule le resultat et la met dans la variable.
   * @return donne la valeur.
   */
  double calculerValeur ();
  
  /**
   * @brief Cette méthode permet de calculer l'erreur du neurone en faisant des appels récurcifs.
   * La méthode calcule le resultat et la met dans la variable.
   * @return donne l'erreur.
   */
  double calculerErreur ();
};

#endif
