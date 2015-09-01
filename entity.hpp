#ifndef ENTITY_HPP
#define ENTITY_HPP

#include <vector>

#include "node.hpp"

class Entity
{
private:
    Node& root;
    double fittness;

    double eval_graph(std::vector<double> vars);

public:
    double calc_fittness();
};

#endif
