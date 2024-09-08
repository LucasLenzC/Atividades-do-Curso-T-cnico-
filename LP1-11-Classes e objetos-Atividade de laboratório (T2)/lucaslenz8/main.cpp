#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <sstream>
#include <fstream>
#include <iomanip>
using namespace std;
class Pessoa {
public:
	string nome;
	int idade, matricula;
	float peso;
	void imprimir() {
		cout << "nome:" << nome << " idade:" << idade << " matricula:"
				<< matricula << " peso:" << peso << endl;
	}
};
void atv1() {
	Pessoa pessoa1;
	pessoa1.nome = "lendes";
	pessoa1.idade = 16;
	pessoa1.matricula = 1021827;
	pessoa1.peso = 81.90;
	pessoa1.imprimir();
}
;
void atv2() {
	Pessoa pessoa2, pessoa3;

	pessoa2.nome = "Peter";
	pessoa2.idade = 19;
	pessoa2.matricula = 2123554;
	pessoa2.peso = 69.90;
	pessoa2.imprimir();

	pessoa3.nome = "Torres";
	pessoa3.idade = 15;
	pessoa3.matricula = 2031231231;
	pessoa3.peso = 69.90;
	pessoa3.imprimir();
}
;

void atv3() {
	Pessoa pessoa[5];
	pessoa[0].nome = "lendes";
	pessoa[0].idade = 16;
	pessoa[0].matricula = 1021827;
	pessoa[0].peso = 81.90;

	pessoa[1].nome = "Peter";
	pessoa[2].idade = 19;
	pessoa[1].matricula = 2123554;
	pessoa[1].peso = 69.90;

	pessoa[2].nome = "Estevao";
	pessoa[2].idade = 15;
	pessoa[2].matricula = 2031231231;
	pessoa[2].peso = 69.90;

	pessoa[3].nome = "Ana";
	pessoa[3].idade = 15;
	pessoa[3].matricula = 2031231231;
	pessoa[3].peso = 69.90;

	pessoa[4].nome = "Torres";
	pessoa[4].idade = 15;
	pessoa[4].matricula = 2031231231;
	pessoa[4].peso = 69.90;

	for (int i = 0; i < 5; i++) {
		pessoa[i].imprimir();

	}
}
void atv4() {
	string s1("dados.csv");
	ifstream in(s1.c_str());

	int tamanho;
	char buffer[1024];
	char titulo[1024];
	float peso;
	string nome;
	int idade, matricula;

	vector <Pessoa> pessoas;

	in.getline(titulo, 1024);
	while (in.getline(buffer, 1024)) {
		tamanho = strlen(buffer);
		for (int j = 0; j < tamanho; j++) {
			if (buffer[j] == ',') {
				buffer[j] = ' ';
			}
		}
		string stemp(buffer);

		//cout << "Line is:" << i << endl;


		stringstream stris(stemp);

		stris >> nome >> idade >> matricula >> peso;
		//cout << titulo << endl;
		Pessoa pessoa;

		pessoa.nome = nome;
		pessoa.idade = idade;
		pessoa.matricula = matricula;
		pessoa.peso = peso;
//		pessoa.imprimir();
		pessoas.push_back(pessoa);

	}

	for (int j = 0; j < pessoas.size(); ++j) {
		pessoas.at(j).imprimir();
		cout << endl;
	}
	in.close();

}

int main(int argc, char **argv) {
	std::cout << "Atividade de laboratório" << std::endl;
	//atv1();
	//atv2();
	//atv3();
	atv4();

}
