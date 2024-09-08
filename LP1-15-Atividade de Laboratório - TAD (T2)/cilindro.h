/*
 * cilindro.h
 *
 *  Created on: 23 de jul de 2024
 *      Author: user
 */

#ifndef CILINDRO_H_
#define CILINDRO_H_

class cilindro{
protected:
	float altura,raio;
public:

	cilindro(float altura,float raio);
	void cilindro_retornos();
	float cilindro_volume();
};

#endif /* CILINDRO_H_ */
