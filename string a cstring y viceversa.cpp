#include <iostream>
#include <cstring>
#include <fstream>
using namespace std;

int main() {
	
	string greeting = "Hola mundo";
	char aux[256];
	strcpy (aux,greeting.c_str());
	
	ofstream archi("archi.txt",ios::binary);
	archi.write(aux,sizeof(aux));
	
	archi.close();
	
	char aux2[256];
	ifstream archi2("archi.txt",ios::binary);
	archi2.read(aux2,sizeof(aux2));
	string str = aux;
	cout << str << endl;
	
	archi2.close();
	
	return 0;
}

