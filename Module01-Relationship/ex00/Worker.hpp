#ifndef WORKER_HPP
#define WORKER_HPP

#include "Position.hpp"
#include "Statistic.hpp"

class Worker {

    private:
        Position _coordonnee;
        Statistic _stat;
    
    public:
        Worker();
        Worker(const Position &pos, const Statistic &stat);

};
#endif