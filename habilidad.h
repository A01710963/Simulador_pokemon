/*
 *
 *Proyecto carrito de compras
 *Claudio Gabriel Lopez Briceño
 *A01710963
 *23/05/23
 *
 *Esta clase define objeto tipo "Habilidad" que contiene las clases heredadas
 *Fisico y Especial
 */

#ifndef HABILIDAD_H_
#define HABILIDAD_H_

#include <iostream>
#include <string>

using namespace std;

//Declaramos la clase "Habilidad" que es abstracta

class Habilidad{

    //Declaro variables de instancia
    protected:
    string nombre, tipo;
    int pp, potencia, precision;

    //Declaro los metodos del objeto
    public:

    //Constructores
    Habilidad();
    Habilidad(string,string,int,int,int);

    //Calcular danio
    int calcularDanio();

    //ImprimirHabilidad
    void imprimeHabilidad();
};

//Constructores "Habilidad"
Habilidad::Habilidad(){
    nombre = "";
    tipo = "";
    pp = 0;
    potencia = 0;
    precision = 0;
}

Habilidad::Habilidad(string _nombre, string _tipo, int _pp, int _potencia, int _precision){
    nombre = _nombre;
    tipo = _tipo;
    pp = _pp;
    potencia = _potencia;
    precision = _precision;
}

//Declaro objeto "Fisico" que hereda de "Habilidad"

class Fisico: public Habilidad{
    //Declaro los metodos del objeto 
    public:
    //Constructores
    Fisico();
    Fisico(string,string,int,int,int);

    //Imprimir habilidad
    void imprimeHabilidad();

};

//Constructores Fisico

Fisico::Fisico():Habilidad("","",0,0,0){

}

Fisico::Fisico(string _nombre, string _tipo, int _pp, int _potencia, int _precision):Habilidad(_nombre,_tipo,_pp,_potencia,_precision){
    
}

/**
 * imprimeHabilidad imprime todos los atributos de la habilidad
 * 
 * Imprime todos los atributos de un objeto "Fisico"
 * 
 * @param
 * @return
*/

void Fisico::imprimeHabilidad(){
    cout << "---------------------------------------------------------" << endl;
    cout << "Imprimiendo datos del movimiento fisico" << endl;
    cout << "Nombre del movimiento: " << nombre << endl;
    cout << "Tipo del movimiento: " << tipo << endl;
    cout << "Puntos de poder del movimiento: " << pp << "/" << pp << endl;
    cout << "Potencia de ataque del movimiento: " << potencia << endl;
    cout << "Precision del movimiento: " << precision << endl;
    cout << "---------------------------------------------------------" << endl;
}

//Declaro objeto "Especial" que hereda de "Habilidad"

class Especial: public Habilidad{
    //Declaro los metodos del objeto
    public:
    //Constructores
    Especial();
    Especial(string,string,int,int,int);

    //Imprimir habilidad
    void imprimeHabilidad();

};

//Constructores Especial

Especial::Especial():Habilidad("","",0,0,0){

}

Especial::Especial(string _nombre, string _tipo, int _pp, int _potencia, int _precision):Habilidad(_nombre,_tipo,_pp,_potencia,_precision){

}

/**
 * imprimeHabilidad imprime todos los atributos de la habilidad
 * 
 * Imprime todos los atributos de un objeto "Especial"
 * 
 * @param
 * @return
*/

void Especial::imprimeHabilidad(){
    cout << "---------------------------------------------------------" << endl;
    cout << "Imprimiendo datos del movimiento especial" << endl;
    cout << "Nombre del movimiento: " << nombre << endl;
    cout << "Tipo del movimiento: " << tipo << endl;
    cout << "Puntos de poder del movimiento: " << pp << "/" << pp << endl;
    cout << "Potencia de ataque especial del movimiento: " << potencia << endl;
    cout << "Precision del movimiento: " << precision << endl;
    cout << "---------------------------------------------------------" << endl;
}

#endif