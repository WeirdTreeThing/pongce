#include "player.h"
#include "game.h"
#include "utils.h"
#include <graphx.h>
#include <keypadc.h>

void move_player_up(struct player *Player) {
    Player->oldy = Player->y;
    Player->y = clamp(Player->y - PLAYER_SPEED, 0, GFX_LCD_HEIGHT);
}

void move_player_down(struct player *Player) {
    Player->oldy = Player->y;
    Player->y = clamp(Player->y + PLAYER_SPEED + PLAYER_HEIGHT, 0, GFX_LCD_HEIGHT) - PLAYER_HEIGHT;
}

void handle_player_controls(struct player *Player) {
    if (kb_Data[7] & kb_Down)
	move_player_down(Player);
    if (kb_Data[7] & kb_Up)
	move_player_up(Player);
}

void render_scores(struct player *Player1, struct player *Player2) {
    // initalize text settings
    gfx_SetTextScale(TEXT_SCALE, TEXT_SCALE);
    gfx_SetTextBGColor(BG_COL);

    // draw old scores as black to clear them for the next value
    gfx_SetTextFGColor(BG_COL);
    gfx_SetTextTransparentColor(FG_COL);
    // score 1
    gfx_SetTextXY(TEXT_OFFSET, TEXT_OFFSET);
    gfx_PrintInt(Player1->oldscore, 2);
    // score2
    gfx_SetTextXY(GFX_LCD_WIDTH - TEXT_OFFSET - 30, TEXT_OFFSET);
    gfx_PrintInt(Player2->oldscore, 2);

    // draw new scores
    gfx_SetTextFGColor(FG_COL);
    gfx_SetTextTransparentColor(BG_COL);
    // score 1
    gfx_SetTextXY(TEXT_OFFSET, TEXT_OFFSET);
    gfx_PrintInt(Player1->score, 2);
    // score 2
    gfx_SetTextXY(GFX_LCD_WIDTH - TEXT_OFFSET - 30, TEXT_OFFSET);
    gfx_PrintInt(Player2->score, 2);
}

void render_player(struct player *Player) {
    gfx_SetColor(BG_COL);
    gfx_FillRectangle(Player->oldx, Player->oldy, PLAYER_WIDTH, PLAYER_HEIGHT);
    gfx_SetColor(FG_COL);
    gfx_FillRectangle(Player->x, Player->y, PLAYER_WIDTH, PLAYER_HEIGHT);
}
