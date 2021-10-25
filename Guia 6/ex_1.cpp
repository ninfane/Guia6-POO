#include <iostream>
#include <vector>
#include <fstream>
#include <cstdlib>
using namespace std;

struct Par {
	int i;
	float f;
};

int main() {
	
	ofstream aout("grupo.dat",ios::binary);
	if(!aout.is_open()){
		cout << "error";
		return 1;
	}
	
	vector<Par> v(200);
	for(size_t i=0;i<v.size();i++) { 
		v[i].i = rand()%101;
		v[i].f = (rand()%101)/20.5;
	}
	
	for(size_t i=0;i<v.size();i++) { 
		aout << v[i].i << " " << v[i].f << endl;
	}
	
	aout.close();
	
	ifstream ain("grupo.dat",ios::binary);
	
	Par p;
	while(ain>>p.i and ain>>p.f){
		cout << p.i << " " << p.f << endl;
	}
	ain.close();
	
	return 0;
}

