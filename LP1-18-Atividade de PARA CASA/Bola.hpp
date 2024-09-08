#include <SFML/Graphics.hpp>
#include <cstdlib>
#include <ctime>
#include <vector>	// for std::vector
#include <iostream> // for std::cout
#include <sstream> 	// for stringstream
#include <string> //for std::string
#include <cmath> //for math functions
#ifndef BOLA_HPP_
#define BOLA_HPP_
class Bola {
private:
	sf::CircleShape shape;
	sf::Color cor;
public:
	int x, y;
		int vx, vy;
		int raio;
	Bola();
	Bola(int x, int y, int vx, int vy, sf::Color cor, int raio);
	void mover();
	void draw(sf::RenderWindow &window);
	void testaColisao(Bola *outra);
	void testaColisaoCircular(Bola *outra);
	void setColor(sf::Color novaCor);
	std::string toString();
	static Bola* criaBolinha();
	virtual ~Bola();
};

#endif /* BOLA_HPP_ */
