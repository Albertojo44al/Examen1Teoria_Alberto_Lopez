#pragma once
#include "Secuencia.h"
#include <iostream>

using namespace std;

class Arista;


class Vertice {
	Vertice* sig;
	Arista* ady;
	string nombre;
	friend class Grafo;

};

class Arista {
	Arista* sig;
	Vertice* ady;
	int peso;
	friend class Grafo;
};


class Grafo
{
	Vertice* root;

public:
	void Init();
	bool Empty();
	int Size();
	Vertice* GetVertice(string nombre);
	void InsertArista(Vertice* origen, Vertice* destino, int peso);
	void InsertVertice(string nombre);
	void FillGraph(Secuencia* );
	void displayMatrix();
};


