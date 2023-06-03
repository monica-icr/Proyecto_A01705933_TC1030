/**
 * Proyecto Mafia clase Partida
 * Mónica Isabel Casillas Rodríguez
 * A01705933
 * 02/06/2023
 * version : 2
 * Esta clase define objetos de tipo partida
 * 
*/

#ifndef PARTIDA_H
#define PARTIDA_H

#include <iostream>
#include <string>
#include "jugador.h"

using namespace std;

// Declaración de la clase Partida
class Partida{
    private: 
    // Atributos
        Jugador * jugadores[20];
        int num_jugadores;
    // Métodos privados 
        void agregar_civil(string name);
        void agregar_doctor(string name);
        void agregar_investigador(string name);
        void agregar_mafia(string name);
    public: 
    // Constructor
        Partida();
    // Métodos
        void agregar_jugadores(string players[20], int num);
        //void muestra_jugadores();

};

Partida::Partida(){
    num_jugadores = 0;
}

void Partida::agregar_jugadores(string players[20], int num){
    num_jugadores = num;
    int maf = (int) num/3 + 1;
    int doc = (int) maf/3;
    int invest = doc;
    cout<< invest; 
    int civ = (int) num_jugadores - maf - doc - invest;

    if(maf > 0){
        for (int i = 0; i < maf; i++){
            int num_jugador = rand() % num_jugadores;
            bool loop = true;
            while (loop){
                if (players[num_jugador] != ""){
                    agregar_mafia(players[num_jugador]);
                    players[num_jugador]= "";
                    cout << "Se agregó mafia" << endl;;
                    loop = false;
                }else{ num_jugador = rand() % num_jugadores;}
            } 
        }
    }

    if (doc > 0){
        for (int i = 0; i < doc; i++){
            int num_jugador = rand() % num_jugadores;
            bool loop = true;
            while (loop){
                if (players[num_jugador] != ""){
                    agregar_doctor(players[num_jugador]);
                    players[num_jugador]= "";
                    cout << "Se agregó doctor" << endl;
                    loop = false;
                }else{ num_jugador = rand() % num_jugadores;}
            } 
        }
    }else{cout << "No hay doctores" << endl;}

    if (invest > 0){ 
        for (int i = 0; i < invest; i++){
            int num_jugador = rand() % num_jugadores;
            bool loop = true;
            while (loop){
                if (players[num_jugador] != ""){
                    agregar_investigador(players[num_jugador]);
                    players[num_jugador]= "";
                    cout << "Se agregó investigador" << endl;
                    loop = false;
                }else{ num_jugador = rand() % num_jugadores;}
            } 
        }
    }else {cout << "No hay investigadores" << endl;}

    if (civ > 0){
        for (int i = 0; i < civ; i++){
            cout << "prueba";
            int num_jugador = rand() % num_jugadores;
            bool loop = true;
            while (loop){
                if (players[num_jugador] != ""){
                    agregar_civil(players[num_jugador]);
                    players[num_jugador]= "";
                    cout << "Se agregó civil" << endl;
                    loop = false;
                }else{ num_jugador = rand() % num_jugadores;}
            } 
        }
    }else {cout << "No hay civiles" << endl;}
}

void Partida::agregar_civil(string name){
    jugadores[num_jugadores] = new Civil(name);
    num_jugadores++;
}

void Partida::agregar_doctor(string name){
    jugadores[num_jugadores] = new Doctor(name);
    num_jugadores++;
}

void Partida::agregar_investigador(string name){
    jugadores[num_jugadores] = new Investigador(name);
    num_jugadores++;
}

void Partida::agregar_mafia(string name){
    jugadores[num_jugadores] = new Mafia(name);
    num_jugadores++;
}

/**void Partida::muestra_jugadores(){
    for (int i = 0; i < num_jugadores; i++){
        if (jugadores[i]->getBando() == 0){
            cout << "Jugador " << i+1 << " es un civil" << endl;
        }
    }
}**/

#endif