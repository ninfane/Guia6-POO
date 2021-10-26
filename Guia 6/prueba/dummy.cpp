#include <iostream>
#include <fstream>
using namespace std;

int main() {
	
	ofstream archi("dummy.dat",ios::binary|ios::in|ios::out);
	
	int insertar = 5;
	int pos = 4;
	
	archi.seekp(pos*sizeof(insertar));
	archi.write(reinterpret_cast<char*>(&insertar),sizeof(insertar));
	
	archi.close();
	
	return 0;
}

