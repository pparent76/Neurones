#ifndef RESEAUNEURONECOUCHES_TEST_H
#define RESEAUNEURONECOUCHES_TEST_H

#include <cppunit/TestFixture.h>
#include <cppunit/extensions/HelperMacros.h>
#include <iostream>

#include"../src/Image.h"


using namespace std;


class Test_ReseauNeuronesCouche : public CppUnit::TestFixture
{
	CPPUNIT_TEST_SUITE( Test_ReseauNeuronesCouche );
	CPPUNIT_TEST(test_Constructeur);
	CPPUNIT_TEST(test_Constructeur2);
	CPPUNIT_TEST(test_CoherenceTailleCouche);
	CPPUNIT_TEST(test_ValeurCouche);
	CPPUNIT_TEST(test_setEntree);
	CPPUNIT_TEST(test_ValeurSortie);
	CPPUNIT_TEST(test_ValeurAttendueCouchePrec);
	CPPUNIT_TEST_SUITE_END();

public:
	//~ Call before tests
	void setUp(void);
	//~ Call after tests
	void tearDown(void);

	void test_Constructeur();
	void test_Constructeur2();
	void test_CoherenceTailleCouche();
	void test_ValeurCouche();
	void test_setEntree();
	void test_ValeurSortie();
	void test_ValeurAttendueCouchePrec();
};

#endif

