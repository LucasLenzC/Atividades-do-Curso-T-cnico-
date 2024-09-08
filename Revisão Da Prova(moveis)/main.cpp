#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <cstring>
#include <cstdlib>
#include <iomanip>
#include <fstream>
using namespace std;

class Movel {
private:
	int posX, posY, velX, velY;
	string Imagem;
public:
	Movel() {
		posX = 0;
		posY = 0;
		velX = 0;
		velY = 0;
		Imagem = "";
	}
	Movel(int x, int y, int vx, int vy, string img) {
		posX = x;
		posY = y;
		velX = vx;
		velY = vy;
		Imagem = img;
	}
	Movel(string linha) {
		string dado;
		stringstream stris(linha);
		getline(stris, dado, ',');
		posX = atoi(dado.c_str());
		getline(stris, dado, ',');
		posY = atoi(dado.c_str());
		getline(stris, dado, ',');
		velX = atoi(dado.c_str());
		getline(stris, dado, ',');
		velY = atoi(dado.c_str());
		getline(stris, dado, ',');
		Imagem = dado;

	}
	void mover(int tempo) {
		posX = posX + velX * tempo;
		posY = posY + velY * tempo;
	}
	void setPos(int x, int y) {
		posX = x;
		posY = y;
	}

	int getPosX() {
		return posX;
	}
	int getPosY() {
		return posY;
	}

	string toString() {
		stringstream ss;
		ss<<posX<< posY<< velX<< velY<<Imagem;
		return ss.str();
	}

};
vector<Movel> carregaMoveis(string caminho) {
    vector<Movel> moveis;
    ifstream arq(caminho.c_str());

    if (!arq.is_open()) {
        cerr << "Erro ao abrir o arquivo: " << caminho << endl;
        return moveis;
    }

    string linha;
    while (getline(arq, linha)) {
        Movel movel(linha);
        moveis.push_back(movel);
    }

    arq.close();
    return moveis;
}


int main(int argc, char **argv) {
	string caminho="moveis.csv";
	//Chama fun��o de carregar dados.
	carregaMoveis(caminho);
	//Atualiza os dados com a fun��o mover.
	Movel movel;//movel sem velocidade
	Movel movel1(0,0,10,1,"bola.png");

	movel.setPos(0,0);
	movel.mover(80);
	cout<<movel.getPosX();
	cout<<movel.getPosY();
	cout<<"==============================="<<endl;
	movel1.setPos(0,0);
	movel1.mover(80);
	cout<<movel1.getPosX();
	cout<<movel1.getPosY();
	//Salva os dados no arquivo novamente.
	return 0;
}

