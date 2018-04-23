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
#include "NeuroneChainee.h"
#include <vector>

using namespace std;

#ifndef RESEAUCHAINE
#define RESEAUCHAINE

/**
 * @class ReseauNeuroneChainees Classe héritant du réseau de neurone permettant de réaliser un réseau de neurone chaîné.
 */
class ReseauNeuronesChainees:ReseauNeurone {
private:
	vector<NeuroneChainee> coucheDEntree;
	vector<NeuroneChainee> coucheDeSortie;
};

#endif
