#include <stdio.h>
#include <stdlib.h>

typedef struct kdnode {
    void* data;
    struct kdnode* left;
    struct kdnode* right;
} KDNode;

typedef struct ktree{
    int dimensions;
    KDNode* root;
    int (*compara)(const void *a, const void *b);

} KDTree;

// Função para criar um novo nó na KD-Tree
KDNode* createNode(void* data) {
    KDNode* newNode = (KDNode*)malloc(sizeof(KDNode));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Função para inserir um nó na KD-Tree
void insert(KDTree* tree, void* pdata) {
    
    KDNode ** ppkno;
    KDNode * pkno;

    ppkno = &(tree->root);

    while(pkno !=NULL){
                           /* 10     20 */
        if (tree->compara(pkno->data,pdata)){ /* direita*/
            ppkno = &(pkno->right);
            pkno = *ppkno;
        }else{                              /* esquerda*/
            ppkno = &(pkno->left);
            pkno = *ppkno;
        }
    }

    if ((*ppkno) == NULL){
        (*ppkno) = malloc(sizeof(KDNode));
        (*ppkno)->data = pdata;
        (*ppkno)->left = NULL;
        (*ppkno)->right = NULL;
    }

}

// Função para pesquisar um nó na KD-Tree
void* search(KDTree* tree, void* target) {
    


    return NULL;
}

int main() {
    // Exemplo de uso da KD-Tree

    // Criando a KD-Tree
    KDTree tree;
    tree.dimensions = 2; 
    tree.root = NULL;

    // Exemplo de dados a serem armazenados
    int point1[2] = {1, 2};
    int point2[2] = {3, 4};
    int point3[2] = {5, 6};

    // Inserindo os dados na KD-Tree
    insert(&tree, point1);
    insert(&tree, point2);
    insert(&tree, point3);

    // Pesquisando um ponto na KD-Tree
    int target[2] = {3, 4};
    int* result = (int*)search(&tree, target);

    if (result != NULL) {
        printf("Ponto encontrado: (%d, %d)\n", result[0], result[1]);
    } else {
        printf("Ponto não encontrado.\n");
    }

    return 0;
}
