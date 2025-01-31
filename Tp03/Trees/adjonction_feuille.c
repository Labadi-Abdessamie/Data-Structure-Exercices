#include <stdio.h>
#include <stdlib.h>
#include "../1-functions.c"

/*
!void Adjonction_fueille(Node **root, int val){
!	if((*root)==NULL){
!		(*root)=createNode(val);
!	}
!	else{
!		if(val<(*root)->valeur)
!			Adjonction_fueille(&(*root)->gauche,val);
!		else
!			Adjonction_fueille(&(*root)->droit,val);
!	}
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
        Adjonction_fueille(&root,data);
    }while(data!=-1);

    printf(" Ordre infixe \n");
    infixe(root);
    printf("NULL");

    return;
}