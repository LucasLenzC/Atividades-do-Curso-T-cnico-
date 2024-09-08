#include <SFML/Graphics.hpp>
#include <iostream>
#include <cstdlib>
#include <ctime>
/**
 * @Autor Alisson RS
 * @site https://gpjecc.blogspot.com/search/label/SFML?&max-results=7
 * @site https://www.sfml-dev.org/learn.php
 */

using namespace std;

class bolas {
public:
	int raio;
};

int main() {
	srand(time(NULL));

	//Define a janela de desenho.
	sf::RenderWindow window(sf::VideoMode(640, 480), "SFML works!");

	window.setFramerateLimit(60); // Limita o frame hate.

	//Define com o nome shape um objeto do tipo circulo de raio 30.
	int posi1 = rand() % 441, posi2 = rand() % 281; // Variáveis para a posição do circulo.
	cout << posi1 << endl;
	cout << posi2 << endl;
	sf::CircleShape shape(30.f);
	//shape.setOrigin(30, 30);
	shape.setFillColor(sf::Color::Green); //Seta a cor pra verde.

	int x = posi1, y = posi2; // Variáveis para a velocidade do circulo.

	while (window.isOpen()) // Loop do jogo.
	{
		//Pega os eventos tipo fechar a janela ou
		//Digitar um tecla ou clicar o mouse.
		sf::Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed)
				window.close();
		}
		//Atualiza os objetos do 'mundo'
		int velocidade=3;


		x = x+velocidade;
		y = y + velocidade;
		shape.setPosition(x, y);
		if (shape.getPosition().x+65 > 640) {
			velocidade = -velocidade;
		}
		if (shape.getPosition().y+65  > 480) {
			y = y - velocidade;
		}

		//Desenha a tela.
		window.clear();
		window.draw(shape);
		window.display();
	} //Fim do loop do jogo.

	return 0;
}

