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

void putstr(char* str, int y_coord, int width)
{
    std::cout << y_coord << " ";
    for (int i = 0; i < 2 * (width + 1); i++)
    {
        std::cout << str[i] << " ";
    }
    std::cout << std::endl;
}

std::ostream &operator<<(std::ostream &out, const Graph &obj) {
    int map_height = static_cast<int>(obj._height) * 2 + 3;  // +3 for borders
    int map_width = static_cast<int>(obj._width) * 2 + 3;
    char map[map_height][map_width];
    
    // Initialize with '.'
    for(int i = 0; i < map_height; i++)
        for(int j = 0; j < map_width; j++)
            map[i][j] = '.';

    for(unsigned long i = 0; i < obj._list.size(); i++) {
        int first = obj._list[i].getCoordinate().first;
        int second = obj._list[i].getCoordinate().second;
        
        // Convert to array indices
        int x_index = first + obj._width + 1;
        int y_index = second + obj._height + 1;
        
        if(x_index >= 0 && x_index < map_width && 
           y_index >= 0 && y_index < map_height) {
            map[y_index][x_index] = 'X';
        }
    }
    
    // Print the grid
    for (int y = 0; y < map_height; y++) {
        int display_y = y - obj._height - 1;
        putstr(map[y], display_y, obj._width);
    }

    out << obj._list[0];
    out << "Height: ";
    return out;
}