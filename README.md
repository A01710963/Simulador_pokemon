# Simulador_pokemon
Este proyecto consiste en un simulador de pokemon el cual le permite al usuario pelear contra un gimnasio, por lo que se genera una estructura de clases para poder manejar a los pokemones, equipos, entrenadores y habilidades. Divide los pokemones en Agua, Planta, Fuego y Normal.

## Funcionalidad
El programa permite al usuario pelear contra un gimnasio pokemon.

Consta con un menu con las opciones iniciales y corre sobre consola.

## Consideraciones
El programa no permite personalizar pokemones, habilidades, equipos ni entrenadores ya que este programa solo es de prueba.

Para que el programa sirva de forma adecuada todos los atributos que son listas dentro de las clases deben tener al menos un valor.

El programa solo corre en la consola y esta hecho con c++ standard por lo que corre en todos los sistemas operativos

compilar con:
    "g++ habilidad.h pokemon.h equipo.h entrenador.h main.cpp"
    
 correr en linux:
      "/a.out"
      
 correr en windows:
      "a.exe"

## Correciones
Se cambio la clase habilidad, ahora no tiene herencia.

Se le agrego herencia a la clase pokemon (Planta, Fuego, Agua, Normal)

Se le agrego polimorfismo a la clase pokemon

La clase Pokemon se convirtio en una clase abstracta a traves de las funciones "calculaDanio" y "agregaHabilidad"
