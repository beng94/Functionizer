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

void Entity::write_dot()
{
    std::ofstream file;
    file.open("graph.dot");
    file << "digraph A\n{\n";
    this->root->write_dot(file);
    file << "}";
    file.close();
}

EntityContainer::EntityContainer()
{
    this->container.reserve(POPULATION_SIZE);
    for(int i = 0; i < POPULATION_SIZE; i++)
    {
        this->container.push_back(Entity());
    }
}
