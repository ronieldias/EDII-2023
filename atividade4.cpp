#include<stdio.h>
#include<iostream>
#include<stdlib.h>

using namespace std;

typedef struct arv {
  char valor;
  struct arv *esq;
  struct arv *dir;
} *Arv;

bool arvoreVazia(Arv a) {
    return (a == NULL);
}

Arv arvCriavazia(void){
    return NULL;
}

Arv arvCria(char n, Arv sae, Arv sad) {
  Arv p = (Arv) malloc(sizeof(struct arv));
  p -> valor = n;
  p -> esq = sae;
  p -> dir = sad;
  return p;
}

void imprimeArvore(Arv a) {
    if (arvoreVazia(a)) {
        cout << "<>";
    } else {
        cout << "<" << a->valor;
        imprimeArvore(a->esq);
        imprimeArvore(a->dir);
        cout << ">";
    }
}

//13.7. Duas arvores binárias A e B  são iguais se elas tem a mesma forma e os mesmos itens. 
//Crie a função igual() que informa se A é igual a B
bool igual(Arv a, Arv b) {
    // Se ambas as árvores são vazias, são consideradas iguais
    if (arvoreVazia(a) && arvoreVazia(b)) {
        return true;
    }
    // Se apenas uma das árvores é vazia, elas são consideradas diferentes
    if (arvoreVazia(a) || arvoreVazia(b)) {
        return false;
    }
    // Verifica se os valores dos nós são iguais
    if (a->valor != b->valor) {
        return false;
    }
    // Verifica recursivamente os filhos das árvores
    bool esquerda = igual(a->esq, b->esq);
    bool direita = igual(a->dir, b->dir);
    // Retorna true somente se os dois filhos são iguais
    return esquerda && direita;
}

int main(){
    Arv a = arvCria('A', arvCria('B', arvCria('D', NULL, NULL), arvCria('E', NULL, NULL)), arvCria('C', NULL, arvCria('F', NULL, NULL)));
    Arv b = arvCria('A', arvCria('B', arvCria('D', NULL, NULL), arvCria('E', NULL, NULL)), arvCria('C', NULL, arvCria('F', NULL, NULL)));
    Arv c = arvCria('A', arvCria('B', arvCria('D', NULL, NULL), arvCria('F', NULL, NULL)), arvCria('C', NULL, arvCria('G', NULL, NULL)));
    cout << "Arvodres A e B iguais? " << (igual(a, b) == true ? "sim" : "nao") << endl;
    cout << "Arvodres A e C iguais? " << (igual(a, c) == true ? "sim" : "nao") << endl; 
    return 0;
}