#include"test_ReseauNeuronesCouches.h"
#include "../src/ReseauNeuronesCouches.h"
#include "../src/Sigmoide.h"
#include <math.h>

CPPUNIT_TEST_SUITE_REGISTRATION( Test_ReseauNeuronesCouche ); 

void Test_ReseauNeuronesCouche ::setUp(void )
{
	//Void
}

void Test_ReseauNeuronesCouche ::tearDown(void )
{
	//Void
}

void Test_ReseauNeuronesCouche ::test_Constructeur()
{
	ReseauNeuronesCouches r(5,5);

	CPPUNIT_ASSERT((r.nbCouches)==5);
	CPPUNIT_ASSERT(r.matriceNeurones[0].size()==5);
	CPPUNIT_ASSERT(r.matriceNeurones[2].size()==5);
	CPPUNIT_ASSERT(r.matriceNeurones[4].size()==5);
}

void Test_ReseauNeuronesCouche::test_Constructeur2()
{
	vector<int> in;
	in.push_back(3);
	in.push_back(2);
	in.push_back(1);
	in.push_back(4);
	ReseauNeuronesCouches r(in);

	CPPUNIT_ASSERT(r.nbCouches==4);
	CPPUNIT_ASSERT(r.matriceNeurones[0].size()==3);
	CPPUNIT_ASSERT(r.matriceNeurones[1].size()==2);
	CPPUNIT_ASSERT(r.matriceNeurones[2].size()==1);
	CPPUNIT_ASSERT(r.matriceNeurones[3].size()==4);
}


void Test_ReseauNeuronesCouche::test_CoherenceTailleCouche()
{
	vector<int> in;
	in.push_back(3);
	in.push_back(2);
	in.push_back(1);
	in.push_back(4);
	ReseauNeuronesCouches r(in);
	CPPUNIT_ASSERT(r.matriceNeurones[0][0].poidsSynaptiques.size()==1);
	CPPUNIT_ASSERT(r.matriceNeurones[1][1].poidsSynaptiques.size()==3);
	CPPUNIT_ASSERT(r.matriceNeurones[2][0].poidsSynaptiques.size()==2);
	CPPUNIT_ASSERT(r.matriceNeurones[3][3].poidsSynaptiques.size()==1);
}

void Test_ReseauNeuronesCouche::test_setEntree()
{
	ReseauNeuronesCouches r(4,4);
	vector<double> in;
	in.push_back(3);
	in.push_back(2);
	in.push_back(1);
	in.push_back(4);

	r.setEntree(in);
	CPPUNIT_ASSERT(r.matriceNeurones[0][0].valeurTransfert==3);
	CPPUNIT_ASSERT(r.matriceNeurones[0][1].valeurTransfert==2);
	CPPUNIT_ASSERT(r.matriceNeurones[0][2].valeurTransfert==1);
	CPPUNIT_ASSERT(r.matriceNeurones[0][3].valeurTransfert==4);
}

void Test_ReseauNeuronesCouche::test_ValeurCouche()
{
	ReseauNeuronesCouches r(4,4);
	vector<double> in;
	in.push_back(1000);
	in.push_back(0);
	in.push_back(-1000);
	in.push_back(1);

	r.setEntree(in);
	CPPUNIT_ASSERT(r.valeurCouche(0)[0]==Sigmoide::f(1000));
	CPPUNIT_ASSERT(r.valeurCouche(0)[1]==Sigmoide::f(0));
	CPPUNIT_ASSERT(r.valeurCouche(0)[2]==Sigmoide::f(-1000));
	CPPUNIT_ASSERT(r.valeurCouche(0)[3]==Sigmoide::f(1));
}

void Test_ReseauNeuronesCouche::test_ValeurSortie()
{
	ReseauNeuronesCouches r(3,3);
	vector<double> in1,in2,res,correct;
	in1.push_back(0.4);
	in1.push_back(0.3);
	in1.push_back(-0.9);

	in2.push_back(-0.1);
	in2.push_back(0.6);
	in2.push_back(-0.1);
	r.matriceNeurones[1][0].poidsSynaptiques=in1;
	r.matriceNeurones[1][1].poidsSynaptiques=in2;
	r.matriceNeurones[1][2].poidsSynaptiques=in1;

	r.matriceNeurones[2][0].poidsSynaptiques=in2;
	r.matriceNeurones[2][1].poidsSynaptiques=in1;
	r.matriceNeurones[2][2].poidsSynaptiques=in2;

	res=r.calculerResultat(in1);
	correct.push_back(0.625181);
	correct.push_back(0.431256);
	correct.push_back(0.625181);
	for (int i=0;i<res.size();i++)
	{
		//TODO
		//CPPUNIT_ASSERT(fabs(res[i]-correct[i])<1e-2);
	}
}

void Test_ReseauNeuronesCouche::test_ValeurAttendueCouchePrec()
{

}

