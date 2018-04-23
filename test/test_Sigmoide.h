#ifndef SIGMO_TEST_H
#define SIGMO_TEST_H

#include <cppunit/TestFixture.h>
#include <cppunit/extensions/HelperMacros.h>
#include <iostream>

#include"../src/Image.h"


using namespace std;


class Test_Sigmoide : public CppUnit::TestFixture
{
	CPPUNIT_TEST_SUITE( Test_Sigmoide );
	CPPUNIT_TEST( test_Fonction );
	CPPUNIT_TEST( test_Inverse );
	CPPUNIT_TEST( test_derive );
	CPPUNIT_TEST_SUITE_END();

public:
	//~ Call before tests
	void setUp(void);
	//~ Call after tests
	void tearDown(void);

	void test_Fonction();
	void test_Inverse();
	void test_derive();


protected:
	Image *a,*b;
};

#endif

