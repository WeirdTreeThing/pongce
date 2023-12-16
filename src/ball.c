#include "ball.h"
#include "player.h"
#include "utils.h"
#include "game.h"
#include <math.h>
#include <graphx.h>
#include <keypadc.h>

static void move_ball_up(struct ball *Ball) {
    Ball->oldy = Ball->y;
    Ball->y = clamp(round(Ball->y - Ball->speed), 0, GFX_LCD_HEIGHT);
}

static void move_ball_down(struct ball *Ball) {
    Ball->oldy = Ball->y;
    Ball->y = clamp(round(Ball->y + Ball->speed + BALL_SIZE), 0, GFX_LCD_HEIGHT) - BALL_SIZE;
}

static void move_ball_right(struct ball *Ball) {
    Ball->oldx = Ball->x;
    Ball->x = clamp(round(Ball->x - Ball->speed), 0, GFX_LCD_WIDTH);
}

static void move_ball_left(struct ball *Ball) {
    Ball->oldx = Ball->x;
    Ball->x = clamp(round(Ball->x + Ball->speed + BALL_SIZE), 0, GFX_LCD_WIDTH) - BALL_SIZE;
}

void move_ball(struct ball *Ball) {
    // up/down
    if (Ball->ydirection)
        move_ball_down(Ball);
    else
        move_ball_up(Ball);
    // left/right
    if (Ball->xdirection)
        move_ball_left(Ball);
    else
        move_ball_right(Ball);
}

void check_ball_screen_edge_collision(struct ball *Ball, struct player *Player1, struct player *Player2) {
    // bounce up if down
    if (Ball->y == (GFX_LCD_HEIGHT - BALL_SIZE))
        Ball->ydirection = 0;
    // bounce down if up
    if (Ball->y == 0)
        Ball->ydirection = 1;
    // touching right side
    if (Ball->x == (GFX_LCD_WIDTH - BALL_SIZE)) {
        // Increase player1 score
        Player1->oldscore = Player1->score;
        Player1->score = clamp(Player1->score + 1, 0, MAX_SCORE); // max out score at 99
        Ball->x = (GFX_LCD_WIDTH / 2) - (BALL_SIZE / 2);
        Ball->y = (GFX_LCD_HEIGHT / 2) - (BALL_SIZE / 2);
        Ball->speed += 0.1;
    }
    // touching left side
    if (Ball->x == 0) {
        // Increase player2 score
        Player2->oldscore = Player2->score;
        Player2->score = clamp(Player2->score + 1, 0, MAX_SCORE);
        Ball->x = (GFX_LCD_WIDTH / 2) - (BALL_SIZE / 2);
        Ball->y = (GFX_LCD_HEIGHT / 2) - (BALL_SIZE / 2);
        Ball->speed += 0.1;
    }
}

void check_ball_player_collision(struct ball *Ball, struct player *Player1, struct player *Player2) {
    // bounce right if touching player 1
    if (check_collision(Ball->x, BALL_SIZE, Ball->y, BALL_SIZE, Player1->x, PLAYER_WIDTH, Player1->y, PLAYER_HEIGHT))
        Ball->xdirection = 1;
    // bounce left if touching player 2
    if (check_collision(Ball->x, BALL_SIZE, Ball->y, BALL_SIZE, Player2->x, PLAYER_WIDTH, Player2->y, PLAYER_HEIGHT))
        Ball->xdirection = 0;
}

void render_ball(struct ball *Ball) {
    gfx_SetColor(BG_COL);
    gfx_FillRectangle(Ball->oldx, Ball->oldy, BALL_SIZE, BALL_SIZE);
    gfx_SetColor(FG_COL);
    gfx_FillRectangle(Ball->x, Ball->y, BALL_SIZE, BALL_SIZE);
}
