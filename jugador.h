/*
 * Proyecto Mafia clase Jugador
 * Mónica Isabel Casillas Rodríguez
 * A01705933
 * 09/06/2023
 * version : 3
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
    int estado;  
    int bando; // 0 civil, 1 mafia

    public:
    // Constructor 
    Jugador (): nombre(""), estado(0){};
    Jugador(string name);
    // Getters
    string getNombre(){ return nombre;}
    int getEstado(){ return estado;}
    int getBando(){ return bando;}
    // Métodos
    void dormir();
    void despertar();
    void morir();
    string votar(string name);
    virtual void ganar(int resultado) = 0; // La clase se vuelve abstracta.
};

Jugador :: Jugador(string name){
    nombre = name;
    estado = 0;
}
/**
 * dormir() cambia el estado del jugador a 1 que indica que está dormido 
 * y lo menciona
 * 
 * @param no recibe parámetros
 * @return no regresa ningún valor
 */

void Jugador::dormir(){
    estado = 1;
    cout << "El jugador " << nombre << " está durmiendo." << endl;
}

/**
 * despertar() cambia el estado del jugador a 0 que indica que está despierto 
 * y NO lo menciona
 * 
 * @param no recibe parámetros
 * @return no regresa ningún valor
 */

void Jugador::despertar(){
    estado = 0;
}

/**
 * morir() cambia el estado del jugador a -1 que indica que está muerto y lo menciona
 * 
 * @param no recibe parámetros
 * @return no regresa ningún valor
 */
void Jugador::morir(){
    estado = -1;
    cout << "El jugador " << nombre << " ha muerto." << endl;
}

/**
 * votar(string name) recibe el nombre del jugador al que se le quiere dar un 
 * voto y lo menciona
 * 
 * @param name es el nombre del jugador al que se le quiere dar un voto
 * @return regresa el nombre del jugador al que se le dio un voto
*/
string Jugador::votar(string name){
    cout << "El jugador " << nombre << " ha votado." << endl;
    return name;
}

// Declaración de la clase Civil que hereda de Jugador

class Civil : public Jugador{
    private: 
    int bando; // 0 es bueno, 1 es malo
    public:
    // Constructor
    Civil (): Jugador() { bando = 0;}
    Civil(string name) : Jugador(name){}
    // Getters
    int getBando(){ return bando;}
    // Métodos
    void ganar(int resultado);
};

/**
 * ganar(int resultado) recibe el resultado del juego y menciona
 *  si el jugador ganó o no
 * 
 * @param resultado es el resultado del juego
 * @return no regresa ningún valor
*/
void Civil::ganar(int resultado){
    if (resultado == 0){
        cout << "El jugador " << nombre << " ha ganado." << endl;
    } else{
        cout << "El jugador " << nombre << " ha perdido." << endl;}
}


// Declaración de la clase Doctor que hereda de Jugador

class Doctor : public Jugador{
    private: 
    int bando; // 0 es bueno, 1 es malo
    public:
    // Constructor
    Doctor () : Jugador(){ bando = 0;}
    Doctor(string name) : Jugador(name){}
    // Getters
    int getBando(){ return bando;}
    // Métodos
    string salvar(string name);
    void ganar(int resultado);
};

/**
 * salvar(string name) recibe el nombre del jugador al que se le quiere salvar
 * y se menciona que se realizó la elección
 * 
 * @param name es el nombre del jugador al que se le quiere salvar
 * @return regresa el nombre del jugador al que se le salvó
*/
string Doctor::salvar(string name){
    cout << "El doctor ha escogido a quien salvar" << endl;
    return name;
}

/**
 * ganar(int resultado) recibe el resultado del juego y menciona
 *  si el jugador ganó o no
 * 
 * @param resultado es el resultado del juego
 * @return no regresa ningún valor
*/

void Doctor::ganar(int resultado){
    if (resultado == 0){
        cout << "El jugador " << nombre << " ha ganado." << endl;
    } else{
        cout << "El jugador " << nombre << " ha perdido." << endl;}
}

// Declaración de la clase Investigador que hereda de Jugador

class Investigador : public Jugador{
    private:
    int bando; // 0 es bueno, 1 es malo
    public:
    // Constructor
    Investigador () : Jugador(){bando = 0;}
    Investigador(string name) : Jugador(name){
    }
    // Getters
    int getBando(){ return bando;}
    // Métodos
    string investigar(string name);
    void ganar(int resultado);
};

/**
 * investigar(string name) recibe el nombre del jugador al que se le quiere investigar
 * y se menciona que se realizó la elección
 * 
 * @param name es el nombre del jugador al que se le quiere investigar
 * @return regresa el nombre del jugador al que se le investigó
*/

string Investigador::investigar(string name){
    cout << "El investigador ha escogido a quien investigar" << endl;
    // Esta función está incompleta ya que no se regresa el bando del jugador
    // que se investigó, se agregará en la siguiente versión
    return name;
}

/**
 * ganar(int resultado) recibe el resultado del juego y menciona
 *  si el jugador ganó o no
 * 
 * @param resultado es el resultado del juego
 * @return no regresa ningún valor
*/
void Investigador::ganar(int resultado){
    if (resultado == 0){
        cout << "El jugador " << nombre << " ha ganado." << endl;
    } else{
        cout << "El jugador " << nombre << " ha perdido." << endl;}
}

// Declaración de la clase Mafia que hereda de Jugador

class Mafia : public Jugador{
    private:
    int bando; // 0 es bueno, 1 es malo
    public:
    // Constructor
    Mafia () : Jugador(){ bando = 1;}
    Mafia(string name) : Jugador(name){
    }
    // Getters 
    int get_bando(){return bando;}
    // Métodos
    string proponer_matar(string name);
    void ganar(int resultado);
};

/**
 * proponer_matar(string name) recibe el nombre del jugador al que se le quiere matar
 * y se menciona que se esta deliberando, no se menciona a quien se mató.
 * 
 * @param name es el nombre del jugador al que se le quiere matar
 * @return regresa el nombre del jugador al que se propone matar
*/
string Mafia::proponer_matar(string name){
    cout << "Las mafias estan escoguiendo a quien matar" << endl;
    return name;
}

/**
 * ganar(int resultado) recibe el resultado del juego y menciona
 *  si el jugador ganó o no
 * 
 * @param resultado es el resultado del juego
 * @return no regresa ningún valor
*/
void Mafia::ganar(int resultado){
    if (resultado == 1){
        cout << "El jugador " << nombre << " ha ganado." << endl;
    } else{
        cout << "El jugador " << nombre << " ha perdido." << endl;}
}

#endif // JUGADOR_H_ 
