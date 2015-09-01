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
