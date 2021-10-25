#include <iostream>
#include <fstream>
using namespace std;

struct Par {
	int i;
	double d;
};

int main() {
	
	//trabajo con fstream para lectura y escritura 
	//ios::in e ios::out porque voy a leer y escribir, pero ademas 
	//para que no me borre todo lo que no modifico 
	//e ios::ate para pararme al final
	fstream archi("datos.dat",ios::binary|ios::in|ios::out|ios::ate);
	if(!archi.is_open()){
		cout << "Error";
		return 1;
	}
	
	//calculo la cantidad de datos
	int n = archi.tellg()/sizeof(Par);
	archi.seekg(0);
	
	//recorro para buscar el mayor de los doubles
	Par mayor = {0,0};
	int pos_mayor;
	for(int i=0;i<n;i++) { 
		Par p;
		archi.read(reinterpret_cast<char*>(&p),sizeof(p));
		if(p.d>mayor.d){
			mayor = p;
			pos_mayor = i; //posicion como si fuese un array 
		}
	}
	
	//como busque la posicion, debo pararme ahi con seekp (en este caso)
	//seekp porque voy a escribir en esa posicion 
	archi.seekp(pos_mayor*sizeof(Par));
	mayor.i = 0; //el programa busca el mayor de los doubles
	//y pone su entero compañero en cero
	
	archi.write(reinterpret_cast<char*>(&mayor),sizeof(mayor));
	archi.close();
	
	return 0;
}

