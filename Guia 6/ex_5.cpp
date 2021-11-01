#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

int busca_pos(const vector<int> &v, int p){
	int pos = 0;
	while(pos<v.size() && p>v[pos]) ++pos;
	return pos;
}
	
void inserta(vector<int> &v, int p){
	int aux = busca_pos(v,p);
	v.resize(v.size()+1);
	for(int i=v.size()-1;i>aux;--i){
		v[i]=v[i-1];
	}
	v[aux] = p;
}	

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
	void IngresarPuntaje(int p){
		inserta(v,p);
	};
	void GuardarArchivo(){
		for(size_t i=0;i<v.size();i++) { 
			file.write(reinterpret_cast<char*>(&v[i]),sizeof(v[i]));
		}
	}
	void Close(){
		file.close();
	}
};

int main() {
	
	Gestion a("puntajes.txt");
	a.IngresarPuntaje(15);
	a.GuardarArchivo();
	a.Close();
	
	return 0;
}

