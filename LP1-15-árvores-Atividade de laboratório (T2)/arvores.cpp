#include "arvores.h"
#include <iostream>



arvores::arvores() {
	for (int i = 0; i < 8; i++) {
		array[i] = 0;
	}
}
void arvores::root(int num) {

	array[0] = num;

}
void arvores::setLeft(int x, int raiz){
	int Fe = (raiz * 2) + 1; //Fe = Filha Esquerda
	array[Fe] = x;
}
void arvores::setRight(int x, int raiz){
	int Fd = (raiz * 2) + 2; //Fr = FIlha direita
	array[Fd] = x;
}

void arvores::printArvore() {
	for (int i = 0; i < 8; ++i) {
		if (array[i] != '\0') {
			std::cout << array[i] << " ";
		}
	}
}


