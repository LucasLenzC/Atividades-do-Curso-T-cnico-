#include <SFML/Graphics.hpp>
#include <SFML/audio.hpp>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

sf::Sprite spawnRaindrop(sf::Texture &texture) {
	sf::Sprite raindrop(texture);
	int x = rand() % (800 - 64);
	x = x > 32 ? x : 32;
	int y = -32;
	raindrop.setPosition(x, y);
	raindrop.setOrigin(raindrop.getLocalBounds().width / 2.,
			raindrop.getLocalBounds().height / 2.);
	return raindrop;
}

int main() {
	/**********************Inicializa Objetos do Jogo**********************/
	srand(time(NULL));
	setbuf(stdout, NULL);

	sf::RenderWindow window(sf::VideoMode(800, 600), "SFML works!",
			sf::Style::Close | sf::Style::Titlebar);
	// Op��es de abertura da janela: sf::Style::Close + sf::Style::Titlebar + sf::Style::Resize

	//Declara vari�vieis para SFML
	sf::Texture textureFundo;
	sf::Sprite fundoImage;

	sf::Texture textureDropImage;
	sf::Sprite dropImage;

	sf::Texture texturebucketImage;
	sf::Sprite bucketImage;

	sf::SoundBuffer bufferDropSound;
	sf::Sound dropSound;
	sf::SoundBuffer bufferGota;
	sf::Sound gotasom;
	sf::SoundBuffer bufferOver;
	sf::Sound overSound;

	sf::Music rainMusic;

	sf::Font font;

	sf::Texture Texturanuvem;
	sf::Sprite nuvem;

	sf::Texture TexturaBolha;
	sf::Sprite bolha;

	//Declara vari�vieis para o jogo
	int pontos = 0;
	int vidas = 5;

	int velBucketX = 0;
	int velBucketY = 0;
	int velDrop = 5;

	int posBolhaY = 600;
	float random;
	random = rand() % 800 + 1;

	bool pausado = false;
	bool controle = false;

	//Inicializa as vari�vies.

	window.setFramerateLimit(60); // Limita os frames
	window.setVerticalSyncEnabled(true); //limita a sincroniza��o

	//Icone da janela.
	sf::Image image = sf::Image { };
	image.loadFromFile("assets/cogumelo.png");
	window.setIcon(image.getSize().x, image.getSize().y, image.getPixelsPtr());

	// load the images for the droplet and the bucket, 64x64 pixels each
	TexturaBolha.loadFromFile("assets/bolhas.png");
	bolha.setTexture(TexturaBolha);
	bolha.setScale(0.2, 0.2);
	bolha.setPosition(random, 600);

	Texturanuvem.loadFromFile("assets/nuvenzinha.png");
	nuvem.setTexture(Texturanuvem);
	nuvem.setScale(0.2, 0.2);
	nuvem.setPosition(0, 0);

	textureFundo.loadFromFile("assets/fundo.png");
	textureDropImage.loadFromFile("assets/droplet.png");
	texturebucketImage.loadFromFile("assets/bucket.png");

	fundoImage.setTexture(textureFundo);
	bucketImage.setTexture(texturebucketImage);
	bucketImage.setOrigin(bucketImage.getLocalBounds().width / 2.,
			bucketImage.getLocalBounds().height / 2.);
	bucketImage.setPosition(400, 550);

	bufferDropSound.loadFromFile("assets/drop.wav");
	dropSound.setBuffer(bufferDropSound);

	bufferGota.loadFromFile("assets/bolhassom.wav");
	gotasom.setBuffer(bufferGota);

	bufferOver.loadFromFile("assets/Sonic-Game-Over.ogg");
	overSound.setBuffer(bufferOver);

	rainMusic.openFromFile("assets/rain.ogg");
	// start the playback of the background music immediately
	rainMusic.setLoop(true);
	rainMusic.play();

	font.loadFromFile("assets/x-files.ttf");

	sf::Text txtVidas("Vidas:\t5", font, 24);
	sf::Text txtPontos("Pontos:\t0", font, 24);
	sf::Text txtGameOver("", font, 96);

	txtPontos.setColor(sf::Color::Blue);
	txtVidas.setColor(sf::Color::Red);

	txtVidas.setPosition(600, 10);
	txtPontos.setPosition(600, 40);

	// a fun��o cria a gota de chuva como um sprite.
	dropImage = spawnRaindrop(textureDropImage);

	float posNuvemX = 5;
	float posNuvemY = 5;
	/**********************Loop do jogo**********************/
	while (window.isOpen()) {
		sf::Event event;
		velBucketX = 0;
		velBucketY = 0;
		//Trata as intera��es.
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed)
				window.close();
			if (event.type == sf::Event::EventType::KeyPressed) { //Tecla pressionada.
				if (event.key.code == sf::Keyboard::Space) {
					pausado = !pausado; // Inverte pausa ou despausa.
				}
			}

			if (event.type == sf::Event::EventType::KeyReleased) { //Tecla Solta.

			}
			if (event.type == sf::Event::MouseButtonPressed) {
				int x = sf::Mouse::getPosition(window).x;
				bucketImage.setPosition(x, bucketImage.getPosition().y);
			}
		} //Fim do loop de eventos.

		if ((nuvem.getPosition().x) <= 800) {

			posNuvemX += 2;
			nuvem.setPosition(posNuvemX, posNuvemY);
		} else {
			posNuvemX = 0;
			nuvem.setPosition(0, 0);
		}
		if (bolha.getGlobalBounds().intersects(dropImage.getGlobalBounds())) {
			pontos++;
			gotasom.play();
			char str[5];
			sprintf(str, "Pontos:\t%d", pontos);
			txtPontos.setString(str);
			dropImage = spawnRaindrop(textureDropImage);
			controle = true;
		}

		if (((bolha.getPosition().y) >= 0)&& (controle == false)) {

			posBolhaY -= 2;
			bolha.setPosition(random, posBolhaY);
		} else if(controle == true) {
			posBolhaY = 600;
			random = rand() % 800 + 1;
			bolha.setPosition(random, posBolhaY);
			controle = false;
		}

		//Verifica teclas individualmente independente do loop de eventos.
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
			velBucketX = -5;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
			velBucketX = 5;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
			velBucketY = -5;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
			velBucketY = 5;
		}

		/**********************Atualiza o mundo**********************/
		if (!pausado) { //Pausa a atualiza��o do mundo (barra de espa�o)

			//Move objetos.
			bucketImage.setPosition(bucketImage.getPosition().x + velBucketX,
					bucketImage.getPosition().y + velBucketY);

			dropImage.setPosition(dropImage.getPosition().x,
					dropImage.getPosition().y + velDrop);

			if (dropImage.getPosition().y > 600 + 64) {
				dropImage = spawnRaindrop(textureDropImage);
				vidas--;
				char str[5];
				sprintf(str, "Vidas:\t%d", vidas);
				txtVidas.setString(str);
			}

			/**********************Testa colis�es **********************/
			if (bucketImage.getGlobalBounds().intersects(
					dropImage.getGlobalBounds())) {
				pontos++;
				dropSound.play();
				char str[5];
				sprintf(str, "Pontos:\t%d", pontos);
				txtPontos.setString(str);
				dropImage = spawnRaindrop(textureDropImage);
			}

			//Verifica o fim do jogo.
			if (vidas == 0) {
				overSound.play(); //Se a condi��o n�o mudar (vidas==0) isso �
								  //chamado 60 vezes por segundo.
								  //Se n�o puder mudar a condi��o use um clock
								  //dar um tempo entre uma chamada e outra.
				rainMusic.pause();
				velDrop = 0;
				dropImage.setPosition(dropImage.getPosition().x, 0 - 64);
				txtGameOver.setString("Game Over!");
				sf::FloatRect bounds(txtGameOver.getLocalBounds());
				txtGameOver.setPosition(
						window.getSize().x / 2
								- (bounds.left + bounds.width / 2),
						window.getSize().y / 2
								- (bounds.top + bounds.height / 2));
				vidas = -1;
			}

		} // Fim do bloco de pause

		/**********************Pinta o mundo**********************/

		window.clear(sf::Color::White);
		window.draw(fundoImage); 	// Desenha backgroud
		window.draw(nuvem);
		window.draw(bucketImage);	// Desenha Balde
		window.draw(dropImage);		// Desenha gota de chuva
		window.draw(txtPontos);		// Desenha potua��o
		window.draw(txtVidas);		// Desenha vidas
		window.draw(txtGameOver);	// Desenha gameOver
		window.draw(bolha);
		window.display();		 	// Mostra na tela.
		sf::sleep(sf::milliseconds(10.0f));

	} //Fim do loop do jogo (janela aberta).

	return 0;
}
