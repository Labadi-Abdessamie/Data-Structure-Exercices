#include <stdio.h>
#include <stdlib.h>

typedef struct liste_L List;
struct liste_L
{
    int val;
    List *suiv;
};

void creation(List **L)
{
    int ajoute;
    List *nouveau, *fin;
    do
    {
        printf("Voulez vous ajouter un element (1-Y/0-N) = ");
        scanf("%d", &ajoute);
    } while (ajoute != 0 && ajoute != 1);

    while (ajoute == 1)
    {

        nouveau = (List *)malloc(sizeof(List));
        printf("Entrer la valeur = ");
        scanf("%d", &(*nouveau).val);
        if ((*L) == NULL)
        {
            *L = nouveau;
            fin = nouveau;
        }
        else
        {
            fin->suiv = nouveau;
            fin = nouveau;
        }
        fin->suiv = NULL;
        do
        {
            printf("Voulez vous ajouter un element (1-Y/0-N) = ");
            scanf("%d", &ajoute);
        } while (ajoute != 0 && ajoute != 1);
    }

    return;
}

List* affichage(List *L)
{
    if (L == NULL)
        printf("NULL;");
    else
    {
        printf("(%d)-->", L->val);
        return affichage(L->suiv);
    }
}

void Ajoute_fin(List **L)
{   
    List *courant = *L;
    if (courant->suiv == NULL)
    {
        List *nouveau;
        nouveau = (List *)malloc(sizeof(List));
        printf("\nEntrer la valeur = ");
        scanf("%d", &(*nouveau).val);
        courant->suiv = nouveau;
        nouveau->suiv = NULL;
    }
    else
    {
        return Ajoute_fin(&courant->suiv);
    }
}

void main()
{
    List *courant;

    List *list;
    list = NULL;
    creation(&list);
    affichage(list);
    Ajoute_fin(&list);
    printf("\n");
    affichage(list);
    return;
}
