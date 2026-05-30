#include "Position.hpp"
#include <iostream>

int main(void) {
    Position test;

    test.x = 10;
    test.y = 5;

    std::cout << "X: " << test.x << "\nY: " << test.y << std::endl; 
}