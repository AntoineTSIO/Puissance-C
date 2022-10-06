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

Player *create_player(const char *color, char token);

Board *create_board(int row, int column, int winCount);

Game *init_game(int playerCount, int row, int column, int winCount);

int wait_column_input();

int play(const Board *board, Player *player, int column);

Player *check_winner_diagonal(Board *board);

Player *check_winner_horizontal(Board *board);

Player *check_winner_vertical(Board *board);

void free_game(Game *game);

void free_board(Board *board);

void free_player(Player *player);

void print_board(const Board *board);

void print_game_over();

void print_winner(const Player *player);

