#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

typedef struct arv {
  char valor;
  struct arv *left;
  struct arv *right;
} *Arv;

Arv criaArvore(char n, Arv sae, Arv sad) {
  Arv p = (Arv) malloc(sizeof(struct arv));
  p -> valor = n;
  p -> left = sae;
  p -> right = sad;
  return p;
}

bool arvoreVazia(Arv a) {
    return (a == NULL);
}

void destroiArvore(Arv *a) {
    if (*a != NULL) {
        destroiArvore(&((*a)->left));
        destroiArvore(&((*a)->right));
        free(*a);
        *a = NULL;
    }
}

void imprimeArvore(Arv a) {
    if (arvoreVazia(a)) {
        cout << "<>";
    } else {
        cout << "<" << a->valor;
        imprimeArvore(a->left);
        imprimeArvore(a->right);
        cout << ">";
    }
}

int main() {
  Arv f = criaArvore('F', NULL, NULL);
  Arv e = criaArvore('E', NULL, NULL);
  Arv d = criaArvore('D', NULL, NULL);
  Arv c = criaArvore('C', NULL, f);
  Arv b = criaArvore('B', d, e);
  Arv a = criaArvore('A', b, c);

  imprimeArvore(a);
  destroiArvore(&a);

  return 0;
}