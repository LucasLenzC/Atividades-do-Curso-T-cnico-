#include <iostream>
#include "arvores.h"
using namespace std;
int main(int argc, char **argv) {
	arvores arvore;
	arvore.root(30);
	arvore.setLeft(25, 0);
	arvore.setRight(40, 0);
	arvore.setLeft(65, 1);
	arvore.setRight(15, 1);
	arvore.setLeft(32, 2);
	arvore.setRight(27, 2);
	arvore.printArvore();

}

