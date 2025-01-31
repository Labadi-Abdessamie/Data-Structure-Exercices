#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Joueur joueur;
struct Joueur
{
    char pseudo[20];
    float score;
};

joueur lire()
{
    joueur nouveau;

    printf("\nDonner le pseudo de joueur : ");
    scanf("%s",&nouveau.pseudo);
    printf("Donner le score de joueur : ");
    scanf("%f",&nouveau.score);

    return nouveau;
}

void affichage(joueur tab[], int n)
{
    int i;
    printf("-----L'affichage des joueurs-----\n");
    for (i = 0; i < n; i++)
    {
        printf("\nLe pseudo de joueur N %i : %s\n", i + 1, (tab[i]).pseudo);
        printf("Le score de joueur N %i = %.2f\n", i + 1, (tab[i]).score);
    }

   /* printf("User\t\t|\t\tScore \n");
    printf("___________________________________________\n");
    for (i = 0; i < n; i++){
    printf("%s\t\t|\t\t%.2f \n",(tab[i]).pseudo,(tab[i]).score);
    printf("___________________________________________\n");
    }
    */
    return;
}

void inssort(joueur tab[], int n)
{   
    int j;
    float temp;
    char temp_c[20];

        for (j = n; (j > 0) && (tab[j].score > tab[j - 1].score); j--)
            {
                temp = tab[j].score;
                tab[j].score = tab[j - 1].score;
                tab[j - 1].score = temp;
                strcpy(temp_c, tab[j].pseudo);
                strcpy(tab[j].pseudo, tab[j - 1].pseudo);
                strcpy(tab[j - 1].pseudo, temp_c);
            }
    return;
}

int suppression(joueur tab[],int k,char nom[]){
    int i,j;
    for(i=0;i<k;i++)
    {
        if(strcmp(tab[i].pseudo,nom)==0)
        {
            for(j=i;j<k-1;j++)
            {
                tab[j].score=tab[j+1].score;
                strcpy(tab[j].pseudo,tab[j+1].pseudo);
            }
            return 1;
        }
    }
    return 0;
}

void main()
{
    joueur tableau[10],temp;
    int i=0,j,existe;
    int choix;
    char nom[20];
    
    tableau[i]=lire();
    
    do
    {  
      printf("\nEntrer 1 pour ajouter 2 pour supprimer 0 pour sortir = ");
      scanf("%d",&choix);

      if(choix == 1 && i<10) {
        temp=lire();
        existe=0;
        for(j=0;j<=i;j++){
            if(strcmp(tableau[j].pseudo,temp.pseudo)==0)
                existe=1;
                        }
        if(existe){
            printf("\t\tCe joueur deja existe\n");
        }
        else{
                i++;
                tableau[i]=temp;
                inssort(tableau,i);
                printf("\t\tLe joueur est ajoute\n");
            }
        }

      if(choix == 2 && i!=0){
        printf("\nEntrer le nom vous voulez supprimer : ");
        scanf("%s",nom);
        if(suppression(tableau,i+1,nom)){
        printf("\t\tLe joueur etait supprime\n");
        i--;
        }
        else printf("\t\tCe joueur n'existe pas\n");
      }
      
    } while ( choix!=0 );
 
    affichage(tableau,i+1);
     
    return;
}