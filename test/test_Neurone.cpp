#include "test_Neurone.h"
#include "../src/Neurone.h"
#include "../src/Sigmoide.h"
#include <math.h>

CPPUNIT_TEST_SUITE_REGISTRATION( Test_Neurone ); 

void Test_Neurone::setUp(void )
{
	//Void
}

void Test_Neurone::tearDown(void )
{
	//Void
}

void Test_Neurone::test_Constructeur()
{
	CPPUNIT_ASSERT(Neurone(1,4).getIdentifiant()==1);
	CPPUNIT_ASSERT(Neurone(1,4).poidsSynaptiques.size()==4);
}

void Test_Neurone::test_CalculeValeurTransphert()
{
	Neurone a(1,4);
	a.poidsSynaptiques[0]=1;
	a.poidsSynaptiques[1]=0;
	a.poidsSynaptiques[2]=2;
	a.poidsSynaptiques[3]=0.5;

	vector<double> in;
	in.push_back(1);
	in.push_back(2);
	in.push_back(3);
	in.push_back(4);

	double correct;
	correct=9;

	a.calculeValeurTransfert(in);
	CPPUNIT_ASSERT(a.valeurTransfert==correct);
}

void Test_Neurone::test_ValeurEntree()
{
	Neurone a(1,4);
	a.setValeurEntree(3);
	CPPUNIT_ASSERT(a.valeurTransfert==3);

}

void Test_Neurone::test_ValeurSortie()
{
	Neurone a(1,4);
	a.valeurTransfert=0.0;
	CPPUNIT_ASSERT(a.getValeurSortie()==Sigmoide::f(0));
	a.valeurTransfert=1000;
	CPPUNIT_ASSERT(a.getValeurSortie()==Sigmoide::f(1000));
	a.valeurTransfert=-1;
	CPPUNIT_ASSERT(a.getValeurSortie()==Sigmoide::f(-1));
}
