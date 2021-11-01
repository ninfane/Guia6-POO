#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>
#include <algorithm>
using namespace std;
class Gestion{
private:
	fstream file;
	vector<int> v;
public:
	Gestion(string name): file(name,ios::binary|ios::in|ios::out|ios::ate) {
		int n = file.tellg()/sizeof(int);
		file.seekg(0);
		for(int i=0;i<n;i++) { 
			int x;
			file.read(reinterpret_cast<char*>(&x),sizeof(x));
			v.push_back(x);
		}
		sort(v.begin(),v.end());
	}
};
int main() {
	
	ofstream archi("notas.txt",ios::binary);
	if(!archi.is_open()){
		cout <<  "error";
		return 1;
	}
	
	for(int i=0;i<10;i++) { 
		int x = rand()%11;
		archi.write(reinterpret_cast<char*>(&x),sizeof(x));
	}
	
	Gestion a("notas.txt");
	
	
	archi.close();
	
	return 0;
}

