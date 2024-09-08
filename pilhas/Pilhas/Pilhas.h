/*
 * Pilhas.h
 *
 *  Created on: 30 de jul de 2024
 *      Author: user
 */

#ifndef PILHAS_H_
#define PILHAS_H_
#define limite 10

class Pilhas {
private:
	int topo, base;
	int valores[limite];
public:
	Pilhas();

	bool InserirPilha(int valor);

	bool ConsultarPilha(int *valorDoTopo);

	bool RemoverPilha(int *valorRemovido);
};

#endif /* PILHAS_H_ */
