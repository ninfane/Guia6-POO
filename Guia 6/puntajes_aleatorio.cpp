#include <iostream>
#include <cstdlib>
#include <fstream>
using namespace std;

int main() {
	
	ofstream archi("puntajes.dat",ios::binary|ios::trunc);
	if(!archi.is_open()){
		cout << "error";
		return 1;
	}
	
	//genero los puntajes de forma aleatoria
	for(int i=0;i<10;i++) { 
		int x = rand()%101;
		archi.write(reinterpret_cast<char*>(&x),sizeof(float));
		cout << x << " ";
	}
	
	archi.close();
	
	return 0;
}

