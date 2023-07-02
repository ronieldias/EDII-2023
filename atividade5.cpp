#include<stdio.h>
#include<iostream>
#include<stdlib.h>

using namespace std;

typedef struct arv {
  int valor;
  struct arv *esq;
  struct arv *dir;
} *Arv;

bool arvoreVazia(Arv a) {
    return (a == NULL);
}

Arv arvCriavazia(void){
    return NULL;
}

Arv arvCria(int n, Arv sae, Arv sad) {
    Arv p = (Arv) malloc(sizeof(struct arv));
    p -> valor = n;
    p -> esq = sae;
    p -> dir = sad;
    return p;
}

float valor(Arv a) {
    //se a arvore for vazia, retorna mensagem de erro e para a execução
    if (arvoreVazia(a)) {
        throw runtime_error("ERRO: arvore vazia");
    }

    //se o nó atual for uma folha, retorna o valor armazenado nele
    if (arvoreVazia(a->esq) && arvoreVazia(a->dir)) {
        return a->valor;
    }

    //avalia as subárvores esquerda e direita e aplica a operação correspondente
    int valorEsquerda = valor(a->esq);
    int valorDireita = valor(a->dir);

    //aplica a operação correspondente ao nó atual
    switch (a->valor) {
        case '+':
            return valorEsquerda + valorDireita;
        case '-':
            return valorEsquerda - valorDireita;
        case '*':
            return valorEsquerda * valorDireita;
        case '/':
            return valorEsquerda / valorDireita;
        default:
            throw runtime_error("ERRO: operador invalido");
    }
}

int main() {
    Arv a = arvCria('+', arvCria(3, NULL, NULL), arvCria('*', arvCria(4, NULL, NULL), arvCria(2, NULL, NULL)));
    int resultado = valor(a);
    cout << "Resultado da expressão: " << resultado << endl;

    return 0;
}
