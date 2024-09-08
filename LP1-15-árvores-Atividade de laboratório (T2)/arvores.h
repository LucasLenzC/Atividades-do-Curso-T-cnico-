#ifndef ARVORES_H_
#define ARVORES_H_



class arvores {
	const static int raiz = 0;
	int array[8];

public:
	arvores();
	void root(int key);

	void setLeft(int x, int raiz);

	void setRight(int x, int raiz);

	void printArvore();

};



#endif /* ARVORES_H_ */
