# Config du projet

---

## structures
### structures/player.c
- typedef struct{char* color; char token; int playedTurnCount;}Player

### structures/board.c
- typedef struct{int row; int column; Player **state;}Board

### structures/game.c
- typedef struct{Player **players; int playerCount; Board *board;}Game
---

## 