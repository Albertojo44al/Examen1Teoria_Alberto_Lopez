#include "Secuencia.h"

Secuencia::Secuencia(Conjunto * conjuntoA, Conjunto * conjuntoB) {

	this->setV = conjuntoA;
	this->setE = conjuntoB;

}

void Secuencia::print() {
	cout << "\n\n( ";
	this->setV->print();
	cout << " , ";
	this->setE->print();
	cout << " )\n";
}


