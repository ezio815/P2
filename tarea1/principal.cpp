/*
  Módulo principal de la tarea 1.

Intérprete de comandos para probar los módulos.

Están creados una TCadena 'cad' y una TColCadenas 'colCads'.

Cada comando tiene un nombre y una secuencia (posiblemente vacía) de parámetros.
Se asume que los comandos están bien formados. Esto implica que:
- el nombre es uno de los descritos más abajo;
- la cantidad y tipo de los parámetros cumplen con lo requerido.


El comando
Fin
termina el programa

El comando
# comentario
imprime comentario.


  Laboratorio de Programación 2.
  InCo-FIng-UDELAR
*/

#include "include/cadena.h"
#include "include/colCadenas.h"
#include "include/info.h"
#include "include/utils.h"

#include <assert.h>
#include <stdio.h>
#include <string.h>

#define MAX_PALABRA 32
#define MAX_LINEA 256

// programa principal
int main() {

  TColCadenas colCads = crearColCadenas();
  TCadena cad = crearCadena();

  char restoLinea[MAX_LINEA + 1];
  char nom_comando[MAX_PALABRA];

  int cont_comandos = 0;
  bool salir = false;
  while (!salir) {
    // mostrar el prompt
    cont_comandos++;
    printf("%u>", cont_comandos);

    // leer el comando
    leerChars(nom_comando);

    // procesar el comando
    if (0 == strcmp(nom_comando, "Fin")) {
      salir = true;
      printf("Fin.\n");
      // comentario
    } else if (0 == strcmp(nom_comando, "#")) {
      leerRestoLinea(restoLinea);
      printf("# %s.\n", restoLinea);

      // operaciones de cadena

    } else if (0 == strcmp(nom_comando, "cantidadEnCadena")) {
      printf("La cantidad es %u.\n", cantidadEnCadena(cad));

    } else if (0 == strcmp(nom_comando, "estaEnCadena")) {
      nat natural = leerNat();
      printf("%u %s en la cadena.\n", natural,
             (estaEnCadena(natural, cad)) ? "está" : "no está");

    } else if (0 == strcmp(nom_comando, "insertarAlInicio")) {
      assert(cantidadEnCadena(cad) < L);
      nat natural = leerNat();
      double real = leerDouble();
      cad = insertarAlInicio(natural, real, cad);
      printf("Se insertó (%d,%4.2lf) al inicio de la cadena.\n", natural, real);

    } else if (0 == strcmp(nom_comando, "infoCadena")) {
      nat natural = leerNat();
      assert(estaEnCadena(natural, cad));
      printf("El elemento es ");
      imprimirInfo(infoCadena(natural, cad));
      printf("\n");

    } else if (0 == strcmp(nom_comando, "removerDeCadena")) {
      nat natural = leerNat();
      assert(estaEnCadena(natural, cad));
      cad = removerDeCadena(natural, cad);
      printf("Se removió la primera aparición de %u de la cadena.\n", natural);

    } else if (0 == strcmp(nom_comando, "imprimirCadena")) {
      imprimirCadena(cad);

      // operaciones de colCadenas
    } else if (0 == strcmp(nom_comando, "cantidadColCadenas")) {
      nat pos = leerNat();
      assert((0 <= pos) && (pos < CANT_CADS));
      printf("La cantidad en la cadena %u es %u.\n", pos,
             cantidadColCadenas(pos, colCads));

    } else if (0 == strcmp(nom_comando, "estaEnColCadenas")) {
      nat natural = leerNat();
      nat pos = leerNat();
      assert((0 <= pos) && (pos < CANT_CADS));
      printf("%u %s en la cadena %u.\n", natural,
             (estaEnColCadenas(natural, pos, colCads)) ? "está" : "no está",
             pos);

    } else if (0 == strcmp(nom_comando, "insertarEnColCadenas")) {
      nat natural = leerNat();
      double real = leerDouble();
      nat pos = leerNat();
      assert((0 <= pos) && (pos < CANT_CADS));
      assert(cantidadColCadenas(pos, colCads) < L);
      colCads = insertarEnColCadenas(natural, real, pos, colCads);
      printf("Se insertó (%u,%4.2lf) en la cadena %u.\n", natural, real, pos);

    } else if (0 == strcmp(nom_comando, "infoEnColCadenas")) {
      nat natural = leerNat();
      nat pos = leerNat();
      assert((0 <= pos) && (pos < CANT_CADS));
      assert(estaEnColCadenas(natural, pos, colCads));
      printf("La primera aparición de %u en la cadena %u es ", natural, pos);
      imprimirInfo(infoEnColCadenas(natural, pos, colCads));
      printf("\n");

    } else if (0 == strcmp(nom_comando, "removerDeColCadenas")) {
      nat natural = leerNat();
      nat pos = leerNat();
      assert((0 <= pos) && (pos < CANT_CADS));
      assert(estaEnColCadenas(natural, pos, colCads));
      colCads = removerDeColCadenas(natural, pos, colCads);
      printf("Se removió la primera aparición de %d de la cadena %d.\n",
             natural, pos);

      /* en siguientes tareas
    } else if (0 == strcmp(nom_comando, "reiniciar")) {
      liberarCadena(cad);
      cad = crearCadena();
      liberarColCadenas(colCads);
      colCads = crearColCadenas();
      printf("Estructuras reiniciadas.\n");
      */

    } else {
      printf("Comando no reconocido.\n");
    } // if
    fgets(restoLinea, MAX_LINEA + 1, stdin);
  } // while

  // en siguientes tareas
  //  liberarCadena(cad);
  //  liberarColCadenas(colCads);
  return 0;
} // main
