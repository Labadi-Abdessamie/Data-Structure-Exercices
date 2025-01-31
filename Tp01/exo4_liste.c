#include <stdio.h>
#include <stdlib.h>

typedef struct liste List;
struct liste
{
    int val;
    List *suiv;
};

List *creation(List **tete, int *n)
{
    int i;
    List *nouveau;
    (*tete) = NULL;
    printf("Entrer le nombre d'elements = ");
    scanf("%d", &(*n));
    for (i = 0; i < (*n); i++)
    {
        nouveau = (List *)malloc(sizeof(List));
        printf("Entrer La valeur N %i = ", i + 1);
        scanf("%d", &(*nouveau).val);
        (*nouveau).suiv = (*tete);
        (*tete) = nouveau;
    }
    return (*tete);
}

List *inserstion_pos(List **tete, int n)
{
    List *nouveau, *courant;
    courant = *tete;
    int i, pos;
    if ((*tete) == NULL)
        printf("Liste vide\n");
    else
    {
        nouveau = (List *)malloc(sizeof(List));
        printf("Entrer La valeur vous voulez ajoute = ");
        scanf("%d", &(*nouveau).val);
        printf("Entrer La position = ");
        scanf("%d", &pos);
        if (pos < 1 || pos > n + 1)
            printf("La position vous avez enter invalid\n");
        else
        {
            if (pos == 1)
            {
                (*nouveau).suiv = (*tete);
                (*tete) = nouveau;
            }
            else
            {
                for (i = 1; i < pos - 1; i++)
                {
                    courant = courant->suiv;
                }
                nouveau->suiv = courant->suiv;
                courant->suiv = nouveau;
            }
        }
    }
    return *tete;
}
void affichage(List *tete)
{
    while (tete != NULL)
    {
        printf("%d-->", (*tete).val);
        tete = tete->suiv;
    }
    printf("NULL\n");
    return;
}

void main()
{
    List *liste1;
    int N;
    liste1 = creation(&liste1, &N);
    affichage(liste1);
    liste1 = inserstion_pos(&liste1, N);
    affichage(liste1);

    return;
}