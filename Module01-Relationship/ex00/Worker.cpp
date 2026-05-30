#include "Worker.hpp"

Worker::Worker(): _coordonnee(Position(0,0)), _stat(Statistic(0,0)) {}

Worker::Worker(const Position &pos, const Statistic &stat): _coordonnee(pos), _stat(stat) {}