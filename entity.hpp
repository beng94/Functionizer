#ifndef ENTITY_HPP
#define ENTITY_HPP

#include <vector>

#include "node.hpp"

//TODO: It shouldn't be hard-coded
const int ARGS = 3;

class Entity
{
private:
    Node* root;
    double fittness;

    double eval_graph(std::vector<double> vars);

public:
    Entity();
    double calc_fittness(std::vector<double> vars, double result);
};

#endif
