CP=g++ -g
CPPUNIT_PATH=/opt/cppunit
CFLAGS=-pedantic -Wall -c -W

#--------------------Executable---------------
main:obj/Main.o obj/Image.o obj/Neurone.o obj/ReseauNeuronesCouches.o obj/Sigmoide.o obj/IHM.o
	$(CP) `sdl-config --cflags --libs` $^ -o $@
#--------------------Objets-------------------
obj/Image.o:src/Image.cpp
	$(CP) $^ -o $@ -c
obj/Neurone.o:src/Neurone.cpp
	$(CP) $^ -o $@ -c
obj/ReseauNeuronesCouches.o:src/ReseauNeuronesCouches.cpp
	$(CP) $^ -o $@ -c
obj/Sigmoide.o:src/Sigmoide.cpp
	$(CP) $^ -o $@ -c
obj/IHM.o:src/IHM.cpp
	$(CP) $^ -o $@ -c
obj/Main.o:src/main.cpp
	$(CP) $^ -o $@ -c
obj/IHM.o:src/IHM.cpp
	$(CP) $^ -o $@ -c

default:main

rapport:
	make -C rapport
documentation:
	make -C doc
tests:
	make -C test
clean:
	rm -vf src/*~..
	rm -vf doc/*~
	rm -vf test/*~
	rm -vf obj/*
	rm -vf *~
	rm -vf main
	make -C test clean
	make -C doc clean
	make -C rapport clean
