/*
 *
 *Proyecto simulador de pokemon
 *Claudio Gabriel Lopez Briceño
 *A01710963
 *23/05/23
 *
 *Esta clase define un objeto tipo "Entrenador"
 */

#ifndef ENTRENADOR_H_
#define ENTRENADOR_H_

#include <iostream>
#include <string>
#include <sstream>
#include "pokemon.h"
#include "habilidad.h"
#include "equipo.h"

using namespace std;

//Declaramos clase Entrenador
class Entrenador{
    private:
    int equiposRegistrados;
    string nombre, genero;

    public:

    Equipo * equipoPok[0];

    Entrenador();
    Entrenador(int,string,string);

    //Getters

    string get_nombre(){return nombre;}

    //Crea equipo
    void creaEquipo(int, int);

    //Muestra equipo
    void muestraEquipo();

    //Imprimir entrenador
    void imprimirEntrenador();

    //Imprimir menu
    void imprimirMenu(Entrenador * ea,Entrenador *e1, Entrenador *e2, Entrenador *e3,Equipo * eqa,Equipo * eq1, Equipo * eq2, Equipo * eq3);

    //Retar boss
    bool retarBoss(Entrenador * ea,Entrenador *e1, Entrenador *e2, Entrenador *e3,Equipo * eqa, Equipo * eq1, Equipo * eq2, Equipo * eq3);

};

//Constructores
Entrenador::Entrenador(){
    equiposRegistrados = 0;
    nombre = "";
    genero = "";
}

Entrenador::Entrenador(int _equiposRegistrados, string _nombre, string _genero){
    equiposRegistrados = _equiposRegistrados;
    nombre = _nombre;
    genero = _genero;
}

/**
 * crearEquipo crea un objeto de la clase Equipo
 * 
 * La funcion crearEquipo crea un objeto de la clase Equipo a traves de los parametros que
 * se le proporcionan
 * 
 * @param
 * int con los pokemonesRegistrados de la clase equipo
 * int con la vidaTotal de la clase Equipo
 * @return
*/
void Entrenador::creaEquipo(int _pokemonesRegistrados, int _vidaTotal){

    equipoPok[equiposRegistrados] = new Equipo(_pokemonesRegistrados, _vidaTotal);
    equiposRegistrados ++;
}

/**
 * muestraEquipo muestra el equipo
 * 
 * Muestra el equipo de la clase Entrenador
 * 
 * @param
 * @return
*/
void Entrenador::muestraEquipo(){

    equipoPok[0]->imprimirEquipo();
}

/**
 * imprimirEntrenador imprime los datos del entrenador
 * 
 * Imprime todos los atributos del entrenador seleccionado
 * 
 * @param
 * @return
*/
void Entrenador::imprimirEntrenador(){
    cout << "Nombre del entrenador: " << nombre << endl;
    cout << "Genero del entrenador: " << genero << endl;
}

/**
 * retarBoss reta a un gimnasio
 * 
 * A traves de los objetos clase que ocupa como parametros la funcion pone a el equipo
 * aliado a batallar con cada uno de los equipos enemigos y verifica si es que perdiste o 
 * ganaste
 * 
 * @param
 * Objeto de la clase Equipo (Aliado)
 * 3 Objetos de la clase Equipo (Enemigos)
 * @return
 * int con la opcion del usuario
*/

bool Entrenador::retarBoss(Entrenador * ea,Entrenador *e1, Entrenador *e2, Entrenador *e3,Equipo * eqa,Equipo * eq1, Equipo * eq2, Equipo * eq3){

    bool perdiste = false;
    
    cout << "Hola " << ea->get_nombre() << " bienvenido al gimnasio del POO, si logras derrotar a todos los entrenadores, entonces pasaras la materia, de lo contrario Benja te reprobara. Suerte!" <<endl;

    cout << "Primera Pelea: \n" << e1->get_nombre() << endl;

    eqa->pelearEquipo(eq1);

    if (eqa->get_vidaTotal() > 0){

        cout << "Wow, haz derrotado a " << e1->get_nombre() << endl;
        cout << "Veamos si puedes contra " << e2->get_nombre() << endl;

        eqa->pelearEquipo(eq2);

        if (eqa->get_vidaTotal() > 0){

            cout << "Que?! Pudiste contra " << e2->get_nombre() << endl;
            cout << "Ya solo tienes que derrotar a " << e3->get_nombre() << endl;
            
            eqa->pelearEquipo(eq3);

            if (eqa->get_vidaTotal() > 0){
                cout << "Haz aprobado orientado a objetos" << endl;
                perdiste = false;
            }

            else{
                cout<< "Benjamin te ha reprobado :(" << endl;
                perdiste = true;
            }
        }

        else{
            cout<< "Benjamin te ha reprobado :(" << endl;
            perdiste = true;
        }
    }

    else{
        cout<< "Benjamin te ha reprobado :(" << endl;
        perdiste = true;
    }

    return perdiste;
}

/**
 * imprimirMenu imprime el menu con las opciones a hacer
 * 
 * Imprime el menu de las opciones a hacer y le pide al usuario que seleccione una opcion
 * dependiedno de la opcion que escoja, el programa realiza diferentes acciones
 * 
 * @param
 * Objeto de la clase Equipo (Aliado)
 * 3 Objetos de la clase Equipo (Enemigos)
 * @return
 * int con la opcion del usuario
*/
void Entrenador::imprimirMenu(Entrenador * ea,Entrenador *e1, Entrenador *e2, Entrenador *e3,Equipo * eqa,Equipo * eq1, Equipo * eq2, Equipo * eq3){
    int opcion;
    cout << "Que deseas hacer? \n 1.Curar equipo \n 2.Retar gimnasio \n 3.Salir" << endl;
    cout << "Selecciona una opcion: ";
    cin >> opcion;

    if (opcion >= 1 && opcion <= 3){
        if (opcion == 1){
            eqa->curarEquipo();
            cout << "El equipo ha sido curado" << endl;
        }

        else if (opcion == 2){
            bool resultadoPelea = retarBoss(ea,e1,e2,e3,eqa, eq1, eq2, eq3);
            
            while (resultadoPelea == true){
                imprimirMenu(ea,e1,e2,e3,eqa,eq1,eq2,eq3);
            }
        }

        else{
            cout << "Adios, gracias por jugar" << endl;
        }
    }
}

#endif