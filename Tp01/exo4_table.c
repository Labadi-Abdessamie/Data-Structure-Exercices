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
    printf("-----L'affichage-----\n");
    for (i = 0; i < n; i++)
        printf("Tab[%i] = %d\n", i, tab[i]);
    return;
}

void insertion(int tab[], int *n)
{
    int i, pos, valeur;
    printf("Entrer la Position de l'element [1..%d] = ", *n + 1);
    scanf("%d", &pos);
    printf("Entrer la Valeur = ");
    scanf("%d", &valeur);
    if (pos - 1 < 0 || pos - 1 > *n)
        printf("La position vous avez entrer est invalid\n");
    else
    {
        (*n) = (*n) + 1;
        if (pos - 1 == *n)
            tab[*n] = valeur;
        else
        {
            for (i = *n; i > pos - 1; i--)
                tab[i] = tab[i-1];
            tab[pos - 1] = valeur;
        }
    }
    return;
}

void main()
{
    int n;
    printf("Entrer le nombre d'elements = ");
    scanf("%d", &n);
    int tableau[n+1];
    lire(tableau, n);
    //    affichage(tableau, n);

    insertion(tableau, &n);
    affichage(tableau, n);
    return;
}