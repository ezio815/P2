/* 6251162 */ // sustituiir con los 7 dígitos de la cédula

#include "../include/cadena.h"

// los elementos se mantienen entre 0 y cantidad - 1, incluidos
struct _rep_cadena {
  TInfo arreglo[L];
  int tope;
};

TCadena crearCadena() {
  TCadena elemento = new _rep_cadena;
  elemento->tope = -1;
  return elemento;
}

/* en siguientes tareas
void liberarCadena(TCadena cad) {
}
*/

nat cantidadEnCadena(TCadena cad) {
  return cad->tope + 1;
}

bool estaEnCadena(nat natural, TCadena cad) {
  for (nat i = 0; i < cantidadEnCadena(cad); i++) {
    if (natInfo(cad->arreglo[i]) == natural)
      return true;
  }
  return false;
}

TCadena insertarAlInicio(nat natural, double real, TCadena cad) {
  if (cantidadEnCadena(cad) < L) {
    for (int i = cantidadEnCadena(cad); i > 0; i--)
      cad->arreglo[i] = cad->arreglo[i - 1];
    cad->arreglo[0] = crearInfo(natural, real);
    cad->tope++;
  }
  return cad;
}

TInfo infoCadena(nat natural, TCadena cad) {
  TInfo elemento;
  if (estaEnCadena(natural, cad)) {
    nat i = 0;
    do {
      elemento = cad->arreglo[i];
      i++;
    } while (natInfo(elemento) != natural && i < cantidadEnCadena(cad));
  }
  return elemento;
}

TCadena removerDeCadena(nat natural, TCadena cad) {
  TInfo elemento = infoCadena(natural, cad);
  bool mover = false;
  for (nat i = 0; i < cantidadEnCadena(cad); i++) {
    if (!mover && cad->arreglo[i] == elemento) {
      liberarInfo(cad->arreglo[i]);
      mover = true;
    }
    if (mover) {
      if (i + 1 < L) {
        cad->arreglo[i] = cad->arreglo[i + 1];
      }
    }
  }
  cad->tope--;
  return cad;
}

void imprimirCadena(TCadena cad) {
  if (cantidadEnCadena(cad) > 0) {
    for (int i = 0; i <= cad->tope; i++)
      imprimirInfo(cad->arreglo[i]);
  }
  printf("\n");
}
