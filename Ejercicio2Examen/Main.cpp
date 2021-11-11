#include <iostream>
#include <fstream>
#include "windows.h"

using namespace std;

int main() {

    int n =6;
    ifstream myfile;
    myfile.open("reglas.txt");
    char mat[6][6];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            myfile >> mat[i][j];
        }
    }
        
    bool exit = false;
    char exitChar;
    cout << "\n* * * * * * * * * * * * I N I C I O * * * * * * * * * * * * \n";
    while (!exit) {

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
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


        int j1, j2;
        cout << "\nJugador 1 ingrese su movimiento : ";
        cin >> j1;
        cout << "Jugador 2 ingrese su movimiento : ";
        cin >> j2;



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
    
    return 0;
}