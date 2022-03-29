struct nodo {
int elem ;
nodo * sig ;
};
typedef nodo * lista ;
void insOrd(int x, lista &l){
    if(l==nullptr || l->elem>=x){
        lista k=new nodo;
        k->elem=x;
        k->sig=l;
        l=k;
    }else{
        insOrd(x, l->sig);
    }
}

void snoc(int x, lista &l){
    if(l==nullptr){
        l=new nodo;
        l->elem=x;
        l->sig=nullptr;
    }else{
        snoc(x,l->sig);
    }
}

void removeAll(int x, lista &l){
    if(l!=nullptr){
        if(l->elem==x){
            lista k=l->sig;
            delete l;
            l=k;
            removeAll(x, l);
        }else{
            removeAll(x, l->sig);
        }
    }
}


int main(){

    return 0;
}