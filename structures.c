//
// Created by Antoine TOUZART on 06/10/2022.
//
typedef struct {
    char *color;
    char token;
    int playedTurnCount;
} Player;

typedef struct {
    int row;
    int column;
    Player **state;
} Board;

typedef struct {
    Player **players;
    int playerCount;
    Board *board;
} Game;
