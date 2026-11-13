#pragma once

#include <cstdint>

using u32 = std::uint32_t;

struct RenderState {
    int width = 0;
    int height = 0;
    u32* pixels = nullptr;
};

extern RenderState render_state;

void clear_screen(u32 color);
void draw_rect_in_pixels(int x0, int y0, int x1, int y1, u32 color);

// Koordinatlar ekran yüksekliğinin yüzdesi, merkez (0, 0)
void draw_rect(float x, float y, float half_size_x, float half_size_y, u32 color);
void draw_arena_borders(float arena_half_x, float arena_half_y, u32 color);
