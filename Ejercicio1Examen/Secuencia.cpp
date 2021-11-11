#include "Secuencia.h"

Secuencia::Secuencia(Conjunto * conjuntoA, Conjunto * conjuntoB) {

	this->conjuntoA = conjuntoA;
	this->conjuntoB = conjuntoB;

}

void Secuencia::print() {
	cout << "\n\n( ";
	this->conjuntoA->print();
	cout << " , ";
	this->conjuntoB->print();
	cout << " )\n";
}


