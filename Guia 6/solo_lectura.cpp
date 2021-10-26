#include <iostream>
#include <fstream>
using namespace std;

struct Par {
	int i;
	float f;
};

int main() {
	
	ifstream archi("grupo.dat",ios::binary|ios::ate);
	if(!archi.is_open()){
		cout << "error";
		return 1;
	}
	
	int n = archi.tellg()/sizeof(Par);
	archi.seekg(0);
	
	for(int i=0;i<n;i++) { 
		Par p;
		archi.read(reinterpret_cast<char*>(&p),sizeof(p));
		cout << p.i << " " << p.f << endl;
	}
	
	archi.close();
	
	return 0;
}

