#include <stdio.h>
#include <iostream>
#include <fstream>
#include <emscripten/emscripten.h>

extern "C" {
    EMSCRIPTEN_KEEPALIVE
    int add(int a, int b) {
        return a + b;
    }

    EMSCRIPTEN_KEEPALIVE
    int read(char* filename) {
        std::ifstream f("file.txt");

        if (f.is_open())
            std::cout << f.rdbuf();

        return 0;
    }
}
