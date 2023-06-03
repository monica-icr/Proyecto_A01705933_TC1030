/**
 * Proyecto Mafia main
 * Mónica Isabel Casillas Rodríguez
 * A01705933
 * 02/06/2023
 * version : 2
 * Este programa simula el juego de mafia en el que hay 4 tipos de jugadores 
 * y cada uno tiene diferentes habilidades.
*/

#include <iostream> // para imprimir
#include <string> // para usar strings

#include "partida.h" // para usar la clase Jugador y sus hijas Civil, Doctor, Investigador y Mafia

using namespace std; // para no escribir std::

int main(){  // función principal
    cout << "Bienvenido al juego de mafia" << endl;
    cout << "¿Cuántos jugadores van a jugar?" << endl;
    int cant_jugadores;
    cin >> cant_jugadores;
    string nombres[20];
    for (int i = 0; i < cant_jugadores; i++){
        cout << "Ingresa el nombre del jugador " << i+1 << endl;
        cin >> nombres[i];
    }
    Partida partida;
    partida.agregar_jugadores(nombres, cant_jugadores);
    cout << "La partida ha iniciado" << endl;
    return 0;
}

