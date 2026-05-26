#ifndef GRAPH_HPP
# define GRAPH_HPP

#include <iostream>
#include <utility>
#include <vector>
#include <cstdlib>
#include "Vect2.hpp"

class Graph {

    std::vector<Vect2> _list;
    
    public:
        Graph();
        ~Graph();
        
        void parse_input();
};

#endif