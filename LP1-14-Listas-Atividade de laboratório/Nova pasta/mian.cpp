#include <iostream>
#include "Filas.h"
using namespace std;
int main(int argc, char **argv) {
	int numero;
	Filas fila;
	for (int j = 0; j < LimiteSuperior; ++j) {
		fila.InserirFila(j);
	}
	fila.RemoverFilaArr();
	fila.ConsultarFilaArr(&numero);


}
