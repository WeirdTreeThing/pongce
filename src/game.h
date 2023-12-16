#ifndef GAME_H
#define GAME_H

#define FG_COL 255 // white
#define BG_COL 0   // black
#define TEXT_OFFSET 20
#define TEXT_SCALE 2
#define MAX_SCORE 99

struct game {
    struct player *Player1;
    struct player *Player2;
    struct ball *Ball;
};

extern struct game *pGame;

#endif
