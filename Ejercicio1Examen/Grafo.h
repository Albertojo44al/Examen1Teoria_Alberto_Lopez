#pragma once
#include "Secuencia.h"
#include <iostream>

using namespace std;

class Arista;


class Vertice {
	Vertice* sig;
	Arista* ady;
	string nombre;
	Secuencia* secuencia;
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
	Vertice* h;
public:
	void Inicializa();
	bool Vacio();
	int Tamano();
	Vertice* GetVertice(string nombre);
	void InsertarArista(Vertice* origen, Vertice* destino, int peso);
	void insertaVertice(string nombre);
	void ListaAdyacencia();
};


