#include <iostream>
#include "Lugar.h"
#include "AVL.h"
using namespace std;


Lugar::Lugar(string name, string inf){
	nombre = name;
	info = inf;
}

Lugar::Lugar(){}

void Lugar::cambiar(string nome, string finfo){
	nombre=nome;
	info=finfo;
}
