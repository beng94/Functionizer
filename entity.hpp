#ifndef ENTITY_HPP
#define ENTITY_HPP

#include <vector>
#include <utility>

#include "node.hpp"

const double MUTATION_RATE = 0.1;
const double CROSS_OVER_LIMIT = 0.5;
const int POPULATION_SIZE = 1000;
const int GENERATION_COUNT = 100;

class Entity
{
private:
    Node* root;
    double fittness;
    int args;

    double eval_graph(std::vector<double> vars);
    Node* get_rand_node(int&);

public:
    Entity(Node*);
    Entity(int args);
    double get_fittness() { return fittness; }
    double get_fittness() const { return fittness; }

    void calc_fittness(std::vector<std::pair<std::vector<double>, double>>);
    void mutate();
    Entity cross_over(Entity&);
    void write_dot();
};

#endif
