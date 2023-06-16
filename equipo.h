/*
 *
 *Proyecto simulador de pokemon
 *Claudio Gabriel Lopez Briceño
 *A01710963
 *23/05/23
 *
 *Esta clase define un objeto tipo "Equipo"
 */

#ifndef EQUIPO_H_
#define EQUIPO_H_

#include <iostream>
#include <string>
#include <sstream>
#include "pokemon.h"
#include "habilidad.h"

using namespace std;


//Declaramos clase "Equipo"
class Equipo{

    //Declaramos variables de instancia
    private:
    int pokemonesRegistrados, vidaTotal;
    Pokemon * pokemones[5];

    //Declaro los metodos del objeto
    public:
    //Constructores
    Equipo();
    Equipo(int,int);

    //Getters
    int get_vidaTotal(){return vidaTotal;}

    //Setters
    void set_vidaTotal(int _vidaTotal){vidaTotal = _vidaTotal;}

    //Imprimir equipo
    void imprimirEquipo();

    void imprimirEquipo(string tipo);

    //Agregar pokemon
    void agregarPokemon(Pokemon *pok);

    //Quitar pokemon
    void quitarPokemon();

    //Curar equipo
    void curarEquipo();

    //Calcular vida total
    void calcularVidaTotal();

    //Pelear equipo
    void pelearEquipo(Equipo *en);

    
};

//Costructores

Equipo::Equipo(){
    pokemonesRegistrados = 0;
    vidaTotal = 0;
}

Equipo::Equipo(int _pokemonesRegistrados, int _vidaTotal){
    pokemonesRegistrados = _pokemonesRegistrados;
    vidaTotal = _vidaTotal;
}

/**
 * imprimirEquipo imprime todos los pokemones del equipo
 * 
 * Utiliza el arreglo pokemones[] y el atributo pokemonesRegistrados, para recorrer el arreglo
 * e imprime todos los pokemones utilizando el metodo "imprimirPokemon"
 * 
 * @param
 * @return
*/

void Equipo::imprimirEquipo(){

    //Ciclo que recorre el arreglo e imprime el objeto
    for (int i =0; i <pokemonesRegistrados; i++){
        pokemones[i]->imprimirPokemon();    
    }
}

/**
 * imprimirEquipo imprime todos los pokemones del equipo que coinciden con el tipo
 * 
 * Utiliza el arreglo pokemones[] y el atributo pokemonesRegistrados, para recorrer el arreglo,
 * verifica que el tipo de pokemon coincida con el tipo ingresado e imprime todos los pokemones
 * que coinciden utilizando el metodo "imprimirPokemon"
 * 
 * @param
 * String que especifica el tipo de pokemon que se busca
 * @return
*/


void Equipo::imprimirEquipo(string tipo){
    //Ciclo que recorre el arreglo e imprime el objeto dependiendo del tipo
    for (int i =0; i <pokemonesRegistrados; i++){
        if (pokemones[i]->get_tipo() == tipo){
            pokemones[i]->imprimirPokemon();
        }    
    }
}

/**
 * AgregarPokemon agrega un pokemon
 * 
 * El usuario ingresa un pokemon y la funcion lo agrega a la lista "pokemones[]" utilizando
 * el atributo "pokemonesRegistrados"
 * 
 * @param
 * Objeto de la clase pokemon
 * @return
*/

void Equipo::agregarPokemon(Pokemon *pokemon){

    //Se agrega un pokemon al array
    pokemones[pokemonesRegistrados] = pokemon;
    cout << pokemon->get_nombre() << " ahora es parte de tu equipo " << endl;
    pokemonesRegistrados++;
}

/**
 * quitarPokemon quita un pokemon del equipo
 * 
 * El usuario selecciona un pokemon a traves de un ciclo que recorre toda la lista
 * despues se verifica que la opcion sea valida utilizando el atributo "pokemonesRegistrados"
 * y por ultimo se elimina el pokemon utilizando la funcion delete
 * 
 * @param
 * @return
*/

void Equipo::quitarPokemon() {
    // Mostrar los pokemones al usuario
    cout << "Selecciona un pokemon: " << endl;
    for (int i = 0; i < pokemonesRegistrados; i++) {
        cout << i + 1 << ". " << pokemones[i]->get_nombre() << endl;
    }

    // Pedir al usuario que seleccione un pokemon
    int opcion;
    cout << "Ingresa el número del pokemon: ";
    cin >> opcion;

    // Verificar si la opción es válida
    if (opcion >= 1 && opcion <= pokemonesRegistrados) {
        // Eliminar el pokemon del arreglo
        delete pokemones[opcion - 1];
        for (int i = opcion - 1; i < pokemonesRegistrados - 1; i++) {
            pokemones[i] = pokemones[i + 1];
        }
        pokemonesRegistrados--;

        cout << "Pokemon eliminado correctamente." << endl;
    } 
    
    else {
        cout << "Opción inválida." << endl;
    }
}

/**
 * curarEquipo cura a todos los pokemones del equipo
 * 
 * A traves de un ciclo for se recorre toda la lista y se setea la vida de cada pokemon a el "hpBaseNivel"
 * 
 * @param
 * @return
*/

void Equipo::curarEquipo(){
    //Ciclo para recorrer todo el array
    for(int i = 0; i <pokemonesRegistrados; i++){
        pokemones[i]->set_hp(pokemones[i]->get_hpBaseNivel());
    }
}

/**
 * calcularVidaTotal calcula la vida total del equipo
 * 
 * A traves de un ciclo for se recorre toda la lista y se van sumando todos los valores "hp"
 * de los pokemones en la lista "pokemones" por ultimo se setea el nuevo valor de vida total
 * 
 * @param
 * @return
*/


void Equipo::calcularVidaTotal(){
    
    int nuevaVidaTotal;

    //Ciclo para recorrer todo el array
     for(int i = 0; i <pokemonesRegistrados; i++){
        nuevaVidaTotal = nuevaVidaTotal + pokemones[i]->get_hp();
    }

    set_vidaTotal(nuevaVidaTotal);
}

/**
 * pelearEquipo hace que dos equipos peleen
 * 
 * Pelear equipo utiliza un objeto de la clase equipo, calcula la vida total y mete
 * al usuario en un ciclo while hasta que alguno de los dos equipos no tenga vida,
 * mientras esta en este ciclo while se le imprime un menu al usuario en el que tiene
 * dos opciones cambiar de pokemon y usar habilidad, si elige cambiar de  pokemon se 
 * le imprimen los pokemones del equipo y se le pide que seleccione uno, si selecciona 
 * usar habilidad se utiliza la funcion usarHabilidad, a traves de un atributo booleano
 * se determina el turno, si el turno es del enemigo entonces se utiliza la funcion
 * "usarHabilidadEnemigo"
 * 
 * @param
 * Objeto de la clase Equipo
 * @return
*/

void Equipo::pelearEquipo(Equipo *en){
    Equipo* equipoAliado = this;
    Equipo* equipoEnemigo = en;

    //Variable booleana para pasar turnos
    bool turnoAliado = true;

    //Variables para saber que pokemon esta seleccionado
    int pokemonASeleccionado = 0; //Aliado
    int pokemonEseleccionado = 0; //Enemigo

    equipoAliado->calcularVidaTotal();
    equipoEnemigo->calcularVidaTotal(); 

    while (equipoAliado->get_vidaTotal() > 0 && equipoEnemigo->get_vidaTotal() > 0){
        //
        Pokemon *pokemonAliado = equipoAliado->pokemones[pokemonASeleccionado];
        Pokemon *pokemonEnemigo = equipoEnemigo->pokemones[pokemonEseleccionado];

        //Si el turno es del equipo aliado entonces
        if (turnoAliado == true){

            //Imprimimos la informacion del turno
            cout << "Es tu turno" << endl;
            cout << "Pokemon aliado" << endl;
            pokemonAliado->imprimirPokemonPelea();
            cout << "Pokemon enemigo" << endl;
            pokemonEnemigo->imprimirPokemonPelea();

            //Menu opciones durante la pelea
            cout << "Que haras ahora?" << endl;
            cout << "1. Usar habilidad" << endl;
            cout << "2. Cambiar de pokemon" << endl;

            //Pedimos al usuario que seleccione una opcion
            int opcion;
            cout << "\n" << "Selecciona una opcion: ";
            cin >> opcion;

            switch (opcion){
                case 1: {
                    //Usar habilidad
                    pokemonAliado->usarHabilidad(pokemonEnemigo);

                    //Verificamos si el pokemon enemigo ha sido derrotado
                    if (pokemonEnemigo->get_hp() == 0){
                        cout << pokemonEnemigo->get_nombre() << " ha sido derrotado!" << endl;
                        pokemonAliado->calcularExpPelea(pokemonEnemigo);
                        pokemonEseleccionado ++;

                        //Verificamos si el pokemon sube de nivel
                        if(pokemonAliado->get_exp() >= pokemonAliado->get_expBaseNivel()){
                            pokemonAliado->subirNivel();
                            cout << pokemonAliado->get_nombre() << " ha subido de nivel, sus nuevos stats son: " << endl;
                            pokemonAliado->imprimirPokemon();
                            
                        }
                        equipoEnemigo->calcularVidaTotal();
                    }

                    turnoAliado = false;
                    break;
                }
                case 2: {
                    // Mostrar los pokemones disponibles al usuario

                    for (int i = 0; i < pokemonesRegistrados; i++) {
                        cout << i + 1 << ". " << pokemones[i]->get_nombre() << "\t" <<pokemones[i]->get_hp() << "/" << pokemones[i]->get_hpBaseNivel() << endl;
                    }
                    
                        int seleccion;

                        cout << "Selecciona un pokemon:" << endl;
                        cin >> seleccion;
                        seleccion--;

                        while (equipoAliado->pokemones[seleccion]->get_hp() == 0){
                            cout << "No puedes seleccionar este pokemon ya que no tiene vida. Intetalo de nuevo: " << endl;
                            for (int i = 0; i < pokemonesRegistrados; i++) {
                                cout << i + 1 << ". " << pokemones[i]->get_nombre() << "\t" <<pokemones[i]->get_hp() << "/" << pokemones[i]->get_hpBaseNivel() << endl;

                                cout << "Selecciona un pokemon:" << endl;
                                cin >> seleccion;
                                seleccion--;
                            }
                        }   

                        pokemonASeleccionado = seleccion;

                        cout << "Haz cambiado el pokemon: " << equipoAliado->pokemones[pokemonASeleccionado]->get_nombre() << endl;
                    

                    turnoAliado = false;
                    
                    break;
                }

            }
        }

        else if (turnoAliado == false){
            if (pokemonEnemigo->get_hp() > 0){
                pokemonEnemigo->usarHabilidadEnemigo(pokemonAliado);

                if (pokemonAliado->get_hp() == 0){
                    pokemonASeleccionado ++;

                }
                turnoAliado = true;
            }
        }
    }

}


#endif