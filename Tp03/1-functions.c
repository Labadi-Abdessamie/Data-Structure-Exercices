#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct noeud Node;
struct noeud
{
    int data;
    Node *left;
    Node *right;
};

Node *createNode(int val)
{
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->data = val;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

//! the three types of display
void infixe(Node *root)
{
    if (root == NULL)
        return;
    infixe(root->left);
    printf("%d - ",root->data);
    infixe(root->right);
}

void prefixe(Node *root)
{
    if (root == NULL)
        return;
    printf("%d - ",root->data);
    prefixe(root->left);
    prefixe(root->right);
}

void postfixe(Node *root)
{
    if (root == NULL)
        return;
    postfixe(root->left);
    postfixe(root->right);
    printf("%d - ",root->data);
}

//! Count nodes function
int CountNodes(Node* root) {
    // Si l'arbre est vide, le nombre de nœuds est zéro.
    if (root == NULL) {
        return 0;
    } else {
        // Nombre de nœuds dans le sous-arbre left + nombre de nœuds dans le sous-arbre right + le nœud actuel.
        return 1 + CountNodes(root->left) + CountNodes(root->right);
    }
}
//! Maximale depth function  == height of the tree
int Maximale_depth(Node* root){
    if (root==NULL) return 0;

    int depth_left=Maximale_depth(root->left);
    int depth_right=Maximale_depth(root->right);
    
    if(depth_right>depth_left)
        return 1+depth_right;
    else 
        return 1+depth_left;
}

//! to see if the node is an leave
bool isLeave(Node* root){
    return (root!=NULL && root->left==NULL && root->right==NULL);
}

//! to Count the leaves numberes 
int CountLeaves(Node* root) {
    // Si l'arbre est vide, le nombre de fueille est zéro.
    if (root == NULL) {
        return 0;
    } else {
            if(isLeave(root)) return 1;
            else return CountLeaves(root->left)+CountLeaves(root->right);
            }
}

//! to see if the arbre (sous_arbre) is right or leftComp
bool isRightcomp(Node* root){
    if(root!=NULL){

        if(isLeave(root->left)) return isRightcomp(root->right);
        else return false;
    }
    return true;
}
bool isleftcomp(Node* root){
    if(root!=NULL){

        if(isLeave(root->right)) return isleftcomp(root->left);
        else return false;
    }
    return true;
}

//! Inverse between the right and left son of each parent (Inverse Tree)
void InverseArbre(Node *root) {
    if (root == NULL) {
        return;  // Si l'arbre est vide, rien à faire
    }

    // Échange des pointeurs left et right du nœud actuel
    Node *temp = root->left;
    root->left = root->right;
    root->right = temp;

    // Appel récursif pour inverser les sous-arbres left et right
    InverseArbre(root->left);
    InverseArbre(root->right);
}
//! Modify the parent value by the product the his two sons 
void multip(Node *root){
    if(root->right==NULL || root->left==NULL) return;
    
    root->data=root->left->data*root->right->data;
    multip(root->left);
    multip(root->right);
   
    return;
}
//! find and point to a given value (so we can modify it or display his sub_trees / anything else)
Node* find(Node* root,int val){
    if(root==NULL) return NULL;
    if(root->data==val) return root;

    if(val<root->data)
        return find(root->left,val);

    if(val>root->data)
        return find(root->right,val);
}

//! Adjonction fueille
void Adjonction_fueille(Node **root, int val){
	if((*root)==NULL){
		(*root)=createNode(val);
	}
	else{
		if(val<(*root)->data)
			Adjonction_fueille(&(*root)->left,val);
		else
			Adjonction_fueille(&(*root)->right,val);
	}
	return;
}
//! Adjonction racine
void couper(Node* root,int val,Node** left,Node** right){
    if (root==NULL){
        *left=NULL;
        *right=NULL;
    }
    else{
        if(val<root->data){
            *right=root;
            couper(root->left,val,left,&(*right)->left);
        }
        else{
            *left=root;
            couper(root->right,val,&(*left)->right,right);
        }
    }
    return; 
}

void Adjonction_racine(Node **root, int val){
    
    Node* R=createNode(val);
    couper(*root,val,&(R->left),&(R->right));
    *root=R;
	return;
}

//! Creation an binary tree under user control
Node* Creation_arbre(){
    int val;

    printf("\nEntrer la valeur de noeud : (-1==NULL) : ");
    scanf("%d",&val);

    if(val==-1) return NULL;

    Node* root=createNode(val);

    printf("\tEntrer les enfants du %d :",root->data);
    printf("\nSous arbre a left du %d :",root->data);
    root->left=Creation_arbre();
    
    printf("Sous arbre a droite du %d :",root->data);
    root->right=Creation_arbre();

    return root;
}

//! delete in BST

    //! 2 ways find the min of the maxs  or  the max of the mins

//!find the min of the maxs
Node* findMin(Node* root){
    while(root->left!=NULL)
        root=root->left;
        
    return root;
}

//!find the max of the mins
Node* findMax(Node* root){
    while(root->right!=NULL)
        root=root->right;

    return root;
}

Node* deleteInBST(Node* root,int val){
     
    if(root==NULL) return root;

    if(val<root->data){
        root->left=deleteInBST(root->left,val);
    }
    else if(val>root->data){
        root->right=deleteInBST(root->right,val);
    }
    else{
            //! here of the root we wanna delete hasn't left child so we take the right and we delete the root
            if(root->left==NULL){
                Node* temp=root->right;
                free(root);
                return temp;
            }   
            //! here of the root we wanna delete hasn't right child so we take the left and we delete the root
            else if(root->right==NULL){
                Node* temp=root->left;
                free(root);
                return temp;
            }
            else{
            //! here if the root has two child so we have 02 ways to do it 
                
                //! the first we take the min of the maxs
                /*
                Node* temp=findMin(root->right);
                root->data=temp->data;
                root->right=deleteInBST(root->right,temp->data);
                */
                //! the second we take the max of the mins 
                
                Node* temp=findMax(root->left);
                root->data=temp->data;
                root->left=deleteInBST(root->left,temp->data);               
            }
    }
    return root;
}

