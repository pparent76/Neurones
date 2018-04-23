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
#include "Sigmoide.h"
#include <math.h>
#include <iostream>

using namespace std;

double Sigmoide::f(double x)
{
	return (1/(1+exp(-x))-0.5)*2;
}

double Sigmoide::f_inverse(double x)
{
	if (x>=1 or x<=0)
		cout<<"Attention signmoide inverse or range"<<endl;
	return -1.0*(log(1/(x/2+0.5)-1)) ;

}

double Sigmoide::f_derive(double x)
{
	if (x>100)
		return 1e-5;
	return 2*exp(x)/((1+exp(x))*(1+exp(x)));

}
