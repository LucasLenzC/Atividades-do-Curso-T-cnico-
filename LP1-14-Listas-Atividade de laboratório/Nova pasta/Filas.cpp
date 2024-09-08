/*
 * Filas.cpp
 *
 *  Created on: 6 de ago de 2024
 *      Author: user
 */

#include "Filas.h"
#include <iostream>
using namespace std;
Filas::Filas() {
	LimiteInicio = 1;

	IncioFila = FinalFila;
	FinalFila = LimiteInicio -1;
	//FinalFila = LimiteInicio - 1;
}
bool Filas::InserirFila(int x) {
	bool sucesso;
	if ((FinalFila != IncioFila - 1) && ((IncioFila != LimiteInicio) || (FinalFila != LimiteSuperior))) {
		if (IncioFila == LimiteInicio - 1) {
			IncioFila = FinalFila;
			FinalFila = LimiteInicio;
		} else if (FinalFila == LimiteSuperior) {
			FinalFila = LimiteInicio;
		} else {
			FinalFila = FinalFila + 1;
		}

		informacao[FinalFila] = x;
		sucesso = true;
	} else {
		sucesso = false;
	}
	return sucesso;
}
bool Filas::RemoverFilaArr() {
	bool sucesso;
	if (IncioFila != LimiteSuperior - 1) {
		if (IncioFila == FinalFila) {
			IncioFila = FinalFila;
			FinalFila = LimiteInicio -1;
		}else if(IncioFila == LimiteSuperior){
			IncioFila = LimiteInicio;
		}else{
			IncioFila = IncioFila +1;
		}
		sucesso = true;
	}else{
		sucesso = false;
	}
	return sucesso;
}
bool Filas::ConsultarFilaArr(int *x) {
	bool sucesso;
	int info;
	if (IncioFila != LimiteInicio - 1) {
		info = informacao[IncioFila];
		*x = info;
		cout<<"O numero da posição "<<IncioFila<<" é "<<info<<endl;
		sucesso = true;
	}else{
		sucesso = false;
	}
	return sucesso;
}

