#include <iostream>
#include <fstream>
using namespace std;

int main() {
	
	ifstream archi("enteros.dat",ios::binary|ios::ate);
	if(!archi.is_open()){
		cout << "error";
		return 1;
	}
	
	int n = archi.tellg()/sizeof(int);
	archi.seekg(0);
	
	for(int i=0;i<n;i++) { 
		int x;
		archi.read(reinterpret_cast<char*>(&x),sizeof(x));
		cout << x << endl;
	}
	archi.close();
	
	return 0;
}

