#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//! For the Representation of the Graph using Matrix : 
    //! Adjacency Matrix :          bool graph[n][n];
    //! Cost Matrix :               int/reel graph[n][n];

//! For The Representation of a Graph with the method Adjacency List we are using :
    //! The strutc sommet to make every node in the graph.
    //! The function create_sommet to alocate memory and initialise the suiv pointer with NULL.
//! The code in the main is just a exepmle for creating the graph in the Support cour.


typedef struct sommet Sommet;
struct sommet {
    int n;
    Sommet* suiv;
};

typedef Sommet* Graphe;

Sommet* create_sommet(int val){
    Sommet* node = (Sommet*)malloc(sizeof(Sommet));
    node->n=val;
    node->suiv=NULL;
    return node;
}

void main(){

    Graphe graphe_1[4];

    graphe_1[0]=create_sommet(1);
        graphe_1[0]->suiv=create_sommet(2);
        graphe_1[0]->suiv->suiv=create_sommet(3);
    
    graphe_1[1]=create_sommet(2);
        graphe_1[1]->suiv=create_sommet(1);
        graphe_1[1]->suiv->suiv=create_sommet(4);
    
    graphe_1[2]=create_sommet(3);
        graphe_1[2]->suiv=create_sommet(2);
    
    graphe_1[3]=create_sommet(4);


    return ;
}
