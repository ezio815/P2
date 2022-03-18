/*
  Módulo de definición de 'TColCadenas'.

  Un elemento de tipo 'TColCadenas' es una colección de CANT_CADS 'TCadena's.

  Cada cadena se identifica con una posición entre 0 y CANT_CADS - 1.

  Laboratorio de Programación 2.
  InCo-FIng-UDELAR
 */

#ifndef _COL_CADENAS_H
#define _COL_CADENAS_H

#include "info.h"

#define CANT_CADS 10

// Representación de 'TColCadenas'.
// Se debe definir en 'colCadenas.cpp'.
// struct _rep_colCadenas;
// Declaración del tipo 'TColCadenas'
typedef struct _rep_colCadenas *TColCadenas;

/*
  Devuelve una colección de 'CANT_CADS' cadenas vacías.
 */
TColCadenas crearColCadenas();

/*
  Libera la memoria asignada a 'col' y todos sus elementos.
 */
// void liberarColCadenas(TColCadenas col); // en siguientes tareas

/*
  Devuelve la cantidad de elementos de la cadena de 'col' identificada con
  'pos'. Precondición: 0 <= pos < CANT_CADS.
 */
nat cantidadColCadenas(nat pos, TColCadenas col);

/*
  Devuelve 'true' si y solo si 'natural' es el componente natural de algún
  elemento de la cadena de 'col' identificada con 'pos'.
  Precondición: 0 <= pos < CANT_CADS.
 */
bool estaEnColCadenas(nat natural, nat pos, TColCadenas col);

/*
  Inserta al inicio de la cadena de 'col' identificada con 'pos'
  un elemento cuyos componentes son 'natural' y 'real'.
  Los demás elementos de esa cadena mantienen su orden relativo.
  Devuelve col.
  Precondición: cantidadColCadenas(pos, col) < L.
 */
TColCadenas insertarEnColCadenas(nat natural, double real, nat pos,
                                 TColCadenas col);

/*
  Devuelve el primer elemento (el más cercano al inicio) de la cadena de 'col'
  identificada con 'pos' cuyo componenete natural es 'natural'.
  Precondición: estaEnColCadenas(natural, pos, col)
 */
TInfo infoEnColCadenas(nat natural, nat pos, TColCadenas col);

/*
  Remueve el primer elemento (el más cercano al inicio) de la cadena de 'col'
  identificada con 'pos' cuyo componenete natural es ' natural'.
  Los demás elementos de esa cadena mantienen su orden relativo.
  Devuelve col.
  Precondición: estaEnColCadenas(natural, pos, col).
 */
TColCadenas removerDeColCadenas(nat natural, nat pos, TColCadenas col);

#endif
