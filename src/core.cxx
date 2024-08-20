#include "core.hxx"
#include "version.hxx"

#include <cstdint>

namespace yaga {
const std::uint32_t core::get_major_version() { return version::major; }
const std::uint32_t core::get_minor_version() { return version::minor; }
const std::uint32_t core::get_patch_version() { return version::patch; }
} // namespace yaga
