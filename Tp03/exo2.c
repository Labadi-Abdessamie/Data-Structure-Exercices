#include <stdio.h>
#include <stdlib.h>

typedef struct Node Arbre;
struct Node
{
	struct Node *left;
	char val;
	struct Node *right;
};

void InsertNodeRecursive(Arbre** root, int val) {
    if ((*root) == NULL) {
        // Si le nœud actuel est NULL, créez un nouveau nœud et assignez-lui la valeur.
        Arbre* newNode = malloc(sizeof(Arbre));
        newNode->val = val;
        newNode->left = NULL;
        newNode->right = NULL;
        (*root) = newNode;
        return;
    }

    // Si la valeur est inférieure, insérez dans le sous-arbre gauche.
    if (val < (*root)->val) {
        InsertNodeRecursive(&((*root)->left), val);
    }
    // Si la valeur est supérieure, insérez dans le sous-arbre droit.
    if (val > (*root)->val) {
        InsertNodeRecursive(&((*root)->right), val);
    }
    // Si la valeur existe déjà, ne faites rien (vous pouvez également choisir de mettre à jour ici).
}


void infixe(Arbre* root){
    if(root==NULL) return;
    infixe(root->left);
    printf("(%d)->",root->val);
    infixe(root->right);
    return;
}


int main() {
    Arbre* arbre = NULL;

    // Insertion d'éléments dans l'arbre
    InsertNodeRecursive(&arbre, 17);
    InsertNodeRecursive(&arbre, 4);
    InsertNodeRecursive(&arbre, 9);
    InsertNodeRecursive(&arbre, 1);
    InsertNodeRecursive(&arbre, 7);
    InsertNodeRecursive(&arbre, 20);
    InsertNodeRecursive(&arbre, 5);
    InsertNodeRecursive(&arbre, 12);

    // Affichage de l'arbre
    infixe(arbre);
    
    return 0;
}