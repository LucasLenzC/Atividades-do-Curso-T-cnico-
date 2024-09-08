#include <iostream>
#include "bolas.hpp"
using namespace std;
void questao1() {

	int *resultadoTeste = new int[5];
	for (int i = 0; i < 5; ++i) {
		resultadoTeste[i] = i;
	}
	for (int i = 0; i < 5; ++i) {
		cout << resultadoTeste[i]<< ",";
	}
	delete resultadoTeste;
}
void questao2() {
	int **resultadoTeste = new int *[4];
	for (int i = 0; i < 4; ++i) {
		resultadoTeste[i] = new int[4];
	}
	for (int i = 0; i < 4; ++i) {
		for (int j = 0; j < 4; ++j) {
			resultadoTeste[i][j] = j + i;
		}
	}
	for (int i = 0; i < 4; ++i) {
			for (int j = 0; j < 4; ++j) {
				cout << resultadoTeste[i][j]<< ",";
			}
		}


	delete resultadoTeste;
}

int main(int argc, char **argv) {
//	questao1();
//	questao2();
	mainBolaSoluction();

}

