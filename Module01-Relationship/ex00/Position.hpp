#ifndef POSITION_HPP
# define POSITION_HPP
# include 

struct Position {
    int x;
    int y;
    Position(int n1, int n2) {
        x = n1;
        y = n2;
    }
    ~Position() {
        std::cout << "Position Destructor Called\n" << std::endl;
    }
};

#endif