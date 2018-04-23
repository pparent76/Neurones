#ifndef NEURONE_TEST_H
#define NEURONE_TEST_H

#include <cppunit/TestFixture.h>
#include <cppunit/extensions/HelperMacros.h>
#include <iostream>

#include"../src/Image.h"


using namespace std;


class Test_Neurone : public CppUnit::TestFixture
{
	CPPUNIT_TEST_SUITE( Test_Neurone );
	CPPUNIT_TEST(test_Constructeur);
	CPPUNIT_TEST(test_CalculeValeurTransphert);
	CPPUNIT_TEST(test_ValeurEntree);
	CPPUNIT_TEST(test_ValeurSortie);
	CPPUNIT_TEST_SUITE_END();

public:
	//~ Call before tests
	void setUp(void);
	//~ Call after tests
	void tearDown(void);

	void test_Constructeur();
	void test_CalculeValeurTransphert();
	void test_ValeurEntree();
	void test_ValeurSortie();
};

#endif

