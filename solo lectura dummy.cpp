#include <iostream>
#include <fstream>
using namespace std;

struct Par {
	int i;
	double d;
};

int main() {
	
	ifstream archi2("datos.dat",ios::binary|ios::ate);
	int size = archi2.tellg()/sizeof(Par);
	archi2.seekg(0);
	
	for(int i=0;i<size;i++) { 
		Par p;
		archi2.read(reinterpret_cast<char*>(&p),sizeof(p));
		cout << p.i << "  " << p.d << endl;
	}
	
	archi2.close();
	
	return 0;
}

