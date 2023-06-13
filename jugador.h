/*
 * Proyecto Mafia clase Jugador
 * Mónica Isabel Casillas Rodríguez
 * A01705933
 * 12/06/2023
 * version : 4
 * Esta clase define objetos de tipo jugador
 * Se incluyen las clases hererdadas
 * Civil, Doctor, Investigador, Mafia. 
 */

#ifndef JUGADOR_H_
#define JUGADOR_H_

#include <iostream>
#include <string>

using namespace std;

// Declaración de la clase Jugador

class Jugador{
    protected: 
    // Atributos
    string nombre;
    string rol;
    int estado;  
    int bando; // 0 civil, 1 mafia

    public:
    // Constructor 
    Jugador (): nombre(""), estado(0), rol(""){};
    Jugador(string name);
    // Getters
    string getNombre(){ return nombre;}
    int getEstado(){ return estado;}
    int getBando(){ return bando;}
    string getRol(){ return rol;}
    // Métodos
    void dormir();
    void despertar();
    void morir();
    void proteger();
    string votar(string name);
    virtual void resultado(int resultado) = 0;
};

Jugador :: Jugador(string name){
    nombre = name;
    estado = 0;
}
/**
 * dormir() cambia el estado del jugador a 1 que indica 
 * que está dormido y NO lo menciona
 * 
 * @param no recibe parámetros
 * @return no regresa ningún valor
 */

void Jugador::dormir(){
    estado = 1;
}

/**
 * despertar() cambia el estado del jugador a 0 que indica que 
 * está despierto y NO lo menciona
 * 
 * @param no recibe parámetros
 * @return no regresa ningún valor
 */

void Jugador::despertar(){
    estado = 0;
}

/**
 * morir() cambia el estado del jugador a -1 que indica
 * que está muerto y NO lo menciona.
 * 
 * @param no recibe parámetros
 * @return no regresa ningún valor
 */
void Jugador::morir(){
    estado = -1;
}

void Jugador::proteger(){
    estado = 2;
}

/**
 * votar(string name) recibe el nombre del jugador al que se le 
 * quiere dar un voto y lo menciona
 * 
 *@param name es el nombre del jugador por el que se quiere votar
 *@return regresa el nombre del jugador al que se le dio un voto
*/
string Jugador::votar(string name){
    cout << "El jugador " << nombre << " ha votado." << endl;
    return name;
}

// Declaración de la clase Civil que hereda de Jugador

class Civil : public Jugador{
    public:
    // Constructor
    Civil (): Jugador() { bando = 0, rol = "civil";}
    Civil(string name, string personaje) : Jugador(name){
        bando = 0, rol = personaje;}
    // Métodos
    void resultado(int resultado);
};

/**
 * ganar(int resultado) recibe el resultado del juego y menciona
 *  si el jugador ganó o no
 * 
 * @param resultado es el resultado del juego
 * @return no regresa ningún valor
*/
void Civil::resultado(int resultado){
    if (resultado == 0){
        cout << "El jugador " << nombre << " ha ganado." << endl;
    } else{
        cout << "El jugador " << nombre << " ha perdido." << endl;}
}

// Declaración de la clase Mafia que hereda de Jugador

class Mafia : public Jugador{
    public:
    // Constructor
    Mafia () : Jugador(){ bando = 1, rol = "mafia";}
    Mafia(string name) : Jugador(name){bando = 1, rol = "mafia";}
    // Métodos
    void resultado(int resultado);
};

/**
 * ganar(int resultado) recibe el resultado del juego y menciona
 *  si el jugador ganó o no
 * 
 * @param resultado es el resultado del juego
 * @return no regresa ningún valor
*/
void Mafia::resultado(int resultado){
    if (resultado == 1){
        cout << "El jugador " << nombre << " ha ganado." << endl;
    } else{
        cout << "El jugador " << nombre << " ha perdido." << endl;}
}

#endif // JUGADOR_H_ 
