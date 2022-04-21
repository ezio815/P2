/* 5576229 */ // sustituiir con los 7 dígitos de la cédula

#include "../include/aplicaciones.h"

TCadena enOrden(TAbb abb, TCadena ncad){
  if(abb != NULL){
    ncad = enOrden(derecho(abb), ncad);
    ncad = insertarAlInicio(natInfo(raiz(abb)), realInfo(raiz(abb)), ncad);
    ncad = enOrden(izquierdo(abb), ncad);
  }
  return ncad;
}

TCadena linealizacion(TAbb abb) {
  TCadena cad = crearCadena();
  cad = enOrden(abb, cad);
  return cad;

}

TCadena enOrdenD(TAbb abb, TCadena ncad, int cont){
  if(abb != NULL){
    cont++;
    ncad = enOrden(izquierdo(abb), ncad);
    ncad = insertarAlInicio(natInfo(raiz(abb)), realInfo(raiz(abb)), ncad);
    ncad = enOrden(derecho(abb), ncad);
  }
  return ncad;
}

void imprimirAbb(TAbb abb) {
  int cont = 0;
  TAbb auxabb = abb; 
  TCadena ncad = NULL;
  while (abb != NULL){
    enOrdenD(abb, ncad, cont);
    for(int i = 0; i<cont-1; i++)
      printf("-");
  }

}

bool esPerfecto(TAbb abb) { return false; }

TAbb menores(double limite, TAbb abb) { return NULL; }

TIterador caminoAscendente(nat clave, nat k, TAbb abb) { return NULL; }

void imprimirPalabrasCortas(nat k, TPalabras palabras) {}

TPalabras buscarFinPrefijo(ArregloChars prefijo, TPalabras palabras) {
  return NULL;
}
