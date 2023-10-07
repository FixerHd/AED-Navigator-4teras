#include<iostream>
#ifndef Carretera_H
#define Carretera_H
using namespace std;
class Carretera{
 private:
	string destino;
	int coste;
	string info;
  public:
  	Carretera();
  	Carretera(string,int,string);
  	string getdestino(){return destino;}
  	void setdestino(string destino);
  	int getcoste(){return coste;}
  	void setcoste(int coste);
  	string getinfo(){return info;}
  	void setinfo(string info);

};


#endif
