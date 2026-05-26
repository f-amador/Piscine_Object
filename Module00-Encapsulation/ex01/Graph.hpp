#ifndef GRAPH_HPP
# define GRAPH_HPP

#include <iostream>
#include <utility>
#include <vector>
#include <cstdlib>
#include "Vect2.hpp"

class Graph {

    std::vector<Vect2> _list;
    float _height;
    float _width;
    
    
    public:

        Graph();
        ~Graph();
        
        void parse_input();
    friend std::ostream &operator<<(std::ostream &out, const Graph &obj);
};

#endif