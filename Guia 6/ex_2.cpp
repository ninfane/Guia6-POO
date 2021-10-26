#include <iostream>
#include <fstream>
using namespace std;

struct Par {
	int i;
	float f;
};

int main() {
	
	fstream archi("grupo.dat",ios::binary|ios::in|ios::out|ios::ate);
	if(!archi.is_open()){
		cout << "error";
		return 1; 
	}
	
	int n = archi.tellg()/sizeof(Par);
	cout << "Size: " << n << endl;
	archi.seekg(0);
	
	cout << "Ingrese un entero, un flotante y una posicion " << endl;
	int e, pos; float f;
	cin >> e >> f >> pos;
	
	Par nuevo = {e,f};
	pos--;
	archi.seekp(pos*sizeof(Par));
	archi.write(reinterpret_cast<char*>(&nuevo),sizeof(nuevo));
	
	archi.close();
	
	return 0;
}

