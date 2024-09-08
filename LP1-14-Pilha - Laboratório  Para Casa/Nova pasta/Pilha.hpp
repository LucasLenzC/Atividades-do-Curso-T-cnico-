#ifndef PILHA_HPP_
#define PILHA_HPP_

#include <iostream>

using namespace std;

#define InicioArranjo   1
#define MaxTam 100

class Dados {
private:
	int x;
public:
	Dados();

	int getDados() {
		return x;
	}

	void setDados(int valor) {
		this->x = valor;

	}

};

class Pilha {
private:
	int base, topo, limite;
	int pilha[MaxTam];
public:
	Pilha() {
		inicializarPilha();
	}

	void inicializarPilha() {
		base = 1;
		topo = base - 1;
		limite = 10;
	}

	int getTopo() {
		return topo;
	}

	bool inserirPilha(Dados valor) {
		if (topo < limite) {
			topo++;
			pilha[topo] = valor.getDados();
			return true;
		}
		return false;
	}
	bool inserirPilha(int valor) {
		if (topo < limite) {
			topo++;
			pilha[topo] = valor;
			return true;
		}
		return false;
	}

	bool removerPilha(int *valorRemovido) {

		if (topo >= base) {
			*valorRemovido = pilha[topo];
			topo--;
			return true;
		}
		return false;
	}

	bool consultarPilha(int *valorRemovido) {
		if (topo >= base) {
			*valorRemovido = pilha[topo];
			return true;
		}
		return false;
	}
	int removeTopo() {
		int valor;
		valor = pilha[topo];
		topo--;
		return valor;
	}

	bool empilharPilha(Pilha cima) {
		int topo2;
		int temp;
		topo2 = cima.getTopo();
		if ((topo + topo2) < limite) {
			for (int i = base; i <= topo2; i++) {
				temp = cima.removeTopo();
				inserirPilha(temp);
			}
			return true;
		} else {
			return false;
		}
	}
	bool dividirPilha() {
		int tamanho, x;
		if (topo % 2 == 0) { // @suppress("Assignment in condition")
			tamanho = topo / 2;
			for (int j = 0; j < tamanho; ++j) {
				removerPilha(&x);
			}
			return true;
		} else {
			cout << "A pilha não pode ser dividida" << endl;
			return false;
		}
	}
	bool somarPilha(int *Resultado) {
		int temp=0, x,soma;
		if (topo != 0) {
			for (int j = 0; j < topo; ++j) {
				consultarPilha(&x);
				soma = x +temp;
				temp = x;
			}
			*Resultado = soma;
			return true;
		} else {
			return false;
		}
	}
};

int testePilha() {

	Pilha pilha;
	Pilha pilha2;
	int item;
	int max = 50;

	/*Insere cada chave na lista */
	for (int i = 0; i < max; i++) {
		item = i;
		if (pilha.inserirPilha(item)) {
			cout << "Empilhou: " << item << endl;
		} else {
			cout << "N o empilhou: " << item << endl;
		}
	}
	for (int i = 0; i < max; i++) {
		item = i;
		if (pilha2.inserirPilha(item)) {
			cout << "Empilhou: " << item << endl;
		} else {
			cout << "N o empilhou: " << item << endl;
		}
	}
	pilha.empilharPilha(pilha2);
	int renato;
	pilha.consultarPilha(&renato);
	cout << renato;

	/*Retira cada chave da lista */
	while (pilha.removerPilha(&item) == true) {
		/*retira chave apontada */
		cout << "Desempilhou: " << item << endl;
	}

	return 0;
}

#endif /* PILHA_HPP_ */
