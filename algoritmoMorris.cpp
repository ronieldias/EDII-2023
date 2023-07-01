#include <iostream>
#include <queue>
using namespace std;

template<class T>
class No {
public:
    T el;
    No<T> *esq, *dir;

    No() {
        esq = dir = 0;
    }

    No(T e, No<T> *l = 0, No<T> *r = 0) {
        el = e;
        esq = l;
        dir = r;
    }
};

template<class T>
class Arv {
protected:
    No<T> *root;

public:
    Arv() {
        root = 0;
    }

    No<T>* getRoot() {
        return root;
    }

    bool isEmpty() const {
        return root == 0;
    }

    void visit(No<T> *p) {
        cout << p->el << " ";
    }

    void insereNaArv(T el) {
        No<T> *p = root, *prev = 0;
        while (p != 0) {
            prev = p;
            if (el < p->el) {
                p = p->esq;
            } else {
                p = p->dir;
            }
        }
        if (root == 0) {
            root = new No<T>(el);
        } else if (el < prev->el) {
            prev->esq = new No<T>(el);
        } else {
            prev->dir = new No<T>(el);
        }
    }

    void inOrder() {
        No<T> *p = root, *tmp;
        while (p != 0) {
            if (p->esq == 0) {
                visit(p);
                p = p->dir;
            } else {
                tmp = p->esq;
                while (tmp->dir != 0 && tmp->dir != p) {
                    tmp = tmp->dir;
                }
                if (tmp->dir == 0) {
                    tmp->dir = p;
                    p = p->esq;
                } else {
                    visit(p);
                    tmp->dir = 0;
                    p = p->dir;
                }
            }
        }
    }

    void preOrder() {
        No<T> *p = root;
        while (p != 0) {
            if (p->esq == 0) {
                visit(p);
                p = p->dir;
            } else {
                No<T> *tmp = p->esq;
                while (tmp->dir != 0 && tmp->dir != p) {
                    tmp = tmp->dir;
                }
                if (tmp->dir == 0) {
                    visit(p);
                    tmp->dir = p;
                    p = p->esq;
                } else {
                    tmp->dir = 0;
                    p = p->dir;
                }
            }
        }
    }
};

int main() {
    Arv<int> *arv = new Arv<int>();

    arv->insereNaArv(16);
    arv->insereNaArv(20);
    arv->insereNaArv(5);
    arv->insereNaArv(7);
    arv->insereNaArv(11);
    arv->insereNaArv(14);
    arv->insereNaArv(25);
    arv->insereNaArv(3);
    arv->insereNaArv(28);
    arv->insereNaArv(17);

    cout << "******************************" << endl; 
    cout << "In Order" << endl;
    arv->inOrder();
    cout << endl;
    cout << "Pre Order" << endl;
    arv->preOrder();
    cout << endl;
    cout << "******************************" << endl; 

    delete arv;

    return 0;
}

/* Características do algoritmo de Morris para percurso in-order: 
- Uso de espaço de memória constante: 
    Não requer estruturas de dados adicionais, como pilhas, resultando em uma implementação 
    eficiente e economia de espaço.
- Preservação a estrutura original da árvore:
    Não modifica a estrutura da árvore original, garantindo que a árvore permaneça inalterada 
    antes e após o percurso.
- Percurso em tempo linear: 
   Realiza o percurso in-order e pre-order em tempo linear, tornando-o eficiente para árvores 
   de qualquer tamanho, evitando o uso de pilhas ou recursão, resultando em um rápido desempenho.
*/