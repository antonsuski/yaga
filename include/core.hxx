#pragma once

#include <cstdint>

namespace yaga {
class core {
  public:
    core(/* args */) {}
    ~core() {}

    const std::uint32_t get_minor_version();
    const std::uint32_t get_major_version();
    const std::uint32_t get_patch_version();
};
} // namespace yaga
