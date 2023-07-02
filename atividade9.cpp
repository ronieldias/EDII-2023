#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct no{
    int dado;
    struct no *esquerda;
    struct no *direita;
};

struct no *criarNoVazio(void){
    return NULL;
}

int arvoreVazia(struct no *no){
    return no == NULL;
};

struct no *criarNovoNo(int dado, struct no *esquerda, struct no *direita){
    struct no *no = (struct no *)malloc(sizeof(struct no));
    if (arvoreVazia(no))
        exit(1);
    no->dado = dado;
    no->esquerda = esquerda;
    no->direita = direita;
    return no;
}

int contarNos(struct no *no){
    if (!arvoreVazia(no))
        return 1 + contarNos(no->esquerda) + contarNos(no->direita);
    else
        return 0;
}

int calcularAltura(struct no *no){
    if (arvoreVazia(no))
        return 0;
    else
    {
        int alturaEsquerda = calcularAltura(no->esquerda);
        int alturaDireita = calcularAltura(no->direita);
        return alturaEsquerda >= alturaDireita ? alturaEsquerda + 1 : alturaDireita + 1;
    }
}

void imprimir(struct no *no){
    if (!arvoreVazia(no))
    {
        printf("<%i", no->dado);
        if (no->esquerda != NULL)
            imprimir(no->esquerda);
        else
            printf("<>");
        if (no->direita != NULL)
            imprimir(no->direita);
        else
            printf("<>");
    }
    printf(">");
}

bool arvoreCompleta(struct no *no, int indice, int numeroNos){
    if (no == NULL)
        return true;
    if (indice >= numeroNos)
        return false;
    return (arvoreCompleta(no->esquerda, 2 * indice + 1, numeroNos) && arvoreCompleta(no->direita, 2 * indice + 2, numeroNos));
}

int main(){
    struct no *arvoreBinaria = criarNovoNo(10,
                                           criarNovoNo(20,
                                                       criarNovoNo(30, criarNoVazio(), criarNoVazio()),
                                                       criarNovoNo(40, criarNoVazio(), criarNoVazio())),
                                           criarNovoNo(50,
                                                       criarNoVazio(),
                                                       criarNovoNo(60, criarNoVazio(), criarNoVazio())));

    imprimir(arvoreBinaria);
    printf("\nTotal de nos: %i\n", contarNos(arvoreBinaria));
    printf("Altura: %i\n", calcularAltura(arvoreBinaria));

    int numeroNos = contarNos(arvoreBinaria);
    int indice = 0;
    if (arvoreCompleta(arvoreBinaria, indice, numeroNos))
        printf("É uma árvore binária completa\n");
    else
        printf("É uma árvore binária incompleta\n");

    return 0;
}