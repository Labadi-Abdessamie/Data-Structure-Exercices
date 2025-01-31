#include <stdio.h>
#include <stdlib.h>

//! This code is of the first TP session which go like create an given binary arbre
//! then display it with the three mode  GPD  ,  PGD  ,  GDP  .

typedef struct noeud Node;
struct noeud
{
    int valeur;
    Node *gauche;
    Node *droit;
};

//* Creation d’un nouveau neoud
Node *createNode(int val)
{
    Node *newNode = malloc(sizeof(Node));
    newNode->valeur = val;
    newNode->gauche = NULL;
    newNode->droit = NULL;
    return newNode;
}

//* ordre G-P-D
void infixe(Node *root)
{
    if (root == NULL)
        return;
    infixe(root->gauche);
    printf("%d -> ",root->valeur);
    infixe(root->droit);
}
//* ordre P-G-D
void prefixe(Node *root)
{
    if (root == NULL)
        return;
    printf("%d -> ",root->valeur);
    prefixe(root->gauche);
    prefixe(root->droit);
}
//* ordre G-D-P
void postfixe(Node *root)
{
    if (root == NULL)
        return;
    postfixe(root->gauche);
    postfixe(root->droit);
    printf("%d -> ",root->valeur);
}


void insertGauche(Node *root, int val)
{
    if(root == NULL){
        printf("Erreur d'insertion du %d.\n",val);
        return;
    }
    root->gauche = createNode(val);
    return;
}

void insertDroit(Node *root, int val)
{
    if(root == NULL){
        printf("Erreur d'insertion du %d.\n",val);
        return;
    }
    root->droit = createNode(val);
    return;
}



int main()
{
    Node *root = createNode(1);
    insertGauche(root, 2);
    insertDroit(root, 3);
    //! cote gauche du root
    insertGauche(root->gauche, 4);
    insertDroit(root->gauche, 5);

    printf(" Ordre infixe \n");
    infixe(root);
    printf("NULL\n Ordre prefixe \n");
    prefixe(root);
    printf("NULL\n Ordre postfixe \n");
    postfixe(root); 
    printf("NULL");

    return 0;
}