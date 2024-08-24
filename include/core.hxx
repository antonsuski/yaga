#pragma once

#include <cstdint>
#include <string>

namespace yaga {
class core {
  public:
    core(/* args */) {}
    ~core() {}

    const std::uint32_t get_minor_version();
    const std::uint32_t get_major_version();
    const std::uint32_t get_patch_version();
    const std::string get_sdl_link_version();
    const std::string get_sdl_comp_version();
};
} // namespace yaga
