#include <iostream>
#include "cilindro.h"
#include<cmath>
using namespace std;
cilindro::cilindro(float altura,float raio){
	this->altura = altura;
	this->raio = raio;
}
void cilindro::cilindro_retornos(){
	cout<<"a altura é "<<altura<<endl;
	cout<<"a raio é "<<raio<<endl;
}
float cilindro::cilindro_volume(){
		float volume = 	altura*raio*M_PI;
		cout<<"o volume do cilindro é:"<<volume<<endl;

		return volume;
}
