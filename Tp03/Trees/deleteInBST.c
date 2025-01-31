#include<stdio.h>
#include<stdlib.h>
#include"../1-functions.c"
    //! in this file there is just an exemple of the deleting 

int main(){ 
    
    Node* root = createNode(25);
    root->left = createNode(10);
    root->right = createNode(60);
    root->left->left = createNode(5);
    root->left->right = createNode(20);
    root->left->right->left = createNode(15);
    

    root->right->left = createNode(35);
    root->right->left->left = createNode(30);
    root->right->left->right = createNode(45);

    
    root->right->left->right->left = createNode(40);
    root->right->left->right->left->left = createNode(37);
    root->right->left->right->left->right = createNode(43);


    root->right->right = createNode(65);
    root->right->right->right = createNode(70);



    printf("\tAvant la suppression\n");
    infixe(root);


    root=deleteInBST(root,60);
    printf("\n\tApres la suppression\n");
    infixe(root);
    
    return 0;
}