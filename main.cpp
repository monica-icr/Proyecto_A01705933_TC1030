/**
 * Proyecto Mafia main
 * Mónica Isabel Casillas Rodríguez
 * A01705933
 * 26/05/2023
 * version : 1
 * Este programa simula el juego de mafia en el que hay 4 tipos de jugadores 
 * y cada uno tiene diferentes habilidades.
*/

#include <iostream> // para imprimir
#include <string> // para usar strings

#include "jugador.h" // para usar la clase Jugador y sus hijas Civil, Doctor, Investigador y Mafia

using namespace std; // para no escribir std::

int main(){  // función principal

// Se muestra un ejemplo de uso de la clase Jugador y sus hijas

    // Se crean 5 jugadores 
    Jugador *jugadores[5];
    // se les asigna un tipo de jugador
    jugadores[0] = new Civil("Mónica");
    jugadores[1] = new Doctor("Luis");
    jugadores[2] = new Investigador("Ana");
    jugadores[3] = new Mafia("Juan");
    jugadores[4] = new Mafia("Pedro");

    // Se duermen a todos los jugadores
    for(int i = 0; i < 5; i++){
        jugadores[i]->dormir();
    }

    // Se despiertan los jugadores con habilidades especiales

    jugadores[1]->despertar();
    ((Doctor*) jugadores[1])-> salvar(jugadores[0]->getNombre());
    jugadores[1]->dormir();

    jugadores[2]->despertar();
    ((Investigador*) jugadores[2])-> investigar(jugadores[3]->getNombre());
    jugadores[2]->dormir();

    jugadores[3]->despertar();
    jugadores[4]->despertar();
    ((Mafia*) jugadores[3])-> proponer_matar(jugadores[0]->getNombre());
    ((Mafia*) jugadores[4])-> proponer_matar(jugadores[2]->getNombre());
    jugadores[3]->dormir();
    jugadores[4]->dormir();

    // Se despiertan todos los jugadores
    for (int i = 0; i < 5; i++){
        jugadores[i]->despertar();
    }

    // Se revelan los resultados de la noche
    jugadores[2]->morir();

    // Se calcula el resultado del juego
    int r;
    int buenos = 0;
    int malos = 0;
    for (int i = 0; i < 5; i++){
       r =  jugadores[i]->getBando();
       if (r == 0){
           buenos ++;
        }else{
            malos ++;
        }
    }

    int res; 

    if (buenos > malos){
        res = 0;
    }else{  
        res = 1;
    }

    // Se muestra el resultado del juego
    ((Civil*) jugadores[0])->ganar(res);
    ((Doctor*) jugadores[1])->ganar(res);
    ((Investigador*) jugadores[2])->ganar(res);
    ((Mafia*) jugadores[3])->ganar(res);
    ((Mafia*) jugadores[4])->ganar(res);

    return 0;
}

