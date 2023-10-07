#include <iostream>
#include <list>
#include "Lugar.h"
#include "Carretera.h"
#ifndef Mapalugares_H
#define Mapalugares_H
using namespace std;

class TablaHash {
  private:
     list<Lugar> T[1000];
     int B;
     int nElem;
  public:
     TablaHash ();
     void inserta (Lugar L);
     Lugar * consulta (string nombre);
     void vacia (void);
     int nTotal (void) {return nElem;}
};

class Mapalugares {
   friend class TablaHash;
   private:
     TablaHash tabla;
   public:
     Mapalugares ();
     void vaciar ();
     void insertar (Lugar L);
     Lugar * consultar (string nombre);
     int nLugares (void) {return tabla.nTotal();}
     void insertarCarretera (string, string, int, string);
     Carretera * consultarCarretera (string, string);
     void listarAdyacentes (string);
     
};

void inicializar();

void insertarlugar(string nombre, string info);

void insertarcarretera(string orig, string dest, string coste, string info);

void listarlugares();

void consultarlugar(string nombre);

void listaradyacentes(string nombre);

void consultarcarretera(string origen, string destino);

void calcularruta(string origen, string destino);
void funsep(string linea, string param[4]);

void interpretecomandos(string comando, string nombre, string info, string info2, string info3);
#endif
