#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct No {
    int valor;
    No* esq;
    No* dir;

    No(int val) {
        valor = val;
        esq = NULL;
        dir = NULL;
    }
};

void insere(No*& root, int valor) {
    if (root == NULL) {
        root = new No(valor);
        return;
    }

    if (valor < root->valor)
        insere(root->esq, valor);
    else
        insere(root->dir, valor);
}

int alturaArv(No* root) {
    if (root == NULL)
        return 0;

    int alturaEsq = alturaArv(root->esq);
    int alturaDir = alturaArv(root->dir);

    return max(alturaEsq, alturaDir) + 1;
}

vector<int> preencheInOrder(No* root) {
    vector<int> aux;
    if (root == NULL)
        return aux;

    vector<int> esq = preencheInOrder(root->esq);
    aux.insert(aux.end(), esq.begin(), esq.end());

    aux.push_back(root->valor);

    vector<int> dir = preencheInOrder(root->dir);
    aux.insert(aux.end(), dir.begin(), dir.end());

    return aux;
}

No* arvBalanceada(vector<int>& sortedArray, int primeiro, int ultimo) {
    if (primeiro > ultimo)
        return NULL;

    int meio = (primeiro + ultimo) / 2;
    No* root = new No(sortedArray[meio]);

    root->esq = arvBalanceada(sortedArray, primeiro, meio - 1);
    root->dir = arvBalanceada(sortedArray, meio + 1, ultimo);

    return root;
}

bool ehBalanceada(No* root){
	int alturaEsq = alturaArv(root->esq);
    int alturaDir = alturaArv(root->dir);
    bool aux = abs(alturaEsq - alturaDir) <= 1;
    
    return aux;
}

bool arvIguais(No* root1, No* root2) {
    if (root1 == NULL && root2 == NULL)
        return true;

    if (root1 == NULL || root2 == NULL)
        return false;

    if (root1->valor != root2->valor)
        return false;

    return arvIguais(root1->esq, root2->esq) && arvIguais(root1->dir, root2->dir);
}
 

int main() {
    // 1) Inclua os seguintes valores na seguinte ordem em uma árvore binária
    int arr[] = {7, 6, 22, 14, 40, 63};
    vector<int> valores(arr, arr + sizeof(arr) / sizeof(arr[0]));

    No* root = NULL;
    for (size_t i = 0; i < valores.size(); ++i)
        insere(root, valores[i]);

        cout << "**************************************************" << endl; 
    // 1.1) Qual a altura da árvore resultante?
    int height = alturaArv(root);
    cout << "Altura da árvore: " << height << endl;

    // 1.2) Mostre a árvore resultante
    cout << "Arvore resultante (in-order): ";
    vector<int> inOrder = preencheInOrder(root);
    for (size_t i = 0; i < inOrder.size(); ++i)
        cout << inOrder[i] << " ";
    cout << endl;

    // 1.3) A árvore resultante está balanceada ou não?
    cout << "Arvore resultante esta balanceada? " << (ehBalanceada(root) ? "Sim" : "Nao") << endl;

    // 1.4) No caso da árvore resultante NÃO ESTAR balanceada aplique o algoritmo de reordenação dos dados para balancear a árvore.
    vector<int> ordenarValores = valores;
    sort(ordenarValores.begin(), ordenarValores.end());
    No* root_ordenada = arvBalanceada(ordenarValores, 0, ordenarValores.size() - 1);

  
    // 1.5) No caso da árvore resultante NÃO ESTAR balanceada aplique o algoritmo de reordenação dos dados para balancear a árvore.
    cout << "Arvore balanceada (in-order): ";
    vector<int> inOrderOrdenada = preencheInOrder(root);
    No* root_ordenada2 = arvBalanceada(ordenarValores, 0, ordenarValores.size() - 1);
    for (size_t i = 0; i < inOrderOrdenada.size(); ++i)
        cout << inOrderOrdenada[i] << " ";
    cout << endl;

    // 1.6) Compare os resultados em 1.4 e 1.5. As árvores resultantes estão balanceadas? Elas são iguais?
    int balancedHeight = alturaArv(root_ordenada);
    cout << "Arvores resultantes balanceadas? " << endl;
    cout << "*Vetor ordenado com sort: "<< (ehBalanceada(root_ordenada) ? "Sim" : "Não") << endl;
    cout << "*Vetor ordenado com percurso in order: "<<(ehBalanceada(root_ordenada2) ? "Sim" : "Não") << endl;
    cout << "Arvores resultantes sao iguais? "<<(arvIguais(root_ordenada,root_ordenada2) ? "Sim" : "Não") << endl;
    cout << "**************************************************" << endl; 

    return 0;
}