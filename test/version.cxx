#include "core.hxx"
#include <iostream>

int main(int, char **) {
    using namespace yaga;
    core test{};
    std::cout << "version:" << test.get_major_version() << '.'
              << test.get_minor_version() << '.' << test.get_patch_version()
              << '\n';
    return 0;
}