#include "renderer.h"

#include <algorithm>

RenderState render_state;

static constexpr float kRenderScale = 0.01f;

void clear_screen(u32 color)
{
    u32* pixel = render_state.pixels;
    for (int y = 0; y < render_state.height; ++y) {
        for (int x = 0; x < render_state.width; ++x) {
            *pixel++ = color;
        }
    }
}

void draw_rect_in_pixels(int x0, int y0, int x1, int y1, u32 color)
{
    x0 = std::clamp(x0, 0, render_state.width);
    x1 = std::clamp(x1, 0, render_state.width);
    y0 = std::clamp(y0, 0, render_state.height);
    y1 = std::clamp(y1, 0, render_state.height);

    for (int y = y0; y < y1; ++y) {
        u32* pixel = render_state.pixels + x0 + y * render_state.width;
        for (int x = x0; x < x1; ++x) {
            *pixel++ = color;
        }
    }
}

static float to_pixels(float units)
{
    return units * render_state.height * kRenderScale;
}

void draw_rect(float x, float y, float half_size_x, float half_size_y, u32 color)
{
    x = to_pixels(x) + render_state.width / 2.f;
    y = to_pixels(y) + render_state.height / 2.f;
    half_size_x = to_pixels(half_size_x);
    half_size_y = to_pixels(half_size_y);

    draw_rect_in_pixels(static_cast<int>(x - half_size_x),
                        static_cast<int>(y - half_size_y),
                        static_cast<int>(x + half_size_x),
                        static_cast<int>(y + half_size_y),
                        color);
}

void draw_arena_borders(float arena_half_x, float arena_half_y, u32 color)
{
    const float half_x = to_pixels(arena_half_x);
    const float half_y = to_pixels(arena_half_y);

    const int x0 = static_cast<int>(render_state.width * .5f - half_x);
    const int x1 = static_cast<int>(render_state.width * .5f + half_x);
    const int y0 = static_cast<int>(render_state.height * .5f - half_y);
    const int y1 = static_cast<int>(render_state.height * .5f + half_y);

    draw_rect_in_pixels(0, 0, render_state.width, y0, color);
    draw_rect_in_pixels(0, y1, render_state.width, render_state.height, color);
    draw_rect_in_pixels(0, y0, x0, y1, color);
    draw_rect_in_pixels(x1, y0, render_state.width, y1, color);
}
