#include <stdio.h>
#include <stdlib.h>
#include "../1-functions.c"

/*
!Node* Creation_arbre(){
!    int val;
!
!    printf("\nEntrer la valeur de noeud : (-1==NULL) : ");
!    scanf("%d",&val);
!
!    if(val==-1) return NULL;
!
!    Node* root=createNode(val);
!
!    printf("\tEntrer les enfants du %d :",root->valeur);
!    printf("\nSous arbre a gauche du %d :",root->valeur);
!    root->gauche=Creation_arbre();
!    
!    printf("Sous arbre a droite du %d :",root->valeur);
!    root->droit=Creation_arbre();
!
!    return root;
!}
*/

int main(){
    Node* root=Creation_arbre();
    infixe(root);

    return 0;
}