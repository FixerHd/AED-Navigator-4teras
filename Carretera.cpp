#include "Carretera.h"
#include <iostream>
using namespace std;

Carretera::Carretera(){
	destino="";
	coste=0;
	info="";
}

void Carretera::setcoste(int cost){
	coste=cost;
}
void Carretera::setdestino(string dest){
	destino=dest;
}
void Carretera::setinfo(string finfo){
	info=finfo;
}
Carretera::Carretera(string dest, int cost, string finfo){
	destino=dest;
	coste=cost;
	info=finfo;
}

