#include <iostream>
#include <cstdlib>
#include <fstream>
using namespace std;

struct Par {
	int i;
	double d;
};

int main() {
	
	//abro el archivo de forma binaria
	ofstream archi("datos.dat",ios::binary);
	if(!archi.is_open()){
		cout << "Error";
		return 1;
	}
	
	for(int i=0;i<10;i++) { 
		Par p;
		p.i = rand()%100+1;
		//random para dobles
		p.d = (rand()%1001)/1000.0;
		archi.write(reinterpret_cast<char*>(&p),sizeof(p));
	}
	
	archi.close();
	
	ifstream archi2("datos.dat",ios::binary);
	for(int i=0;i<10;i++) { 
		Par p;
		archi2.read(reinterpret_cast<char*>(&p),sizeof(p));
		cout << p.i << "  " << p.d << endl;
	}
	
	archi2.close();
	return 0;
}

