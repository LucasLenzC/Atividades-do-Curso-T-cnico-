#include <iostream>
#include "Pilhas.h"
using namespace std;
int main(int argc, char **argv) {
	int valor, valorRemovido, ValorTopo;
	Pilhas pilha;
	bool resutdo;
	for (int i = 0; i <= 20; ++i) {
		resutdo = pilha.InserirPilha(i);
		if (!resutdo) {
			cout << "Nao foi possivel inserir o valor " << i << endl;
		}
	}
	resutdo = pilha.RemoverPilha(&valorRemovido);
	if (!resutdo) {
		cout << "Nao foi possivel remover o topo da pilha!" << endl;
	}
	cout << "Valor Removido: " << valorRemovido << endl;
	resutdo = pilha.ConsultarPilha(&ValorTopo);
	if (!resutdo) {
		cout << "Nao foi possivel remover o topo da pilha!" << endl;
	}
	cout << "Valor do Topo: " << ValorTopo << endl;

}

