/*
  Módulo de definición de 'TAbb'.

  Los elementos de tipo 'TAbb' son árboles binarios de búsqueda de
  elementos de tipo 'TInfo'.

  La propiedad de orden de los árboles es definida por el componente
  natural de sus elementos. O sea, para cada nodo, el componente natural
  del elemento contenido en él es mayor que el componente natural de los
  elementos contenidos en los nodos de su subárbol izquierdo y menor que
  el componente natural de los elementos contenidos en los nodos de su
  subárbol derecho.


  Laboratorio de Programación 2.
  InCo-FIng-UDELAR
 */

#ifndef _ABB_H
#define _ABB_H

#include "info.h"

// Representación de 'TAbb'.
// Se debe definir en abb.cpp.
// struct _rep_abb;
// Declaración del tipo 'TAbb'
typedef struct _rep_abb *TAbb;

/*
  Devuelve un 'TAbb' vacío (sin elementos).
 */
TAbb crearAbb();

/*
  Libera la memoria asociada a 'abb' y todos sus elementos.
 */
void liberarAbb(TAbb abb);

/*
  Devuelve 'true' si y solo si 'abb' es vacío (no tiene elementos).
 */
bool esVacioAbb(TAbb abb);

/*
  Devuelve el subárbol que tiene como raíz al nodo con el elemento cuyo
  componente natural es 'clave'.
  Si 'clave' no pertenece a 'abb', devuelve el árbol vacío.
 */
TAbb buscarSubarbol(nat clave, TAbb abb);

/*
  Devuelve el elemento contenido en la raíz de 'b'.
  Precondición: ! esVacioAbb(abb).
 */
TInfo raiz(TAbb abb);

/*
  Devuelve el subárbol izquierdo de 'abb'.
  Precondición: ! esVacioAbb(abb).
 */
TAbb izquierdo(TAbb abb);

/*
  Devuelve el subárbol derecho de 'abb'.
  Precondición: ! esVacioAbb(abb).
 */
TAbb derecho(TAbb abb);

/*
  Devuelve el elemento menor (según la propiedad de orden definida) de 'abb'.
  Precondición: ! esVacioAbb(abb).
 */
TInfo menorEnAbb(TAbb abb);

/*
  Devuelve el elemento mayor (según la propiedad de orden definida) de 'abb'.
  Precondición: ! esVacioAbb(abb).
 */
TInfo mayorEnAbb(TAbb abb);

/*
  Devuelve un 'TAbb' con 'dato' en su raíz y subárboles izquierdo y
  derecho son 'izq' y 'der' respectivamente.
  El resulrado comparte memoria con los parámetros.
  Precondiciones:
    - esVacioAbb(izq) || (natInfo(mayorEnAbb(izq)) < natInfo(dato))
    - esVacioAbb(der) || (natInfo(menorEnAbb(der)) > natInfo(dato))
 */
TAbb consAbb(TInfo dato, TAbb izq, TAbb der);

/*
  Inserta 'dato' en 'abb' respetando la propiedad de orden definida.
  Devuelve 'abb'.
  Precondición: esVacioAbb(buscarSubarbol(natInfo(dato), abb))
 */
TAbb insertarEnAbb(TInfo dato, TAbb abb);

/*
  Remueve de 'abb' el nodo que contiene el elemento cuyo componente natural
  es 'clave'.
  Libera la memoria del nodo y del elemento.
  Si los dos subárboles del nodo a remover son no vacíos, en sustitución
  del elemento removido debe quedar el que es el mayor (segun la propiedad
  de orden definida) en el subárbol izquierdo.
  Devuelve 'abb'.
  Precondición: ! esVacioAbb(buscarSubarbol(clave, abb))
 */
TAbb removerDeAbb(nat clave, TAbb abb);

/*
  Devuelve una copia de 'abb'.
  El resultado NO comparte memoria con el parámetro.
 */
TAbb copiaAbb(TAbb abb);

#endif
