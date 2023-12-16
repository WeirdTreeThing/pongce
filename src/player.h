#ifndef PLAYER_H
#define PLAYER_H

#define PLAYER_HEIGHT 70
#define PLAYER_WIDTH 10
#define PLAYER_SPEED 3

struct player {
    int x;
    int y;
    int oldx;
    int oldy;
    int score;
    int oldscore;
};

void render_scores(struct player *Player1, struct player *Player2);
void handle_player_controls(struct player *Player);
void move_player_up(struct player *Player);
void move_player_down(struct player *Player);
void render_player(struct player *Player);
#endif
