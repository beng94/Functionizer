#ifndef ENTITY_HPP
#define ENTITY_HPP

#include <vector>
#include <utility>

#include "node.hpp"

const double MUTATION_RATE = 0.1;
const double CROSS_OVER_LIMIT = 0.5;
const int POPULATION_SIZE = 1000;

class Entity
{
private:
    Node* root;
    double fittness;
    int args;

    double eval_graph(std::vector<double> vars);

public:
    Entity(int args);
    double get_fittness();

    void calc_fittness(std::vector<std::pair<std::vector<double>, double>>);
    void mutate();
    Entity cross_over(Entity&);
    void write_dot();
};

class EntityContainer
{
private:
    std::vector<Entity> container;
    std::vector<std::pair<std::vector<double>, double>> tst_cases;

    void sort();
    bool found_solution();
    void print_solutions();

public:
    EntityContainer(std::vector<std::pair<std::vector<double>, double>>);
    void evolve();
};

#endif
