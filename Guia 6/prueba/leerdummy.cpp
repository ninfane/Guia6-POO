#include <iostream>
#include <fstream>
using namespace std;

int main() {
	
	ifstream archi("harta.dat",ios::binary|ios::ate);
	
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

