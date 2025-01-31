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

List *affichage(List *L)
{
    if (L == NULL)
        printf("NULL;");
    else
    {
        printf("(%d)-->", L->val);
        return affichage(L->suiv);
    }
}

void eclatation(List *L, List **l1, List **l2)
{
    List *nouveau,*fin_l1 ,*fin_l2;
    fin_l1=NULL;
    fin_l2=NULL;
    while (L != NULL)
    {
    nouveau = (List *)malloc(sizeof(List));
    nouveau->val = L->val;
    nouveau->suiv = NULL;
        if (abs(L->val) % 2 == 1)
        {
            if (*l1 == NULL)
            *l1 = nouveau;
            else
            fin_l1->suiv = nouveau;
            fin_l1 = nouveau;
        }
        else
        {
            if (*l2 == NULL)
            *l2 = nouveau;
            else
            fin_l2->suiv = nouveau;
            fin_l2 = nouveau;
        }
    L=L->suiv;
    }

    return;
}

void main()
{
    List *courant;

    List *list, *l_paire, *l_impaires;
    list = NULL;
    l_paire = NULL;
    l_impaires = NULL;
    creation(&list);
    affichage(list);
    eclatation(list, &l_impaires, &l_paire);
    printf("\n");
    printf("Les nombres impaires : ");
    affichage(l_impaires);
    printf("\n");
    printf("Les nombres paires : ");
    affichage(l_paire);
    return;
}
