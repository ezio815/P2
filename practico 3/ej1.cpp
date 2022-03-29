#include <cstddef>

struct nodo {
int elem ;
nodo * sig ;
};
typedef nodo * lista ;

/*dada una lista no vacía, retorna su último elemento.*/
int last(lista a) {
    while (a->sig != NULL)
    {
        a = a->sig;
    }
    
    return a->elem;
}

/*dada una lista no vacía, retorna el promedio de sus elementos.*/
int average(lista a) {
    int contador = 0;
    int suma = 0;
    do {
        suma += a->elem;
        contador++;
        a = a->sig;
    } while (a->sig != NULL);
    return suma / contador;
}

/*dados un entero x y una lista l ordenada: inserta x en l ordenadamente. Comparar con la
solución recursiva.*/
void insOrd(int x, lista l) {
    bool fin = false;
    while (l->sig != NULL && !fin)
    {
        if(l->sig->elem >= x){
            lista q = new nodo;
            q->elem = x;
            q->sig = l->sig;
            l->sig = q;
            fin = true;
        }
        else
            l = l->sig;
    }
}

/*dados un entero x y una lista l, inserta x al final de l.*/
void snoc(int x, lista l) {
    while (l->sig != NULL) {
        l = l->sig;
    }
    lista q = new nodo;
    q->sig = NULL;
    q->elem = x;
    l->sig = q;
}

/*dados un entero x y una lista l, elimina a x de l.*/
void removeAll(lista l, int x) {
    lista q;
    while (l->sig != NULL)
    {
        if(x==l->sig->elem){
            q = l->sig;
            l->sig=q->sig;
            delete(q);
        }
        else {
            l = l->sig;
        }
    }
    

}

/*dadas dos listas l y p, verifica si l está incluida en p. Una lista l1 está incluida en l2 si
y sólo sí existen dos listas, l3 y l4, tal que cumplen que l2 = l3l1l4. Tenga en cuenta que las listas li,
con i ∈ {1, ..., 4} pueden ser vacías.*/
bool isIncluded() {
    return false;
}

int main() {
    return 0;
}


/*
Utilizando la representación de la Figura 1, implemente las siguientes funciones o procedimientos en
forma iterativa y sin usar procedimientos auxiliares. En el caso de inserciones o eliminaciones se
debe modificar los parámetros de entrada y compartir memoria con los mismos.
I. last: dada una lista no vacía, retorna su último elemento.
II. average: dada una lista no vacía, retorna el promedio de sus elementos.
III. insOrd: dados un entero x y una lista l ordenada: inserta x en l ordenadamente. Comparar con la
solución recursiva.
IV. snoc: dados un entero x y una lista l, inserta x al final de l.
V. removeAll: dados un entero x y una lista l, elimina a x de l.
VI. isIncluded: dadas dos listas l y p, verifica si l está incluida en p. Una lista l1 está incluida en l2 si
y sólo sí existen dos listas, l3 y l4, tal que cumplen que l2 = l3l1l4. Tenga en cuenta que las listas li,
con i ∈ {1, ..., 4} pueden ser vacías.
*/

/*l1 = [2, 3]

l2 = [1, 2, 3, 4]

l3 = [1]

l4 = [4]

l2 = [2, 3] -> l3 = [], l4 = []*/