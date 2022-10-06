#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "regles.c"



/*
Board *create_board(int row, int column, int winCount){
    char** grid = malloc(sizeof(int*)*row); //première dimention de la grille faites
    for(int indexRows=0; indexRows < maxRows; indexRows++){ // seconde dimention de la grille intégré
        grid[indexRows] = malloc(sizeof(int*)*maxColumns);
    }
};
*/

int main() {
    printf("Bienvenue sur Puissance C\n");

    initPartie();   //methode pour initialiser la partie selon le fichier, en commentaire tant que non fontionnel

    int rawN = 1;
    int columnN = 1;
    int joueur = 1;
    printf("Nombre de raw ?\n");
    scanf(rawN);
    printf("Nombre de column ?\n");
    scanf(columnN);
    printf("Nombre de joueurs ?\n");
    scanf(joueur);

    // mettre tous les caractères de la grille a l'état vide, vide = ?

    for(int i=0;i<rawN;i++){    //boucle pour afficher la grille
        for(int j=0;j<columnN;j++){
            printf("%d ",grid[i][j]);
        }
        printf("\n");
    }

    killGrid(); //libère l'espace mémoire de la grille.

    return 0;
}
