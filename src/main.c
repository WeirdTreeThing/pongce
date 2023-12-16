#include "game.h"
#include "player.h"
#include "ball.h"
#include "ai.h"

#include <ti/screen.h>
#include <ti/getcsc.h>
#include <stdlib.h>
#include <graphx.h>
#include <keypadc.h>

struct player Player1 = {
    .x = 0,
    .y = (GFX_LCD_HEIGHT / 2) - (PLAYER_HEIGHT / 2),
    .oldx = 0,
    .oldy = (GFX_LCD_HEIGHT / 2) - (PLAYER_HEIGHT / 2),
    .score = 0,
    .oldscore = 0,
};
struct player Player2 = {
    .x = GFX_LCD_WIDTH - PLAYER_WIDTH,
    .y = (GFX_LCD_HEIGHT / 2) - (PLAYER_HEIGHT / 2),
    .oldx = GFX_LCD_WIDTH - PLAYER_WIDTH,
    .oldy = (GFX_LCD_HEIGHT / 2) - (PLAYER_HEIGHT / 2),
    .score = 0,
    .oldscore = 0,
};
struct ball Ball = {
    .x = (GFX_LCD_WIDTH / 2) - (BALL_SIZE / 2),
    .y = (GFX_LCD_HEIGHT / 2) - (BALL_SIZE / 2),
    .oldx = (GFX_LCD_WIDTH / 2) - (BALL_SIZE / 2),
    .oldy = (GFX_LCD_HEIGHT / 2) - (BALL_SIZE / 2),
    .speed = INITIAL_BALL_SPEED,
    .xdirection = 1,
    .ydirection = 1,
};
struct game Game = {
    .Player1 = &Player1,
    .Player2 = &Player2,
    .Ball = &Ball,
};
struct game *pGame = &Game;

static int exit_key(void) {
    if (kb_Data[1] & kb_Del)
        return 1;
    else
        return 0;
}

static void init(void) {
    gfx_Begin();
    gfx_ZeroScreen();
    gfx_SetDrawBuffer();
    gfx_ZeroScreen();
    kb_SetMode(MODE_3_CONTINUOUS);
}

static void end(void) {
    kb_SetMode(MODE_0_IDLE);
    gfx_End();
}

static int game_logic(void) {
    if (exit_key())
        return 0;

    handle_player_controls(pGame->Player1);
    player_ai(pGame->Player2, pGame->Ball);
    move_ball(pGame->Ball);
    check_ball_screen_edge_collision(pGame->Ball, pGame->Player1, pGame->Player2);
    check_ball_player_collision(pGame->Ball, pGame->Player1, pGame->Player2);

    return 1;
}

static void render(void) {
    render_ball(pGame->Ball);
    render_player(pGame->Player1);
    render_player(pGame->Player2);
    render_scores(pGame->Player1, pGame->Player2);
}

int main(void) {
    init();

    while (game_logic()) {
        gfx_BlitScreen();
        render();
        gfx_SwapDraw();
    }

    end();
    return 0;
}
