#include <iostream>
#include <fstream>
using namespace std;

int main() {
	fstream f("pares.dat",ios::binary|ios::in);
	cout << f.is_open();
	return 0;
}

