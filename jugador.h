/*
 * Proyecto Mafia clase Jugador
 * Mónica Isabel Casillas Rodríguez
 * A01705933
 * 15/06/2023
 * version : 5
 * Esta clase define objetos de tipo jugador
 * Se incluyen las clases hererdadas
 * Civil y Mafia. 
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
    virtual void resultado(int resultado) = 0;
};

/**
 * Constructor Jugador(string name) recibe el nombre del jugador
 * y lo asigna al atributo nombre
 * 
 * @param name es el nombre del jugador
 * @return no regresa ningún valor
*/
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

/**
 * proteger() cambia el estado del jugador a 2 que indica
 * que está protegido y NO lo menciona.
 * 
 * @param no recibe parámetros
 * @return no regresa ningún valor
 */
void Jugador::proteger(){
    estado = 2;
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
 * resultado(int resultado) recibe el resultado del juego y menciona
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
 * resultado(int resultado) recibe el resultado del juego y menciona
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