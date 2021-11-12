#include <iostream>
#include <fstream>
#include "windows.h"

using namespace std;
#define size 6

char mat[size][size];

void leerArchivo() {
    ifstream myfile;
    myfile.open("reglas.txt");

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            myfile >> mat[i][j];
        }
    }
}

void imprimirOpciones() {

    printf("\x1B[41m\n 1 \033[0m\t");
    printf("\x1B[43m 2 \033[0m\t");
    printf("\x1B[45m 3 \033[0m\t");
    printf("\x1B[42m 4 \033[0m\t");
    printf("\x1B[44m 5 \033[0m\t\n");
}

int main() {

    leerArchivo();
        
    bool exit = false;
    char exitChar;
   
    while (!exit) {
        cout << "\n* * * * * * * * * * * * I N I C I O * * * * * * * * * * * * \n";
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                switch (mat[i][j]) {
                case '1':
                    printf("\x1B[41m %c \033[0m", mat[i][j]);
                    break;
                case '2':
                    printf("\x1B[43m %c \033[0m", mat[i][j]);
                    break;
                case '3':
                    printf("\x1B[45m %c \033[0m", mat[i][j]);
                    break;
                case '4':
                    printf("\x1B[42m %c \033[0m", mat[i][j]);
                    break;
                case '5':
                    printf("\x1B[44m %c \033[0m", mat[i][j]);
                    break;
                default:
                    cout << " " << mat[i][j] << " ";
                }
            }
            cout << endl;
        }

        imprimirOpciones();

        int j1, j2;
        cout << "\nJugador 1 ingrese su movimiento : ";
        cin >> j1;
        cout << "Jugador 2 ingrese su movimiento : ";
        cin >> j2;

        if (j1 > 5 || j1 < 1)
            cout << "\nMovimiento del jugador 1 no valido\n";
        if (j2 > 5 || j2 < 1)
            cout << "\nMovimiento del jugador 2 no valido\n";

        char resultado = mat[j2][j1];
        if (resultado == 'P')
            cout << "\n* *Jugador 2 Gana* *\n";
        if (resultado == 'G')
            cout << "\n* *Jugador 1 Gana* *\n";
        if (resultado == 'E')
            cout << "\n* *Empate* *\n";

        cout << "\nDesea continuar?  Si[s]  No[n] : ";
        cin >> exitChar;
        exit = exitChar == 'n' ? exit = true : false;
        
            
        system("cls");

    }
    cout << "* *JUEGO TERMINADO* *";
    return 0;
}