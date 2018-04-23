#include "test_Image.h"
#include "../src/Image.h"

CPPUNIT_TEST_SUITE_REGISTRATION( Image_Test );


void Image_Test::setUp(void )
{
	//nothing
}

void Image_Test::tearDown(void )
{
	//nothing
}

void Image_Test::test_Chargement()
{
	a=new Image("img_test/test_a.bmp");
	b=new Image("img_test/test_dummy.bmp");
	CPPUNIT_ASSERT( a->img!=NULL );
	CPPUNIT_ASSERT( b->img!=NULL );
}

void Image_Test::test_un_pixel()
{
	b=new Image("img_test/test_dummy.bmp");
	CPPUNIT_ASSERT( b->obtenirPixel(0,0)==1 );
	CPPUNIT_ASSERT( b->obtenirPixel(1,0)==0 );
	CPPUNIT_ASSERT( b->obtenirPixel(1,1)==1 );
	CPPUNIT_ASSERT( b->obtenirPixel(2,2)==1 );
}

void Image_Test::test_les_pixels()
{
	b=new Image("img_test/test_dummy.bmp");
	vector<double> correct;
	correct.push_back(50);
	correct.push_back(-50);
	correct.push_back(50);
	correct.push_back(-50);
	correct.push_back(50);
	correct.push_back(-50);
	correct.push_back(50);
	correct.push_back(-50);
	correct.push_back(50);
	CPPUNIT_ASSERT( b->obtenirPixels()==correct );
}

void Image_Test::test_lignes_colone()
{
	b=new Image("img_test/test_dummy.bmp");
	vector<int> correct;
	correct.push_back(2);
	correct.push_back(1);
	correct.push_back(2);
	correct.push_back(2);
	correct.push_back(1);
	correct.push_back(2);
	CPPUNIT_ASSERT( b->LigneColonne()==correct );
}
