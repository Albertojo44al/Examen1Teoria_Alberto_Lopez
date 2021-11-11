#include "Grafo.h"



int main() {

	Conjunto * A = new Conjunto();
	Conjunto * B = new Conjunto();

	A->create("A");
	B->create("B");

	Secuencia * seq = new Secuencia(A, B);

	seq->print();

}