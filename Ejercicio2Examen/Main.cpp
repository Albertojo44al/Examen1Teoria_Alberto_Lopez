#include <iostream>
#include <fstream>
#include "windows.h"
#include "color.h"

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
    std::cout << "\n\n";
    std::cout << " " << dye::on_red(" 1 ") << " ";
    std::cout << " " << dye::on_yellow(" 2 ") << " ";
    std::cout << " " << dye::on_purple(" 3 ") << " ";
    std::cout << " " << dye::on_green(" 4 ") << " ";
    std::cout << " " << dye::on_blue(" 5 ") << " ";
    std::cout << "\n";
}

int main() {

    leerArchivo();
        
    bool exit = false;
    char exitChar;
   
    while (!exit) {
        std::cout << dye::green("\n* * * * * * * * * * * * I N I C I O * * * * * * * * * * * * \n");
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                switch (mat[i][j]) {
                case '0':
                    std::cout << dye::on_white("   ");
                    break;
                case '1':
                    std::cout <<  dye::on_red(" 1 ");
                    break;
                case '2':
                    std::cout << dye::on_yellow(" 2 ") ;
                    break;
                case '3':
                    std::cout << dye::on_purple(" 3 ");
                    break;
                case '4':
                    std::cout  << dye::on_green(" 4 ") ;
                    break;
                case '5':
                    std::cout  << dye::on_blue(" 5 ");
                    break;
                default:
                    std::cout << " "  << mat[i][j] << " ";
                }
            }
            std::cout << endl;
        }

        imprimirOpciones();

        int j1, j2;
        std::cout << "\nJugador 1 ingrese su movimiento : ";
        cin >> j1;
        std::cout << "Jugador 2 ingrese su movimiento : ";
        cin >> j2;

        if (j1 > 5 || j1 < 1)
            std::cout << "\nMovimiento del jugador 1 no valido\n";
        if (j2 > 5 || j2 < 1)
            std::cout << "\nMovimiento del jugador 2 no valido\n";

        char resultado = mat[j2][j1];
        if (resultado == 'P')
            std::cout << dye::green("\n* *JUGADOR 2 GANA* *\n");
        if (resultado == 'G')
            std::cout << dye::green("\n* *JUGADOR 1 GANA* *\n");
        if (resultado == 'E')
            std::cout << dye::yellow("\n* *EMPATE* *\n");

        std::cout << "\nDesea continuar?  Si[s]  No[n] : ";
        cin >> exitChar;
        exit = exitChar == 'n' ? exit = true : false;
        
            
        system("cls");
       
    }
    std::cout << "* *JUEGO TERMINADO* *";
    return 0;
}