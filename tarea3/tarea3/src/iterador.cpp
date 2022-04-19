/* 5576229 */ // sustituiir con los 7 dígitos de la cédula

#include "../include/iterador.h"

struct _nodo{
  nat num;
  _nodo * sig;
};

struct _rep_iterador {
  _nodo * pri;
  _nodo * ult;
  _nodo * act;
};

typedef struct _nodo * nodo ;

TIterador crearIterador() {
  TIterador iterador = new _rep_iterador;
  iterador->act = NULL;
  iterador->pri = NULL;
  iterador->ult = NULL;
  return iterador;
}

void liberarIterador(TIterador iter) {
  if(iter != NULL) {
    nodo naux = iter->pri;
    while(naux != NULL) {
      nodo rnodo = naux;
      naux = naux->sig;
      delete rnodo;
    }
    delete iter;
  }
}

bool estaDefinidaActual(TIterador iter) {
  if(iter->act != NULL){
    return true;
  }else{
    return false;
  }
}

void agregarAIterador(nat elem, TIterador const iter) {
  if(iter->ult == NULL){
    nodo nodo = new _nodo;
    nodo->num = elem;
    nodo->sig = NULL;
    iter->ult = nodo;
    iter->pri = nodo; 
  }else{
    nodo nodo = new _nodo;
    nodo->num = elem;
    iter->ult->sig = nodo;
    nodo->sig = NULL;
    iter->ult = nodo;  
  }
}

void reiniciarIterador(TIterador const iter) {
    iter->act=iter->pri;
}

void avanzarIterador(TIterador const iter) {
  if (estaDefinidaActual(iter))
  {
   if(iter->act == iter->ult){
     iter->act = NULL;
   }else{
     iter->act=iter->act->sig;
   }
  } 
}

nat actualEnIterador(TIterador iter) {
    return iter->act->num;  
}
