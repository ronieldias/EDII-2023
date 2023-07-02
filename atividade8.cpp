#include <stdio.h>
#include <iostream>
#include <stdlib.h>
using namespace std;

typedef struct arv{
  char info;
  struct arv *esq;
  struct arv *dir;
} Arv;

bool arvoreVazia(Arv *a){
  return (a == NULL);
}

Arv *arvore(char x, Arv *e, Arv *d){
  Arv *novo = (Arv *)malloc(sizeof(Arv));
  novo->esq = e;
  novo->dir = d;
  novo->info = x;
  return novo;
}

void imprime(Arv *n){
  if (n != NULL){
    cout << "<" << n->info;
    imprime(n->esq);
    imprime(n->dir);
    cout << ">";
  }else
    cout << "<>";
}

int calculaQuantNos(Arv *no){
  if (no == NULL)
    return 0;
  else
    return 1 + calculaQuantNos(no->esq) + calculaQuantNos(no->dir);
}

int calculaQuantNosFolha(Arv *no){
  if (no == NULL)
    return 0;
  else if (no->esq == NULL && no->dir == NULL)
    return 1;
  else
    return calculaQuantNosFolha(no->esq) + calculaQuantNosFolha(no->dir);
}

int alturaArvore(Arv *no){
  if (arvoreVazia(no)){
    return -1;
  }
  else{
    int alturaEsquerda = alturaArvore(no->esq);
    int alturaDireita = alturaArvore(no->dir);
    if (alturaEsquerda > alturaDireita){
      return alturaEsquerda + 1;
    }
    else{
      return alturaDireita + 1;
    }
  }
}

int procura(Arv *no, char valor){
  if (arvoreVazia(no)){
    return false;
  }
  else if (no->info == valor){
    return true;
  }
  else{
    bool encontradoEsquerda = procura(no->esq, valor);
    bool encontradoDireita = procura(no->dir, valor);
    return encontradoEsquerda || encontradoDireita;
  }
}

void removeSubArvore(Arv *no, char valor){
  if (arvoreVazia(no))
    return;
  if (no->esq != NULL && no->esq->info == valor){
    removeSubArvore(no->esq, valor);
    free(no->esq);
    no->esq = NULL;
  }
  if (no->dir != NULL && no->dir->info == valor){
    removeSubArvore(no->dir, valor);
    free(no->dir);
    no->dir = NULL;
  }
  removeSubArvore(no->esq, valor);
  removeSubArvore(no->dir, valor);
}

bool arvoreCheia(Arv* no) {
  if (no == NULL)
    return true;
  //se o nó não tiver filhos, ele é uma folha
  if (no->esq == NULL && no->dir == NULL)
    return true;
  //se o nó não tiver exatamente dois filhos, não é uma árvore cheia
  if (no->esq == NULL || no->dir == NULL)
    return false;
  //verifica recursivamente se os filhos são árvores cheias
  return arvoreCheia(no->esq) && arvoreCheia(no->dir);
}

int main(){
  Arv *f = arvore('F', NULL, NULL);
  Arv *e = arvore('E', NULL, NULL);
  Arv *d = arvore('D', NULL, NULL);
  Arv *c = arvore('C', NULL, f);
  Arv *b = arvore('B', d, e);
  Arv *a = arvore('A', b, c);

  Arv *s = arvore('S', NULL, NULL);
  Arv *o = arvore('O', NULL, NULL);
  Arv *i = arvore('I', NULL, NULL);
  Arv *g = arvore('G', NULL, NULL);
  Arv *p = arvore('P', o, s);
  Arv *h = arvore('H', g, i);
  Arv *m = arvore('M', h, p);

  cout << "**************************************************" << endl;
  // arvore A original
  cout << "Arvore A original" << endl;
  imprime(a);
  cout << endl;
  cout << "Arvore cheia? " << (arvoreCheia(a) == true ? "sim" : "nao") << endl;
  
  cout << endl;

  // arvore M original
  cout << "Arvore M original" << endl;
  imprime(m);
  cout << endl;
  cout << "Arvore cheia? " << (arvoreCheia(m) == true ? "sim" : "nao") << endl;
  cout << "**************************************************" << endl;

  return 0;
}