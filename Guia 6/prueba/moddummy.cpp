#include <iostream>
#include <fstream>
using namespace std;

int main() {
	
	fstream archi("harta.dat",ios::binary|ios::in|ios::out);
	
	int x = 100;
	int pos = 2-1;
	
	archi.seekp(pos*sizeof(int));
	archi.write(reinterpret_cast<char*>(&x),sizeof(x));
	
	archi.close();
	
	return 0;
}

