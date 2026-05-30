#include "Vect2.hpp"
#include "Graph.hpp"
#include "macros.h"
#include <iostream>
#include <string>
#include <cstdlib>

int main(void)
{
    std::cout << "Hello World" << std::endl;

    Graph graph;
    while (1)
    {
        std::string input;

        //std::system("clear");
        std::cout << WELCOME_MSG;
        std::getline(std::cin, input);
        if (input == "1")
            graph.parse_input();
        if (input == "2") {
            std::cout << graph;
            std::system("clear");
            break;
        }
    }
}