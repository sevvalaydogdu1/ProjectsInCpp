#include "renderer.h"

RenderState render_state;

void clear_screen(u32 color)
{
    u32* pixel = render_state.pixels;
    for (int y = 0; y < render_state.height; ++y) {
        for (int x = 0; x < render_state.width; ++x) {
            *pixel++ = color;
        }
    }
}
