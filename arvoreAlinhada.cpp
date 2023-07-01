#include <iostream>

using namespace std;

template<typename T>
struct ArvNo {
    T valor;
    ArvNo<T>* esq;
    ArvNo<T>* dir;
    ArvNo(const T& valor):valor(valor), esq(NULL), dir(NULL){}
};

template<typename T>
void inOrder(ArvNo<T>* raiz){
    if(raiz!=NULL){
        inOrder(raiz->esq);
        cout << raiz->valor << " ";
        inOrder(raiz->dir);
    }
}

template<typename T>
void preOrder(ArvNo<T>* raiz) {
    if(raiz!= NULL){
        cout<< raiz->valor << " ";
        preOrder(raiz->esq);
        preOrder(raiz->dir);
    }
}

template<typename T>
void inserir(ArvNo<T>*& raiz, const T& valor){
    if(raiz==NULL){
        raiz = new ArvNo<T>(valor); 
    } else {
        if(valor < raiz->valor){
            inserir(raiz->esq, valor);
        } else {
            inserir(raiz->dir, valor);
        }
    }
} 

int main(){
    ArvNo<int>* raiz = NULL; 

    inserir(raiz, 9);
    inserir(raiz, 4);
    inserir(raiz, 14);
    inserir(raiz, 3);
    inserir(raiz, 6);

	cout << "******** ARVORE ALINHADA ********" << endl;
    cout << "Percurso In-Order: ";
    inOrder(raiz);
    cout << endl;

    cout << "Percurso Pre-Order: ";
    preOrder(raiz);
    cout << endl;
    cout << "*********************************" << endl;

    return 0;
}