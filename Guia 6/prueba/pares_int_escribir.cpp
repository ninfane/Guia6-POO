#include <iostream>
#include <fstream>
#include <cstdlib>
#include <vector>
using namespace std;

struct Pares{
	int i1;
	int i2;
};

int main() {
	
	ofstream archi("datos.dat",ios::binary);
	
	vector<Pares> v(10);
	for(size_t i=0;i<v.size();i++) { 
		v[i].i1 = rand()%25;
		v[i].i2 = rand()%15;
	}
	
	for(size_t i=0;i<v.size();i++) { 
		Pares p = v[i];
		archi.write(reinterpret_cast<char*>(&p),sizeof(p));
	}
	
	archi.close();
	
	return 0;
}

