//
// Created by Antoine TOUZART on 06/10/2022.
//
#include <stdio.h>
#include <stdlib.h>
#include "../structures.c"


char** grid;    //max = grid[6][7]
int rows = 7;   // X max, max de la largeur de la grille
int column = 6; // Y max, max de la hauteur de la grille
int nbPourVictoire = 4; //nb de pions a alligner pour gagner
short Reseau = 0;   //détermine le mode de réseau 0 = local, 1 = client, 2 = host
unsigned int portReseau = 666;   //port réseau, uniquement utilisé si monde réseau >= 1
char nbJoueur = 2; //nombre de joueur dans la partie
/*Player Joueur1;
Player Joueur2;
Player Joueur3;
Player Joueur4;

char Joueur_ChoisirCaractere(){
    char result;
    printf("Veuillez choisir votre arme (1 caractère).\n");
    scanf("%c",&result);
    return result;
}

void initJoueur(Player* Joueur){
    Joueur->playedTurnCount = 0;
    Joueur->token = Joueur_ChoisirCaractere();
    Joueur->color = "gris";
}*/

void initGrid(int maxColumn, int maxRows, char** grid){
    grid = malloc(sizeof(int*)*maxRows);
    for(int indexRows=0; indexRows < maxRows; indexRows++){ // seconde dimention de la grille intégré
        grid[indexRows] = malloc(sizeof(int*)*maxColumn);
    }
}

void freeBoard(){
    for(int i = 0; i < column;i++){
        for(int j = 0; j < rows; j++){
            grid[i][j] = 9;
        }
    }
}

void killGrid(){
    for(int i = 0; i < rows; i++){
        free(grid[i]);
    }
    free(grid);
}

void initPartie(){  //attention

    FILE *fichierConfig = fopen("config.ini","r+");
    if(fichierConfig == NULL){
        printf("attention le dossier de configuration n\'existe pas\n");
        return;
    }

    //--------------------------------
    //a trouver dans dossier .ini
    char* poubelle = malloc( 11 * sizeof(char));
    fscanf(fichierConfig,"%s %d",poubelle,nbPourVictoire);
    fscanf(fichierConfig,"%s %d",poubelle,rows);
    fscanf(fichierConfig,"%s %d",poubelle,column);
    fscanf(fichierConfig,"%s %d",poubelle,nbJoueur);
    fscanf(fichierConfig,"%s %d",poubelle,Reseau);
    fscanf(fichierConfig,"%s %d",poubelle,portReseau);
    free(poubelle);
    //------------------------------------
    //dossier .ini touché par l'utilisateur, la bête la plus vicieuses qui existe sur ce clavier
    if(nbPourVictoire < 2 || (nbPourVictoire > rows || nbPourVictoire > column)) nbPourVictoire = 4;
    if(rows < 0) rows = 7;
    if(column < 0) column = 6;
    if(nbJoueur < 2 || nbJoueur > 4) nbJoueur = 2;
    if(Reseau > 2 || Reseau < 0) Reseau = 0;

    initGrid(column,rows,grid);//mettre en place le tableau
    freeBoard();



    fclose(fichierConfig);
}

