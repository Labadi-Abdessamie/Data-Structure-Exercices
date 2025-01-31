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

int recherche(List *L,int val,int c){
    if(L==NULL){
        return 0;
    }
    else
    {
        if(L->val==val) return c;
        else {
            c=c+1;
            return recherche(L->suiv,val,c);
            }
    }
}

void main()
{   
    int compteur=1,valeur;
    List *list;
    list = NULL;
    creation(&list);
    affichage(list);
    printf("\nEntrer la valeur vous voulez recherche = ");
    scanf("%d",&valeur);
    compteur=recherche(list,valeur,compteur);
    if(compteur!=0)
    printf("il existe dans la position %d ",compteur);
    else
    printf("Cette valeur n'existe pas");
    return;
}
