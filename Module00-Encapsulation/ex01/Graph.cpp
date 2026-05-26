#include "Graph.hpp"

Graph::Graph()
{
    _list = std::vector<Vect2>();
}

Graph::~Graph() {
    std::cout << "Graph destructor called\n";
}

void Graph::parse_input(){
    std::string input;
    float x , y;

    std::cout << "\nX Coordinate: ";
    std::getline(std::cin, input);
    x = std::atof(input.c_str());
    if (!x && input.size() == 1 && !std::isdigit(input[0])) {
        std::cerr << "INVALID INPUT" << std::endl;
        std::exit(1);
    }
    std::cout << "\nY Coordinate: ";
    std::getline(std::cin, input);
    y = std::atof(input.c_str());
    if (!y && input.size() == 1 && !std::isdigit(input[0])) {
        std::cerr << "INVALID INPUT" << std::endl;
        std::exit(1);
    }
    Vect2 Coordinate(x,y);
    _list.push_back(Coordinate);
}