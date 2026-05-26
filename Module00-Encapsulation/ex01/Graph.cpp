#include "Graph.hpp"
#include "Vect2.hpp"
Graph::Graph()
{
    _list = std::vector<Vect2>();
    _height = 0;
    _width = 0;
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
    for (std::vector<Vect2>::iterator it = _list.begin(); it != _list.end(); it ++) {
        if (*it == Coordinate)
        {
            std::cerr << "DUPLICATE COORDINATE" << std::endl;
            std::exit(1);
        }

    }
    if(std::abs(x) > _width)
        _width = std::abs(x);
    if (std::abs(y) > _height)
        _height = std::abs(y);
    std::cout << "\nHeight: " << _height << "\nWidth: " << _width << std::endl; 
    _list.push_back(Coordinate);
}

std::ostream &operator<<(std::ostream &out, const Graph &obj) {
    char map[static_cast<int>(obj._height) * 2][static_cast<int>(obj._width * 2)] = {'.'};

    for(unsigned long i = 0; i < obj._list.size(); i++) {
        int first = obj._list[i].getCoordinate().first;
        int second = obj._list[i].getCoordinate().second;
        if (first < 0)
            first = std::abs(first);
        else
            first = first + obj._width;
        if (second < 0)
            second = std::abs(second);
        else
            second = second + obj._height;
        map[second][first] = 'X';
    }
    int x;
    char **s = map;
    for (int y = -obj._height - 1; y <= obj._height + 1; y++) {
        for (x = -obj._width - 1; x <= obj._height +1; y++) {
            std::cout  << *(map++);
        }
    }

    out << obj._list[0];
    out << "Height: ";
    return out;
}