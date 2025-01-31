#include <stdio.h>
#include <stdlib.h>

//! out of the organizations just a try 

typedef struct node Node;
struct node
{
	struct node *G;
	char val;
	struct node *D;
};

Node *create_noeud()
{
	int valeur;
	Node *nouveau;
	nouveau = (Node *)malloc(sizeof(Node));
	printf("\nValeur = ");
	scanf("%d", &valeur);
	nouveau->val = valeur;
	nouveau->D = NULL;
	nouveau->G = NULL;
	return nouveau;
}

Node *creation_arbre(Node **root)
{

	int answer;
	int arret ;
	if (*root == NULL)
	{
		*root = create_noeud();
	}

	do
	{
		do
		{
			printf("\nInserer a gauche du %d ?", (*root)->val);
			scanf("%d", &answer);
		} while (answer != 0 && answer != 1);
		
		if (answer == 1)
			(*root)->G = creation_arbre(&(*root)->G);
		do
		{
			printf("\nInserer a droite du %d ?", (*root)->val);
			scanf("%d", &answer);
		} while (answer != 0 && answer != 1);
		
		if (answer == 1)
			(*root)->D = creation_arbre(&(*root)->D);

		printf("Quitter modification sur %d : ", (*root)->val);
		scanf("%d", &arret);
	
	} while(arret!=1);
	return *root;
}

void infixe(Node *root)
{
	if (root == NULL)
		return;

	infixe(root->G);
	printf("%d - ", root->val);
	infixe(root->D);
}

void main()
{
	int add;
	Node *racine = NULL;
	racine = creation_arbre(&racine);
	infixe(racine);
	return;
}