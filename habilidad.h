/*
 *
 *Proyecto simulador de pokemon
 *Claudio Gabriel Lopez Briceño
 *A01710963
 *23/05/23
 *
 *Esta clase define objeto tipo "Habilidad"
 */

#ifndef HABILIDAD_H_
#define HABILIDAD_H_

#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

//Declaramos la clase "Habilidad" que es abstracta

class Habilidad{

    //Declaro variables de instancia
    private:
    string nombre, tipo, clasificacion;
    int potencia, pp, ppBase;

    //Declaro los metodos del objeto
    public:

    //Constructores
    Habilidad();
    Habilidad(string,string,string,int,int,int);

    //Getters
    string get_tipo(){return tipo;}

    string get_clasificacion(){return clasificacion;}
    
    int get_potencia(){return potencia;}

    string get_nombre(){return nombre;}

    int get_ppBase(){return ppBase;}

    int get_pp(){return pp;}

    //Setters
    
    void set_pp(int _pp){pp = _pp;}

    //ImprimirHabilidad
    void imprimeHabilidad();
};

//Constructores "Habilidad"
Habilidad::Habilidad(){
    nombre = "";
    tipo = "";
    clasificacion = "";
    potencia = 0;
    pp = 0;
    ppBase = 0;
}

Habilidad::Habilidad(string _nombre, string _tipo, string _clasificacion, int _potencia, int _pp,int _ppBase){
    nombre = _nombre;
    tipo = _tipo;
    clasificacion = _clasificacion;
    potencia = _potencia;
    pp = _pp;
    ppBase = _ppBase;
}


/**
 * imprimeHabilidad imprime todos los atributos de la habilidad
 * 
 * Imprime todos los atributos de un objeto "Habilidad"
 * 
 * @param
 * @return
*/

void Habilidad::imprimeHabilidad(){
    cout << "---------------------------------------------------------" << endl;
    cout << "Imprimiendo datos del movimiento " << endl;
    cout << "Nombre del movimiento: " << nombre << endl;
    cout << "Tipo del movimiento: " << tipo << endl;
    cout << "Clasificacion del movimiento: " << clasificacion << endl;
    cout << "Puntos de poder del movimiento: " << pp << "/" << pp << endl;
    cout << "Potencia del movimiento: " << potencia << endl;
    cout << "---------------------------------------------------------" << endl;
}


#endif