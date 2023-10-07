#include <iostream>
#include "Mapalugares.h"
#include "Lugar.h"
#include "Carretera.h"
#include "AVL.h"
using namespace std;
int main(void){
   string comando;
   while (cin >> comando) {
   	string param[4];
    string parametros;
	getline(cin, parametros);
	funsep(parametros, param);
 	interpretecomandos(comando, param[0], param[1], param[2], param[3]);
	
	
 }
}
