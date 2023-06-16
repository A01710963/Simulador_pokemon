/*
 *
 *Proyecto simulador de pokemon
 *Claudio Gabriel Lopez Briceño
 *A01710963
 *23/05/23
 *
 *Main
 */

#include <iostream>
#include <string>
#include "habilidad.h"
#include "pokemon.h"
#include "equipo.h"
#include "entrenador.h"

using namespace std;

//Creamos Objetos

Entrenador *entrenadorUsuario = new Entrenador(0,"Claudio","Masculino");
Entrenador *polimorfismo = new Entrenador(0,"Polimorfismo","Sin genero");
Entrenador *sobrecarga = new Entrenador(0, "Sobrecarga", "Sin genero");
Entrenador *benjamin = new Entrenador(0, "Benja", "Masculino");


Pokemon *bulbasaur = new Planta("Bulbasaur", "planta", 10000, 50, 0, 185, 149, 143, 177, 150, 0, 15, 78, 15, 84, 109, 78, 85, 185, 78, 17000);
Pokemon *charizard = new Fuego("Charizard", "fuego", 13000, 50, 0, 193, 130, 154, 175, 155, 0, 17, 76, 14, 81, 105, 73, 89, 193, 74, 17000);
Pokemon *blastoise = new Agua("Blastoise", "agua", 12500, 50, 0, 187, 147, 147, 170, 160, 0, 16, 78, 15, 82, 106, 75, 90, 187, 70, 17000);

Pokemon *metapod = new Normal("Metapod", "normal", 8000, 30, 0, 100, 98, 112, 155, 133, 0, 10, 54, 10, 59, 82, 48, 61, 100, 49, 9000);

Pokemon *pikachu = new Normal("Pikachu", "normal", 6000, 20, 0, 60, 63, 82, 125, 102, 0, 8, 32, 8, 38, 64, 35, 52, 60, 35, 7000);

Pokemon *mewtwo = new Normal("Mewtwo", "normal",18000, 60, 0, 203, 170, 175, 203, 186, 0, 24, 95, 10, 102, 132, 93, 108, 203, 90, 20000);

Habilidad *mordisco = new Habilidad("mordisco", "normal", "fisico", 60, 35, 35);
Habilidad *dobleGolpe = new Habilidad("dobleGolpe", "normal", "fisico", 35, 16, 16);
Habilidad *surf = new Habilidad("surf", "agua", "especial", 90, 15, 15);
Habilidad *ondaIgnea = new Habilidad("ondaIgnea", "fuego", "especial", 95, 10, 10);
Habilidad *fuerzaG = new Habilidad("fuerzaG", "planta", "fisico", 80, 10, 10);



//Main

int main(){

    //Creamos equipos
    entrenadorUsuario->creaEquipo(0,0);
    polimorfismo->creaEquipo(0,0);
    sobrecarga->creaEquipo(0,0);
    benjamin->creaEquipo(0,0);

    Equipo * equipoAliado = entrenadorUsuario->equipoPok[0];
    Equipo * equipoPoli = polimorfismo->equipoPok[0];
    Equipo * equipoSobre = sobrecarga->equipoPok[0];
    Equipo * equipoBenja = benjamin->equipoPok[0];

    //Agregamos habilidaddes a pokemones
    bulbasaur->agregaHabilidad(fuerzaG);
    bulbasaur->agregaHabilidad(mordisco);

    charizard->agregaHabilidad(ondaIgnea);
    charizard->agregaHabilidad(mordisco);

    blastoise->agregaHabilidad(surf);
    blastoise->agregaHabilidad(mordisco);

    metapod->agregaHabilidad(mordisco);

    pikachu->agregaHabilidad(mordisco);
    pikachu->agregaHabilidad(dobleGolpe);

    mewtwo->agregaHabilidad(mordisco);
    mewtwo->agregaHabilidad(dobleGolpe);

    //Agregamos pokemones a equipos
    equipoAliado->agregarPokemon(bulbasaur);
    equipoAliado->agregarPokemon(charizard);
    equipoAliado->agregarPokemon(blastoise);

    equipoPoli->agregarPokemon(pikachu);

    equipoSobre->agregarPokemon(metapod);

    equipoBenja->agregarPokemon(mewtwo);

    entrenadorUsuario->imprimirMenu(entrenadorUsuario, polimorfismo, sobrecarga, benjamin,equipoAliado,equipoPoli,equipoSobre,equipoBenja);

    return 0;
}