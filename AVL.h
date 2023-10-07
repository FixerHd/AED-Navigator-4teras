#ifndef AVL_H
#define AVL_H
#include"Carretera.h"
#include<list>
using namespace std;
class Nodo{
	friend class AVL;
	private:
		Nodo*izq;
		Nodo*der;
		Carretera car;
		int altura;
	public:
		Nodo();
		Nodo(Carretera);
		~Nodo(){delete izq;delete der;};
};

class AVL{
	private:
		Nodo*raiz;
		int contador;
	public:
		AVL();
		~AVL(){delete raiz;}
		Nodo*getRaiz(){return raiz;}
		int altura(Nodo*);
		void RSD(Nodo* &);
		void RSI(Nodo* &);
		void RDD(Nodo* &);
		void RDI(Nodo* &);
		void insertar(Carretera c);
		void insertar(Carretera c,Nodo* &a);
		Carretera*consultar(string destino);
		Carretera*consultar(string destino,Nodo* a);

		void listar(Nodo* a);
		void listar();
	
};
#endif

