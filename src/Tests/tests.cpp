#include <iostream>

#include "Tests/testing.h"
#include "Tests/SDL_RectExtensionsTests.h"

int main(int argc, char** argv) {
    std::cout << "Running Tests" << std::endl;

    RunSDL_RectExtensionTests();
    
    return 0;
}