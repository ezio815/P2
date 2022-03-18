/* 6251162 */ // sustituiir con los 7 dígitos de la cédula

#include "../include/colCadenas.h"
#include "../include/cadena.h"


struct _rep_colCadenas {
  TCadena cadenas[CANT_CADS];
  int tope;
};

TColCadenas crearColCadenas() {
  TColCadenas columna = new _rep_colCadenas;
  for (nat i = 0; i < CANT_CADS; i++)
    columna->cadenas[i] = crearCadena();
  return columna;
}

/* en siguientes tareas
void liberarColCadenas(TColCadenas col) {
}
*/

nat cantidadColCadenas(nat pos, TColCadenas col) {
  return cantidadEnCadena(col->cadenas[pos]);
}

bool estaEnColCadenas(nat natural, nat pos, TColCadenas col) {
  return estaEnCadena(natural, col->cadenas[pos]);
}

TColCadenas insertarEnColCadenas(nat natural, double real, nat pos,
                                 TColCadenas col) {
  insertarAlInicio(natural, real, col->cadenas[pos]);
  return col;
}

TInfo infoEnColCadenas(nat natural, nat pos, TColCadenas col) {
  return infoCadena(natural, col->cadenas[pos]);
}

TColCadenas removerDeColCadenas(nat natural, nat pos, TColCadenas col) {
  removerDeCadena(natural, col->cadenas[pos]);
  return col;
}