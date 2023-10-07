#include"AVL.h"
#include <iostream>
using namespace std;
Nodo::Nodo(){
	altura=-1;
	der=NULL;
	izq=NULL;
}
Nodo::Nodo(Carretera c){
	car=c;
	altura=0;
	der=NULL;
	izq=NULL;
}
AVL::AVL(){
	raiz=NULL;
	contador=0;
}
int AVL::altura(Nodo* root){
	if(root==NULL){
		return -1;
	}
	else{
		return root->altura;
	}
}

void AVL::RSD(Nodo* &a){
	if(a!=NULL && a->der!=NULL){
		Nodo*b=a->der;
		a->der=b->izq;
		b->izq=a;
		a->altura=1+max(altura(a->izq),altura(a->der));
		b->altura=1+max(a->altura,altura(b->der));
		a=b;
	}
	
	
}
void AVL::RSI(Nodo* &b){
	if(b!=NULL && b->izq!=NULL){	
	Nodo*a=b->izq;
	b->izq=a->der;
	a->der=b;
	b->altura=1+max(altura(b->izq),altura(b->der));
	a->altura=1+max(b->altura,altura(a->izq));
	b=a;
	}

	
}


void AVL::RDD(Nodo* &a){
	RSI(a->der);
	RSD(a);
}

void AVL::RDI(Nodo* &a){
	RSD(a->izq);
	RSI(a);
}

void AVL::insertar(Carretera c){
	insertar(c,raiz);
}
void AVL::insertar(Carretera c,Nodo*&a){
	if(a==NULL){
		a=new Nodo(c);
		contador++;	
	}
	else{
		if(c.getdestino().compare(a->car.getdestino())<0){
			insertar(c,a->izq);
		if((altura(a->izq))-(altura(a->der))>1){
		if(c.getdestino().compare(a->izq->car.getdestino())<0){
				RSI(a);
			}
   			else{
				RDI(a);
				}
			}
			else{
				a->altura=1+max(altura(a->izq),altura(a->der));
			}
		}
		else if(c.getdestino().compare(a->car.getdestino())>0){
		insertar(c,a->der);
		   if((altura(a->der))-(altura(a->izq))>1){
			if(c.getdestino().compare(a->der->car.getdestino())<0){
				RSD(a);
			}
			else{
 			RDD(a);
			}
			}
			else{
				a->altura=1+max(altura(a->izq),altura(a->der));
			}
		}
		else{
			a->car.setcoste(c.getcoste());
			a->car.setinfo(c.getinfo());
		}	
	}	
	
}
Carretera* AVL::consultar(string destino){
	return consultar(destino,raiz);
}
Carretera* AVL::consultar(string destino,Nodo*a){
	if(a==NULL) return NULL;
	
	else if(a->car.getdestino().compare(destino)==0){
		Carretera *c=&(a->car);
		return c;
	}
	else if(a->car.getdestino().compare(destino)<0){
		return consultar(destino,a->der);
	}
	else{
		return consultar(destino,a->izq);
	}
}
void AVL::listar(Nodo* a) {
   if(a!=NULL){
	this->listar(a->izq);
	if(a->izq!=NULL){cout<<", ";}
	cout<<a->car.getdestino();
	if(a->der!=NULL){cout<<", ";}
     	this->listar(a->der);
	}
}
void AVL::listar(){
	listar(raiz);	
}

