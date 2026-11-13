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
