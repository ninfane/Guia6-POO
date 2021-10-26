#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

struct Par {
	int i;
	double d;
};

int main() {
	fstream f("pares.dat",ios::binary|ios::ate|ios::in|ios::out);
	if (not f.is_open()) {
		cerr << "No lo encuentro :(" << endl;
		return 1;
	}
	
	int tamanio_archivo = f.tellg();
	int n = tamanio_archivo / sizeof(Par);
	
	f.seekg(0);
	
	Par p, p_may = { 0, -1 };
	int i_mayor;
	for (int i=0; i<n; ++i) {
		f.read(reinterpret_cast<char*>(&p),sizeof(Par));
		if (p.d>p_may.d) {
			p_may = p;
			i_mayor = i;
		}
	}
	
	cout << i_mayor << endl;
	
	p_may.i = 42;
	f.seekp(i_mayor*sizeof(Par));
	f.write(reinterpret_cast<char*>(&p_may),sizeof(Par));
	
	
	return 0;
}

