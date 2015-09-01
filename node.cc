#include <cstdlib>
#include "node.hpp"

Node::Node(int level, int args) : data{level, args}
{
    if(this->data.get_type() != Num)
    {
        this->rChild = new Node(level + 1, args);
        this->lChild = new Node(level + 1, args);
    }
    else
    {
        //data.num will store the id of the variable in a std::vector
        this->rChild = NULL;
        this->lChild = NULL;
    }
}
