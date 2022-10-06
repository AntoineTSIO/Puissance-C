#include "player.c"
#include "board.c"
//
// Created by Antoine TOUZART on 06/10/2022.
//
typedef struct {
    Player **players;
    int playerCount;
    Board *board;
} Game;