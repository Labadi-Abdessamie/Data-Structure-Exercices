#include <stdio.h>
#include <stdlib.h>
#include "../1-functions.c"
/*
!void couper(Node* root,int val,Node** left,Node** right){
!   if (root==NULL){
!        *left=NULL;
!        *right=NULL;
!    }
!    else{
!        if(val<root->valeur){
!            *right=root;
!            couper(root->gauche,val,left,&(*right)->gauche);
!        }
!        else{
!            *left=root;
!            couper(root->droit,val,&(*left)->droit,right);
!        }
!    }

!    return; 
!}

!void Adjonction_racine(Node **root, int val){
!    
!    Node* R=createNode(val);
!    couper(*root,val,&(R->gauche),&(R->droit));
!   *root=R;
!	return;
!}
*/

void main()
{
    int data;
    Node *root=NULL;
    
    do{
        printf("\nEnter la valeur  :  -1 pour Quitter = ");
        scanf("%d",&data);
        if (data!=-1)
        Adjonction_racine(&root,data);
    }while(data!=-1);
    
    printf(" Ordre infixe \n");
    infixe(root);
    printf("NULL");

    return;
}