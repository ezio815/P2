typedef unsigned int uint ;

struct nodoAB {
uint elem ;
nodoAB * izq , * der ;
};

typedef nodoAB * AB ;

AB consArbol(uint x, AB a, AB b){
    AB c=new nodoAB;
    c->elem=x;
    c->izq=a;
    c->der=b;
    return c;
}

uint contarElems(AB a){
    if(a==nullptr){
        return 0;
    }else{
        return 1 + contarElems(a->izq) + contarElems(a->der);
    }
}

uint contarHojas(AB a){
    if(a==nullptr){
        return 0;
    }else{
        if(a->izq==nullptr && a->der==nullptr){
            return 1;
        }else{
            return contarHojas(a->izq) + contarHojas(a->der);
        }
    }
}

uint altura(AB a){
    if(a==nullptr){
        return 0;
    }else{
        uint alturaI = altura(a->izq);
        uint alturaD = altura(a->der);
        if (alturaI >= alturaD){
            return 1 + alturaI;
        }
        else{
            return 1 + alturaD;
        }
    }
}

AB copiar(AB a){
    if(a==nullptr){
        return nullptr;
    }else{
        AB b = new nodoAB;
        b->elem=a->elem;
        b->izq=copiar(a->izq);
        b->der=copiar(a->der);
        return b;
    }
}

void liberarArbol(AB a){
    if(a!=nullptr){
        liberarArbol(a->izq);
        liberarArbol(a->der);
        delete a;
    }
}