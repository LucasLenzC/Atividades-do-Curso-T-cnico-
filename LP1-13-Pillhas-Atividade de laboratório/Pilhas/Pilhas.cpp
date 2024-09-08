/*
 * Pilhas.cpp
 *
 *  Created on: 30 de jul de 2024
 *      Author: user
 */

#include "Pilhas.h"

Pilhas::Pilhas() {

	this->base = 1;
	this->topo = base - 1;
}
bool Pilhas::InserirPilha(int valor) {
	bool sucesso;

	if (topo < limite) {
		topo++;
		valores[topo] = valor;
		sucesso = true;
	} else {
		sucesso = false;
	}

	return sucesso;
}
bool Pilhas::ConsultarPilha(int *valorDoTopo) {
	bool sucesso;

	if (topo >= base) {
		*valorDoTopo = valores[topo];
		sucesso = true;
	} else {
		sucesso = false;
	}

	return sucesso;
}

bool Pilhas::RemoverPilha(int *valorRemovido) {
	bool sucesso;

	if (topo >= base) {
		*valorRemovido = valores[topo];
		topo--;
		sucesso = true;
	} else {
		sucesso = false;
	}

	return sucesso;
}


