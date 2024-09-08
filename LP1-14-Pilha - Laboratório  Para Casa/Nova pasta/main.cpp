#include <iostream>
#include "Pilha.hpp"
int main(int argc, char **argv) {
	Pilha pilha;
	Pilha pilha2;

		int item,u;
		int max = 4;
		for (int i = 0; i < max; i++) {
				item = i;
				if (pilha.inserirPilha(item)) {
					cout << "Empilhou: " << item << endl;
				} else {
					cout << "N o empilhou: " << item << endl;
				}
			}
			for (int i = 0; i < max; i++) {
				item = 9;
				if (pilha2.inserirPilha(item)) {
					cout << "Empilhou: " << item << endl;
				} else {
					cout << "N o empilhou: " << item << endl;
				}
			}
			bool certo;
			pilha.somarPilha(&u);
//			certo = pilha.consultarPilha(&u);
			cout<<u;

}



