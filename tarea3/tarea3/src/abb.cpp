/* 5576229 */ // sustituiir con los 7 dígitos de la cédula

#include "../include/abb.h"

struct _rep_abb {

    TInfo info;
    _rep_abb * izq;
    _rep_abb * der;
};

TAbb crearAbb() { return NULL; }

void liberarAbb(TAbb abb) {
     if (abb!=NULL)
    {
        liberarAbb(abb->der);
        liberarAbb(abb->izq);
        liberarInfo(abb->info);
        delete abb;
    }
  }

bool esVacioAbb(TAbb abb) { 
    if (abb==NULL){
        return true;
    }else{
        return false;
    }
}

TAbb buscarSubarbol(nat clave, TAbb abb) { 
    if (abb != NULL){
        if (clave == natInfo(abb->info))
        {
            return abb;
        }else if(natInfo(abb->info) > clave){
            return buscarSubarbol(clave, abb->izq);
        }else{
           return buscarSubarbol(clave, abb->der);
        }
    }else{
        return NULL;
    }
}

TInfo raiz(TAbb abb) {
    return abb->info; 
}

TAbb izquierdo(TAbb abb) {
    return abb->izq;

}

TAbb derecho(TAbb abb) {
    return abb->der;
}

TInfo menorEnAbb(TAbb abb) {
    if (abb->der != NULL && abb->izq == NULL){
        return abb->info;
    }else if (abb->izq == NULL && abb->der == NULL){
        return abb->info;
    }else
        return menorEnAbb(abb->izq);
}

TInfo mayorEnAbb(TAbb abb) {
    if (abb->der == NULL && abb->izq != NULL)
    {
        return abb->info;
    }else if(abb->izq == NULL && abb->der == NULL){
        return abb->info;
    }else
    return mayorEnAbb(abb->der);

}

TAbb consAbb(TInfo dato, TAbb izq, TAbb der) {
     TAbb raiz = new _rep_abb;
     raiz->info = dato;
     raiz->izq = izq;
     raiz->der = der;
     return raiz;
}

void insertarEnAbb2(TInfo dato, TAbb &abb) {
  if(abb == NULL) {
    TAbb nodo = new _rep_abb;
    nodo->info = dato;
    nodo->izq = NULL;
    nodo->der = NULL;
    abb = nodo;
  } else if(natInfo(abb->info) > natInfo(dato))
    insertarEnAbb2(dato, abb->izq);
  else
    insertarEnAbb2(dato, abb->der);
}

TAbb insertarEnAbb(TInfo dato, TAbb abb) {
    insertarEnAbb2(dato, abb);
    return abb;
}




TAbb removerDeAbb(nat clave, TAbb abb) {
    if (abb != NULL){
        if(natInfo(abb->info) == clave){
            if (abb->izq == NULL){
                TAbb aux = abb;
                abb=abb->der;
                liberarInfo(aux->info);
                delete aux;
            }else if (abb->der == NULL){
                TAbb aux = abb;
                abb=abb->izq;
                liberarInfo(aux->info);
                delete aux;
            }else{
                liberarInfo(abb->info);
                abb->info = copiaInfo(mayorEnAbb(abb->izq));
                abb->izq = removerDeAbb(natInfo(abb->info), abb->izq);
            }
        }else if(clave < natInfo(abb->info)){
           abb->izq = removerDeAbb(clave, abb->izq);
        }else{
           abb->der = removerDeAbb(clave, abb->der);
        }
    }
    return abb;
}

TAbb copiaAbb(TAbb abb) {
     if (abb == NULL){
        return NULL;
    }else{ 
        TAbb copia = new _rep_abb;
        copia -> info = abb -> info;
        copia -> der = copiaAbb (abb -> der);
        copia -> izq = copiaAbb (abb -> izq);
        return copia;
    }
}

