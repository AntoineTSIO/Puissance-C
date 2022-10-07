//
// Created by Antoine TOUZART on 06/10/2022.
//
#include <printf.h>
#include "../intialisation/config.c"

/*void print_board(const Board *board) {
    for(int i=0;i<rows;i++){ // a déplacer dans print_board
        for(int j=0;j<column;j++){
            printf("%d ",grid[i][j]);
        }
        printf("\n");
    }
};*/

void print_game_over(){ // affiche la défaite
    printf("====================\n");
    printf("\t\tGAME OVER\n");
    printf("====================");
};

void print_winner(const Player *player){ // affiche la victoire
    printf("====================\n");
    printf("\tWinner is %c\n", player->token);
    printf("\tWon in %d turns !\n", player->playedTurnCount);
    printf("====================\n");
};

int wait_column_input(Player *player){ // prend la column ou le joueur veut jouer
    printf("%d player turn\n", player->token);
    int column = 0;
    printf("Enter column\n");
    scanf("%d",column);
    return column;
};

int play(const Board *board, Player *player, int column){ // ajoute un jeton dans le tableau
    char color = player->color;
    player->playedTurnCount = player->playedTurnCount + 1;
};

Player *create_player(const char *color, char token){
    Player * player = malloc(sizeof(Player));
    player->token = token;
    player->color = color;
    player->playedTurnCount = 0;
    return player;
}

Player *check_winner_diagonal(Board *board){

};

Player *check_winner_horizontal(Board *board){

};

Player *check_winner_vertical(Board *board){

};

void print_grid(char** grid, int row, int column) {
    for(int i=0;i<row;i++){    //boucle pour afficher la grille
        printf("| ");
        for(int j=0;j<column;j++){
            printf("%c |",grid[i][j]);
        }
        printf("\n");
    }
}
