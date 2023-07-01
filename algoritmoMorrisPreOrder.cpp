/*
Verifique se o algoritmo está correto ou não.
EXPLIQUE O PORQUÊ DA SUA RESPOSTA.
VALENDO 0.5 PT PARA O 1o ALUNO QUE POSTAR A RESPOSTA.
*/

void MorrisPreorder(){
    ArvoreNo<T> *p = root, *tmp;
    while (p != 0){
        if (p->left == 0){
            visit(p);
            p = p->right;
        }
        else{
            tmp = p->left;
            while (tmp->right != 0 && tmp->right != p)
                tmp = tmp->right;
            if (tmp->right == 0){
                visit(p);
                tmp->right = p;
                p = p->left;
            }
            else{
                tmp->right = 0;
                p = p->right;
            } /*fim else*/
        }
    } /*fim while*/
}

/*
    Resoposta: Sim, pois no laço while para percorrer os nós da árvore, faz uso dos ponteiros 
    *left e *right de cada nó para se conectar temporariamente e avançar para os pŕoximos nós
    a serem visitados. Dessa forma o percurso pre-order é realizado de maneira eficiente, sem 
    utilizar pilhas ou recursão, e mantendo a estrutura original da árvore.
*/