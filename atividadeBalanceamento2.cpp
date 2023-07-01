#include <queue>
#include <iostream>

using namespace std;

template <class T>
class ArvoreNo{
public:
    T el;
    ArvoreNo<T> *left, *right;
    ArvoreNo(){
        left = right = 0;
    }
    ArvoreNo(T e, ArvoreNo<T> *l = 0, ArvoreNo<T> *r = 0){
        el = e;
        left = l;
        right = r;
    }
};

template <class T>
class Arvore{
protected:
    ArvoreNo<T> *root;

public:
    Arvore(){
        root = 0;
    }
    ~Arvore(){
        clear();
    }
    void clear(){
        clear(root);
        root = 0;
    }

    ArvoreNo<T> *getRoot(){
        return root;
    }
    bool isEmpty() const{
        return root = 0;
    }

    void visit(ArvoreNo<T> *p){
        cout << p->el << " ";
    }

    T search(T el){
        ArvoreNo<T> *p = root;
        while (p != 0){

            if (el == p->el)
                return p->el;
            else{
                if (el < p->el)
                    p = p->left;
                else
                    p = p->right;
            }
        }
        return 0;
    }
    // obs: pg 209 figura 6.23
    void insert(T el){
        ArvoreNo<T> *p = root, *prev = 0;
        while (p != 0){
            prev = p;
            if (el < p->el)
                p = p->left;
            else
                p = p->right;
        }
        if (root == 0) // a arvore esta vazia
            root = new ArvoreNo<T>(el);
        else if (el < prev->el)
            prev->left = new ArvoreNo<T>(el);
        else
            prev->right = new ArvoreNo<T>(el);
    }

    void percusoExtensao(){
        queue<ArvoreNo<T> *> f;
        ArvoreNo<T> *p = root;
        if (p != 0){
            f.push(p);
            while (!f.empty()){
                p = f.front();
                visit(p);
                f.pop();
                if (p->left != 0)
                    f.push(p->left);
                if (p->right != 0)
                    f.push(p->right);
            }
        }
    }

    void preorder(ArvoreNo<T> *p){
        if (p != 0){
            visit(p);
            preorder(p->left);
            preorder(p->right);
        }
    }

    void backbone(ArvoreNo<T> *p){
        if (p == 0)
            return;
        ArvoreNo<T> *prev = 0;
        while (p != 0){
            if (p->left != 0){
                ArvoreNo<T> *temp = p->left;
                p->left = temp->right;
                temp->right = p;
                if (prev != 0)
                    prev->right = temp;
                else
                    root = temp;
                p = temp;
            }
            prev = p;
            p = p->right;
        }
    }
};

template <class T>
int arvAltura(ArvoreNo<T> *node){
    if (node == 0)
        return 0;

    int alturaEsq = arvAltura(node->left);
    int alturaDir = arvAltura(node->right);

    return 1 + max(alturaEsq, alturaDir);
}

template <class T>
int arvBalanceamento(ArvoreNo<T> *node){
    if (node == 0)
        return 0;

    int alturaEsq = arvAltura(node->left);
    int alturaDir = arvAltura(node->right);

    return alturaEsq - alturaDir;
}

template <class T>
bool verifBalanceamento(ArvoreNo<T> *node){
    if (node == 0)
        return true;

    int balanceamento = arvBalanceamento(node);
    if (balanceamento > 1 || balanceamento < -1)
        return false;

    return arvBalanceamento(node->left) && arvBalanceamento(node->right);
}

int main(){
    Arvore<int> *a = new Arvore<int>();
    // 1) Inclua os seguintes valores na seguinte ordem em uma árvore binária:
    a->insert(7);
    a->insert(22);
    a->insert(14);
    a->insert(40);
    a->insert(30);
    a->insert(63);
    a->insert(80);

    // 1.1) Qual a altura da árvore resultante?
    int altura = arvAltura(a->getRoot());
    cout << "A altura da arvore eh: " << altura << endl;

    // 1.2) Mostre a árvore resultante.
    cout << "Arvore resultante: ";
    a->preorder(a->getRoot());
    cout << endl;

    // 1.3) A árvore resultante está balanceada ou não?
    bool balanceada = verifBalanceamento(a->getRoot());
    if (balanceada == true){
        cout << "Arvore balanceada: sim" << endl;
    }else{
        cout << "Arvore balanceada: nao" << endl;
    }

    // 1.4) Implemente a 1ª parte do algoritmo DWS, aonde a resultante da árvore após as
    // rotações deve ser uma árvore somente com filhos a esquerda.
    a->backbone(a->getRoot());

    // 1.5) Mostre a árvore resultante
    cout << "---Apos as rotacoes -----" << endl;
    a->preorder(a->getRoot());
    cout << endl;

    return 0;
}