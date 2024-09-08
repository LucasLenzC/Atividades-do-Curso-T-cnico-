#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int Atividade1A() {
	int i = 0, j = 0, matriz[2][2], resultado=0;
	printf("Entre com os elementos da matriz\n");
	for (i = 0; i < 2; i++) {
		for (j = 0; j < 2; j++) {
			printf("Entre com  o elemento [%d][%d]:", i, j);
			scanf("%d", &matriz[i][j]);

		}

	}
	printf("Matriz fornecida:\n");
	for (i = 0; i < 2; i++) {
		for (j = 0; j < 2; j++) {
			printf("[%d]", matriz[i][j]);

		}
		printf("\n");
	}
	Atividade1B(matriz, resultado);

}
int Atividade1B(int matriz[2][2], int total) {
	int multi1, multi2;

	multi1 = matriz[0][0] * matriz[1][1];
	multi2 = matriz[0][1] * matriz[1][0];
	total = multi1 - multi2;
	printf("%d", total);
}
int Atividade2A() {
	int i = 0, j = 0;
	char posicao[4][5],tiravirlgula[5];
	FILE * arq;


	arq = fopen("data.txt", "r");
	if (arq == NULL) {
		printf("Arquivo não aberto");
	}
	for (i = 0; i < 4; i++) {

		for (j = 0; j < 14; j++) {
			if (fscanf(arq, "%c", &posicao[i][j]) != EOF){
				printf("%c", posicao[i][j]);
				posicao[i][j] = strtok(NULL ,",");

			}
			else {
				break;
			}

		}


	}

	fclose(arq);

}

int main(int argc, char **argv) {
	setbuf(stdout, NULL);
	//Atividade1A();
	Atividade2A();
	return 0;
}

