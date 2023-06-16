/*
 *
 *Proyecto simulador de pokemon
 *Claudio Gabriel Lopez Briceño
 *A01710963
 *23/05/23
 *
 *Esta clase define objeto tipo "Pokemon" que contiene las clases heredadas
 *planta, fuego, agua y normal
 */

#ifndef POKEMON_H_
#define POKEMON_H_

#include <iostream>
#include <string>
#include <sstream>
#include <cstdlib>
#include <math.h>
#include "habilidad.h"

using namespace std;

//Declaramos la clase "Pokemon"

class Pokemon{

    //Declaro variables de instancia
    protected:
    string nombre, tipo;
    int exp, nivel, ratioCaptura, hp, ataque, defensa, ataqEspecial, defEspecial, habilidadesRegistradas, ev, hpBase, evBase, ataqBase, ataqEspBase, defBase, defEspBase, hpBaseNivel, expBase, expBaseNivel;
    Habilidad * habilidades[3];

    //Declaro los metodos del objeto
    public:
    Pokemon();
    Pokemon(string,string,int,int,int,int,int,int,int,int,int,int,int,int,int,int,int,int,int,int,int);

    //Getters
    string get_tipo(){return tipo;}

    string get_nombre(){return nombre;}

    int get_defensa(){return defensa;}

    int get_defEspecial(){return defEspecial;}

    int get_ataque(){return ataque;}

    int get_ataqEspecial(){return ataqEspecial;}

    int get_hp(){return hp;}

    int get_hpBaseNivel(){return hpBaseNivel;}

    int get_nivel(){return nivel;}

    int get_expBase(){return expBase;}

    int get_exp(){return exp;}

    int get_expBaseNivel(){return expBaseNivel;}


    //Setters
    void set_hp(int _hp){hp = _hp;}

    void set_ataque(int _ataque){ataque = _ataque;}

    void set_ataqEspecial(int _ataqEspecial){ataqEspecial = _ataqEspecial;}

    void set_defensa(int _defensa){defensa = _defensa;}

    void set_defEspecial(int  _defEspecial){defEspecial = _defEspecial;}

    void set_hpBaseNivel(int _hpBaseNivel){hpBaseNivel = _hpBaseNivel;}

    void set_expBaseNivel(int _expBaseNivel){expBaseNivel = _expBaseNivel;}

    void set_nivel(int _nivel){nivel = _nivel;}

    //Imprimir pokemon
    void imprimirPokemon();

    //Imprimir pokemon pelea imprime al pokemon en formato de pelea
    void imprimirPokemonPelea();
        
    //Imprimir habilidades
    void imprimirHabilidades();

    //Agrega habilidad
    virtual void agregaHabilidad(Habilidad *hab) = 0;

    //Calcula el danio de una habilidad
    virtual int calculaDanio(Pokemon *pe, Habilidad *habilidadSeleccionada) = 0;

    //Calcular vida (+nivel)
    void calcularVida();

    //Calcular caracteristicas (+nivel)
    void calcularCaracteristicas();

    //Calcular exp necesaria para subir de nivel
    void calcularExpBaseNivel();

    //Calcular la experiencia al derrotar a un pokemon
    void calcularExpPelea(Pokemon *pe);

    //Sube un pokemon de nivel
    void subirNivel();

    //Usa una habilidad y modifica los stats del pokemon enemigo
    void usarHabilidad (Pokemon *pe);

    //Usa una habilidad pero desde la perspectiva del enemigo
    void usarHabilidadEnemigo (Pokemon *pe);

    
};

//Constructores

Pokemon::Pokemon(){
    nombre = "";
    tipo = "";
    exp = 0;
    nivel = 0;
    ratioCaptura = 0;
    hp = 0;
    ataque = 0;
    defensa = 0;
    ataqEspecial = 0;
    defEspecial = 0;
    habilidadesRegistradas = 0;
    ev = 0;
    hpBase = 0;
    evBase = 0;
    ataqBase = 0;
    ataqEspBase = 0;
    defBase = 0;
    defEspBase = 0;
    hpBaseNivel = 0;
    expBase = 0;
    expBaseNivel = 0;
}

Pokemon::Pokemon(string _nombre, string _tipo,int _exp, int _nivel, int _ratioCaptura, int _hp, int _ataque, int _defensa, int _ataqEspecial, int _defEspecial, int _habilidadesRegistradas, int _ev, int _hpBase, int _evBase, int _ataqBase, int _ataqEspBase, int _defBase, int _defEspBase, int _hpBaseNivel, int _expBase, int _expBaseNivel){
    nombre = _nombre;
    tipo = _tipo;
    exp = _exp;
    nivel = _nivel;
    ratioCaptura = _ratioCaptura;
    hp = _hp;
    ataque = _ataque;
    defensa = _defensa;
    ataqEspecial = _ataqEspecial;
    defEspecial = _defEspecial; 
    habilidadesRegistradas = _habilidadesRegistradas;
    ev = _ev;
    hpBase = _hpBase;
    evBase = _evBase;
    ataqBase = _ataqBase;
    ataqEspBase = _ataqEspBase;
    defBase = _defBase;
    defEspBase = _defEspBase;
    hpBaseNivel = _hpBaseNivel;
    expBase = _expBase;
    expBaseNivel = _expBaseNivel;
}

/**
 * imprimirPokemon imprime todos los atributos del pokemon
 * 
 * Imprime todos los atributos de un objeto de la clase "Pokemon"
 * 
 * @param
 * @return
*/

void Pokemon::imprimirPokemon(){
    cout << "Nombre del pokemon: " << nombre << endl;
    cout << "Tipo del pokemon: " << tipo << endl;
    cout << "Nivel del pokemon: " << nivel << endl;
    cout << "Exp: " << exp << endl;
    cout << "-----------------------------------------" << endl;
    cout << "Imprimiendo stats del pokemon: " << endl;
    cout << "Puntos de vida del pokemon: " << hp << endl;
    cout << "Ataque del pokemon: " << ataque << endl;
    cout << "Defensa del pokemon: " << defensa << endl;
    cout << "Ataque especial del pokemon: " << ataqEspecial << endl;
    cout << "Defensa especial del pokemon: " << defEspecial << endl;
}

/**
 * imprimirPokemonPelea imprime el nombre y la vida del pokemon
 * 
 * Imprime los atrivutos "nombre", "hp" y "hpBaseNivel" del pokemon
 * 
 * @param
 * @return
*/

void Pokemon::imprimirPokemonPelea(){
    cout << nombre << "\t" << hp << "/" << hpBaseNivel << endl;
    cout << "----------------------------------------" << endl;
}

/**
 * imprimirHabilidades imprime todas las habilidades del pokemon
 * 
 * Imprime todos los objetos de la clase "Habilidad" que se encuentren dentro de la lista de "hab" en un objeto de la clase "Pokemon"
 * 
 * @param
 * @return
*/

void Pokemon::imprimirHabilidades(){
    for (int i = 0; i < habilidadesRegistradas; i++){
        habilidades[i]->imprimeHabilidad();
    }
}

/**
 * calcularVida calcula la vida del pokemon al subir el nivel
 * 
 * Calcula los puntos de vida que se van a obtener al subir de nively settea el atributo hp
 * con el valor del resultado del calculo
 * 
 * @param
 * @return
 * 
*/

void Pokemon::calcularVida(){
    int nuevohp;

    int iv = 0+(rand()%31);

    //Formula para calcular el nuevo valor del atributo "hp" al subir de nivel
    nuevohp = ((((hpBase + iv)*2+(sqrt(evBase/4))*nivel)/100)+nivel+10);

    //Setteamos el nuevo valor de hp
    set_hp(nuevohp);
    set_hpBaseNivel(nuevohp);
}

/**
 * calcularCaracteristicas calcula las caracteristicas del pokemon al subir el nivel (menos hp)
 * 
 * Calcula los puntos de vida que se van a obtener al subir de nively modifica los valores
 *  del objeto con el resultado de los calculos
 * 
 * @param
 * @return
 * 
*/

void Pokemon::calcularCaracteristicas(){
    int nuevoAtaq;
    int nuevoAtaqEsp;
    int nuevoDef;
    int nuevoDefEsp;

    int iv = 0+(rand()%31);

    //Formula para calcular el nuevo valor de la caracteristica al subir de nivel
    nuevoAtaq = ((((ataqBase + iv)*2+(sqrt(evBase/4))*nivel)/100)+5);
    nuevoAtaqEsp = ((((ataqEspBase + iv)*2+(sqrt(evBase/4))*nivel)/100)+5);
    nuevoDef = ((((defBase + iv)*2+(sqrt(evBase/4))*nivel)/100)+5);
    nuevoDefEsp = ((((defEspBase + iv)*2+(sqrt(evBase/4))*nivel)/100)+5);

    //Setteamos los nuevos atributos
    set_ataque(nuevoAtaq);
    set_ataqEspecial(nuevoAtaqEsp);
    set_defensa(nuevoDef);
    set_defEspecial(nuevoDefEsp);
}

/**
 * calcularExpBaseNivel calcula experiencia necesaria para subir de nivel
 * 
 * Utilizando una formula se calcula la experiencia que necesita obtener un pokemon para subir de nivel
 * y settea el atributo "expBase" a este nuevo valor
 * 
 * @param
 * @return
 * 
*/

void Pokemon::calcularExpBaseNivel(){
    int nuevoExpBaseNivel;
    nuevoExpBaseNivel = 0.8*(pow(nivel,3));
    set_expBaseNivel(nuevoExpBaseNivel);
}

/**
 * calcularExpPelea calcula la experiencia que recibe el pokemon al subir de nivel
 * 
 * Utilizando un objeto de la clase pokemon se calcula la experiencia que recibira el pokemon
 * aliado al derrotar al pokemon enemigo y este se suma a la experiencia que tiene y se settea 
 * el nuevo valor al atributo exp
 * 
 * @param
 * Objeto de la clase Pokemon
 * @return
 * 
*/

void Pokemon::calcularExpPelea(Pokemon *pe){
    int nuevoExp;
    int expRecibido;

    expRecibido = (pe->get_expBase()*pe->get_nivel()*1.5)/7;

    nuevoExp = nuevoExp + expRecibido;
    set_expBaseNivel(nuevoExp);
}

/**
 * subirNivel sube de nivel al pokemon
 * 
 * Utilizando las funciones calcularVida, calcularCaracterisitcas y calcularExpBase
 * modificamos algunos stats del pokemon dependiendo del nivel al que suba y se le agrega
 * 1 al atributo nivel del pokemon
 * 
 * @param
 * @return
 * 
*/

void Pokemon::subirNivel(){
    Pokemon *pokemonActual = this;

    //Calculamos y seteamos los nuevos atributos del pokemon
    pokemonActual->calcularVida();
    pokemonActual->calcularCaracteristicas();
    pokemonActual->calcularExpBaseNivel();

    //Modificamos el nivel del pokemon y le agregamos uno
    pokemonActual->set_nivel(pokemonActual->get_nivel() + 1);
}

/**
 * usarHabilidad utiliza la habilidad seleccionada en el enemigo
 * 
 * El usuario elige una habilidad de la lista "habilidades" se calcula el danio
 * que realiza esta habilidad tomando en cuenta a el pokemon enemigo y por ultimo se 
 * imprime un mensaje en el que se especifica el nombre de la habilidad el danio que causo
 * y la vida restante del enemigo, en caso de que la vida restante del enemigo sea 0 se imprime
 * un mensaje en el que se especifica que el enemigo ha sido derrotado
 * 
 * Tambien resta 1 al atributo "pp" del objeto
 * 
 * @param
 * Un objeto de la clase "Pokemon" (enemigo)
 * @return
 * 
*/

void Pokemon::usarHabilidad(Pokemon *pe){
    // Mostrar las habilidades disponibles al usuario
    cout << "Selecciona una habilidad:" << endl;
    for (int i = 0; i < habilidadesRegistradas; i++) {
        cout << i + 1 << ". " << habilidades[i]->get_nombre() << "\t" <<"PP: " << habilidades[i]->get_pp() << "/" << habilidades[i]->get_ppBase() << endl;
    }

    // Pedir al usuario que seleccione una habilidad
    int opcion;
    cout << "Ingresa el número de la habilidad: ";
    cin >> opcion;

    // Verificar si la opcion seleccionada es valida y obtenerla
    if (opcion >= 1 && opcion <= habilidadesRegistradas) {

        Habilidad* habilidadSeleccionada = habilidades[opcion - 1];

        //Si el pp de la habilidad es igual a 0 lo mete en un ciclo while hasta que escoja una habilidad que tenga un pp mayor a 0
        while (habilidadSeleccionada->get_pp() <= 0){
            cout << nombre << " ya no puede utilizar esta habilidad, porfavor selecciona otra." << endl;
            cout << "Selecciona una habilidad:" << endl;
            for (int i = 0; i < habilidadesRegistradas; i++) {
            cout << i + 1 << ". " << habilidades[i]->get_nombre() << "\t" <<"PP: " << habilidades[i]->get_pp() << "/" << habilidades[i]->get_ppBase() << endl;
            }

            int opcion;
            cout << "Ingresa el número de la habilidad: ";
            cin >> opcion;

            if (opcion >= 1 && opcion <= habilidadesRegistradas) {
                habilidadSeleccionada = habilidades[opcion - 1];
            }
            else{
                cout << "Opción inválida. La habilidad seleccionada no existe." << endl;
            }
        }

        habilidadSeleccionada->set_pp(habilidadSeleccionada->get_ppBase()-1);

        // Calcular el danio utilizando la funcion "calculaDanio"
        int danio = calculaDanio(pe, habilidadSeleccionada);

        // Restar el valor de la vida del enemigo con el daño calculado
        int nuevoHP = pe->get_hp() - danio;

        // Verificar si el nuevo HP es menor o igual a cero e imprimir mensaje
        if (nuevoHP <= 0) {
            nuevoHP = 0; // Establecer el HP en cero si es negativo

            cout << "¡El enemigo ha sido derrotado!" << endl;
        }

        pe->set_hp(nuevoHP);

        cout << nombre << " utilizo la habilidad " << habilidadSeleccionada->get_nombre() << " y causo " << danio << " puntos de danio." << endl;
        cout << "La vida restante de " << pe->get_nombre() << " es " << nuevoHP << "." << endl;
    } 
    
    else {
        cout << "Opción inválida. La habilidad seleccionada no existe." << endl;
    }
}

void Pokemon::usarHabilidadEnemigo(Pokemon *pe){
    //Seleccionamos habilidad al azar
    int seleccionHabilidad = 0+(rand()%habilidadesRegistradas);

    while (habilidades[seleccionHabilidad]->get_pp() == 0){
        int seleccionHabilidad = 0+(rand()%habilidadesRegistradas);
    }

    Habilidad *habilidadSeleccionada = habilidades[seleccionHabilidad];

    habilidadSeleccionada->set_pp(habilidadSeleccionada->get_pp()-1);

    int danio = calculaDanio(pe, habilidadSeleccionada);

    int nuevoHP = pe->get_hp()-danio;

     if (nuevoHP <= 0) {
        nuevoHP = 0; // Establecer el HP en cero si es negativo

        cout << "Haz sido derrotado" << endl;
    }

    pe->set_hp(nuevoHP);

    cout << nombre << " utilizo la habilidad " << habilidadSeleccionada->get_nombre() << " y causo " << danio << " puntos de danio." << endl;
    cout << "La vida restante de " << pe->get_nombre() << " es " << nuevoHP << "." << endl;

}


//Declaro clase "Planta" que hereda de "Pokemon"

class Planta: public Pokemon{
    public:
    //Constructores
    Planta();

    Planta(string,string,int,int,int,int,int,int,int,int,int,int,int,int,int,int,int,int,int,int,int);

    //Calcula el danio de una habilidad
    int calculaDanio(Pokemon *pe, Habilidad *habilidadSeleccionada);

    //Agrega una habilidad al objeto de la clase Planta
    void agregaHabilidad(Habilidad *hab);
};

//Constructores clase Planta

Planta::Planta():Pokemon("","planta",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0){}

Planta::Planta(string _nombre, string _tipo,int _exp, int _nivel, int _ratioCaptura, int _hp, int _ataque, int _defensa, int _ataqEspecial, int _defEspecial, int _habilidadesRegistradas, int _ev, int _hpBase, int _evBase, int _ataqBase, int _ataqEspBase, int _defBase, int _defEspBase, int _hpBaseNivel, int _expBase, int _expBaseNivel):
        Pokemon(_nombre, "planta", _exp, _nivel, _ratioCaptura, _hp, _ataque, _defensa, _ataqEspecial, _defEspecial, _habilidadesRegistradas, _ev, _hpBase, _evBase, _ataqBase, _ataqEspBase, _defBase, _defEspBase, _hpBaseNivel, _expBase, _expBaseNivel){};

/**
 * calculaDanio calcula el danio que realiza la habilidad
 * 
 * Calcula el danio que hace el objeto de la clase "Planta" que hereda de "Pokemon"
 *  al utilizar x habilidad tomando en cuenta los stats del pokemon enemigo y los
 * de la habilidad que va a utilizar 
 * 
 * @param
 * Objeto de la clase "Habilidad"
 * Objeto de la clase "Pokemon" (enemigo)
 * 
 * @return
 * int que guarda la cantidad de danio que realizara el movimiento
*/

int Planta::calculaDanio(Pokemon *pe, Habilidad *habilidadSeleccionada){
    int danioTotal;

    //Generamos un numero random en un rango de 85 a 100
    int variacion = 85+(rand()%100);

    double bonificacion;

    double efectividad;

    //Si el tipo de la habilidad es el mismo al del pokemon se le asigna un valor de 1.5 a la variable "bonificacion", de lo contrario se le asgina 1
    if (habilidadSeleccionada->get_tipo() == "planta"){
        bonificacion = 1.5;
    }
    else{
        bonificacion = 1;
    }

    //Asignamos el valor de la variable efectividad, dependiendo del tipo del pokemon enemigo
    if(pe->get_tipo()  == "planta"){
        efectividad = 0.5;
    }

    else if(pe->get_tipo() == "fuego"){
        efectividad = 0.5;
    }

    else if(pe->get_tipo() == "agua"){
        efectividad = 2;
    }
    else{
        efectividad = 1;
    }

    if (bonificacion == 1){
        efectividad = 1;
    }

    //Aplicamos la formula para calcular el danio dependiendo de la clasificacion de la habilidad
    if (habilidadSeleccionada->get_tipo() == "fisico"){
        danioTotal = round((0.01*bonificacion*efectividad*variacion/(((0.2*nivel+1)*ataque*habilidadSeleccionada->get_potencia())/(25*pe->get_defensa()))));
    }

    else if (habilidadSeleccionada->get_tipo() == "especial"){
        danioTotal = round((0.01*bonificacion*efectividad*variacion/(((0.2*nivel+1)*ataqEspecial*habilidadSeleccionada->get_potencia())/(25*pe->get_defEspecial()))));
    }

    //Retornamos el int con el danio total
    
    return danioTotal;
}

/**
 * agregaHabilidad agrega objetos de la clase Habilidad a la lista "habilidades"
 * 
 * Agrega una habilidad a la lista "habilidades" donde se guardan las 4 habilidades que es capaz de tener un objeto de la clase Pokemon,
 * solo permite guardar habilidades del mismo tipo o de tipo normal
 * 
 * @param 
 * Objeto de la clase Habilidad
 * @return
 * 
*/

void Planta::agregaHabilidad(Habilidad *habilidad) {
    if (habilidadesRegistradas < 3) {
        // Verificar si la habilidad es del tipo "planta" o "normal"
        if (habilidad->get_tipo() == "planta" || habilidad->get_tipo() == "normal") {
            habilidades[habilidadesRegistradas] = habilidad;
            habilidadesRegistradas++;
            cout << nombre << " ha aprendido "<< habilidad->get_nombre() << endl;
        } else {
            cout << "No se pudo agregar la habilidad. Solo se permiten habilidades de tipo planta o normal." << endl;
        }
    } else {
        cout << "No se pudo agregar la habilidad. Ya se alcanzó el límite de habilidades (4)." << endl;
    }
}

//Declaro clase "Fuego" que hereda de "Pokemon"

class Fuego: public Pokemon{
    public:
    //Constructores
    Fuego();

    Fuego(string,string,int,int,int,int,int,int,int,int,int,int,int,int,int,int,int,int,int,int,int);

    //Calcula el danio de una habilidad
    int calculaDanio(Pokemon *pe, Habilidad *habilidadSeleccionada);

    //Agrega una habilidad al objeto de la clase Fuego
    void agregaHabilidad(Habilidad *hab);
};

//Constructores clase Fuego

Fuego::Fuego():Pokemon("","fuego",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0){}

Fuego::Fuego(string _nombre, string _tipo,int _exp, int _nivel, int _ratioCaptura, int _hp, int _ataque, int _defensa, int _ataqEspecial, int _defEspecial, int _habilidadesRegistradas, int _ev, int _hpBase, int _evBase, int _ataqBase, int _ataqEspBase, int _defBase, int _defEspBase, int _hpBaseNivel, int _expBase, int _expBaseNivel):
        Pokemon(_nombre, "fuego", _exp, _nivel, _ratioCaptura, _hp, _ataque, _defensa, _ataqEspecial, _defEspecial, _habilidadesRegistradas, _ev, _hpBase, _evBase, _ataqBase, _ataqEspBase, _defBase, _defEspBase, _hpBaseNivel, _expBase, _expBaseNivel){};

/**
 * calculaDanio calcula el danio que realiza la habilidad
 * 
 * Calcula el danio que hace el objeto de la clase "Planta" que hereda de "Pokemon"
 *  al utilizar x habilidad tomando en cuenta los stats del pokemon enemigo y los
 * de la habilidad que va a utilizar 
 * 
 * @param
 * Objeto de la clase "Habilidad"
 * Objeto de la clase "Pokemon" (enemigo)
 * 
 * @return
 * int que guarda la cantidad de danio que realizara el movimiento
*/

int Fuego::calculaDanio(Pokemon * pe, Habilidad *habilidadSeleccionada){
    int danioTotal;

    //Generamos un numero random en un rango de 85 a 100
    int variacion = 85+(rand()%100);

    double bonificacion;

    double efectividad;

    //Si el tipo de la habilidad es el mismo al del pokemon se le asigna un valor de 1.5 a la variable "bonificacion", de lo contrario se le asgina 1
    if (habilidadSeleccionada->get_tipo() == "fuego"){
        bonificacion = 1.5;
    }
    else{
        bonificacion = 1;
    }

    //Asignamos el valor de la variable efectividad, dependiendo del tipo del pokemon enemigo
    if(pe->get_tipo()  == "planta"){
        efectividad = 2;
    }

    else if(pe->get_tipo() == "fuego"){
        efectividad = 0.5;
    }

    else if(pe->get_tipo() == "agua"){
        efectividad = 0.5;
    }
    else{
        efectividad = 1;
    }

    //Si el tipo de la habilidad es normal, la efectividad sera de 1
    if (bonificacion == 1){
        efectividad = 1;
    }

    //Aplicamos la formula para calcular el danio dependiendo de la clasificacion de la habilidad
    if (habilidadSeleccionada->get_tipo() == "fisico"){
        danioTotal = round((0.01*bonificacion*efectividad*variacion/(((0.2*nivel+1)*ataque*habilidadSeleccionada->get_potencia())/(25*pe->get_defensa()))));
    }

    else if (habilidadSeleccionada->get_tipo() == "especial"){
        danioTotal = round((0.01*bonificacion*efectividad*variacion/(((0.2*nivel+1)*ataqEspecial*habilidadSeleccionada->get_potencia())/(25*pe->get_defEspecial()))));
    }

    //Retornamos el int con el danio total
    
    return danioTotal;  
}

/**
 * agregaHabilidad agrega objetos de la clase Habilidad a la lista "habilidades"
 * 
 * Agrega una habilidad a la lista "habilidades" donde se guardan las 4 habilidades que es capaz de tener un objeto de la clase Pokemon,
 * solo permite guardar habilidades del mismo tipo o del tipo normal
 * 
 * @param 
 * Objeto de la clase Habilidad
 * @return
 * 
*/

void Fuego::agregaHabilidad(Habilidad *habilidad){
    if (habilidadesRegistradas < 3) {
        // Verificar si la habilidad es del tipo "planta" o "normal"
        if (habilidad->get_tipo() == "fuego" || habilidad->get_tipo() == "normal") {
            habilidades[habilidadesRegistradas] = habilidad;
            habilidadesRegistradas++;
            cout << nombre << " ha aprendido "<< habilidad->get_nombre() << endl;
        } else {
            cout << "No se pudo agregar la habilidad. Solo se permiten habilidades de tipo fuego o normal." << endl;
        }
    } else {
        cout << "No se pudo agregar la habilidad. Ya se alcanzó el límite de habilidades (4)." << endl;
    }
}

//Declaro clase "Agua" que hereda de "Pokemon"

class Agua: public Pokemon{
    public:
    //Constructores
    Agua();

    Agua(string,string,int,int,int,int,int,int,int,int,int,int,int,int,int,int,int,int,int,int,int);

    //Calcula el danio de una habilidad
    int calculaDanio(Pokemon *pe, Habilidad *habilidadSeleccionada);

    //Agrega una habilidad al objeto de la clase Agua
    void agregaHabilidad(Habilidad *hab);
};

//Constructores clase Agua

Agua::Agua():Pokemon("","agua",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0){}

Agua::Agua(string _nombre, string _tipo,int _exp, int _nivel, int _ratioCaptura, int _hp, int _ataque, int _defensa, int _ataqEspecial, int _defEspecial, int _habilidadesRegistradas, int _ev, int _hpBase, int _evBase, int _ataqBase, int _ataqEspBase, int _defBase, int _defEspBase, int _hpBaseNivel, int _expBase, int _expBaseNivel):
        Pokemon(_nombre, "agua", _exp, _nivel, _ratioCaptura, _hp, _ataque, _defensa, _ataqEspecial, _defEspecial, _habilidadesRegistradas, _ev, _hpBase, _evBase, _ataqBase, _ataqEspBase, _defBase, _defEspBase, _hpBaseNivel, _expBase, _expBaseNivel){};

/**
 * calculaDanio calcula el danio que realiza la habilidad
 * 
 * Calcula el danio que hace el objeto de la clase "Planta" que hereda de "Pokemon"
 *  al utilizar x habilidad tomando en cuenta los stats del pokemon enemigo y los
 * de la habilidad que va a utilizar 
 * 
 * @param
 * Objeto de la clase "Habilidad"
 * Objeto de la clase "Pokemon" (enemigo)
 * 
 * @return
 * int que guarda la cantidad de danio que realizara el movimiento
*/

int Agua::calculaDanio(Pokemon * pe, Habilidad *habilidadSeleccionada){
    int danioTotal;

    //Generamos un numero random en un rango de 85 a 100
    int variacion = 85+(rand()%100);

    double bonificacion;

    double efectividad;

    //Si el tipo de la habilidad es el mismo al del pokemon se le asigna un valor de 1.5 a la variable "bonificacion", de lo contrario se le asgina 1
    if (habilidadSeleccionada->get_tipo() == "agua"){
        bonificacion = 1.5;
    }
    else{
        bonificacion = 1;
    }

    //Asignamos el valor de la variable efectividad, dependiendo del tipo del pokemon enemigo
    if(pe->get_tipo()  == "planta"){
        efectividad = 2;
    }

    else if(pe->get_tipo() == "fuego"){

    //Si el tipo de la habilidad es normal, la efectividad sera de 1
    if (bonificacion == 1){
        efectividad = 1;
    }

    //Aplicamos la formula para calcular el danio dependiendo de la clasificacion de la habilidad
    if (habilidadSeleccionada->get_tipo() == "fisico"){
        danioTotal = round((0.01*bonificacion*efectividad*variacion/(((0.2*nivel+1)*ataque*habilidadSeleccionada->get_potencia())/(25*pe->get_defensa()))));
    }

    else if (habilidadSeleccionada->get_tipo() == "especial"){
        danioTotal = round((0.01*bonificacion*efectividad*variacion/(((0.2*nivel+1)*ataqEspecial*habilidadSeleccionada->get_potencia())/(25*pe->get_defEspecial()))));
    }
  
    }
    return danioTotal;  
}

/**
 * agregaHabilidad agrega objetos de la clase Habilidad a la lista "hab"
 * 
 * Agrega una habilidad a la lista "hab" donde se guardan las 4 habilidades que es capaz de tener un objeto de la clase Pokemon,
 * solo permite guardar habilidades del mismo tipo o de tipo normal
 * 
 * @param
 * Objeto de la clase Habilidad
 * @return
 * 
*/

void Agua::agregaHabilidad(Habilidad * habilidad){
    if (habilidadesRegistradas < 3) {
        // Verificar si la habilidad es del tipo "agua" o "normal"
        if (habilidad->get_tipo() == "agua" || habilidad->get_tipo() == "normal") {
            habilidades[habilidadesRegistradas] = habilidad;
            habilidadesRegistradas++;
            cout << nombre << " ha aprendido "<< habilidad->get_nombre() << endl;
        } else {
            cout << "No se pudo agregar la habilidad. Solo se permiten habilidades de tipo agua o normal." << endl;
        }
    } else {
        cout << "No se pudo agregar la habilidad. Ya se alcanzó el límite de habilidades (4)." << endl;
    }
}

//Declaro calse "Normal" que hereda de "Pokemon"

class Normal:public Pokemon{
    public:
    //Constructores
    Normal();

    Normal(string,string,int,int,int,int,int,int,int,int,int,int,int,int,int,int,int,int,int,int,int);

    //Calcula el danio de una habilidad
    int calculaDanio(Pokemon *pe, Habilidad *habilidadSeleccionada);

    //Agrega una habilidad al objeto de la clase Normal
    void agregaHabilidad(Habilidad *hab);
};

//Constructores
Normal::Normal():Pokemon("","normal",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0){};

Normal::Normal(string _nombre, string _tipo,int _exp, int _nivel, int _ratioCaptura, int _hp, int _ataque, int _defensa, int _ataqEspecial, int _defEspecial, int _habilidadesRegistradas, int _ev, int _hpBase, int _evBase, int _ataqBase, int _ataqEspBase, int _defBase, int _defEspBase, int _hpBaseNivel, int _expBase, int _expBaseNivel):
    Pokemon(_nombre, "normal", _exp, _nivel, _ratioCaptura, _hp, _ataque, _defensa, _ataqEspecial, _defEspecial, _habilidadesRegistradas, _ev, _hpBase, _evBase, _ataqBase, _ataqEspBase, _defBase, _defEspBase, _hpBaseNivel, _expBase, _expBaseNivel){};

/**
 * calculaDanio calcula el danio que realiza la habilidad
 * 
 * Calcula el danio que hace el objeto de la clase "normal" que hereda de "Pokemon"
 *  al utilizar x habilidad tomando en cuenta los stats del pokemon enemigo y los
 * de la habilidad que va a utilizar 
 * 
 * @param
 * Objeto de la clase "Habilidad"
 * Objeto de la clase "Pokemon" (enemigo)
 * 
 * @return
 * int que guarda la cantidad de danio que realizara el movimiento
*/

int Normal::calculaDanio(Pokemon * pe, Habilidad *habilidadSeleccionada){
    int danioTotal;

    //Generamos un numero random en un rango de 85 a 100
    int variacion = 85+(rand()%100);

    double bonificacion;

    double efectividad;

    //Si el tipo de la habilidad es el mismo al del pokemon se le asigna un valor de 1.5 a la variable "bonificacion", de lo contrario se le asgina 1
    if (habilidadSeleccionada->get_tipo() == "normal"){
        bonificacion = 1.5;
    }
    else{
        bonificacion = 1;
    }

    //Asignamos el valor de la variable efectividad, dependiendo del tipo del pokemon enemigo
    efectividad = 1;

    //Aplicamos la formula para calcular el danio dependiendo de la clasificacion de la habilidad
    if (habilidadSeleccionada->get_tipo() == "fisico"){
        danioTotal = round((0.01*bonificacion*efectividad*variacion/(((0.2*nivel+1)*ataque*habilidadSeleccionada->get_potencia())/(25*pe->get_defensa()))));
    }

    else if (habilidadSeleccionada->get_tipo() == "especial"){
        danioTotal = round((0.01*bonificacion*efectividad*variacion/(((0.2*nivel+1)*ataqEspecial*habilidadSeleccionada->get_potencia())/(25*pe->get_defEspecial()))));
    }

    //Retornamos el int con el danio total
    
    return danioTotal;  
}

/**
 * agregaHabilidad agrega objetos de la clase Habilidad a la lista "habilidades"
 * 
 * Agrega una habilidad a la lista "habilidades" donde se guardan las 4 habilidades que es capaz de tener un objeto de la clase Pokemon,
 * solo permite guardar habilidades del mismo tipo
 * 
 * @param 
 * Objeto de la clase Habilidad
 * @return
 * 
*/

void Normal::agregaHabilidad(Habilidad *habilidad){
    if (habilidadesRegistradas < 3) {
        // Verificar si la habilidad es del tipo "normal"
        if (habilidad->get_tipo() == "normal") {
            habilidades[habilidadesRegistradas] = habilidad;
            habilidadesRegistradas++;
            cout << nombre << " ha aprendido "<< habilidad->get_nombre() << endl;
        } else {
            cout << "No se pudo agregar la habilidad. Solo se permiten habilidades de tipo normal." << endl;
        }
    } else {
        cout << "No se pudo agregar la habilidad. Ya se alcanzó el límite de habilidades (4)." << endl;
    }
}

#endif