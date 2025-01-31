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
    for (i = 0; i < n; i++)
        printf("Tab[%i] = %d\n", i, tab[i]);
    return;
}

void inverse(int tab[], int n)
{
    int i;
    int tab_2[n];
    for (i = 0; i < n; i++)
        tab_2[i] = tab[i];
    for (i = 0; i < n; i++)
        tab[i] = tab_2[n - 1 - i];
    return;
}

void inverse_meme(int tab[], int n)
{
    int i, temp;
    for (i = 0; i < n / 2; i++)
    {
        temp = tab[i];
        tab[i] = tab[n - 1 - i];
        tab[n - 1 - i] = temp;
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
    printf("-----L'inverse avec un autre tableau-----\n");
    inverse(tableau, n);
    affichage(tableau, n);

    printf("-----L'inverse avec le meme tableau-----\n");
    inverse_meme(tableau, n);
    affichage(tableau, n);
    return;
}