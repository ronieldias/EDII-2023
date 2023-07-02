//Membros: Roniel Dias

#include <queue>
#include <iostream>
#include <math.h>

using namespace std;

template <class T>
class ArvoreNo
{
public:
    T el;
    ArvoreNo<T> *left, *right;
    ArvoreNo()
    {
        left = right = 0;
    }
    ArvoreNo(T e, ArvoreNo<T> *l = 0, ArvoreNo<T> *r = 0)
    {
        el = e;
        left = l;
        right = r;
    }
};

template <class T>
class Arvore
{
protected:
    ArvoreNo<T> *root;

public:
    Arvore()
    {
        root = 0;
    }
    ~Arvore()
    {
        clear();
    }
    void clear()
    {
        clear(root);
        root = 0;
    }

    ArvoreNo<T> *getRoot()
    {
        return root;
    }
    bool isEmpty() const
    {
        return root = 0;
    }

    void visit(ArvoreNo<T> *p)
    {
        cout << p->el << " ";
    }

    T search(T el)
    {
        ArvoreNo<T> *p = root;
        while (p != 0)
        {

            if (el == p->el)
                return p->el;
            else
            {
                if (el < p->el)
                    p = p->left;
                else
                    p = p->right;
            }
        }
        return 0;
    }
    // obs: pg 209 figura 6.23
    void insert(T el)
    {
        ArvoreNo<T> *p = root, *prev = 0;
        while (p != 0)
        {
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

    void percusoExtensao()
    {
        queue<ArvoreNo<T> *> f;
        ArvoreNo<T> *p = root;
        if (p != 0)
        {
            f.push(p);
            while (!f.empty())
            {
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

    void preorder(ArvoreNo<T> *p)
    {
        if (p != 0)
        {
            visit(p);
            preorder(p->left);
            preorder(p->right);
        }
    }

    int arvAltura(ArvoreNo<T> *node)
    {
        if (node == 0)
            return -1;
        else
        {
            int alturaEsq = arvAltura(node->left);
            int alturaDir = arvAltura(node->right);

            // return 1 + max(alturaEsq, alturaDir);
            if (alturaEsq >= alturaDir)
            {
                return alturaEsq + 1;
            }
            else
            {
                return alturaDir + 1;
            }
        }
    }

    void imprime(ArvoreNo<T> *node)
    {
        if (node != 0)
        {
            cout << "<" << node->el;
            if (node->left != 0)
            {
                imprime(node->left);
            }
            else
            {
                cout << "<>";
            }
            if (node->right != 0)
            {
                imprime(node->right);
            }
            else
            {
                cout << "<>";
            }
        }
        cout << ">";
    }

    void backbone(ArvoreNo<T> *p)
    {
        ArvoreNo<T> *atual = p;
        int node_count = 0;

        while (atual != 0)
        {
            while (atual->right != NULL)
            {
                rotacaoEsq(atual);
            }
            atual = atual->left;
            node_count++;
        }
    }

    void rotacaoEsq(ArvoreNo<T> *p)
    {
        if (p == NULL || p->right == NULL)
        {
            return;
        }
        const int tmp_value = p->el;
        p->el = p->right->el;
        p->right->el = tmp_value;
        ArvoreNo<T> *oR = p->right;
        p->right = oR->right;
        oR->right = oR->left;
        oR->left = p->left;
        p->left = oR;
    }

    void rotacaoDir(ArvoreNo<T> *p) {
        if (p == NULL || p->left == NULL) {
            return;
        }
        const int tmp_value = p->el;
        p->el = p->left->el;
        p->left->el = tmp_value;
        ArvoreNo<T> *oL = p->left;
        p->left = oL->left;
        oL->left = oL->right;
        oL->right = p->right;
        p->right = oL;
    }

    void balancearArv(ArvoreNo<T> *p) {
        ArvoreNo<T> *atual = p;
        int contNo = 0;

        while (atual != 0) {
            while (atual->left != NULL) {
                rotacaoDir(atual);
            }
            atual = atual->right; 
            contNo++;
        }

        int expected = ceil(log2(contNo) - contNo);
        ArvoreNo<T> *atual1 = p;

        for(int i = 0; i < expected; i++) {
            if(i == 0) {
                rotacaoEsq(atual1);
                atual1 = p;
            } else {
                rotacaoEsq(atual1->right);
                atual1 = atual1->right;
            }
        }

        int times = contNo;
        while(times > 1) {
            times /= 2;
            
            rotacaoEsq(p);
            ArvoreNo<T> *atual2 = p;

            for(int i = 0; i < times - 1; i++) {
                rotacaoEsq(atual2->right);
                atual2 = atual2->right;
            }
        }
    }
};

int main()
{
    Arvore<int> *a = new Arvore<int>();

    a->insert(7);
    a->insert(22);
    a->insert(14);
    a->insert(40);
    a->insert(30);
    a->insert(63);
    a->insert(80);
    cout << "**************************************************" << endl;
    cout << "Altura da arvore: ";
    cout << a->arvAltura(a->getRoot()) << endl;
    cout << "--- Arvore original ---" << endl;
    a->imprime(a->getRoot());
    cout << endl;
    a->preorder(a->getRoot());

    a->balancearArv(a->getRoot());

    cout << "\n--- Arvore apos as rotacoes ---" << endl;
    a->imprime(a->getRoot());
    cout << endl;
    cout << "**************************************************" << endl;

    return 0;
}