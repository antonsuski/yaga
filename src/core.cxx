#include "core.hxx"
#include "version.hxx"

#include <SDL3/SDL.h>
#include <SDL3/SDL_error.h>

#include <cstdint>
#include <iostream>

namespace yaga {
core::core(unsigned int w, unsigned int h) : m_w{w}, m_h{h}, m_window{nullptr} {
    std::cout << "Creating core ...\n";
}
core::~core() { std::cout << "Destroying core ...\n"; }

bool core::init() {
    std::cout << "Initializing SDL library ...\n";
    if (0 != SDL_Init(SDL_INIT_VIDEO | SDL_INIT_EVENTS)) {
        std::cerr << "Can't initialize SDL library:" << SDL_GetError() << '\n';
        return false;
    } else {
        m_window = SDL_CreateWindow("Init", m_w, m_h, 0);
    }

    return true;
}

void core::close() {
    std::cout << "Uninitializating SDL library ...\n";
    SDL_DestroyWindow(m_window);
    SDL_Quit();
}

const std::uint32_t core::get_major_version() { return version::major; }
const std::uint32_t core::get_minor_version() { return version::minor; }
const std::uint32_t core::get_patch_version() { return version::patch; }

const std::string core::get_sdl_link_version() {
    std::string version{};
    const int sdl_linked_version = SDL_GetVersion();
    version += std::to_string(SDL_VERSIONNUM_MAJOR(sdl_linked_version)) + "." +
               std::to_string(SDL_VERSIONNUM_MINOR(sdl_linked_version)) + "." +
               std::to_string(SDL_VERSIONNUM_MICRO(sdl_linked_version));
    return version;
}

const std::string core::get_sdl_comp_version() {
    std::string version{};
    const int sdl_linked_version = SDL_VERSION;
    version += std::to_string(SDL_VERSIONNUM_MAJOR(sdl_linked_version)) + "." +
               std::to_string(SDL_VERSIONNUM_MINOR(sdl_linked_version)) + "." +
               std::to_string(SDL_VERSIONNUM_MICRO(sdl_linked_version));
    return version;
}
} // namespace yaga
