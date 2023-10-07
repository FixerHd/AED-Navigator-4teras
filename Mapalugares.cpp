#include <iostream>
#include <list>
#include <stdlib.h>
#include "Lugar.h"
#include "Mapalugares.h"
#include "Carretera.h"
using namespace std;

int totalcarreteras=0;
int hashe(string word)   
// POST: the index of entry is returned
{       int sum = 0;
        for (int k = 0; k < word.length(); k++)
            sum = sum + int(word[k]);
        return  sum % 1000; 
}

int clave(string s){
	return hashe(s);
}	


TablaHash::TablaHash(){
	B=0;
	nElem=0;
}

Mapalugares::Mapalugares(){};

void TablaHash::vacia(){
	for(int i=0;i<1000;i++){
	 if(!T[i].empty()){
	 T[i].clear();
	 }
	 }
	 nElem=0;
}
void Mapalugares::vaciar() {
   tabla.vacia();
}

	

void TablaHash::inserta(Lugar L) {
	if(T[clave(L.getnombre())].empty()){
		T[clave(L.getnombre())].push_front(L);
		nElem++;
		return;
	}
	list<Lugar>::iterator it;
	it=T[clave(L.getnombre())].begin();
	
	while(it!=T[clave(L.getnombre())].end()&&(it->getnombre().compare(L.getnombre())<0)){
		it++;
	}   
	if(it==T[clave(L.getnombre())].end()){
		T[clave(L.getnombre())].push_back(L);
		nElem++;

	}
	else if((it)->getnombre().compare(L.getnombre())==0){
		it->cambiar(L.getnombre(), L.getinfo());
	}
	else{
		T[clave(L.getnombre())].insert(it, L);
		nElem++;
	}	
	
   
}

void Mapalugares::insertar(Lugar L){
	tabla.inserta(L);
}

   

Lugar * TablaHash::consulta(string nombre) {
   list<Lugar>::iterator it;
   for (it= T[clave(nombre)].begin(); it!=T[clave(nombre)].end(); it++){
   		if(nombre.compare((*it).getnombre())==0) return &(*it);
   }
   return NULL;
}

Lugar * Mapalugares::consultar(string nombre){
    return tabla.consulta(nombre);
}

void Mapalugares::insertarCarretera (string origen, string destino, int coste, string informacion){
   if(tabla.consulta(origen)!=NULL && tabla.consulta(destino)!=NULL){
   	Carretera car=Carretera(destino, coste, informacion);
   	consultar(origen)->insertarcarretera(car);
}
}
Carretera * Mapalugares::consultarCarretera (string origen, string destino)
{
  if(tabla.consulta(origen)!=NULL){
     if(consultar(origen)->consultarcarretera(destino)!=NULL){
	return consultar(origen)->consultarcarretera(destino);
     }
}
return NULL;
}
void Mapalugares::listarAdyacentes (string origen) {
   if(tabla.consulta(origen)!=NULL){
   	cout<<"Encontrado: "<<origen<<endl;
        cout<<"Adyacentes: ";
        tabla.consulta(origen)->listaradyacentes();
        cout<<endl;
}else{ cout<<"No encontrado: "<<origen<<endl;}
} 


Mapalugares mapa;


void inicializar(){
   mapa.vaciar();
   totalcarreteras=0;
   cout << "Mapa inicializado" << endl;
}

void insertarlugar(string nombre, string info)
{
   Lugar L(nombre, info);
   mapa.insertar(L);
   cout <<"Añadido: "<<nombre<<". Total: "<< mapa.nLugares()<<" lugares"<<endl;
}

void AL(string nombre){
	Lugar L(nombre, "");
    mapa.insertar(L);
}


void listarlugares(){
	cout<<"Total: "<<mapa.nLugares()<<" lugares"<<endl;
}

void consultarlugar(string nombre){
	if(mapa.consultar(nombre)!=NULL){
	cout<<"Encontrado: "<<nombre<<endl;
	cout<<"Información: "<<mapa.consultar(nombre)->getinfo()<<endl;
	
}else{
	cout<<"No encontrado: "<<nombre<<endl;
}
}

void insertarcarretera (string orig, string dest, string coste, string info) {
    	if((mapa.consultar(orig)!=NULL) && (mapa.consultar(dest)!=NULL)){
    	if(mapa.consultarCarretera(orig,dest)==NULL && orig.compare(dest)!=0) totalcarreteras++; 
    	 if(orig.compare(dest)!=0) {mapa.insertarCarretera(orig,dest,atoi(coste.c_str()),info);
	cout<<"Añadido: "<<orig<<"-"<<dest<<". Total: "<<totalcarreteras<<" carreteras"<<endl;
	}
 }
}

void AC (string orig, string dest, string coste) {
	if((mapa.consultar(orig)!=NULL) && (mapa.consultar(dest)!=NULL)){
        if(mapa.consultarCarretera(orig,dest)==NULL && orig.compare(dest)!=0) totalcarreteras++;
    	 if(orig.compare(dest)!=0) mapa.insertarCarretera(orig,dest,atoi(coste.c_str()),"");
 }
}

void listaradyacentes(string nombre){
	mapa.listarAdyacentes(nombre);
}

void consultarcarretera (string origen, string destino)
{
  if(mapa.consultarCarretera(origen, destino)!=NULL){
  cout <<"Encontrado: "<<origen<<"-"<<destino<<endl; 
  cout<<"Coste: "<<mapa.consultarCarretera(origen, destino)->getcoste()<<endl;
  cout<<"Información: "<<mapa.consultarCarretera(origen, destino)->getinfo()<<endl;
  }else{
  cout <<"No encontrado: "<<origen<<"-"<<destino<<endl; 
}
}

void calcularruta(string origen, string destino){
	cout<<"No existe ningún camino entre "<<origen<<" y "<<destino<<endl;
}
void funsep(string linea, string param[4]){
	int counter = 0;
	string aux = "";
	for(unsigned int i = 1; i<linea.length();i++){
		if(linea[i]==','){
			param[counter] = aux;
			counter++;
			aux="";
		}else{
			aux += linea[i];
		
	}
		
	}
	
	param[counter] = aux;
}

void interpretecomandos(string comando, string nombre, string info, string info2, string info3){
	if(comando == "Inicializar") inicializar();
	else if(comando == "AñadirLugar") insertarlugar(nombre, info);
	else if(comando == "AL") AL(nombre);
	else if(comando == "AC") AC(nombre, info, info2);
	else if(comando == "AñadirCarretera") insertarcarretera(nombre, info, info2, info3);
	else if(comando == "ConsultarLugar") consultarlugar(nombre);
	else if(comando == "ListarAdyacentes") listaradyacentes(nombre);
	else if(comando == "ListarLugares") listarlugares();
	else if(comando == "ConsultarCarretera") consultarcarretera(nombre, info);
	else if(comando == "CalcularRuta") calcularruta(nombre, info);
}



