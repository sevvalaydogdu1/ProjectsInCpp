#include "game.h"

#include "colors.h"
#include "renderer.h"

static constexpr float kArenaHalfX = 85.f;
static constexpr float kArenaHalfY = 45.f;

void simulate_game(float)
{
    draw_rect(0, 0, kArenaHalfX, kArenaHalfY, kArenaColor);
    draw_arena_borders(kArenaHalfX, kArenaHalfY, kBorderColor);
}
