# file: makefile
# next line has to be changed to the installation-path of CppUnit
CPPUNIT_PATH=/opt/cppunit
CP=gcc -g
FLAGS=-lstdc++ -lcppunit -ldl
OBJ=../obj/Image.o ../obj/Neurone.o ../obj/ReseauNeuronesCouches.o ../obj/Sigmoide.o
OBJ_TEST=main_test.o Image_test.o test_Neurone.o test_ReseauNeuronesCouches.o test_Sigmoide.o

#

etest:  $(OBJ_TEST) $(OBJ) 
	$(CP) -o $@ $^ -L$(CPPUNIT_PATH)/lib `sdl-config --cflags --libs` $(FLAGS)




Image_test.o:test_Image.cpp
	$(CP) $^ -o  $@ -c -I$(CPPUNIT_PATH)/include
	make -C .. obj/Image.o
test_Neurone.o:test_Neurone.cpp
	$(CP) $^ -o  $@ -c -I$(CPPUNIT_PATH)/include
	make -C .. obj/Neurone.o
test_ReseauNeuronesCouches.o:test_ReseauNeuronesCouches.cpp
	$(CP) $^ -o  $@ -c -I$(CPPUNIT_PATH)/include
	make -C .. obj/ReseauNeuronesCouches.o
test_Sigmoide.o:test_Sigmoide.cpp
	$(CP) $^ -o  $@ -c -I$(CPPUNIT_PATH)/include
	make -C .. obj/Sigmoide.o

main_test.o: main_test.cpp
	$(CP) $^ -o  $@ -c -I$(CPPUNIT_PATH)/include


clean:
	rm -vf *.o
	rm -vf etest
	rm -vf *~ src/*~ 
	rm -vf *.xml