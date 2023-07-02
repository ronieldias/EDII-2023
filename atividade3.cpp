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

/*
int nos(Arv a) {
    if (arvoreVazia(a)) {
        return 0;
    } else {
        return 1 + nos(a->left) + nos(a->right);
    }
}

int folhas(Arv a) {
    if (arvoreVazia(a)) {
        return 0;
    } else if (a->left == NULL && a->right == NULL) {
        return 1;
    } else {
        return folhas(a->left) + folhas(a->right);
    }
}

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
*/

//13.6. Uma arvore A é estritamente binária se cada nó em A é uma folha ou tem dois filhos
//Crie uma função eb(A) que informa se a arvore A é estritamente binária.
bool eb(Arv a) {
    // Se a árvore estiver vazia, consideramos como estritamente binária
    if (arvoreVazia(a)) {
        return true;
    }
    // Se o nó atual não é uma folha nem possui dois filhos, não é estritamente binária
    if ((a->left == NULL && a->right != NULL) || (a->left != NULL && a->right == NULL)) {
        return false;
    }
    // Verifica recursivamente os filhos da árvore
    bool esquerda = eb(a->left);
    bool direita = eb(a->right);
    // Retorna true somente se ambos os filhos são estritamente binários
    return esquerda && direita;
}

int main() {
    Arv f = criaArvore('F', NULL, NULL);
    Arv e = criaArvore('E', NULL, NULL);
    Arv d = criaArvore('D', NULL, NULL);
    Arv c = criaArvore('C', NULL, f);
    Arv b = criaArvore('B', d, e);
    Arv a = criaArvore('A', b, c);

    imprimeArvore(a);
    cout << "\nArvore estritamente binaria: " << (eb(a) == true? "sim" : "nao") << endl;
    /*
    cout << "\nNumero de nos: " << nos(a) << endl;;
    cout << "Número de folhas: " << folhas(a) << endl;
    cout << "Altura da árvore: " << altura(a) << endl;

    char item1 = 'E', item2 = 'J';
    cout << "Item " << item1 << " encontrado: " << (tem(a, item1) == true? "sim" : "nao") << endl;
    cout << "Item " << item2 << " encontrado: " << (tem(a, item2) == true? "sim" : "nao") << endl;
    */
    destroiArvore(&a);    
  return 0;
}
