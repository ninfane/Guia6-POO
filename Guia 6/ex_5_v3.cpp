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

class Puntaje{
private:
	fstream archi;
	vector<int> v;
	int m_size;
public:
	Puntaje(string name): archi(name,ios::binary|ios::in|ios::out|ios::ate){
		m_size = archi.tellg()/sizeof(int);
		for(int i=0;i<m_size;i++) { 
			int x;
			archi.read(reinterpret_cast<char*>(&x),sizeof(int));
			v.push_back(x);
		}
		sort(v.begin(),v.end());
	}
	void IsOpen() {
		if(!archi.is_open()) cout << "error";
	}
	int VerSize() const { return m_size; }
	void NuevoPuntaje(int p){
		int pos = busca_pos(v,p);
		if(pos!=0){
			inserta(v,p);
			v.resize(v.size()-1);
		}
	}
	void Sobreescribir(){
		archi.seekp(0);
		for(int i=0;i<m_size;i++) { 
			archi.write(reinterpret_cast<char*>(&v[i]),sizeof(int));
		}
	}
	void VerReg(int i){
		archi.seekg(0);
		int x;
		archi.seekg(i*sizeof(int));
		archi.read(reinterpret_cast<char*>(&x),sizeof(int));
		cout << x << endl;
	}
	void Close(){
		archi.close();
	}
	void VerVector() const {
		for(size_t i=0;i<v.size();i++) { 
			cout << v[i] << " ";
		}
		cout << endl;
	}
};

int main() {
	
	Puntaje a("puntajes.dat");
	a.IsOpen();
	
	int n = a.VerSize();
	cout << n << endl;
	
	a.VerVector();
	
	return 0;
}

