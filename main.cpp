/**
 * Proyecto Mafia main
 * Mónica Isabel Casillas Rodríguez
 * A01705933
 * 15/06/2023
 * version : 5
 * Este programa simula el juego de mafia en el que hay 4
 * tipos de jugadores y cada uno tiene diferentes habilidades.
*/

#include <iostream> // para imprimir
#include <string> // para usar strings

#include "partida.h" //para usar la clase Jugador
                    //y sus hijas Civil y Mafia
using namespace std; // para no escribir std::

/**
 * asignar_roles() asigna los roles a los jugadores y los añade a la partida
 * 
 * 
 * @param num es el número de jugadores
 * @param part es el objeto de tipo Partida el cual es de tipo apuntador
 * para poder realizar cambios en él
 * @return no regresa ningún valor
*/

void asignar_roles(int num, Partida * part){
    int num_mafia = (int) num / 3;
    int num_doctor = (int) num_mafia / 3;
    int num_investigador = num_doctor;
    int num_civil = num - num_mafia - num_doctor - num_investigador;

    cout << "Por la cantidad de jugadores,"<<
    " en esta partida habrá:\n "<< num_mafia << " mafiosos, "<<
    num_doctor << " doctores, "<< num_investigador << 
    " investigadores y "<< num_civil << " civiles."<< endl;

    for (int i = 0; i < num_mafia; i++){
        string nombre;
        cout << "Ingresa el nombre del jugador "<< 
        "que quieres que sea la MAFIA no."<< i+1 << endl;
          getline(cin >> ws, nombre);
        for (int j = 0; j < nombre.length(); j++){
            nombre[j] = tolower(nombre[j]);
        }
        Jugador * mafia = new Mafia(nombre);
        part->agregar_jugador(mafia);
    }

    for (int i = 0; i < num_doctor; i++){
        string nombre;
        cout << "Ingresa el nombre del jugador "<< 
        "que quieres que sea el DOCTOR no."<< i+1 << endl;
        getline(cin >> ws, nombre);
        for (int j = 0; j < nombre.length(); j++){
            nombre[j] = tolower(nombre[j]);
        }
        Jugador * doctor = new Civil(nombre, "doctor");
        part->agregar_jugador(doctor);
    }

    for (int i = 0; i < num_investigador; i++){
        string nombre;
        cout << "Ingresa el nombre del jugador "<< 
        "que quieres que sea el INVESTIGADOR no."<< i+1 << endl;
        getline(cin >> ws, nombre);
        for (int j = 0; j < nombre.length(); j++){
            nombre[j] = tolower(nombre[j]);
        }
        Jugador * investigador = new Civil(nombre, "investigador");
        part->agregar_jugador(investigador);
    }

    for (int i = 0; i < num_civil; i++){
        string nombre;
        cout << "Ingresa el nombre del jugador "<< 
        "que quieres que sea el CIVIL no."<< i+1 << endl;
        getline(cin >> ws, nombre);
        for (int j = 0; j < nombre.length(); j++){
            nombre[j] = tolower(nombre[j]);
        }
        Jugador * civil = new Civil(nombre, "civil");
        part->agregar_jugador(civil);
    }

    part->muestra_jugadores();
}

/**
 * main() es la función principal
 * 
 * 
 * @param no tiene parámetros
 * @return regresa 0 si todo sale bien
*/
int main(){  
    cout << "Bienvenido al juego de mafia\n\n" << 
    "\nEsta es una guía para el DIOS"<<
    "\nTU eres el DIOS y vas a guiar esta partida.\n\n"<< endl;
    cout << "¿Cuántos jugadores van a jugar?" << 
    "(no te cuentes a ti mismo)"<<endl;
    int cant_jugadores;
    cin >> cant_jugadores;
    while (true){
        if (cant_jugadores < 3){
            cout << "No hay suficientes jugadores"<<
            " para jugar una partida de mafia"<< endl;
            cout << "¿Cuántos jugadores van a jugar?" << 
            "(no te cuentes a ti mismo)"<<endl; 
            cin >> cant_jugadores;
        }else if (cant_jugadores > 21){
            cout << "Hay demasiados jugadores"<<
            " para jugar una partida de mafia"<< endl;
            cout << "Deben haber máximo 21 jugadores"<< endl;
            cout << "¿Cuántos jugadores van a jugar?" << endl;
            cin >> cant_jugadores;
        }else{break;}
    }
    Partida * partida = new Partida();
    asignar_roles(cant_jugadores, partida);
    bool loop = true;
    int res; // resultado de la partida
    while (loop){
        partida->ronda_noche();
        res = partida->ronda_dia();
        if (res == 1){
            loop = false;
        }
    }
    return 0;
}