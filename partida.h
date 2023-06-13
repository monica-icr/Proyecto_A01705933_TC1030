/**
 * Proyecto Mafia clase Partida
 * Mónica Isabel Casillas Rodríguez
 * A01705933
 * 12/06/2023
 * version : 4
 * Esta clase define objetos de tipo partida
 * 
*/

#ifndef PARTIDA_H
#define PARTIDA_H

#include <iostream>
#include <string>
#include "Jugador.h"

using namespace std;

// Declaración de la clase Partida
class Partida{
    private: 
    // Atributos
        Jugador * jugadores[20];
        int num_jugadores;
    public: 
    // Constructor
        Partida(){num_jugadores = 0;}
    // Métodos
        void agregar_jugador(Jugador * jugador);
        void muestra_jugadores();
        void ronda_noche();
        int ronda_dia();
};

void Partida::agregar_jugador(Jugador * jugador){
    jugadores[num_jugadores] = jugador;
    num_jugadores++;
}

void Partida::muestra_jugadores(){
    cout <<"Los jugadores son:"<< endl;
    for (int i = 0; i < num_jugadores; i++){
        cout << jugadores[i]->getNombre() << endl;
    }
}

void Partida::ronda_noche(){
    cout << "La ronda de noche ha iniciado" << endl;
    Jugador * vivos[20];
    int num_vivos = 0;
    int num_mafia = 0;
    int num_doctor = 0;
    int num_investigador = 0;
    int num_civil = 0;
    for (int i = 0; i < num_jugadores; i++){
        if ((jugadores[i])->getEstado() != -1){
            vivos[num_vivos] = jugadores[i];
            num_vivos++;
            if ((jugadores[i])->getRol() == "mafia"){
                num_mafia++;
            }
        }
    }
    if ((num_mafia < (num_vivos - num_mafia) or num_mafia == 
    (num_vivos - num_mafia)) and num_mafia > 0){
        for (int i = 0; i < num_vivos; i++){
            vivos[i]->dormir();
        }
        for (int i = 0; i < num_vivos; i++){
            if (vivos[i]->getRol() == "mafia"){
                vivos[i]->despertar();
                int num_mafia = 0;
                num_mafia++;
            }
        }
        cout << "Los mafiosos despiertan" << endl;
        cout << "Pregunta, sin que hablen" <<
        " ¿A quién quieren matar?" << endl;
        string victima; 
        getline(cin >> ws, victima);
        cout << "La mafia ha escogido a quién matar" << endl;
        for (int i = 0; i < victima.length(); i++){
            victima[i] = tolower(victima[i]);
        }
        for (int j = 0; j < num_vivos; j++){
            if (vivos[j]->getNombre() == victima){
                vivos[j]->morir();
            }
        }
        for (int i = 0; i < num_vivos; i++){
            if (vivos[i]->getRol() == "mafia"){
                 vivos[i]->dormir();
            }
        }
        cout << "Los mafiosos duermen" << endl;
        for (int i = 0; i < num_jugadores; i++){
            if ((jugadores[i])->getRol() == "doctor"){
                num_doctor++;
                cout << "Se despierta el doctor no. " << num_doctor << endl;
                cout << "Pregunta, sin que hable" << 
                " ¿A quién quiere salvar?" << endl;
                if ((jugadores[i])->getEstado() != -1){
                    string salvado;
                    getline(cin >> ws, salvado);
                    for (int k = 0; k < salvado.length(); k++){
                        salvado[i] = tolower(salvado[i]);
                    }
                    for (int l = 0; l < num_vivos; l++){
                        if (vivos[l]->getNombre() == salvado){
                            vivos[l]->proteger();
                        }
                    }
                    jugadores[i]->dormir();
                }
                cout << "El doctor no. " << num_doctor << " ha escogido" <<
                " a quién salvar" << endl;
                cout << "El doctor no. " << num_doctor << " duerme" << endl;
            }
        } 
        for (int i = 0; i < num_jugadores; i++){
            if ((jugadores[i])->getRol() == "investigador"){
                num_investigador++;
                cout << "Se despierta el investigador no. " << 
                num_investigador << endl;
                cout << "Pregunta, sin que hable" << 
                " ¿A quién quiere investigar?" << endl;
                if ((jugadores[i])->getEstado() != -1){
                    string investigado;
                    getline(cin >> ws, investigado);
                    for (int k = 0; k < investigado.length(); k++){
                        investigado[i] = tolower(investigado[i]);
                    }
                    for (int l = 0; l < num_vivos; l++){
                        if (vivos[l]->getNombre() == investigado){
                            int bando = vivos[l]->getBando();
                            if (bando == 1){
                                cout << "El investigado es malo" << endl;
                            }else if (bando == 0){
                                cout << "El investigado es bueno" << endl;
                            }
                        }
                    }
                    jugadores[i]->dormir();
                }
                cout << "El investigador no. " << num_investigador << 
                " ha escogido" << " a quién investigar" << endl;
                cout << "El investigador no. " << num_investigador <<
                 " duerme" << endl;
            }
        }  
        cout << "Se acabó la ronda" << endl;
        cout << "Se despiertan todos los jugadores" << endl;
        for (int i = 0; i < num_vivos; i++){
            if ((vivos[i])->getEstado() != -1){
                vivos[i]->despertar();
            }
        }        
    }
}

int Partida:: ronda_dia(){
    cout << "La noche pasó y los sobrevientes son:" << endl;
    Jugador * vivos[20];
    int num_vivos = 0;
    int num_mafia = 0;
    for (int i = 0; i < num_jugadores; i++){
        if ((jugadores[i])->getEstado() != -1){
            cout << jugadores[i]->getNombre() << endl;
            vivos[num_vivos] = jugadores[i];
            num_vivos++;
        }
    }
    for (int i = 0; i < num_vivos; i++){
        if (vivos[i]->getRol() == "mafia"){
            num_mafia++;
        }
    }
    
    if (num_mafia > (num_vivos - num_mafia-1)){
        cout << "Los mafiosos ganan" << endl;
        for (int i = 0; i < num_jugadores; i++){
            jugadores[i]->resultado(1);
        }
        return 1;
    }else{
        cout << "Se inicia la ronda de votación" << endl;
        int votos[num_vivos];
        for (int i = 0; i < num_vivos; i++){
            votos[i] = 0;
        }
        for (int i = 0; i < num_vivos; i++){
            cout << "¿A quién quiere votar " << 
            vivos[i]->getNombre()<< "?" << endl;
            string votado;
            getline(cin >> ws, votado);
            for (int k = 0; k < votado.length(); k++){
                votado[i] = tolower(votado[i]);
            }
            for (int l = 0; l < num_vivos; l++){
                if (vivos[l]->getNombre() == votado){
                    votos[l]++;
                }
            }
        }
        int max = 0;
        int cant_max = 0;
        string candidatos[num_vivos];
        for (int i = 0; i < num_vivos; i++){
            if (votos[i] > max){
                max = votos[i];
                cant_max = 1;
                candidatos[0] = vivos[i]->getNombre();
            }else if (votos[i] == max){
                cant_max++;
                candidatos[cant_max-1] = vivos[i]->getNombre();
            }
        }
        while (cant_max >1){
            cout << "Hay un empate entre los jugadores: " << endl;
            for (int i = 0; i < cant_max; i++){
                cout << candidatos[i] << endl;
            }
            cout << "Se procede a una nueva ronda de votación" << endl;
            int votos2[cant_max];
            for (int i = 0; i < cant_max; i++){
                votos2[i] = 0;
            }
            for (int i = 0; i < num_vivos; i++){
                cout << "¿A quién quiere votar " << 
                vivos[i]->getNombre()<< "?" << endl;
                string votado;
                getline(cin >> ws, votado);
                for (int k = 0; k < votado.length(); k++){
                    votado[k] = tolower(votado[k]);
                }
                for (int l = 0; l < num_vivos; l++){
                    if (vivos[l]->getNombre() == votado){
                        votos2[l]++;
                    }
                }
            }
            int max2 = 0;
            int cant_max2 = 0;
            string candidatos2[cant_max];
            for (int i = 0; i < cant_max; i++){
                if (votos2[i] > max2){
                    max2 = votos2[i];
                    cant_max2 = 1;
                    candidatos2[0] = candidatos[i];
                }else if (votos2[i] == max2){
                    cant_max2++;
                    candidatos2[cant_max2-1] = candidatos[i];
                }
            }
            cant_max = cant_max2;
        }
        cout << "El jugador que ha sido linchado es: " << candidatos[0] << endl;
        cout << "Los jugadores aún vivos son: " << endl;
        for (int i = 0; i < num_vivos; i++){
            if (vivos[i]->getNombre() == candidatos[0]){
                vivos[i]->morir();
            }
        }
        num_vivos = 0;
        num_mafia = 0;
        for (int i = 0; i < num_jugadores; i++){
            if ((jugadores[i])->getEstado() != -1){
                cout << jugadores[i]->getNombre() << endl;
                vivos[num_vivos] = jugadores[i];
                num_vivos++;
            }
        }
        for (int i = 0; i < num_vivos; i++){
            if (vivos[i]->getRol() == "mafia"){
                num_mafia++;
            }
        }
        if (num_mafia == 0){
            cout << "Los buenos ganan" << endl;
            for (int i = 0; i < num_jugadores; i++){
                jugadores[i]->resultado(0);
            }
            return 1;
        }else if(num_mafia > (num_vivos - num_mafia)){
                cout << "Los mafiosos ganan" << endl;
                for (int i = 0; i < num_jugadores; i++){
                    jugadores[i]->resultado(1);
                }
            return 1; 
        }else{
            cout << "La ronda de día ha terminado" << endl;
            return 0;
        }
    }  
}


#endif
