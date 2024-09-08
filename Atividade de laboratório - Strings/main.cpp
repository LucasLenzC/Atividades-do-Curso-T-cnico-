#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <iomanip>
#include <sstream>



using namespace std;
int main(int argc, char **argv) {
	string vectorName = "alunos.csv";
	int numero;
	cout << "Fale o local de aruivo a ser procurado:" << endl;
	//cin >> vectorName;
	ifstream file;
	file.open(vectorName.c_str(), ios::in);
	if (!file) {
		cout << " nao pode ser aberto" << endl;
		abort();
	}
	string teste;
	while(getline(file,teste)) {
		cout<<teste;
	}

	file.close();
	return 0;
}

