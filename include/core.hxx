#pragma once

#include <SDL3/SDL.h>

#include <cstdint>
#include <string>

namespace yaga {
class core {
    unsigned int m_w{};
    unsigned int m_h{};

    SDL_Window *m_window{nullptr};

  public:
    core(unsigned int w = 600, unsigned int h = 400);
    ~core();

    const std::uint32_t get_minor_version();
    const std::uint32_t get_major_version();
    const std::uint32_t get_patch_version();
    const std::string get_sdl_link_version();
    const std::string get_sdl_comp_version();

    bool init();
    void close();
};
} // namespace yaga
