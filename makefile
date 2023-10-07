# Un comentario de make
a.out: main.o Lugar.o Mapalugares.o Carretera.o AVL.o
	g++ main.o Lugar.o Mapalugares.o Carretera.o AVL.o

main.o: main.cpp Mapalugares.h Lugar.h AVL.h Carretera.h
	g++ -c main.cpp	

Lugar.o: Lugar.cpp Lugar.h AVL.h Carretera.h
	g++ -c Lugar.cpp
	
Mapalugares.o: Mapalugares.cpp Mapalugares.h Lugar.h Carretera.h
	g++ -c Mapalugares.cpp
	
Carretera.o: Carretera.cpp Carretera.h
	g++ -c Carretera.cpp
	
AVL.o: AVL.cpp AVL.h Carretera.h
	g++ -c AVL.cpp			
