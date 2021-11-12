#include "Grafo.h"
#include <string>

void Grafo::Init()
{
	this->root = 0;
}

bool Grafo::Empty()
{
	if (this->root == 0)
		return true;
	else
		return false;
}
int Grafo::Size()
{
	int cont = 0;
	Vertice* aux;
	aux = this->root;
	while (aux != 0) {
		aux = aux->sig;
		cont++;
	}
	return cont;
}

Vertice* Grafo::GetVertice(string nombre)
{
	Vertice* aux;
	aux = root;

	while (aux != 0) {

		if (aux->nombre == nombre)
			return aux;

		aux = aux->sig;
	}
	return 0;
}

void Grafo::InsertVertice(string nombre) {
	Vertice* nuevo = new Vertice;
	nuevo->nombre = nombre;
	nuevo->sig = 0;
	nuevo->ady = 0;

	if (Empty()) {
		this->root = nuevo;
	}
	else {
		Vertice* aux;
		aux = root;
		while (aux->sig != 0) {
			aux = aux->sig;
		}
		aux->sig = nuevo;
	}
}

void Grafo::InsertArista(Vertice* origen, Vertice* destino, int peso) {
	Arista* nueva = new Arista;
	nueva->peso = peso;
	nueva->sig = 0;
	nueva->ady = 0;

	Arista* aux;
	aux = origen->ady;

	if (aux == 0) {
		origen->ady = nueva;
		nueva->ady = destino;
	}
	else {
		while (aux->sig != 0) {
			aux = aux->sig;
		}
		aux->sig = nueva;
		nueva->ady = destino;
	}
}

void Grafo::FillGraph(Secuencia* sec) {
	Conjunto* V = sec->setV;
	Conjunto* E = sec->setE;

	for (int i = 0; i < V->length; i++) {
		InsertVertice(to_string(V->setArray[i]));
	}


	for (int i = 0; i < E->length; i++) {

		string origen, destino;
		int peso;
		cout << "Ingrese del nombre del vertice origen: ";
		cin.ignore();
		getline(cin, origen, '\n');
		cout << "Ingrese el nombre del vertice destino: ";
		getline(cin, destino, '\n');
		cout << "Ingrese el peso: ";
		cin >> peso;

		if (GetVertice(origen) == NULL || GetVertice(destino) == NULL)
		{
			cout << "Uno de los vertices no es valido" << endl;
		}
		else
		{
			InsertArista(GetVertice(origen), GetVertice(destino), peso);
		}
	}

}

void Grafo::displayMatrix() {

	Vertice* VertAux;
	Arista* AristaAux;

	VertAux = root;
	while (VertAux != NULL) {
		cout << VertAux->nombre << "->";
		AristaAux = VertAux->ady;
		while (AristaAux != NULL) {
			cout << AristaAux->ady->nombre << "->";
			AristaAux = AristaAux->sig;
		}
		VertAux = VertAux->sig;
		cout << endl;
	}
}




