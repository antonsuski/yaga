#include "core.hxx"
#include "version.hxx"

#include <SDL3/SDL.h>
#include <SDL3/SDL_error.h>

#include <cstdint>
#include <iostream>

namespace yaga {
core::core(unsigned int w, unsigned int h)
    : m_w{w}, m_h{h}, m_gl_major_v{3}, m_gl_minor_v{2}, m_window{nullptr},
      m_gl_contex{nullptr} {
    std::cout << "Creating core ...\n";
}
core::~core() { std::cout << "Destroying core ...\n"; }

bool core::init() {
    std::cout << "Initializing SDL library ...\n";
    if (0 != SDL_Init(SDL_INIT_VIDEO | SDL_INIT_EVENTS)) {
        std::cerr << "Can't initialize SDL library:" << SDL_GetError() << '\n';
        return false;
    } else {
        m_window = SDL_CreateWindow("Init", m_w, m_h, SDL_WINDOW_OPENGL);
    }
    return true;
}

bool core::init_opengl() {
    int res{0};

    std::cout << "Initializing OpenGL ...\n";

    res |= SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, m_gl_major_v);
    res |= SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, m_gl_minor_v);

    if (0 > res) {
        std::cerr << "Can't setup Open GL " << m_gl_major_v << '.'
                  << m_gl_minor_v << " version.\n"
                  << SDL_GetError();
        return false;
    }

    res |= SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK,
                               SDL_GL_CONTEXT_PROFILE_ES);

    if (0 > res) {
        std::cerr << "Can't setup ES context. Switching to Core context ...\n";
        res = 0;
        res |= SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK,
                                   SDL_GL_CONTEXT_PROFILE_CORE);

        if (0 > res) {
            std::cerr << "Can't setup Core context.\n" << SDL_GetError();
            return false;
        }
    }

    m_gl_contex = SDL_GL_CreateContext(m_window);
    if (nullptr == m_gl_contex) {
        std::cerr << "Can't create GL context.\n" << SDL_GetError();
        return false;
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
