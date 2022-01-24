#include "stdio.h"
#include <iostream>

int main(int argc, char **argv) {

    for (int i = 0; i < argc - 1; i++) {
        printf("%d\n", argv[i]);
    }

    std::cout << "initial commit" << std::endl;

    return 0;
}