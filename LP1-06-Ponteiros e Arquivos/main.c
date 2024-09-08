#include <stdio.h>
#include <string.h>
#include <locale.h>

void acharMaior(char *nomeTexto, int minimoPalavra) {
    char maiorPalavra[300], palavra[300];
    int tamanhoMaior = 0, cont = 0, numero = 0;
    FILE *arquivo;
    arquivo = fopen(nomeTexto, "r");
    if (arquivo == NULL) {
        printf("Não foi possivel abrir o arquivo!");
        return;
    }

    while (fscanf(arquivo, "%s", palavra) != EOF) {
        char *token = strtok(palavra, ",.;- ");
        while (token != NULL) {
            numero = strlen(token);
            if (tamanhoMaior < numero) {
                strcpy(maiorPalavra, token);
                tamanhoMaior = strlen(maiorPalavra);
            }
            if (numero > minimoPalavra) {
                cont++;
            }
            token = strtok(NULL, ",.;- ");
        }
    }

    printf("A maior palavra é %s com %d caracteres.\nExistem %d palavras maiores que %d.\n", maiorPalavra, tamanhoMaior, cont, minimoPalavra);

    fclose(arquivo);
}

int main(int argc, char **argv) {
    setlocale(LC_ALL, "Portuguese");
    setbuf(stdout, NULL);

    char nome[] = "NovoTestamento.txt";
    int tamanho = 15;

    acharMaior(nome, tamanho);

    return 0;
}
