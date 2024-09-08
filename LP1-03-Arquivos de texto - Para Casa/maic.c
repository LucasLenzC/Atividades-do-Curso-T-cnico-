#include <stdio.h>
#include <string.h>
#include <locale.h>

int main(int argc, char **argv) {
	setbuf(stdout, NULL);
	setlocale(LC_ALL, "Portuguese");
	char busca[100], palavra[100], novaPalavra[100];
	int i = 0, cont = 0;
	FILE *Faroeste;
	Faroeste = fopen("FaroesteCaboclo.txt", "r");
	printf("Digite  uma palavra  para ser pesquisada:");
	gets(busca);
	while (fscanf(Faroeste, "%s", palavra) != EOF) {
		if (!strcmp(palavra, busca)) {
			i++;
		}
	}
	printf("a palavra %s apareceu:%d\n\n\n", busca, i);
	fclose(Faroeste);

	FILE * novoFaroeste;
	novoFaroeste = fopen("NOVOFaroesteCaboclo.txt", "w");
	Faroeste = fopen("FaroesteCaboclo.txt", "r");
	printf("Digite  uma palavra  para ser substiduida:");
	gets(busca);
	printf("Digite  uma palavra  a nova palavra:");
	gets(novaPalavra);
	while (fscanf(Faroeste, "%s", palavra) != EOF) {
		if (!strcmp(palavra, busca)) {
			fprintf(novoFaroeste, "%s ", novaPalavra);
		} else {
			fprintf(novoFaroeste, "%s ", palavra);
		}
		cont++;
		if (cont == 10) {
			fprintf(novoFaroeste, "\n");
			cont = 0;
		}
		if (!strcmp(palavra, "Urbana")) {
			fprintf(novoFaroeste, "\n");
		}

	}

}

