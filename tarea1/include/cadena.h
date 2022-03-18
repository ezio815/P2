/*
  Módulo de definición de 'TCadena'.

  Los elementos de tipo TCadena son colecciones lineales acotadas de hasta 'L'
  elemtntos de tipo TInfo.

  Laboratorio de Programación 2.
  InCo-FIng-UDELAR
 */

#ifndef _CADENA_H
#define _CADENA_H

#include "info.h"

#define L 10 // máxima cantidad de elementos de una TCadena

// Representación de 'TCadena'.
// Se debe definir en 'cadena.cpp'.
// struct _rep_cadena;
// Declaración del tipo 'TCadena'
typedef struct _rep_cadena *TCadena;

/*
  Devuelve la 'TCadena' vacía (sin elementos).
 */
TCadena crearCadena();

/*
  Libera la memoria asignada a 'cad' y la de todos sus elementos.
 */
// void liberarCadena(TCadena cad); // en siguientes tareas

/*
  Devuelve la cantidad de elementos de 'cad'.
 */
nat cantidadEnCadena(TCadena cad);

/*
  Devuelve 'true' si y solo si 'natural' es el componente natural de algún
  elemento de 'cad'.
 */
bool estaEnCadena(nat natural, TCadena cad);

/*
  Inserta al inicio de 'cad' un elemento cuyos componentes son 'natural' y
  'real'.
  Los demás elementos de 'cad' mantienen su orden relativo.
  Devuelve 'cad'.
  Precondición: cantidadEnCadena(cad) < L.
 */
TCadena insertarAlInicio(nat natural, double real, TCadena cad);

/*
  Devuelve el primer elemento de 'cad' cuyo componente natural es 'natural'.
  Precondición: estaEnCadena(natural, cad).
  El tiempo de ejecución en el peor caso es O(n), siendo 'n' la cantidad de
  elementos en 'cad'.
 */
TInfo infoCadena(nat natural, TCadena cad);

/*
  Remueve el primer elemento de 'cad' cuyo componente natural es 'natural'.
  Los demás elementos de 'cad' mantienen su orden relativo.
  Se libera la memoria asignada al mismo.
  Devuelve 'cad'.
  Precondición: estaEnCadena(natural, cad).
 */
TCadena removerDeCadena(nat natural, TCadena cad);

/*
  Imprime los elementos de 'cad' de la siguiente forma:
  (n de pos1,r de pos1)(n de pos2,r de pos2) ...
  donce 'n' es el componente natural y 'r' es el componente real.
  Antes de terminar, se debe imprimir un fin de linea.
  Si cantidadEnCadena(cad) es 0 sólo se imprime el fin de línea.
 */
void imprimirCadena(TCadena cad);

#endif
