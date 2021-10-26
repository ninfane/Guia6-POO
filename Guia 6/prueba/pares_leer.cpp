#include <iostream>
#include <fstream>
using namespace std;

struct Pares{
	int i1;
	int i2;
};

int main() {
	
	ifstream archi("datos.dat",ios::binary|ios::ate);
	
	int n = archi.tellg()/sizeof(Pares);
	archi.seekg(0);
	
	for(int i=0;i<n;i++) { 
		Pares aux;
		archi.read(reinterpret_cast<char*>(&aux),sizeof(aux));
		cout << aux.i1 << " " << aux.i2 << endl;
	}
	
	archi.close();
	
	return 0;
}

