#include <iostream>
#include <fstream>
using namespace std;

struct Par {
	int i;
	float f;
};

int main() {
	
	fstream archi("grupo.dat",ios::binary|ios::in|ios::out);
	if(!archi.is_open()){
		cout << "error";
		return 1;
	}
	
	cout << "Ingrese entero, flotante y posicion" << endl;
	int e, pos; float f;
	cin >> e >> f >> pos;
	
	pos = pos-1;
	Par nuevo = {e,f};
	
	archi.seekp(pos*sizeof(Par));
	archi.write(reinterpret_cast<char*>(&nuevo),sizeof(nuevo));
	
	archi.close();
	
	return 0;
}

