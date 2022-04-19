/* 5576229 */ // sustituiir con los 7 dígitos de la cédula

#include "../include/cadena.h"

struct _rep_cadena {
  TInfo info;
  _rep_cadena * sig;

};

TCadena crearCadena() {
  return NULL;
}


void liberarCadena(TCadena cad) {
  if (cad != NULL){
    if(cad->sig == cad){
      liberarInfo(cad->info);
      delete(cad);
    }else{
      TCadena aux = cad;
      cad=cad->sig;
      do{
        TCadena aux2 = cad;
        cad=cad->sig;
        liberarInfo(aux2->info);
        delete(aux2);
      }
      while (cad != aux);
      liberarInfo(cad->info);
      delete(cad);
    }
  }
}

nat cantidadEnCadena(TCadena cad) {
  nat cont = 0;
  if(cad != NULL){
    if (cad == cad->sig){
      cont++;
    }else{
    TCadena aux = cad;
    do{
      cont++;
      cad=cad->sig;
    }
    while (cad != aux);
  }
  }
  return cont;
}

bool estaEnCadena(nat natural, TCadena cad) {
  if (cad == NULL)
  {
    return false;
  }
    TCadena aux = cad;
    do{
      if (natInfo(cad->info) == natural)
      {
        return true;
      }
      cad= cad->sig;
    }
    while (cad != aux);
  return false;
}

TCadena insertarAlInicio(nat natural, double real, TCadena cad) {
  
  if (cad == NULL)
  {
    cad = new _rep_cadena; 
    cad->info=crearInfo(natural, real);
    cad->sig=cad;
    return cad;
  }else{
    TCadena aux = new _rep_cadena;
    aux->sig=cad->sig;
    cad->sig = aux;
    aux->info=cad->info;
    cad->info=(crearInfo(natural, real));
    return cad;
  }
}

TInfo infoCadena(nat natural, TCadena cad) {
  TCadena aux = cad;
  if(cad != NULL){
    do{
      if (natInfo(cad->info) == natural)
      {
        return cad->info;
      }else{
        cad=cad->sig;
      }
    }
    
    while (cad != aux);
    }
    return  NULL;
}

TInfo primeroEnCadena(TCadena cad) {
    return cad->info;
}

TCadena cadenaSiguiente(TCadena cad) {
  if (cad == NULL || cad->sig==cad)
  {
    return cad;
  }else{
     return cad->sig;
  }
}

TCadena removerDeCadena(nat natural, TCadena cad) {
  TCadena aux = cad;
    if (natInfo(cad->info) == natural){
      if(cad->sig != cad){
        TCadena auxr = cad->sig;
        cad->sig = cad->sig->sig;
        liberarInfo(cad->info);
        cad->info = auxr->info;
        delete (auxr);
        return (cad);
      }else{
        liberarInfo(cad->info);
        delete(cad);
        return NULL;
      }
    }
      do{
        if (natInfo(cad->sig->info) == natural)
        {
          TCadena aux2 = cad->sig->sig;
          TCadena auxr = cad->sig;
          liberarInfo(auxr->info);
          delete (auxr);
          cad->sig = aux2;
          return aux;
        }else{
        cad=cad->sig; 
        }
      } while (cad != aux);
return cad;
}
void imprimirCadena(TCadena cad) {
  TCadena aux= cad;
  if(cantidadEnCadena(cad) != 0){
  do{
    imprimirInfo(aux->info);
    aux=aux->sig;
  }
  while (cad != aux);
  }
  printf("\n");
}
