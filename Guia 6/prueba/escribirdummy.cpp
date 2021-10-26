#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;

int main() {
	
	ofstream archi("harta.dat",ios::binary);
	
	for(int i=0;i<20;i++) { 
		int x = rand()%26;
		archi.write(reinterpret_cast<char*>(&x),sizeof(x));
		cout << x << endl;
	}
	
	archi.close();
	
	return 0;
}

