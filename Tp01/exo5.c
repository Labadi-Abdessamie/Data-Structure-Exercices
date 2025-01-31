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
    printf("-----L'affichage apres la multi-----\n");
    for (i = 0; i < n; i++)
        printf("Tab[%i] = %d\n", i, tab[i]);
    return;
}

void multi(int tab[], int tab_2[], int n)
{

    int i;
    tab_2[0] = tab[0] * tab[1];
    for (i = 1; i < n - 1; i++)
        tab_2[i] = tab[i - 1] * tab[i + 1];
    tab_2[n - 1] = tab[n - 1] * tab[n - 2];
    return;
}

void main()
{
    int n;
    printf("Entrer le nombre d'elements = ");
    scanf("%d", &n);
    int tableau[n], tableau_2[n];
    lire(tableau, n);
    multi(tableau, tableau_2, n);
    affichage(tableau_2, n);
    return;
}