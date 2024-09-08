#include"cubo.h"
#include"cilindro.h"
#include<iostream>
using namespace std;
int main(int argc, char **argv) {
	Cubo c1;
	float aresta =5.0;
	c1.cubo_atribui(aresta);
	cout<< "a area do cubo é:"<<c1.cubo_area()<<endl;
	cout<< "o volume do cubo é:"<<c1.cubo_volume()<<endl;
	cout<<"=============================================================="<<endl;
	cilindro cili(2.0,1.0);
	cili.cilindro_retornos();
	cili.cilindro_volume();

}



