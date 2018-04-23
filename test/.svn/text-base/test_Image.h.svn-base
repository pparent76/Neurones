#ifndef IMAGE_TEST_H
#define IMAGE_TEST_H

#include <cppunit/TestFixture.h>
#include <cppunit/extensions/HelperMacros.h>
#include <iostream>

#include"../src/Image.h"


using namespace std;


class Image_Test : public CppUnit::TestFixture
{
	CPPUNIT_TEST_SUITE( Image_Test );
	CPPUNIT_TEST( test_Chargement );
	CPPUNIT_TEST( test_un_pixel );
	CPPUNIT_TEST( test_les_pixels );
	CPPUNIT_TEST( test_lignes_colone );
	CPPUNIT_TEST_SUITE_END();

public:
	//~ Call before tests
	void setUp(void);
	//~ Call after tests
	void tearDown(void);

	void test_Chargement();
	void test_un_pixel();
	void test_les_pixels();
	void test_lignes_colone();


protected:
	Image *a,*b;
};

#endif
