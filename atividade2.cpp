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

//13.2. Crie a função nos(A), que devolve o total de nós na árvore binária A.
int nos(Arv a) {
    if (arvoreVazia(a)) {
        return 0;
    } else {
        return 1 + nos(a->left) + nos(a->right);
    }
}

//13.3. Crie a função folhas(A), que devolve o total de folhas na árvore binária A.
int folhas(Arv a) {
    if (arvoreVazia(a)) {
        return 0;
    } else if (a->left == NULL && a->right == NULL) {
        return 1;
    } else {
        return folhas(a->left) + folhas(a->right);
    }
}

//13.4. Crie a função altura(A) que devolva a altura da arvore binária A.
int altura(Arv a) {
    if (arvoreVazia(a)) {
        return -1;
    } else {
        int alturaEsquerda = altura(a->left);
        int alturaDireita = altura(a->right);
        if (alturaEsquerda > alturaDireita){
            return alturaEsquerda + 1;
        }else{
            return alturaDireita + 1;
        }
    }
}

//13.5. Crie a função tem(A, x) que informa se a árvore binária A tem o item X.
bool tem(Arv a, char item) {
    if (arvoreVazia(a)) {
        return false;
    } else if (a->valor == item) {
        return true;
    } else {
        bool encontradoEsquerda = tem(a->left, item);
        bool encontradoDireita = tem(a->right, item);
        return encontradoEsquerda || encontradoDireita;
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
    cout << "\nNumero de nos: " << nos(a) << endl;;
    cout << "Número de folhas: " << folhas(a) << endl;
    cout << "Altura da árvore: " << altura(a) << endl;

    char item1 = 'E', item2 = 'J';
    cout << "Item " << item1 << " encontrado: " << (tem(a, item1) == true? "sim" : "nao") << endl;
    cout << "Item " << item2 << " encontrado: " << (tem(a, item2) == true? "sim" : "nao") << endl;
    destroiArvore(&a);

  return 0;
}