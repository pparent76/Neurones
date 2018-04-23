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
#include "Sigmoide.h"
#include <iostream>
#include <stdlib.h>

Neurone::Neurone(int id, int nbAntecedents)
{
	fonctionTransfert=Sigmoide();
	identifiant=id;
	//Les coefficient synaptics vallent 0 au début
	for (int i=0;i<nbAntecedents;i++)
		poidsSynaptiques.push_back(1.0*rand()/RAND_MAX*0.2 -0.1);
}

Neurone::Neurone (const Neurone &n)
{
	identifiant=n.identifiant;
	valeurTransfert=n.valeurTransfert;
	valeurErreur=n.valeurErreur;
	poidsSynaptiques=n.poidsSynaptiques;
	fonctionTransfert=n.fonctionTransfert;
}

void Neurone::chargerNeurone (ifstream * sauvegarde){
	int i;
	string s;
	sauvegarde->ignore(9);
	*sauvegarde >> identifiant;
	for(i=0; i<poidsSynaptiques.size(); i++){
		*sauvegarde >> poidsSynaptiques[i];
	}
}

void Neurone::sauvegarderNeurone (ofstream * sauvegarde){
	int i;
	*sauvegarde << "Neurone " << identifiant << endl;
	for(i=0; i<poidsSynaptiques.size(); i++){
		*sauvegarde << poidsSynaptiques[i] << " ";
	}
	*sauvegarde << endl;
}

void Neurone::calculeValeurTransfert(std::vector< double > entreeSynaptique)
{
	valeurTransfert=0;
	if (entreeSynaptique.size()!=poidsSynaptiques.size())
	{
		cout<<"Erreur la taille des entreeSynaptique ne correspont pas"<<endl;
		return;
	}
	for (int i=0;i<entreeSynaptique.size();i++)
		valeurTransfert+=entreeSynaptique[i]*poidsSynaptiques[i];
}

double Neurone::getValeurSortie()
{
	return Sigmoide::f(valeurTransfert);
}

int Neurone::getIdentifiant()
{
	return identifiant;
}

void Neurone::setValeurEntree(double v)
{
	valeurTransfert=v;
}

void Neurone::setPoidsSynaptic(std::vector< double > poids)
{
	poidsSynaptiques=poids;
}

std::vector< double, std::allocator< double > > Neurone::getPoidsSynaptic()
{
	return poidsSynaptiques;
}

double Neurone::getValeurAvantTrasphert()
{
	return valeurTransfert;
}
