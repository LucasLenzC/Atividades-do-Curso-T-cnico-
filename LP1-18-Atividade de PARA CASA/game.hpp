#include <SFML/Graphics.hpp>
#include <cstdlib>
#include <ctime>
#include <vector>	// for std::vector
#include <iostream> // for std::cout
#include <sstream> 	// for stringstream
#include <string> //for std::string
#include <cmath> //for math functions
#include "Bola.hpp"

#ifndef BOLA_H_
#define BOLA_H_
using std::vector;
using std::string;
using std::stringstream;

namespace lp1 {

class Game {

	sf::RenderWindow window;
	Bola *bola1;
	vector<Bola*> bolas;

	static const int LARGURA = 800;
	static const int ALTURA = 600;

public:
	Game();

	void iniciar();

	void atualizar();

	void desenhar();

	~Game();


};

}



#endif /* BOLA_H_ */
