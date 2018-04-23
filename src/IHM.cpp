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
#include "IHM.h"
#include "Image.h"
#include "Neurone.h"
#include "ReseauNeuronesCouches.h"
#include<stdio.h>
#include<cstdlib>
#include<iostream>
#include<string.h>
#include<fstream>
#include<dirent.h>
#define NBTEST 15
#define NBAPPRA 24
#define NBAPPRB 25
using namespace std;

IHM::IHM() {
	// TODO Auto-generated constructor stub

}

IHM::~IHM() {
	// TODO Auto-generated destructor stub
}

string IHM::str(int number) {
	if (number == 0)
		return "0";
	string temp = "";
	string returnvalue = "";
	while (number > 0) {
		temp += number % 10 + 48;
		number /= 10;
	}
	for (int i = 0; i < temp.length(); i++)
		returnvalue += temp[temp.length() - i - 1];
	return returnvalue;
}

int IHM::listFile(string pathRepertoire) {
	int i = 0;
	DIR *pDIR;
	struct dirent *entry;
	if (pDIR = opendir(pathRepertoire.data())) {
		while (entry = readdir(pDIR)) {

			if (strcmp(entry->d_name, ".") != 0 && strcmp(entry->d_name, "..")!= 0)
				i++;
		}
		closedir(pDIR);
	}
	return i;
}

void IHM::calcul() {
	vector<Image> a;
	vector<Image> test;
	vector<double> corect;

	for (int i = 1; i <= NBAPPRA; i++)
		a.push_back(Image("img/a/" + str(i) + ".bmp"));

	for (int i = 1; i <= NBAPPRB; i++)
		a.push_back(Image("img/b/" + str(i) + ".bmp"));

	for (int i = 1; i <= NBTEST; i++)
		test.push_back(Image("img/test" + str(i) + ".bmp"));

	corect.push_back(1);
	corect.push_back(0);
	corect.push_back(0);
	corect.push_back(1);
	corect.push_back(0);
	corect.push_back(0);
	corect.push_back(0);
	corect.push_back(1);
	corect.push_back(1);
	corect.push_back(0);
	corect.push_back(0);
	corect.push_back(0);
	corect.push_back(0);
	corect.push_back(0);
	corect.push_back(1);

	vector<double> in[100];
	vector<double> out[100];
	vector<double> out1, out2;
	vector<int> dim;

	dim.push_back(900);
	dim.push_back(12);
	dim.push_back(10);
	dim.push_back(2);

	ReseauNeuronesCouches r(dim);

	out1.push_back(0.99);
	out1.push_back(-0.99);
	out2.push_back(-0.99);
	out2.push_back(0.99);

	for (int i = 0; i < a.size(); i++) {
		in[i] = a[i].obtenirPixels();
		a[i].afficher(100);
		if (i >= NBAPPRA)// Les trois dernières images attendent pour réponse 0.01
			out[i] = out2;
		else
			out[i] = out1;
	}

	cout << "Apprentissage du jeu d'images A B contenant 30 images" << endl
			<< "15 premières images attendent A en réponse, les 15 dernières B"
			<< endl;
	r.apprendre(in,out,a.size());
	cout << "---------Échantillon d'apprentissage-----------" << endl;
	for (int i = 0; i < a.size(); i++) {
		in[0] = a[i].obtenirPixels();
		vector<double> res = r.calculerResultat(in[0]);
		if (res[0] >= res[1])
			cout << "A a" << " ";
		else
			cout << "B b" << " ";
		for (int j = 0; j < res.size(); j++)
			cout << "Image appr " << i << " :" << res[j] << " ";
		cout << endl;
		a[i].afficher(100);
	}
	r.sauvegarderReseau("res/test.txt");

	cout << "---------Echantillon de test-----------" << endl;
	for (int i = 0; i < NBTEST; i++) {
		in[0] = test[i].obtenirPixels();
		vector<double> res = r.calculerResultat(in[0]);
		double cor;
		if (res[0] >= res[1]) {
			cout << "A a" << " ";
			cor = 0;
		} else {
			cout << "B b" << " ";
			cor = 1;
		}
		if (cor == corect[i])
			cout << "ok ;) ";
		else
			cout << "ouch :( ";
		for (int j = 0; j < res.size(); j++)
			cout << "Image test " << i << " :" << res[j] << " ";
		cout << endl;
		test[i].afficher(1000);
	}
}

void IHM::apprendreIhm(string pathImage, string pathReseau) {
	vector<int> dim;
	vector<Image> vimage;// = new Image("pathImage");
	vector<double> in[1000], out[1000], out1, out2;

	// out1 pour a , out2 pour b
	out1.push_back(0.99);
	out1.push_back(-0.99);
	out2.push_back(-0.99);
	out2.push_back(0.99);
	
	// les paramètres par défaut
	// dim = liste qui contient le nombre de neurone de chaque couche (ce nombre peut varier d'une couche à l'autre)
	dim.push_back(900); 
	dim.push_back(12);
	dim.push_back(10);
	dim.push_back(2);
	ReseauNeuronesCouches rnc(dim);
	 
	// lire des images
	for (int i = 1; i <= listFile(pathImage + "image/a/"); i++)
		vimage.push_back(Image(pathImage + "image/a" + str(i) + ".bmp"));
		
	for (int i = 1; i <= listFile(pathImage + "image/b/"); i++)
		vimage.push_back(Image(pathImage + "img/b" + str(i) + ".bmp"));

	// numériser les images
	for (int i = 0; i < vimage.size(); i++) {
		in[i] = vimage[i].obtenirPixels();
		vimage[i].afficher(100);
		if (i >= listFile(pathImage + "image/a/")) // Les trois derniéres images attendent pour réponse 0.01
			out[i] = out2;
		else
			out[i] = out1;
	}
	
	rnc.apprendre(in, out, vimage.size());
	rnc.sauvegarderReseau(pathReseau);
}

void IHM::reconnaitreIhm(string pathImage, string pathReseau) {
	Image image(pathImage);
	ReseauNeuronesCouches rnc;// = new ReseauNeuronesCouches();
	vector<double> resultat;
	double max = -1;
	int indice;

	rnc.chargerReseau(pathReseau);
	resultat = rnc.calculerResultat(image.obtenirPixels());

	for (int i = 0; i < resultat.size(); i++) {
		if (resultat[i] > max) {
			max = resultat[i];
			indice = i;
		}
	}
	cout << "C'est le caractère numéro :" << indice+1<<" ("<<(char)(indice+97)<<")"<< endl;
}

void IHM::menu() {
	int menu;
	string pathImage, pathReseau, fichReseau;

	cout << endl
			<< "\033[40m\033[035m-----------Projet C++: Réseaux Neurones--------------- \033[0m\n";
	cout << endl << "<======================= MENU =====================>"
			<< endl << endl;
	cout << "1. Mode Automatique" << endl;
	cout << "2. Apprentissage" << endl;
	cout << "3. Reconnaissance" << endl;
	cout << "0. Quitter" << endl << endl;
	cout << "Choix : ";
	cin >> menu;
	cout << "<===================================================> \n";
	cout << endl;

	switch (menu) {
	case 0:
		break;

	case 1:
		cout << "Faire tourner le programme avec les paramètres par défaut()"
				<< endl;
		calcul();
		break;

	case 2:
		cout<< "Apprendre et sauvegarder le réseau" << endl;
		cout<< "Entrer l'addresse de l'image" << endl;
		cin>> pathImage;
		cout<< "Entrer l'addresse souhaitée où l'on sauvegarde le réseau"<<endl;
		cin>> pathReseau;
		apprendreIhm(pathImage, pathReseau);
		cout<< "Votre réseau est sauvegardé à l'adresse " + pathReseau <<endl;
		break;

	case 3:
		cout << "Reconnaissance" << endl;
		cout << "Entrer l'addresse de l'image" << endl;
		cin >> pathImage;
		cout << "Entrer un réseau" << endl;
		cin >> fichReseau;
		reconnaitreIhm(pathImage, fichReseau);
		break;

	}
}
