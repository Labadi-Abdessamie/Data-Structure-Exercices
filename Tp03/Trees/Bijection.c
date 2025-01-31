#include <stdio.h>
#include <stdlib.h>

typedef struct node node;
struct node
{
    int data;
    node *first;
    node *second;
    node *third;
    node *forth;
};

typedef struct b_node b_node;
struct b_node
{
    int data;
    b_node *st_son;
    b_node *brothers;
};

node *createNode(int val)
{
    node *newNode = (node *)malloc(sizeof(node));
    newNode->data = val;
    newNode->first = NULL;
    newNode->second = NULL;
    newNode->third = NULL;
    newNode->forth = NULL;
    return newNode;
}

b_node *createnode(int val)
{
    b_node *newNode = (b_node *)malloc(sizeof(b_node));
    newNode->data = val;
    newNode->st_son = NULL;
    newNode->brothers = NULL;
    return newNode;
}
//! This functions does not work the problem is the childs of the root done but here when he stop 
        // !he do not handle their childs
/* 
void bijection(node *root, b_node **b_root)

{
    if (root == NULL)
        return;

    b_node *newNode = createnode(root->data);
    b_node *sibling=NULL;
    if (*b_root == NULL) {
       *b_root = newNode;
	}

    if (root->first != NULL){
        newNode->st_son = createnode(root->first->data);
		sibling = newNode->st_son;  
        bijection(root->first, &newNode->st_son);
    }
    if (root->second != NULL){
        while (sibling->brothers != NULL) {
            sibling = sibling->brothers;
        }
		sibling->brothers = createnode(root->second->data);
    	bijection(root->second, &sibling->brothers);
    }
    
    
    if (root->third != NULL){
        while (sibling->brothers != NULL) {
            sibling = sibling->brothers;
        }
        sibling->brothers = createnode(root->third->data);
    	bijection(root->third, &sibling->brothers);
    }
    if (root->forth != NULL){
        while (sibling->brothers != NULL) {
            sibling = sibling->brothers;
        }
        sibling->brothers = createnode(root->forth->data);
    	bijection(root->forth, &sibling->brothers);
    }
    return;
}*/


void bijection(node *root, b_node **b_root)
{
    if (root == NULL)
        return;

    b_node *newNode = createnode(root->data);
    b_node *sibling = NULL;

    if (*b_root == NULL) {
        *b_root = newNode;
    } else {
        sibling = *b_root;
        while (sibling->brothers != NULL) {
            sibling = sibling->brothers;
        }
        sibling->brothers = newNode;
    }
    if (root->first != NULL) {
        bijection(root->first, &newNode->st_son);
    }
    if (root->second != NULL) {
        bijection(root->second, &newNode->brothers);
    }
    if (root->third != NULL) {
        bijection(root->third, &newNode->brothers);
    }
    if (root->forth != NULL) {
        bijection(root->forth, &newNode->brothers);
    }
}


void affichage(node *root)
{
    if (root == NULL)
        return;
    printf("(%d)->", root->data);
    affichage(root->first);
    affichage(root->second);
    affichage(root->third);
    affichage(root->forth);
    return;
}

void affichage1(b_node* root){
    if (root == NULL)
        return;
    printf("(%d)->", root->data);
    if (root->st_son != NULL){
    affichage1(root->st_son);
    }
    if (root->brothers != NULL){
    affichage1(root->brothers);
    }
    return;
}
void main()
{
    int data;
    node *root = createNode(0);
    root->first = createNode(1);
    root->second = createNode(2);
    root->third = createNode(3);
    root->forth = createNode(4);

    root->first->first = createNode(5);
    root->first->second = createNode(6);
    root->first->third = createNode(7);

    root->second->first = createNode(8);

    root->forth->first = createNode(9);
    root->forth->second = createNode(10);
    root->forth->third = createNode(11);
    root->forth->forth = createNode(12);

    root->forth->second->first = createNode(13);
    root->forth->second->second = createNode(14);

    root->forth->forth->first = createNode(15);
    root->forth->forth->second = createNode(16);
   
    printf("\n\tDisplay the General Tree \n\n");
	affichage(root);
    
	b_node *b_root = NULL;  

    bijection(root, &b_root);
	printf("\n\n\tDisplay the Binary Tree :\n\n");
    affichage1(b_root);

    printf("\n\n");
    return;
}