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

/*
int calcule(int tab[], int n)
{
    int i, j, c, nbr_en_double = 0;

    for (i = 0; i < n; i++)
    {
        c = 0;
        for (j = 0; j < n; j++)
            if (tab[i] == tab[j])
                c++;

        for (j = i + 1; j < n; j++)
            if (tab[i] == tab[j])
                c = 0;

        if (c == 3){
            printf("Le nombre repete 3 fois = %d\n",tab[i]);
            nbr_en_double++;
        }
            
    }

    return nbr_en_double;
}
*/
int calcule(int tab[], int n)
{
    int nbr_en_double = 0;

    for (int i = 0; i < n; i++)
    {
        int c = 0;
        int last_seen=-1;
        for (int j = 0; j < n; j++)
        {
            if (tab[i] == tab[j])
            {
                c++;
                last_seen=j;
            }
        }

        if ( c == 3 && i == last_seen)
        {
        
            printf("Le nombre repete 3 fois = %d\n", tab[i]);
            nbr_en_double++;
            
        }
    }

    return nbr_en_double;
}
void main()
{
    int n;
    printf("Entrer le nombre d'elements = ");
    scanf("%d", &n);
    int tableau[n];
    lire(tableau, n);
    affichage(tableau, n);
    //  printf("\nLe nombre d'elements en double = %d", calcule(tableau, n ));
    printf("\nLe nombre d'elements repete 03 fois = %d", calcule(tableau, n));
    return;
}
