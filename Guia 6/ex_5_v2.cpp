#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cstdlib>
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

int main() {
	
	ifstream archi("puntajes.dat",ios::binary|ios::ate);
	if(!archi.is_open()){
		cout << "error";
		return 1;
	}
	
	vector<int> aux;
	int n = archi.tellg()/sizeof(int);
	archi.seekg(0);
	
	for(int i=0;i<n;i++) { 
		int x;
		archi.read(reinterpret_cast<char*>(&x),sizeof(int));
		aux.push_back(x);
	}
	
	sort(aux.begin(),aux.end());
	for(size_t i=0;i<aux.size();i++) { 
		cout << aux[i] << " ";
	}
	cout << endl;
	
	cout << "Ingrese puntaje nuevo: " << endl;
	int p; cin >> p;
	
	int pos = busca_pos(aux,p);
	if(pos!=0){
		inserta(aux,p);
		//para eliminar la ultima posicion y que solo me muestre
		//los 10 mejores puntajes
		aux.resize(aux.size()-1);
	}

	for(size_t i=0;i<aux.size();i++) { 
		cout << aux[i] << " ";
	}
	cout << endl;
	
	archi.close();
	
	ofstream archi2("puntajes.dat",ios::binary);
	for(size_t i=0;i<aux.size();i++) { 
		archi2.write(reinterpret_cast<char*>(&aux[i]),sizeof(int));
	}
	
	archi2.close();
	
	return 0;
}

