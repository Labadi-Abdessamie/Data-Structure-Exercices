#include <stdio.h>
#include <stdlib.h>

typedef struct Node Arbre;
struct Node
{
	struct Node *left;
	char val;
	struct Node *right;
};

void InsertNode(Arbre** root,int val){
    Arbre* Node;
    Node=malloc(sizeof(Arbre));
    Node->val=val;
    Node->left=NULL;
    Node->right=NULL;

    //! if the root null the new node will be the root
    if((*root)==NULL)
    {
        (*root)=Node;
        return;
    }

    //! if the root exist we see where we place it.
    Arbre* courant=(*root);

    while(1){
        if(Node->val<courant->val){
            if(courant->left==NULL){
                courant->left=Node;
                break;
            }
            else{
                courant=courant->left;
            }
        }
        else if(Node->val>courant->val){
            if(courant->right==NULL){
                courant->right=Node;
                break;
            }
            else{
                courant=courant->right;
            }
        }
        else{
            free(Node);
            break;
        }
    }
    return;
}


void infixe(Arbre* root){
    if(root==NULL) return;
    infixe(root->left);
    printf("(%d)->",root->val);
    infixe(root->right);
    return;
}

void main(){
    Arbre *arbre=NULL; 
    InsertNode(&arbre,17);
    InsertNode(&arbre,4);
    InsertNode(&arbre,9);
    InsertNode(&arbre,1);
    InsertNode(&arbre,7);
    InsertNode(&arbre,20);
    InsertNode(&arbre,5);
    InsertNode(&arbre,12);
    infixe(arbre);
    return;
}