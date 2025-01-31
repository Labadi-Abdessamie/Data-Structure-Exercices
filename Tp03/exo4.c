#include<stdio.h>
#include<stdlib.h>
#include"1-functions.c"


int Maximale_depth(Node* root){
    if (root==NULL) return 0;

    int depth_left=Maximale_depth(root->left);
    int depth_right=Maximale_depth(root->right);
    
    if(depth_right>depth_left)
        return 1+depth_right;
    else 
        return 1+depth_left;
}


void main()
{
    int data;
    Node *root=NULL;
    
    do{
        printf("\nEnter la valeur  :  -1 pour Quitter = ");
        scanf("%d",&data);
        if (data!=-1)
        Adjonction_fueille(&root,data);
    }while(data!=-1);
  
    printf(" Ordre infixe \n");
    infixe(root);
    printf("\n Le profondeur maximale = %d ",Maximale_depth(root));
    return;
}