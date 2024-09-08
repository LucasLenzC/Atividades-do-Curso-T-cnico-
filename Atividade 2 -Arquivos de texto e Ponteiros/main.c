#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void Multiplica(int tamanho, int * vetor) {
	int i,j;
	for (i = 0; i < tamanho; i++) {
		vetor[i] = vetor[i] * 2;
	}

}
int main(int argc, char **argv) {
	int numeros[] = { 10, 20, 30, 40, 50, 60, 70, 80, 90, 100 };
	int j;

	printf("Tamanho antes da função\n");
	for (j = 0; j < 10; ++j) {
		printf("%d - ", numeros[j]);
	}
	Multiplica(10, numeros);

	printf("\nTamanho depois da função\n");
	for (j = 0; j < 10; ++j) {
		printf("%d - ", numeros[j]);
	}
	return 0;
}
