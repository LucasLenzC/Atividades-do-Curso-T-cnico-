#include<iostream>
#include<string>
#include<sstream>
#include<fstream>
#include<iomanip>
#include<string.h>
#include<cstdlib>
#include<vector>

using namespace std;
class Gpu {
public:
	int id;
	string code;
	string fabricante;
	float valor;
	Gpu(string linha) {
		for (int i = 0; i < linha.size(); ++i) {
			if (linha[i] == ';' or linha[i] == '"') {
				linha[i] = ' ';
			}
			stringstream stris(linha);
			stris >> id >> code >> fabricante >> valor;
		}

	}

	void mostradados() {
		std::cout << id << "," << code << "," << fabricante << "," << valor
				<< endl;
	}

};

vector<Gpu> carregaDados(string caminho) {
	vector<Gpu> Dado;
	ifstream arq(caminho.c_str());

	string str;

	while (getline(arq, str)) {

		if (str[0] != 'i') {

			Gpu novodado(str);
			Dado.push_back(novodado);

		}

	}

	return Dado;
}
float MenorValor(vector<Gpu> Dados, string fabricante) {
	float menorValor = 10000.00;
	int local;
	vector<int> ArmazenadorDeLocais;
	for (int i = 0; i < Dados.size(); ++i) {
		if (Dados[i].fabricante == fabricante) {
			ArmazenadorDeLocais.push_back(i);
			for (int j = 0; j < ArmazenadorDeLocais.size(); ++j) {
				local = ArmazenadorDeLocais[j];
				if (Dados[local].valor != Dados[i].valor) {

					if (Dados[local].valor > Dados[i].valor) {
						menorValor = Dados[i].valor;

					} else if (Dados[local].valor < Dados[i].valor) {
						menorValor = Dados[local].valor;

					}
				}

			}
		}
	}
	return menorValor;
}
float verificaValorMedio(vector<Gpu> Dados) {
	int contAMD = 0, contIntel = 0;
	string caminho = "gpus.csv";
	vector<Gpu> vetor = carregaDados(caminho);
	float temp, somaAMD, mediaAMD, mediaIntel, somaIntel,menorMedia;

	for (int i = 0; i < Dados.size(); ++i) {
		if (Dados[i].fabricante == "AMD") {
			contAMD++;
			somaAMD = Dados[i].valor + temp;

			temp = Dados[i].valor;

		}

	}
	for (int i = 0; i < Dados.size(); ++i) {
		if (Dados[i].fabricante == "Intel") {
			contIntel++;
			somaIntel = Dados[i].valor + temp;

			temp = Dados[i].valor;

		}



	}
	mediaAMD = somaAMD / contAMD;
	mediaIntel = somaIntel/contIntel;

	if(mediaAMD>mediaIntel){
		menorMedia = mediaIntel;

		cout<<MenorValor(vetor, "Intel")<<endl;

	}if(mediaAMD<mediaIntel){
		menorMedia = mediaAMD;

		cout<<MenorValor(vetor, "AMD")<<endl;
	}
	return menorMedia;
}

int main() {
	string caminho = "gpus.csv";
	vector<Gpu> Gpu1 = carregaDados(caminho);
	for (int i = 0; i < Gpu1.size(); ++i) {
		Gpu1[i].mostradados();
	}
	cout << verificaValorMedio(Gpu1) <<endl;

	return 0;
}


