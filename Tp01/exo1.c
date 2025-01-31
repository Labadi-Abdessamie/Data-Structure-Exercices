#include <stdio.h>
#include <stdlib.h>

void lire(int tab[], int n)
{
	int i;
	printf("-----La saisie-----\n");
	for (i = 0; i < n; i++)
	{
		printf("Tab[%i] = ", i);
		scanf("%d", &tab[i]);
	}
	return;
}

void affichage(int tab[], int n)
{
	int i;
	printf("-----L'affichage apres le tri-----\n");
	for (i = 0; i < n; i++)
		printf("Tab[%i] = %d\n", i, tab[i]);
	return;
}

void Tri_a_bulles(int tab[], int n)
{
	int i, j;
	int temp;
	for (j = 0; j < n; j++)
		for (i = n - 1; i > j; i--)
		{
			if (tab[i] < tab[i - 1])
			{
				temp = tab[i];
				tab[i] = tab[i - 1];
				tab[i - 1] = temp;
			}
		}
	return;
}

void main()
{
	int n;
	printf("Entrer le nombre d'elements = ");
	scanf("%d", &n);
	int tableau[n];
	lire(tableau, n);
	Tri_a_bulles(tableau, n);
	affichage(tableau, n);
	return;
}