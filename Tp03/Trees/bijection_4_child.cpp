#include <iostream>
using namespace std;

// D�finition de la structure du n�ud de l'arbre non binaire
struct NonBinaryTreeNode {
    int data;
    NonBinaryTreeNode* firstChild;
    NonBinaryTreeNode* secondChild;
    NonBinaryTreeNode* thirdChild;
    NonBinaryTreeNode* fourthChild;

    NonBinaryTreeNode(int value)
        : data(value), firstChild(NULL), secondChild(NULL), thirdChild(NULL), fourthChild(NULL) {}
};

// D�finition de la structure du n�ud de l'arbre binaire
struct BinaryTreeNode {
    int data;
    BinaryTreeNode* left;
    BinaryTreeNode* right;

    BinaryTreeNode(int value) : data(value), left(NULL), right(NULL) {}
};

// Fonction pour transformer un arbre non binaire en un arbre binaire
BinaryTreeNode* transformToBinaryTree(NonBinaryTreeNode* nonBinaryRoot) {
    if (nonBinaryRoot == NULL) {
        return NULL;
    }

    // Cr�er un n�ud binaire avec la m�me valeur que le n�ud non binaire
    BinaryTreeNode* binaryRoot = new BinaryTreeNode(nonBinaryRoot->data);

    // Utiliser le premier enfant comme sous-arbre gauche
    binaryRoot->left = transformToBinaryTree(nonBinaryRoot->firstChild);

    // Utiliser le deuxi�me enfant comme fils droit du premier enfant
    if (nonBinaryRoot->firstChild != NULL) {
        binaryRoot->left->right = transformToBinaryTree(nonBinaryRoot->secondChild);
    }

    // Utiliser le troisi�me enfant comme fils droit du deuxi�me enfant
    if (nonBinaryRoot->secondChild != NULL) {
        binaryRoot->left->right->right = transformToBinaryTree(nonBinaryRoot->thirdChild);
    }

    // Utiliser le quatri�me enfant comme fils droit du troisi�me enfant
    if (nonBinaryRoot->thirdChild != NULL) {
        binaryRoot->left->right->right->right = transformToBinaryTree(nonBinaryRoot->fourthChild);
    }

    return binaryRoot;
}

// Fonction pour afficher l'arbre binaire en ordre pr�fixe
void preOrderTraversal(BinaryTreeNode* root) {
    if (root != NULL) {
        cout << root->data << " ";
        preOrderTraversal(root->left);
        preOrderTraversal(root->right);
    }
}

int main() {
    // Exemple d'un arbre non binaire
    NonBinaryTreeNode* nonBinaryTree = new NonBinaryTreeNode(1);
    nonBinaryTree->firstChild = new NonBinaryTreeNode(2);
    nonBinaryTree->firstChild->firstChild = new NonBinaryTreeNode(3);
    nonBinaryTree->firstChild->secondChild = new NonBinaryTreeNode(4);
    nonBinaryTree->firstChild->thirdChild = new NonBinaryTreeNode(5);
    nonBinaryTree->firstChild->fourthChild = new NonBinaryTreeNode(6);

    // Transformer l'arbre non binaire en un arbre binaire
    BinaryTreeNode* binaryTree = transformToBinaryTree(nonBinaryTree);

    // Afficher l'arbre binaire en ordre pr�fixe
    cout << "\n Arbre binaire en ordre pr�fixe : ";
    preOrderTraversal(binaryTree);
    cout << endl;

    return 0;
}

