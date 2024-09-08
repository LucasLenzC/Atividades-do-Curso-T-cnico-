
#ifndef FILAS_H_
#define FILAS_H_

#define LimiteSuperior 10

class Filas {
private:
	int LimiteInicio,IncioFila,FinalFila,informacao[LimiteSuperior];
public:
	Filas();
	bool InserirFila(int x);
	bool RemoverFilaArr();
	bool ConsultarFilaArr(int *x);

};

#endif /* FILAS_H_ */
