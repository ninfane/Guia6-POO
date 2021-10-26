#include <iostream>
#include <fstream>
using namespace std;

struct Pares{
	int i1;
	int i2;
};

int main() {
	
	fstream archi("datos.dat",ios::binary|ios::in|ios::out|ios::ate);
	
	int n = archi.tellg()/sizeof(Pares);
	cout << "Size: " << n << endl;
	archi.seekg(0);
	
	Pares mayor = {0,0};
	int pos_mayor = 0;
	for(int i=0;i<n;i++) { 
		Pares p;
		archi.read(reinterpret_cast<char*>(&p),sizeof(p));
		if(p.i1>mayor.i1 and p.i2>mayor.i2){
			mayor = p;
			pos_mayor = i;
		}
	}
	
	archi.seekp(pos_mayor*sizeof(Pares));
	Pares nuevo = {0,0};
	
	archi.write(reinterpret_cast<char*>(&nuevo),sizeof(nuevo));
	
	archi.close();
	
	return 0;
}

