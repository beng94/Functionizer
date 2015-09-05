#include "entity.hpp"
#include "node.hpp"

Entity::Entity() : fittness{-1.0}
{
    root = new Node(0, ARGS);
}

double Entity::get_fittness()
{
    if(this->fittness == -1.0)
    {
        //TODO: Calculate the fittness and save it
    }

    return this->fittness;
}

double Entity::eval_graph(std::vector<double> vars)
{
    return this->root->eval_node(vars);
}

void Entity::calc_fittness(std::vector<std::pair<std::vector<double>, double>> pairs)
{
    double fittness = 0.0;
    for(auto pair: pairs)
    {
        std::vector<double> vars = pair.first;
        double result = pair.second;
        double calc_result = this->eval_graph(vars);

        fittness += (result - calc_result) * (result - calc_result);
    }

    this->fittness = fittness;
}

void Entity::write_dot()
{
    std::ofstream file;
    file.open("graph.dot");
    file << "digraph A\n{\n";
    this->root->write_dot(file);
    file << "}";
    file.close();
}

EntityContainer::EntityContainer(std::vector<std::pair<std::vector<double>, double>> tst_cases) :
                 tst_cases{tst_cases}
{
    this->container.reserve(POPULATION_SIZE);
    for(int i = 0; i < POPULATION_SIZE; i++)
    {
        Entity new_entity;
        new_entity.calc_fittness(tst_cases);
        this->container.push_back(new_entity);
    }
}
