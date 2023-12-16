#include "ai.h"
#include "player.h"
#include "game.h"
#include <stdlib.h>

void player_ai(struct player *Player, struct ball *Ball) {
    // very dumb ai for testing
    int i = rand();
    if ((i % 2) == 0) {
        if (Player->y + (PLAYER_HEIGHT / 2) < Ball->y)
            move_player_down(Player);
        else
            move_player_up(Player);
    }
}
