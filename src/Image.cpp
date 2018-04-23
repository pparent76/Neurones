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
#include <iostream>
#include <unistd.h>
#define LIMITE_NOIRE 300
#define MIN_DIMENTION_FENNETRE 50
#define max(x,y) (x>y?x:y)

int Image::SDL_Fenetre_Open=0;
int Image::nbInstances=0;

Image::Image(string path)
{
	img=SDL_LoadBMP(path.c_str());
	if (img==NULL)
		cout<<"Erreur impossible de charger "<<path<<endl;
	if (nbInstances==0)
		SDL_Init(SDL_INIT_VIDEO);
	nbInstances++;
}

Image::~Image(){
	// SDL_FreeSurface(img);
	if (nbInstances==1)
		SDL_Quit();
	nbInstances--;
}

int Image::obtenirPixel(int x, int y)
{
	Uint8 r,g,b,a;
	Uint32 res;
	/*nbOctetsParPixel représente le nombre d'octets utilisés pour stocker un pixel.
    En multipliant ce nombre d'octets par 8 (un octet = 8 bits), on obtient la profondeur de couleur
    de l'image : 8, 16, 24 ou 32 bits.*/
	int nbOctetsParPixel = img->format->BytesPerPixel;
	/* Ici p est l'adresse du pixel que l'on veut connaitre */
	/*surface->pixels contient l'adresse du premier pixel de l'image*/
	Uint8 *p = (Uint8 *)img->pixels + y * img->pitch + x * nbOctetsParPixel;

	if (x>img->w or y>img->h or x<0 or y<0)
	{
		printf("Erreur:pixel hors image\n");
		return 0;
	}

	/*Gestion différente suivant le nombre d'octets par pixel de l'image*/
	switch(nbOctetsParPixel)
	{
	case 1:
		res= *p;
	case 2:
		res= *(Uint16 *)p;
	case 3:
		/*Suivant l'architecture de la machine*/
		if(SDL_BYTEORDER == SDL_BIG_ENDIAN)
			res= p[0] << 16 | p[1] << 8 | p[2];
		else
			res= p[0] | p[1] << 8 | p[2] << 16;
	case 4:
		res=*(Uint32 *)p;
	}
	//On récupére les conposante r,g,b
	SDL_GetRGBA(res, img->format, &r, &g, &b, &a);

	if (r+g+b<LIMITE_NOIRE)
		return 1;
	else
		return 0;
}

vector<double> Image::obtenirPixels()
{
	vector<double> res;
	for (int i=0;i<img->w;i++)
		for (int j=0;j<img->h;j++)
			res.push_back(obtenirPixel(i,j)*100-50);
	return res;
}

std::vector< int > Image::LigneColonne()
{
	vector<int> res;
	int sum;

	for (int j=0;j<img->h;j++)
	{
		sum =0;
		for (int i=0;i<img->w;i++)
			sum+=obtenirPixel(i,j);
		res.push_back(sum);
	}

	for (int i=0;i<img->w;i++)
	{
		sum =0;
		for (int j=0;j<img->h;j++)
			sum+=obtenirPixel(i,j);
		res.push_back(sum);
	}
	return res;
}

void Image::afficher()
{
	SDL_Rect pos;
	if (SDL_Fenetre_Open!=0)
	{
		cout<<"Erreur: ne peut afficher deux images en même temps"<<endl;
		return;
	}
	SDL_Surface *ecran=SDL_SetVideoMode (max(img->w,MIN_DIMENTION_FENNETRE), max(img->h,MIN_DIMENTION_FENNETRE), 32, SDL_HWSURFACE|SDL_DOUBLEBUF);
	pos.x=0,pos.y=0;
	SDL_BlitSurface(img, NULL, ecran, &pos);
	SDL_Flip(ecran);
	SDL_Event event;
	int continuer=1;
	while (continuer==1)
	{
		SDL_WaitEvent(&event);
		if (event.type==SDL_QUIT)
			continuer = 0;//continuer=0 et on sort de la boucle.
	}
	SDL_FreeSurface(ecran);

}

void Image::afficher(int n)
{
	SDL_Rect pos;
	if (SDL_Fenetre_Open!=0)
	{
		cout<<"Erreur: ne peut afficher deux images en même temps"<<endl;
		return;
	}

	SDL_Surface *ecran;
	ecran=SDL_SetVideoMode (max(img->w,MIN_DIMENTION_FENNETRE), max(img->h,MIN_DIMENTION_FENNETRE), 32, SDL_HWSURFACE|SDL_DOUBLEBUF);
	SDL_FillRect(ecran,NULL,SDL_MapRGB(ecran->format,30, 50, 193));

	pos.x=0,pos.y=0;
	SDL_BlitSurface(img, NULL, ecran, &pos);
	SDL_Flip(ecran);
	usleep(n*1000);
}
