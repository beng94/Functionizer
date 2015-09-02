#ifndef ENTITY_HPP
#define ENTITY_HPP

#include <vector>

#include "node.hpp"

//TODO: It shouldn't be hard-coded
const int ARGS = 3;
const double MUTATION_RATE = 0.1;
const double CROSS_OVER_LIMIT = 0.5;
const int POPULATION_SIZE = 1000;

class Entity
{
private:
    Node* root;
    double fittness;

    double eval_graph(std::vector<double> vars);

public:
    Entity();
    double calc_fittness(std::vector<double> vars, double result);
    void mutate();
    Entity cross_over(Entity&);
};

class EntityContainer
{
private:
    std::vector<Entity> container;

    void sort();
public:
    EntityContainer();
    void evolve();
};

#endif
