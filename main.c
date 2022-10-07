#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "regles.c"



/*
Board *create_board(int row, int column, int winCount){
    char** grid = malloc(sizeof(int*)*row); //première dimention de la grille faites
    for(int indexRows=0; indexRows < maxRows; indexRows++){ // seconde dimention de la grille intégré
        grid[indexRows] = malloc(sizeof(int*)*maxColumns)
    }
};
*/

int main() {

    printf("Bienvenue sur La Malédiction du C\n");
    //--------------------------------------------------------------------------
    //il faut mettre ces valeurs dans le fichier, elles peuvent aussi être dans des variables mais le fichier est ce qui importe
    int rawN = 1;
    int columnN = 1;
    int joueur = 1;
    char token;
    printf("Nombre de raw (entre 2-20)?\n");
    scanf("%d", &rawN);
    printf("Nombre de column ( entre 2-20) ?\n");
    scanf("%d", &columnN);
    printf("Nombre de joueurs ?\n");
    scanf(joueur);

    // mettre tous les caractères de la grille a l'état vide, vide = ?
    print_grid(grid, rawN, columnN);
    /*for(int i=0;i<rawN;i++){    //boucle pour afficher la grille
        for(int j=0;j<columnN;j++){
            printf("%d ",grid[i][j]);
        }
        printf("\n");
    }*/
    int count = 0;
    int indexPlayer = 0;

    while (1){
        int columnChoice = wait_column_input(player); // Récupération du choix de l'utilisateur
        for (int i = 0; i < rawN; ++i) {
            if (grid[i][columnChoice] == ' ' && i != rawN-1) {
                //printf("entrée condition if\n");
                continue;
            }
            else if (grid[i][columnChoice] == ' ' && i == rawN-1){
                //printf("entrée condition else if\n");
                token = player[indexPlayer]->token;
                indexPlayer = indexPlayer+1%joueur;
                grid[i][columnChoice] = token;
                //player[indexPlayer]->playedTurnCount+=1;
            }
            else {
                //printf("entrée condition else\n");
                if (i == 0){
                    continue;
                } else {
                    grid[i-1][columnChoice] = token;
                    //player[indexPlayer]->playedTurnCount+=1;
                }
            }
        }
        for (int j =0; j < columnN; j++)
        {
            if (grid[0][j] != NULL){
                count = count + 1;
                //printf("  count %d   \n", count);
                if (count == columnN) {
                    printf("MATCH NUL\n");
                    //print_game_over();
                    goto end;
                }
            }
        }
        print_grid(grid, rawN, columnN);
    }



    /*for(int i=0;i<rawN;i++){    //boucle pour afficher la grille
        for(int j=0;j<columnN;j++){
            printf("%d ",grid[i][j]);
        }
        printf("\n");
    }*/

    killGrid(grid); //libère l'espace mémoire de la grille.
    for(int i = 0; i < joueur; i++){
        free(player[i]);
    }
    free(player);
    //return 0;
}
