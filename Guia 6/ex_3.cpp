#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>
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
	
int main() {
	
	ofstream archi("enteros.dat",ios::binary);
	if(!archi.is_open()){
		cout << "error";
		return 1;
	}
	
	vector<int> v(10);
	for(size_t i=0;i<v.size();i++) { 
		v[i] = rand()%101;
	}
	
	sort(v.begin(),v.end());
	for(size_t i=0;i<v.size();i++) { 
		archi.write(reinterpret_cast<char*>(&v[i]),sizeof(v[i]));
	}
	archi.close();
	
	//esto no hace falta es para ver que se haya escrito 
	//bien en el archivo
	/*
	ifstream archi2("enteros.dat",ios::binary);
	for(size_t i=0;i<v.size();i++) { 
		int x;
		archi2.read(reinterpret_cast<char*>(&x),sizeof(x));
		cout << x << endl;
	}
	archi2.close();
	*/
	
	cout << "Ingrese un numero a insertar" << endl;
	int num; cin >> num;
	
	inserta(v,num);
	
	ofstream archi2("enteros.dat",ios::binary);
	if(!archi2.is_open()){
		cout << "error";
		return 1; 
	}
	
	for(size_t i=0;i<v.size();i++) { 
		archi2.write(reinterpret_cast<char*>(&v[i]),sizeof(v[i]));
	}
	archi2.close();
	
	return 0;
}

