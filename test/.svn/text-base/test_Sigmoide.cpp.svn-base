#include"test_Sigmoide.h"
#include "../src/Sigmoide.h"
#include <math.h>

CPPUNIT_TEST_SUITE_REGISTRATION( Test_Sigmoide );


void Test_Sigmoide::setUp(void )
{

}

void Test_Sigmoide::tearDown(void )
{

}

void Test_Sigmoide::test_Fonction()
{
	CPPUNIT_ASSERT( fabs(Sigmoide::f(0))<1e-5);
	CPPUNIT_ASSERT( fabs(Sigmoide::f(1000)-1)<1e-2);
	CPPUNIT_ASSERT( fabs(Sigmoide::f(-1000)+1)<1e-2);
}

void Test_Sigmoide::test_Inverse()
{
	CPPUNIT_ASSERT( fabs(Sigmoide::f_inverse(Sigmoide::f(0.5))-0.5)<1e-5 );
}

void Test_Sigmoide::test_derive()
{
	double h=1e-10;
	double x=2;
	CPPUNIT_ASSERT( (Sigmoide::f(x+h)-Sigmoide::f(x))/h-Sigmoide::f_derive(x)<1e-5);
}
