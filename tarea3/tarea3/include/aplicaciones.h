/*
  Módulo de definición de 'aplicaciones'.


  Laboratorio de Programación 2.
  InCo-FIng-UDELAR
 */

#ifndef _APLICACIONES_H
#define _APLICACIONES_H

#include "abb.h"
#include "cadena.h"
#include "iterador.h"
#include "palabras.h"

/*
  Devuelve una 'TCadena' con los elementos de 'abb' en orden creciente según
  sus componentes naturales.
  La 'TCadena' devuelta no comparte memoria con 'abb'.
  Cada elemento de 'abb' se debe visitar una sola vez.
 */
TCadena linealizacion(TAbb abb);

/*
  Imprime los elementos de 'abb', uno por línea, en orden descendente de la
  propiedad de orden de los árboles 'TAbb'.
  Antes del elemento imprime una cantidad de guiones igual a su profundidad.
  El elemento se imprime según la especificación dada en 'infoATexto'.
  La profundidad de la raíz es 0.
  Cada elemento de 'abb' se debe visitar una sola vez.
 */
void imprimirAbb(TAbb abb);

/*
  Devuelve 'true' si y solo si 'abb' es perfecto.
  Un árbol es perfecto si todas las hojas están en el mismo nivel y todos los
  nodos internos tienen dos subárboles no vacíos; o sea, si todos los niveles
  están completos.
 */
bool esPerfecto(TAbb abb);

/*
  Devuelve un 'TAbb' con copias de los elementos de 'abb' que cumplen la
  condición  "realInfo(elemento) < limite".
  La estructura del árbol resultado debe ser análoga a la de 'abb'. Esto
  significa que dados dos nodos 'U' y 'V' de 'abb' en los que se cumple la
  condición y tal que 'U' es ancestro de 'V', en el árbol resultado la copia de
  'U' debe ser ancestro de la copia de 'V' cuando sea posible. Esto no siempre
  se puede lograr y al mismo tiempo mantener la propiedad de orden del árbol
  en el caso en el que en un nodo 'W' no se cumple la condición y en sus dos
  subárboles hay nodos en los que se cumple. En este caso, la copia del nodo
  cuyo elemento es el mayor (según la propiedad de orden definida) de los que
  cumplen la condición en el subárbol izquierdo de 'W' deberá ser ancestro de
  las copias de todos los descendientes de 'W' que cumplen la condición.
  Ver ejemplos en la letra y en los casos en 'test'.
  El árbol resultado no comparte memoria con 'abb'.
  Cada elemento de 'abb' se debe visitar una sola vez.
 */
TAbb menores(double limite, TAbb abb);

/*
  Devuelve un 'TIterador' con los hasta 'k' primeros componentes naturales de
  los elementos que están en el camino ascendente que va desde el nodo que
  contiene al elemento cuyo componente natrual es 'clave' hacia la raíz.
  Si 'k' es mayor que la cantidad de elementos en ese camino solo se incluyen
  los elementos corresponientes al camino.
  Ver ejemplos en la letra y en los casos en 'test'.
  El resultado NO comparte memoria con los parámetros.
  Precondición: ! esVacioAbb(buscarSubarbol(clave, abb)).
  Solo se puede acceder a nodos que están en el camino desde la raíz de 'abb'
  hacia el nodo que contiene al elemento cuyo componente natural es 'clave' y
  cada uno de ellos solo puede visitarse una vez .
  Poscondición: en el 'TIterador' resultado la posición debe quedar no definida.
 */
TIterador caminoAscendente(nat clave, nat k, TAbb abb);

/*
  Imprime las palabras representadas en el árbol 'palabras' cuyo largo es
  menor o igual a 'k'.
  Las imprime una por línea en orden lexicográfico.
  Ningún nodo debe ser visitado más de una vez.
  Precondición: k > 0.
  Ver ejemplos en la letra y en los casos de prueba.
 */
void imprimirPalabrasCortas(nat k, TPalabras palabras);

/*
  Devuelve el subárbol de 'palabras' que representa el fin (la última letra) de
  'prefijo'.
  Si 'prefijo' no está representado en 'pals' devuelve NULL.
  O sea, si 'prefijo' está en 'palabras' el nodo más profundo del camino que lo
  representa es la ráiz del subárbol resultado.
  Ver ejemplos en la letra y en los casos de prueba.
 */
TPalabras buscarFinPrefijo(ArregloChars prefijo, TPalabras palabras);

#endif
