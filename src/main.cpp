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

using namespace std;

string str(int number) {
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

int listFile(string pathRepertoire) {
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
/*
#include "Image.h"
#include "Neurone.h"
#include "ReseauNeuronesCouches.h"
#include "IHM.h"
#include <iostream>
#define NBTEST 15
#define NBAPPRA 24
#define NBAPPRB 25
*/

/*
string str(int number)
{
	if (number == 0)
		return "0";
	string temp="";
	string returnvalue="";
	while (number>0)
	{
		temp+=number%10+48;
		number/=10;
	}
	for (int i=0;i<temp.length();i++)
		returnvalue+=temp[temp.length()-i-1];
	return returnvalue;
} */

int main(int argc, char *argv[])
{
  
  if (argc<4)
  {
   cout<<"Mauvais usage"<<endl; 
  }
  else
  {
    if (strcmp(argv[1],"-a")==0)
    {
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
	 
	int i = 0;
	DIR *pDIR;
	struct dirent *entry;
	if (pDIR = opendir(argv[3])) {
		while (entry = readdir(pDIR)) {

			if (entry->d_name[0]!='.')
			{
				vimage.push_back(Image(string(argv[3])+entry->d_name));
				out[2*i+1] = out1;
				in[2*i+1] = vimage[i].obtenirPixels();
				vimage[i].afficher(100);
				i++;
				cout<<entry->d_name<<endl;
				
			}
			
		}
		closedir(pDIR);
	}
	
	i=0;
	if (pDIR = opendir(argv[4])) {
		while (entry = readdir(pDIR)) {

			if (entry->d_name[0]!='.')
			{
				vimage.push_back(Image(string(argv[4])+entry->d_name));
				out[2*i] = out2;
				in[2*i] = vimage[int(vimage.size())-1].obtenirPixels();
				vimage[int(vimage.size())-1].afficher(100);
				i++;
								cout<<entry->d_name<<endl;
			}
		}
		closedir(pDIR);
	}


	
	rnc.apprendre(in, out, vimage.size());
	rnc.sauvegarderReseau(argv[2]);
    }
    
    if (strcmp(argv[1],"-r")==0)
    {
	Image image(argv[3]);
	ReseauNeuronesCouches rnc;
	vector<double> resultat;
	double max = -100;
	int indice;


	rnc.chargerReseau(argv[2]);
	resultat = rnc.calculerResultat(image.obtenirPixels());

	for (int i = 0; i < resultat.size(); i++) {  
		if (resultat[i] > max) {
		
			max = resultat[i];
			indice = i;
		}
	}
	cout << "C'est le caractère numéro :" << indice+1<<" ("<<(char)(indice+97)<<") "<<int(resultat[indice]*100)<<"\% de certitude"<<endl;
	image.afficher(2000);
    }
    
  }
  
  /*
	IHM ihm;
	ihm.menu();
	
	
	vector<Image> a;
	vector<Image> test;
	vector<double> corect; 
	for (int i=1;i<=NBAPPRA;i++)
		a.push_back(Image("img/appr_a"+str(i)+".bmp"));
	for (int i=1;i<=NBAPPRB;i++)
		a.push_back(Image("img/appr_b"+str(i)+".bmp"));

	for (int i=1;i<=NBTEST;i++)
		test.push_back(Image("img/test"+str(i)+".bmp"));


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
	vector<double> out1,out2;
	vector<int> dim;

	dim.push_back(900);
	// dim.push_back(900);
	// dim.push_back(500);
	// dim.push_back(500);
	// dim.push_back(100);
	// dim.push_back(20);
	// dim.push_back(20);
	// dim.push_back(20);
	// dim.push_back(10);
	// dim.push_back(2);
	// dim.push_back(20);
	dim.push_back(12);
	dim.push_back(10);
	// dim.push_back(10);
	// dim.push_back(10);
	// dim.push_back(10);
	// dim.push_back(10);
	// dim.push_back(2);
	dim.push_back(2);
	ReseauNeuronesCouches r(dim);

	out1.push_back(0.99);
	out1.push_back(-0.99);
	out2.push_back(-0.99);
	out2.push_back(0.99);

	for (int i=0;i<a.size();i++)
	{
		in[i]=a[i].obtenirPixels();
		a[i].afficher(100);
		if (i>=NBAPPRA)// Les trois derniéres images attendent pour réponse 0.01
			out[i]=out2;
		else
			out[i]=out1;
	}

	cout<<"Apprentissage du jeu d'images A B contenant 30 images"<<endl<<"15 premiére image attendent A en réponse, les 15 dérniéres B"<<endl;
	//r.apprendre(in,out,a.size());
	r.chargerReseau("res/test.txt");
	cout<<"---------Echantillon d'apprentissage-----------"<<endl;
	for (int i=0;i<a.size();i++)
	{
		in[0]=a[i].obtenirPixels();
		vector<double> res =r.calculerResultat(in[0]);
		if (res[0]>=res[1])
			cout<<"A a"<<" ";
		else
			cout<<"B b"<<" ";
		for (int j=0;j<res.size();j++)
			cout<<"Image appr "<<i<<" :"<<res[j]<<" ";
		cout<<endl;
		a[i].afficher(100);
	}
	//r.sauvegarderReseau("test.txt");

	cout<<"---------Echatillon de test-----------"<<endl;
	for (int i=0;i<NBTEST;i++)
	{

		in[0]=test[i].obtenirPixels();
		vector<double> res =r.calculerResultat(in[0]);
		double cor;
		if (res[0]>=res[1])
		{
			cout<<"A a"<<" ";
			cor=0;
		}
		else
		{
			cout<<"B b"<<" ";
			cor=1;
		}
		if (cor==corect[i])
			cout<<"ok ;) ";
		else
			cout<<"ouch :( ";
		for (int j=0;j<res.size();j++)
			cout<<"Image test "<<i<<" :"<<res[j]<<" ";
		cout<<endl;
		test[i].afficher(1000);
	}
	*/
	
}
