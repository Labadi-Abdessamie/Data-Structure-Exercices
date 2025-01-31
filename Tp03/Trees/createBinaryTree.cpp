#include <iostream>
using namespace std;


// D�finition de la structure du n�ud de l'arbre binaire
struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int value) : data(value), left(NULL), right(NULL) {}
};

// Fonction r�cursive pour cr�er un arbre binaire
TreeNode* createBinaryTree() {
    int value;
    cout << "Entrez la valeur du noeud (ou -1 pour un noeud vide) : ";
    cin >> value;

    // Si la valeur est -1, cela signifie un n�ud vide
    if (value == -1) {
        return NULL;
    }

    // Cr�er le n�ud actuel avec la valeur lue
    TreeNode* root = new TreeNode(value);

    // Cr�er r�cursivement les sous-arbres gauche et droit
    cout << "Entrez les enfants du noeud " << value << " : " << endl;
    cout << "Sous-arbre gauche de " << value << " : ";
    root->left = createBinaryTree();
    cout << "Sous-arbre droit de " << value << " : ";
    root->right = createBinaryTree();

    return root;
}

// Fonction de parcours infixe

void infixe(TreeNode* root)
{
	if (root != NULL) {
		infixe(root->left);
        cout << "(" << root->data << ")-";
		infixe(root->right);	
	}

}


int main() {
    // Appel de la fonction pour cr�er un arbre binaire
    TreeNode* root = createBinaryTree();

    // Affichage de l'arbre en utilisant un parcours en largeur (BFS)
    cout << "\nArbre binaire cree (parcours en largeur) : ";
    infixe(root);

    return 0;
}

