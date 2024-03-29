#include "Conjunto.h"


Conjunto::Conjunto() {
	for (int i = 0; i < SET_LENGTH; i++) {
		this->setArray[i] = 0;
	}
	this->length = 0;
}

void Conjunto::print()
{
	cout << "{";
	for (int i = 0; i < this->length; i++) {

		cout << this->setArray[i];
		if (i < this->length - 1)
			cout << ",";
	}
	cout << "}";
}

void Conjunto::create(string name)
{
	char option;
	cout << "\nConjunto " << name;
	cout << "\nDesea leer un archivo[a] o ingresar valores manualmente[m]?: ";
	cin >> option;
	if (option != 'm') {
		int valid = false;
		while (!valid) {
			try {
				ifstream infile(name + ".txt");
				string sLine;

				if (infile.good())
				{
					getline(infile, sLine);
				}

				for (int i = 0; i < sLine.length(); i++) {

					if (sLine[i] != ',') {

						this->setArray[this->length] = stoi(&sLine[i]);
						this->length++;
					}
				}
				valid = true;
			}
			catch (exception e) {
				cout << "El arcihvo solo puede contener numeros enteros";
				valid = false;
			}
		}
		
	}
	else {
		int qty=0;
		cout << "Ingrese la cantidad de valores que desea : ";
		while (!(cin >> qty)) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "el dato debe ser un numero entero positivo\n";
			cout << "Ingrese la cantidad de valores que desea : ";
		}
		if (qty < 0) {
			qty = qty * (-1);
		}
		for (int i = 0; i < qty; i++) {
			
				cout << "Ingrese el elemento "<<i+1<<" : ";

				while (!(cin >> this->setArray[this->length])) {
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					cout << "el dato debe ser un numero entero\n";
					cout << "ingrese el elemento " << i + 1 << " : ";
				}
				this->length++;

		}

	}
}