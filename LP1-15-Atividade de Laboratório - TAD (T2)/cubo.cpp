#include<iostream>
#include"cubo.h"
#include <cmath>
void Cubo::cubo_atribui(float aresta) {
	tamanho = aresta;
}
float Cubo::cubo_area() {
	float area = 6 * tamanho;
	return area;
}
float Cubo::cubo_volume() {
	float volume =  pow(tamanho,3);
	return volume;
}
