#include <iostream>
#include <fstream>
using namespace std;

struct Par {
	int i;
	double d;
};

int main() {
	
	//con el operador | puedo usar mas de una bandera
	//ios::ate dice que empiece al final del archivo, entonces
	//tengo el "cursor" al final, entonces pregunto en que posicion
	//estoy
	ifstream  archi2("datos.dat",ios::binary|ios::ate);
	if(!archi2.is_open()){
		cout << "Error";
		return 1;
	}
	
	//calcular cuantos datos tiene mi archivo
	//con .tellg() me dice donde estoy parado en el archivo 
	//y como estoy al final, me dice el tamaño, dividido en el sizeof
	//del tipo de dato que estoy usando, me da la cantidad de datos
	//que tengo 
	int n = archi2.tellg()/sizeof(Par);
	//con .seekg(0) voy al ppio. del archivo, o a otra posicion
	//de ser necesario 
	archi2.seekg(0);
	
	for(int i=0;i<n;i++) { 
		Par p;
		archi2.read(reinterpret_cast<char*>(&p),sizeof(p));
		cout << p.i << "  " << p.d << endl;
	}
	
	return 0;
}

