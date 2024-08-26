#include "core.hxx"

#include <iostream>
#include <unistd.h>

int main(int argc, char const *argv[]) {
    std::cout << "Init ..." << std::endl;
    yaga::core test;
    test.init();
    test.init_opengl();
    std::cout << "Sleep for 5 sec\n";
    sleep(5);
    test.close();
    return 0;
}
