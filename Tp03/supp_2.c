#include <stdio.h>
#include <stdlib.h>
#include "1-functions.c"

//! affihcer les sous arbres d'un parent(valeur) dans une ABR


Node* find(Node* root,int val){
    if(root==NULL) return NULL;
    if(root->data==val) return root;

    if(val<root->data)
        return find(root->left,val);

    if(val>root->data)
        return find(root->right,val);
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
    for(int i=0;i<5;i++){

        printf("\nDonner la valeur du parent pour afficher ces sous arbes : ");
        scanf("%d",&data);
        Node* sous_arbres=NULL;
        sous_arbres=find(root,data);
        if(sous_arbres==NULL) printf("Cette valeur n'existe pas dans l'arbre !");
        else infixe(sous_arbres);
    }
    
    return;
}