#include "Grafo.h"



int main() {

	Conjunto * A = new Conjunto();
	Conjunto * B = new Conjunto();

	A->create("V");
	B->create("E");

	Secuencia * seq = new Secuencia(A, B);

	seq->print();

	Grafo
}