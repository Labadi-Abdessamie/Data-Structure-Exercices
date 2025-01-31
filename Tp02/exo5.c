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

void inverse(List **L){
    /*  
    ! the try
    List *courant,*fin;
    
    for(int i=0;i<3;i++){
    fin=*L;
    while(fin->suiv!=NULL){
        fin=fin->suiv;
    } 
    courant=*L;
    while(courant->suiv!=fin){
        courant=courant->suiv;
    }
    courant->suiv=NULL;
    fin->suiv=courant;
    
}
    (*L)=fin;
*/

/*
    !  first sol  ALEM 1ere
  List *courant, *precedent, *suivant;

  if(*L!=NULL){
    precedent=*L;
    courant=(**L).suiv;
    while(courant!=NULL){
      suivant=(*courant).suiv;
      (*courant).suiv=precedent;
      precedent=courant;
      courant=suivant;
    }
    (**L).suiv=NULL;
    (*L)=precedent;
  }
}
*/
  
    //! Second sol   GPT the simple
    List *prev = NULL;
    List *current = *L;
    List *next = NULL;

    while (current != NULL) {
        next = current->suiv;
        current->suiv = prev;
        
        prev = current;
        current = next;
    }

    (*L) = prev;

    return;
}

void main()
{   
    List *list;
    list = NULL;
    creation(&list);
    affichage(list);
    inverse(&list);
    printf("\nL'inverse : ");
    affichage(list);
    return;
}