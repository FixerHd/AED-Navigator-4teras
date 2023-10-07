#ifndef Lugar_H
#define Lugar_H
#include "Carretera.h"
#include "AVL.h"
#include <iostream>
using namespace std;
class Lugar
{	
	private:
	 string nombre;
	 string info;
	 AVL adyacente;
	
	public:
	 Lugar(string, string);
	 Lugar();
	 string getnombre(){ return nombre; }
	 string getinfo(){ return info; }
	 void cambiar(string, string);
	 void insertarcarretera (Carretera c){ adyacente.insertar(c); }
	 Carretera *consultarcarretera (string destino){return adyacente.consultar(destino);}
	 void listaradyacentes (){adyacente.listar();}
         AVL getAVL(){return adyacente;}
};



#endif
