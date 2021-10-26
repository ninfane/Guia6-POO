#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>
using namespace std;

struct Par {
	int i;
	float f;
};

int main() {
	
	ofstream archi("grupo.dat",ios::binary);
	if(!archi.is_open()){
		cout << "Error";
		return 1;
	}
	
	vector<Par> v(20);
	//son 200, hago 20 para la prueba
	for(size_t i=0;i<v.size();i++) { 
		v[i].i = rand()%101;
		v[i].f = (rand()%1001)/20.5;
	}
	
	for(size_t i=0;i<v.size();i++) { 
		archi.write(reinterpret_cast<char*>(&v[i]),sizeof(v[i]));
	}
	
	archi.close();
	
	return 0;
}

