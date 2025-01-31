#include <stdio.h>
#include <stdlib.h>
#include "1-functions.c"

//! modifier l'arbre par remplacer la valeur du pere par le produit de ces deux fils. 

void multip(Node *root){
    if(root->right==NULL || root->left==NULL) return;
    
    //! soit calcule de pere apres go down
    root->data=root->left->data*root->right->data;
    multip(root->left);
    multip(root->right);
    
    /*//! or save the left and right of each parent then go down when finish return to modify the parent 
    int gauche=root->gauche->valeur;
    int droit=root->droit->valeur;
    multip(root->gauche);
    multip(root->droit);
    root->valeur=gauche*droit;*/
    
    return;
}


void main(){
    int data;
    Node *root=NULL;
    
    do{
        printf("\nEnter la valeur  :  -1 pour Quitter = ");
        scanf("%d",&data);
        if (data!=-1)
        Adjonction_fueille(&root,data);
    }while(data!=-1);
    
    printf("\n");
    infixe(root);
    printf("\n Apres la multiplication du les deux fils : \n");
    multip(root);
    infixe(root);

    return;
}