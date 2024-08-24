#include "core.hxx"
#include <iostream>

int main(int, char **) {
    using namespace yaga;
    core test{};
    std::cout << "Version:" << test.get_major_version() << '.'
              << test.get_minor_version() << '.' << test.get_patch_version()
              << '\n';
    std::cout << "SDL linked version:" << test.get_sdl_link_version() << '\n';
    std::cout << "SDL compiled version:" << test.get_sdl_comp_version() << '\n';
    return 0;
}