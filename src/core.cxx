#include "core.hxx"
#include "version.hxx"

#include <SDL3/SDL.h>

#include <cstdint>

namespace yaga {
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
