#include <stdio.h>
#include <iostream>
#include <stdlib.h>
//#include <string>

using namespace std;

typedef struct arv {
    int valor;
    struct arv* esq;
    struct arv* dir;
} *Arv;


bool arvVazia(Arv a) {
    return (a == NULL);
}

Arv arvCriavazia(void){
    return NULL;
}

Arv arvCria(int n, Arv e, Arv d) {
    Arv p = (Arv) malloc(sizeof(struct arv));
    p -> valor = n;
    p -> esq = e;
    p -> dir = d;
    return p;
}

void arvDestroi(Arv *a) {
    if (*a != NULL) {
        arvDestroi(&((*a)->esq));
        arvDestroi(&((*a)->dir));
        free(*a);
        *a = NULL;
    }
}

void arvImprime(Arv a) {
    if (!arvVazia(a)){
        cout<<"<" <<a->valor;
        arvImprime(a->esq);
        arvImprime(a->dir);
        cout<<">";
    }
    else {
        cout<<"<>";
    }
}

void arvImprimeDecrescente(Arv a) {
    if (!arvVazia(a)){
        arvImprimeDecrescente(a->dir);
        cout << a->valor << " ";
        arvImprimeDecrescente(a->esq);
    }
}

int main(){
    Arv a = arvCria(10, arvCria(5, arvCria(3, NULL, NULL), arvCria(7, NULL, NULL)), arvCria(15, NULL, arvCria(20, NULL, NULL)));
    cout << "******************************" << endl;
    cout << "Estrutura da arvore" << endl;
    arvImprime(a);
    cout << endl;
    cout << "Elementos em ordem decrescente" << endl;
    arvImprimeDecrescente(a);
    cout << endl;
    cout << "******************************" << endl;
    
    return 0;
}