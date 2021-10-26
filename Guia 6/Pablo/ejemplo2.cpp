#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

struct Par {
	int i;
	double d;
};

int main() {
	ifstream f("pares.dat",ios::binary|ios::ate);
	if (not f.is_open()) {
		cerr << "No lo encuentro :(" << endl;
		return 1;
	}
	
	int tamanio_archivo = f.tellg();
	int n = tamanio_archivo / sizeof(Par);
	
	f.seekg(0);
	
	vector<Par> v(n);
	for (size_t i=0; i<v.size(); ++i) 
		f.read(reinterpret_cast<char*>(&v[i]),sizeof(Par));
	
	for (size_t i=0; i<v.size(); ++i) 
		cout << "#" << i << ": { " << v[i].i << ", " << v[i].d << "} " << endl;
	return 0;
}

