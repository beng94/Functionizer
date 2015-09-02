#include "entity.hpp"
#include "node.hpp"

static Node* gen_new_graph()
{
    //Node's ctor recursively generates a tree
    Node* root = new Node(0, ARGS);

    return root;
}

Entity::Entity() : fittness{0.0}
{
    root = gen_new_graph();
}

EntityContainer::EntityContainer()
{
    this->container.reserve(POPULATION_SIZE);
    for(int i = 0; i < POPULATION_SIZE; i++)
    {
        this->container.push_back(Entity());
    }
}
