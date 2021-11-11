#pragma once
#include "Conjunto.h"

class Secuencia
{
public:
	Secuencia(Conjunto*, Conjunto*);
	Conjunto* conjuntoA;
	Conjunto* conjuntoB;

	void print();

};

