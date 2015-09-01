#ifndef NODE_HPP
#define NODE_HPP

#include "data.hpp"

class Node
{
private:
    Data data;
    Node* rChild;
    Node* lChild;

public:
    Node(int, int);
};

#endif
