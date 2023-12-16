#ifndef BALL_H
#define BALL_H

#include "player.h"

#define INITIAL_BALL_SPEED 2
#define BALL_SIZE 16

struct ball {
    int x;
    int y;
    int oldx;
    int oldy;
    float speed;
    int xdirection;
    int ydirection;
};

#include "game.h"

void move_ball(struct ball *Ball);
void check_ball_screen_edge_collision(struct ball *Ball, struct player *Player1, struct player *Player2);
void check_ball_player_collision(struct ball *Ball, struct player *Player1, struct player *Player2);
void render_ball(struct ball *Ball);

#endif
