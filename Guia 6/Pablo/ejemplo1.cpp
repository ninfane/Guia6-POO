#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

struct Par {
	int i;
	double d;
};

int main() {
	
	vector<Par> v;
	for (int i=0; i<10; ++i) {
		v.push_back( Par{ rand()%101,double(rand())/RAND_MAX } );
		cout << "Par #" << i << ": = { " << v[i].i << ", " << v[i].d << " }" << endl;
	}
	
	ofstream f( "pares.dat", ios::binary);
	for (size_t i=0; i<v.size(); ++i) {
		f.write( reinterpret_cast<const char*>(&v[i]), sizeof(Par) );
	}
	
	return 0;
}

